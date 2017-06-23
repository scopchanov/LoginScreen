#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>
#include <QDebug>
#include "LoginPanel.h"

class LoginScreen : public QMainWindow
{
	Q_OBJECT
public:
	explicit LoginScreen(QWidget *parent = 0);

private slots:
	void on_youtubeLoginRequested(const QString &email, const QString &pass);
	void on_twitchLoginRequested(const QString &email, const QString &pass);
};

#endif // LOGINSCREEN_H
