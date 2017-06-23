#include "LoginScreen.h"

LoginScreen::LoginScreen(QWidget *parent) : QMainWindow(parent)
{
	QWidget *centralWidget = new QWidget(this);
	QVBoxLayout *layoutMain = new QVBoxLayout(centralWidget);
	QHBoxLayout *layoutPanels = new QHBoxLayout();
	LoginPanel *wgtYoutube = new LoginPanel(centralWidget, QPixmap(":/pix/images/icons/youtube-icon.png"), "rgb(205, 30, 24)"),
			*wgtTwitch = new LoginPanel(centralWidget, QPixmap(":/pix/images/icons/twitch-icon.png"), "rgb(100, 65, 164)");

	layoutPanels->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	layoutPanels->addWidget(wgtYoutube);
	layoutPanels->addWidget(wgtTwitch);
	layoutPanels->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	layoutPanels->setSpacing(24);

	layoutMain->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	layoutMain->addLayout(layoutPanels);
	layoutMain->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	layoutMain->setContentsMargins(12, 12, 12, 12);
	layoutMain->setSpacing(6);

	setCentralWidget(centralWidget);
	setWindowTitle("Login Screen");
	resize(640, 480);

	connect(wgtYoutube, &LoginPanel::requestLogin, this, &LoginScreen::on_youtubeLoginRequested);
	connect(wgtTwitch, &LoginPanel::requestLogin, this, &LoginScreen::on_twitchLoginRequested);
}

void LoginScreen::on_youtubeLoginRequested(const QString &email, const QString &pass)
{
	qDebug() << email << pass;
}

void LoginScreen::on_twitchLoginRequested(const QString &email, const QString &pass)
{
	qDebug() << email << pass;
}
