#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "EntryField.h"

class LoginPanel : public QWidget
{
	Q_OBJECT
public:
	explicit LoginPanel(QWidget *parent, const QPixmap &pixmap, const QString &color);

	void setImage(const QPixmap &pixmap);

private:
	EntryField *m_editEmail, *m_editPassword;

private slots:
	void on_btnLoginClicked();

signals:
	void requestLogin(const QString &, const QString &);
};

#endif // LOGINPANEL_H
