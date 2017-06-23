#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class LineEdit : public QLineEdit
{
	Q_OBJECT
public:
	explicit LineEdit(QWidget *parent);

protected:
	void focusInEvent(QFocusEvent *event);
	void focusOutEvent(QFocusEvent *event);

private slots:
	void on_textChanged(const QString &str);

signals:
	void focusChanged(bool);
	void cleared(bool);
};

#endif // LINEEDIT_H
