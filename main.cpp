// Graphics Example 8

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


int main(int argc, char* argv[])

{
	QApplication myApp(argc, argv);				
	
	QPixmap myMap(400,300);								// Establish 400 x 300 pixmap
	myMap.fill(Qt::black);								// Makes sure background is black
	
	QPainter p(&myMap);									// QPainter class attached to QPixmap
	p.setRenderHint(QPainter::Antialiasing, true);		// Enable antialiasing
	p.setWindow(-50, -50, 100, 100);					// Define Logical coordinate window
	// Logical (-50, -50) corresponds to physical (0, 0) and scales 400 x 300 to 100 x 100
	// Draw red arrow polygon
	p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
	p.setBrush(QBrush(Qt::SolidPattern));
	QPoint points[4] = { QPoint(0,25),		/* Top Middle */
	 					 QPoint(15,-25),	/* Bottom Right */ 
	 					 QPoint(0, 0),		/* Bottom Middle */
	 					 QPoint(-15, -25) };/* Bottom Left */
	p.drawPolygon(points, 4);
	
	// Rotate 45 degrees and redraw polygon
	p.rotate(45.0);										// Rotate from logical center
	p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
	p.drawPolygon(points, 4);
	
	// Create QLabel and set Pixmap into QLabel
	QLabel myLabel;
	myLabel.setPixmap(myMap);
	myLabel.show();
	
	return myApp.exec();
}
