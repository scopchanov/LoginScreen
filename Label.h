#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>

class Label : public QLabel
{
	Q_OBJECT
	Q_PROPERTY(double fontSize READ fontSize WRITE setFontSize)
public:
	explicit Label(QWidget *parent, const QString &str);

public slots:
	void zoom(bool out);
	void enableZoom(bool value);

private:
	double fontSize() const;
	void setFontSize(double value);

	int m_fontSize;
	bool m_zoomEnabled = true;
};

#endif // LABEL_H
