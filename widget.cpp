#include "widget.h"

Widget::Widget(QWidget *parent) : QPushButton(parent)
{
	illuminated = false;
	
	blackPixmap = new QPixmap(400,100);
	painter = new QPainter(blackPixmap);	// connects QPainter to blackPixmap
	blackPixmap->fill(Qt::black);			// set pixmap to black
	blackIcon = new QIcon(*blackPixmap);	// copies pixmap to QIcon
	delete painter;
	delete blackPixmap;
	
	redPixmap = new QPixmap(400,100);
	painter = new QPainter(redPixmap);		// connects QPainter to redPixmap
	redPixmap->fill(Qt::red);				// set pixmap to red
	redIcon = new QIcon(*redPixmap);		// copies pixmap to QIcon
	delete painter;
	delete redPixmap;
	
	this->setIcon(*blackIcon);
	connect(this, SIGNAL(clicked()), this, SLOT(togglePixmap()));
}

void Widget::paintEvent(QPaintEvent* pe)
{
	// Adjust icon based upon illuminated flag
	if (illuminated)
		this->setIcon(*redIcon);
	else
		this->setIcon(*blackIcon);
	
	// Pass on other paint events to parent class event handler
	QPushButton::paintEvent(pe);
}

void Widget::togglePixmap()
{
	// Toggle illuminated flag
	illuminated = !illuminated;
	
	// Trigger update of widget display
	this->update();
}

Widget::~Widget()
{
}
