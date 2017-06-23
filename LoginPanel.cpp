#include "LoginPanel.h"

LoginPanel::LoginPanel(QWidget *parent, const QPixmap &pixmap, const QString &color) : QWidget(parent)
{
	QVBoxLayout *layoutMain = new QVBoxLayout(this);
	QHBoxLayout *horizontalLayout = new QHBoxLayout();
	QLabel *labImage = new QLabel(this), *labMessage = new QLabel(tr("No password provided!"), this);
	QPushButton *btnLogin = new QPushButton(tr("LOGIN"), this);

	m_editEmail = new EntryField(this, tr("Enter e-mail:"), color);
	m_editPassword = new EntryField(this, tr("Enter password:"), color);

	labImage->setFixedHeight(80);
	labImage->setPixmap(pixmap);

	labMessage->setAlignment(Qt::AlignCenter);
	labMessage->setStyleSheet("QLabel { color: " + color + "; }");

	btnLogin->setStyleSheet(QString("QPushButton {\n"
							"	color: white;\n"
							"	background-color: %1;\n"
							"	border: 0px solid %1;\n"
							"	border-radius: 2px;\n"
							"	width: 92px;\n"
							"	height: 36px;\n"
							"}\n"
							"QPushButton:hover {\n"
							"	color:  %1;\n"
							"	background-color: white;\n"
							"	border: 0px solid white;\n"
							"}\n"
							"QPushButton:pressed {\n"
							"	color:  %1;\n"
							"	background-color: rgb(224, 224, 224);\n"
							"	border: 0px solid rgb(224, 224, 224);\n"
							"}").arg(color));

	horizontalLayout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	horizontalLayout->addWidget(btnLogin);
	horizontalLayout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

	layoutMain->addWidget(labImage);
	layoutMain->addWidget(m_editEmail);
	layoutMain->addWidget(m_editPassword);
	layoutMain->addWidget(labMessage);
	layoutMain->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed));
	layoutMain->addLayout(horizontalLayout);

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	connect(btnLogin, &QPushButton::clicked, this, &LoginPanel::on_btnLoginClicked);
}

void LoginPanel::on_btnLoginClicked()
{
	requestLogin(m_editEmail->text(), m_editPassword->text());
}
