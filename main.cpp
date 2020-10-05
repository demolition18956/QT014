// Graphics Example 2

#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <QPoint>
#include <QLabel>

	// Goal: Draw two "spaceships"

int main(int argc, char* argv[])

{
	QApplication myApp(argc, argv);				
	
	QPixmap myMap(400,300);								// Establish 400 x 300 pixmap
	myMap.fill(Qt::black);								// Makes sure background is black
	
	QPainter p(&myMap);									// QPainter class attached to QPixmap
	p.setRenderHint(QPainter::Antialiasing, true);		// Enable antialiasing
	
	// Draw red arrow polygon
	p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
	p.setBrush(QBrush(Qt::SolidPattern));
	QPoint points[4] = { QPoint(200,100),	/* Top Middle */
	 					 QPoint(215,175),	/* Bottom Right */ 
	 					 QPoint(200, 150),	/* Bottom Middle */
	 					 QPoint(185, 175) };/* Bottom Left */
	p.drawPolygon(points, 4);
	
	// Apply translation and redraw polygon as green
	p.translate(75,50);
	p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
	p.drawPolygon(points, 4);
	
	// Create QLabel and set Pixmap into QLabel
	QLabel myLabel;
	myLabel.setPixmap(myMap);
	myLabel.show();
	
	return myApp.exec();
}
