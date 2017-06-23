#include "EntryField.h"

EntryField::EntryField(QWidget *parent, const QString &str, const QString &color) : QWidget(parent)
{
	QVBoxLayout *layoutMain = new QVBoxLayout(this);

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	m_label = new Label(this, str);
	m_label->setStyleSheet("QLabel { color: " + color + "; }");
	m_lineEdit = new LineEdit(this);
	m_lineEdit->setStyleSheet(QString("QLineEdit { font-size: 12pt; padding-bottom: 5px; border: none; background-color: transparent; border-bottom: 2px solid %1; color: %1;}").arg(color));

	layoutMain->addSpacerItem(new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed));
	layoutMain->addWidget(m_lineEdit);
	layoutMain->setContentsMargins(0, 0, 0, 0);
	layoutMain->setSpacing(0);

	connect(m_lineEdit, &LineEdit::focusChanged, m_label, &Label::zoom);
	connect(m_lineEdit, &LineEdit::cleared, m_label, &Label::enableZoom);
}

QString EntryField::text() const
{
	return m_lineEdit->text();
}

void EntryField::setText(const QString &str)
{
	m_lineEdit->setText(str);
}

void EntryField::setTitle(const QString &str)
{
	m_label->setText(str);
}
