// Graphics Example 2

#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <QPoint>
#include <QLine>
#include <QFont>
#include <QLabel>

	// Goal: Draw a sniper crosshair along
	// with the word "Fire"

int main(int argc, char* argv[])

{
	QApplication myApp(argc, argv);				
	
	QPixmap myMap(400,300);								// Establish 400 x 300 pixmap
	myMap.fill(Qt::black);								// Makes sure background is black
	
	QPainter p(&myMap);									// QPainter class attached to QPixmap
	p.setRenderHint(QPainter::Antialiasing, true);		// Enable antialiasing
	
	// Draw four points and two crosshair lines
	p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap));
	QPoint p1(200,25);			// West
	QPoint p2(200,275);			// East
	QPoint p3(50, 150);			// North
	QPoint p4(350, 150);		// South
	p.drawPoint(p1);
	p.drawPoint(p2);
	p.drawPoint(p3);
	p.drawPoint(p4);
	p.setPen(QPen(Qt::white, 5, Qt::SolidLine, Qt::FlatCap));
	QLine line1(p1, p2);
	QLine line2(p3, p4);
	p.drawLine(line1);
	p.drawLine(line2);
	
	// Define Bounding Rectangle, set pen, and draw ellipse
	p.setPen(QPen(Qt::blue, 5, Qt::SolidLine, Qt::SquareCap));
	QRect rect1(125,75,150,150);						// 150 x 150 circle at (125,75)
	p.drawEllipse(rect1);
	
	// Write text
	p.setPen(Qt::red);
	QPoint tp(300,175);
	p.drawText(tp, "Fire");
	
	// Draw arcs --- angles are 1/16 of a degree, hence the scale factor
	p.setPen(Qt::green);
	p.drawArc(QRect(100, 50, 200, 200), 00*16, 90*16);	// Rectangle defines ellipse
	p.drawArc(QRect(100, 50, 200, 200), 180*16, 90*16);	// second arg is start angle
	p.drawArc(QRect(100, 50, 200, 200), 120*16, 30*16);	// third arg is span size of angle
	p.drawArc(QRect(100, 50, 200, 200), 300*16, 30*16);
	
	
	// Create QLabel and set Pixmap into QLabel
	QLabel myLabel;
	myLabel.setPixmap(myMap);
	myLabel.show();
	
	return myApp.exec();
}
