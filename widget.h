#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QIcon>

class Widget : public QPushButton
{
	Q_OBJECT
	
	public:
		Widget(QWidget *parent = 0);
		~Widget();
		
	protected:
		void paintEvent(QPaintEvent* pe);	// Override paint event handler
		
	private:
		QPixmap* redPixmap;
		QPixmap* blackPixmap;
		QPainter* painter;
		QIcon* redIcon;
		QIcon* blackIcon;
		bool illuminated;
		
	private slots:
		void togglePixmap();
};
#endif
