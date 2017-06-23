#include "LineEdit.h"

LineEdit::LineEdit(QWidget *parent) : QLineEdit(parent)
{
	connect(this, &LineEdit::textChanged, this, &LineEdit::on_textChanged);
}

void LineEdit::focusInEvent(QFocusEvent *event)
{
	QLineEdit::focusInEvent(event);

	focusChanged(true);
}

void LineEdit::focusOutEvent(QFocusEvent *event)
{
	QLineEdit::focusOutEvent(event);

	focusChanged(false);
}

void LineEdit::on_textChanged(const QString &str)
{
	cleared(str.isEmpty());
}
