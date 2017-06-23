#ifndef ENTRYFIELD_H
#define ENTRYFIELD_H

#include <QVBoxLayout>
#include "Label.h"
#include "LineEdit.h"

class EntryField : public QWidget
{
	Q_OBJECT
public:
	explicit EntryField(QWidget *parent, const QString &str, const QString &color);

	QString text() const;
	void setText(const QString &str);
	void setTitle(const QString &str);

private:
	Label *m_label;
	LineEdit *m_lineEdit;
};

#endif // ENTRYFIELD_H
