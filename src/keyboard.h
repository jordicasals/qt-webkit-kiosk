#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <QWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QStackedLayout>

class Keyboard : public QWidget {
    Q_OBJECT

	public:
		explicit Keyboard(QWidget *parent = 0);

		inline void setWidget(QWidget *widget) {
			this->widget = widget;
		}

	public slots:
		void nextShift();
		virtual void show();

	protected slots:
		void notifyClicked(int key);
		void notifyClicked(const QString &text);

	protected:
		QPushButton *addKey(const QString &label, int key, QSignalMapper *signalMapper, QLayout *l, int width = 64, int height = 64);
		QPushButton *addKey(const QString &text, QSignalMapper *signalMapper, QLayout *l, int width = 64, int height = 64);
		QPushButton *addKey(const QString &label, const QString &text, QSignalMapper *signalMapper, QLayout *l, int width = 64, int height = 64);
		QPushButton *addKey(const QString &label, const char *slot, QLayout *l, int width = 64, int height = 64);
		QPushButton *addKey(const QString &label, QLayout *l, int width = 64, int height = 64);

		void sendKeyEvent(int key, const QString &text = QString());

	private:
		QWidget *widget;
		QStackedLayout *sl;
};

#endif
