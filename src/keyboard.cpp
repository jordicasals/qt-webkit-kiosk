#include "keyboard.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QKeyEvent>
#include <QCoreApplication>

////////////////////////////////////////////////////////////////////////////////////////////////////
Keyboard::Keyboard(QWidget *parent) : QWidget(parent) {
	setFocusPolicy(Qt::NoFocus);

	// Style
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::darkGray);
	setAutoFillBackground(true);
	setPalette(pal);

	QSignalMapper *signalMapper = new QSignalMapper(this);

	sl = new QStackedLayout(this);
	if (sl) {
		QVBoxLayout *vl1 = new QVBoxLayout(this);
		if (vl1) {
			vl1->setAlignment(Qt::AlignCenter);

			// First row
			QHBoxLayout *hl1 = new QHBoxLayout(this);
			if (hl1) {
				hl1->setAlignment(Qt::AlignCenter);
				hl1->setSpacing(5);
				hl1->setContentsMargins(0, 0, 0, 0);

				addKey("1", signalMapper, hl1);
				addKey("2", signalMapper, hl1);
				addKey("3", signalMapper, hl1);
				addKey("4", signalMapper, hl1);
				addKey("5", signalMapper, hl1);
				addKey("6", signalMapper, hl1);
				addKey("7", signalMapper, hl1);
				addKey("8", signalMapper, hl1);
				addKey("9", signalMapper, hl1);
				addKey("0", signalMapper, hl1);

				vl1->addLayout(hl1);
			}

			// Second row
			QHBoxLayout *hl2 = new QHBoxLayout(this);
			if (hl2) {
				hl2->setAlignment(Qt::AlignCenter);
				hl2->setSpacing(5);
				hl2->setContentsMargins(0, 0, 0, 0);

				addKey("q", signalMapper, hl2);
				addKey("w", signalMapper, hl2);
				addKey("e", signalMapper, hl2);
				addKey("r", signalMapper, hl2);
				addKey("t", signalMapper, hl2);
				addKey("y", signalMapper, hl2);
				addKey("u", signalMapper, hl2);
				addKey("i", signalMapper, hl2);
				addKey("o", signalMapper, hl2);
				addKey("p", signalMapper, hl2);

				vl1->addLayout(hl2);
			}

			// Third row
			QHBoxLayout *hl3 = new QHBoxLayout(this);
			if (hl3) {
				hl3->setAlignment(Qt::AlignCenter);
				hl3->setSpacing(5);
				hl3->setContentsMargins(0, 0, 0, 0);

				addKey("a", signalMapper, hl3);
				addKey("s", signalMapper, hl3);
				addKey("d", signalMapper, hl3);
				addKey("f", signalMapper, hl3);
				addKey("g", signalMapper, hl3);
				addKey("h", signalMapper, hl3);
				addKey("j", signalMapper, hl3);
				addKey("k", signalMapper, hl3);
				addKey("l", signalMapper, hl3);

				vl1->addLayout(hl3);
			}

			// Fourth row
			QHBoxLayout *hl4 = new QHBoxLayout(this);
			if (hl4) {
				hl4->setAlignment(Qt::AlignCenter);
				hl4->setSpacing(5);
				hl4->setContentsMargins(0, 0, 0, 0);

				addKey("z", signalMapper, hl4);
				addKey("x", signalMapper, hl4);
				addKey("c", signalMapper, hl4);
				addKey("v", signalMapper, hl4);
				addKey("b", signalMapper, hl4);
				addKey("n", signalMapper, hl4);
				addKey("m", signalMapper, hl4);

				vl1->addLayout(hl4);
			}

			// Fifth row
			QHBoxLayout *hl5 = new QHBoxLayout(this);
			if (hl5) {
				hl5->setAlignment(Qt::AlignCenter);
				hl5->setSpacing(5);
				hl5->setContentsMargins(0, 0, 0, 0);

				addKey("ABC", SLOT(nextShift()), hl5, 101);
				addKey(",", signalMapper, hl5);
				addKey(" ", signalMapper, hl5, 340);
				addKey(".", signalMapper, hl5);
				addKey("\u232B", Qt::Key_Backspace, signalMapper, hl5, 101);

				vl1->addLayout(hl5);
			}

			QWidget *w = new QWidget();
			w->setLayout(vl1);

			sl->addWidget(w);
		}

		QVBoxLayout *vl2 = new QVBoxLayout(this);
		if (vl2) {
			vl2->setAlignment(Qt::AlignCenter);

			// First row
			QHBoxLayout *hl1 = new QHBoxLayout(this);
			if (hl1) {
				hl1->setAlignment(Qt::AlignCenter);
				hl1->setSpacing(5);
				hl1->setContentsMargins(0, 0, 0, 0);

				addKey("1", signalMapper, hl1);
				addKey("2", signalMapper, hl1);
				addKey("3", signalMapper, hl1);
				addKey("4", signalMapper, hl1);
				addKey("5", signalMapper, hl1);
				addKey("6", signalMapper, hl1);
				addKey("7", signalMapper, hl1);
				addKey("8", signalMapper, hl1);
				addKey("9", signalMapper, hl1);
				addKey("0", signalMapper, hl1);

				vl2->addLayout(hl1);
			}

			// Second row
			QHBoxLayout *hl2 = new QHBoxLayout(this);
			if (hl2) {
				hl2->setAlignment(Qt::AlignCenter);
				hl2->setSpacing(5);
				hl2->setContentsMargins(0, 0, 0, 0);

				addKey("Q", signalMapper, hl2);
				addKey("W", signalMapper, hl2);
				addKey("E", signalMapper, hl2);
				addKey("R", signalMapper, hl2);
				addKey("T", signalMapper, hl2);
				addKey("Y", signalMapper, hl2);
				addKey("U", signalMapper, hl2);
				addKey("I", signalMapper, hl2);
				addKey("O", signalMapper, hl2);
				addKey("P", signalMapper, hl2);

				vl2->addLayout(hl2);
			}

			// Third row
			QHBoxLayout *hl3 = new QHBoxLayout(this);
			if (hl3) {
				hl3->setAlignment(Qt::AlignCenter);
				hl3->setSpacing(5);
				hl3->setContentsMargins(0, 0, 0, 0);

				addKey("A", signalMapper, hl3);
				addKey("S", signalMapper, hl3);
				addKey("D", signalMapper, hl3);
				addKey("F", signalMapper, hl3);
				addKey("G", signalMapper, hl3);
				addKey("H", signalMapper, hl3);
				addKey("J", signalMapper, hl3);
				addKey("K", signalMapper, hl3);
				addKey("L", signalMapper, hl3);

				vl2->addLayout(hl3);
			}

			// Fourth row
			QHBoxLayout *hl4 = new QHBoxLayout(this);
			if (hl4) {
				hl4->setAlignment(Qt::AlignCenter);
				hl4->setSpacing(5);
				hl4->setContentsMargins(0, 0, 0, 0);

				addKey("Z", signalMapper, hl4);
				addKey("X", signalMapper, hl4);
				addKey("C", signalMapper, hl4);
				addKey("V", signalMapper, hl4);
				addKey("B", signalMapper, hl4);
				addKey("N", signalMapper, hl4);
				addKey("M", signalMapper, hl4);

				vl2->addLayout(hl4);
			}

			// Fifth row
			QHBoxLayout *hl5 = new QHBoxLayout(this);
			if (hl5) {
				hl5->setAlignment(Qt::AlignCenter);
				hl5->setSpacing(5);
				hl5->setContentsMargins(0, 0, 0, 0);

				addKey("{@=", SLOT(nextShift()), hl5, 101);
				addKey(",", signalMapper, hl5);
				addKey(" ", signalMapper, hl5, 340);
				addKey(".", signalMapper, hl5);
				addKey("\u232B", Qt::Key_Backspace, signalMapper, hl5, 101);

				vl2->addLayout(hl5);
			}

			QWidget *w = new QWidget();
			w->setLayout(vl2);

			sl->addWidget(w);
		}

		QVBoxLayout *vl3 = new QVBoxLayout(this);
		if (vl3) {
			vl3->setAlignment(Qt::AlignCenter);

			// First row
			QHBoxLayout *hl1 = new QHBoxLayout(this);
			if (hl1) {
				hl1->setAlignment(Qt::AlignCenter);
				hl1->setSpacing(5);
				hl1->setContentsMargins(0, 0, 0, 0);

				addKey("1", signalMapper, hl1);
				addKey("2", signalMapper, hl1);
				addKey("3", signalMapper, hl1);
				addKey("4", signalMapper, hl1);
				addKey("5", signalMapper, hl1);
				addKey("6", signalMapper, hl1);
				addKey("7", signalMapper, hl1);
				addKey("8", signalMapper, hl1);
				addKey("9", signalMapper, hl1);
				addKey("0", signalMapper, hl1);

				vl3->addLayout(hl1);
			}

			// Second row
			QHBoxLayout *hl2 = new QHBoxLayout(this);
			if (hl2) {
				hl2->setAlignment(Qt::AlignCenter);
				hl2->setSpacing(5);
				hl2->setContentsMargins(0, 0, 0, 0);

				addKey("%", signalMapper, hl2);
				addKey("~", signalMapper, hl2);
				addKey("$", signalMapper, hl2);
				addKey("€", signalMapper, hl2);
				addKey("[", signalMapper, hl2);
				addKey("]", signalMapper, hl2);
				addKey("<", signalMapper, hl2);
				addKey(">", signalMapper, hl2);
				addKey("{", signalMapper, hl2);
				addKey("}", signalMapper, hl2);

				vl3->addLayout(hl2);
			}

			// Third row
			QHBoxLayout *hl3 = new QHBoxLayout(this);
			if (hl3) {
				hl3->setAlignment(Qt::AlignCenter);
				hl3->setSpacing(5);
				hl3->setContentsMargins(0, 0, 0, 0);

				addKey("@", signalMapper, hl3);
				addKey("#", signalMapper, hl3);
				addKey("&&", signalMapper, hl3);
				addKey("*", signalMapper, hl3);
				addKey("-", signalMapper, hl3);
				addKey("+", signalMapper, hl3);
				addKey("=", signalMapper, hl3);
				addKey("(", signalMapper, hl3);
				addKey(")", signalMapper, hl3);

				vl3->addLayout(hl3);
			}

			// Fourth row
			QHBoxLayout *hl4 = new QHBoxLayout(this);
			if (hl4) {
				hl4->setAlignment(Qt::AlignCenter);
				hl4->setSpacing(5);
				hl4->setContentsMargins(0, 0, 0, 0);

				addKey("_", signalMapper, hl4);
				addKey("|", signalMapper, hl4);
				addKey("\"", signalMapper, hl4);
				addKey("'", signalMapper, hl4);
				addKey(":", signalMapper, hl4);
				addKey(";", signalMapper, hl4);
				addKey("/", signalMapper, hl4);

				vl3->addLayout(hl4);
			}

			// Fifth row
			QHBoxLayout *hl5 = new QHBoxLayout(this);
			if (hl5) {
				hl5->setAlignment(Qt::AlignCenter);
				hl5->setSpacing(5);
				hl5->setContentsMargins(0, 0, 0, 0);

				addKey("abc", SLOT(nextShift()), hl5, 101);
				addKey(",", signalMapper, hl5);
				addKey(" ", signalMapper, hl5, 340);
				addKey(".", signalMapper, hl5);
				addKey("\u232B", Qt::Key_Backspace, signalMapper, hl5, 101);

				vl3->addLayout(hl5);
			}

			QWidget *w = new QWidget();
			w->setLayout(vl3);

			sl->addWidget(w);
		}

		setLayout(sl);
	}

	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(notifyClicked(int)));
	connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(notifyClicked(const QString &)));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QPushButton *Keyboard::addKey(const QString &label, QSignalMapper *signalMapper, QLayout *l, int width, int height) {
	return addKey(label, label, signalMapper, l, width, height);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QPushButton *Keyboard::addKey(const QString &label, int key, QSignalMapper *signalMapper, QLayout *l, int width, int height) {
	QPushButton *button = addKey(label, l, width, height);
	if (button) {
		if (signalMapper) {
			signalMapper->setMapping(button, key);
			connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		}
	}
	return button;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QPushButton *Keyboard::addKey(const QString &label, const QString &text, QSignalMapper *signalMapper, QLayout *l, int width, int height) {
	QPushButton *button = addKey(label, l, width, height);
	if (button) {
		if (signalMapper) {
			signalMapper->setMapping(button, text);
			connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
		}
	}
	return button;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QPushButton *Keyboard::addKey(const QString &label, const char *slot, QLayout *l, int width, int height) {
	QPushButton *button = addKey(label, l, width, height);
	if (button) {
		connect(button, SIGNAL(clicked()), this, slot);
	}
	return button;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
QPushButton *Keyboard::addKey(const QString &label, QLayout *l, int width, int height) {
	QPushButton *button = new QPushButton(label);
	if (button) {
		button->setFixedSize(width, height);

		if (l) {
			l->addWidget(button);
		}
	}
	return button;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Keyboard::notifyClicked(int key) {
	sendKeyEvent(key);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Keyboard::notifyClicked(const QString &text) {
	if (text == "&&") {
		sendKeyEvent(0, QString("&"));
	} else {
		sendKeyEvent(0, text);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Keyboard::sendKeyEvent(int key, const QString &text) {
	qDebug() << "send key event:" << key << text;

	widget->setFocus();

	QKeyEvent pressEvent = QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, text);
	QKeyEvent releaseEvent = QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier, text);

	QCoreApplication::sendEvent(widget, &pressEvent);
	QCoreApplication::sendEvent(widget, &releaseEvent);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Keyboard::nextShift() {
	int index = (sl->currentIndex() + 1) % sl->count();
	sl->setCurrentIndex(index);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void Keyboard::show() {
	sl->setCurrentIndex(0);
	QWidget::show();
}
