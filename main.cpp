// Graphics Example 6

#include <QApplication>
#include <QtDebug>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <QPoint>
#include <QLabel>

	// Goal: Save and load
	// .jpg into pixmap

int main(int argc, char* argv[])

{
	QApplication myApp(argc, argv);				
	
	QPixmap yourMap(400,300);								// Establish 400 x 300 pixmap
	yourMap.fill(Qt::black);								// Makes sure background is black
	
	QPainter p(&yourMap);									// QPainter class attached to QPixmap
	p.setRenderHint(QPainter::Antialiasing, true);		// Enable antialiasing
	
	// Draw red arrow polygon
	p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
	p.setBrush(QBrush(Qt::SolidPattern));
	QPoint points[4] = { QPoint(200,100),	/* Top Middle */
	 					 QPoint(215,175),	/* Bottom Right */ 
	 					 QPoint(200, 150),	/* Bottom Middle */
	 					 QPoint(185, 175) };/* Bottom Left */
	p.drawPolygon(points, 4);
	
	// Save Pixmap as jpg
	// 0 = determine image format by looking at filename; -1 = default image quality
	if (!yourMap.save("arrow.jpg",0,-1))
		qDebug() << "Error - unable to save pixmap";
		
	// Load jpeg image from file
	QPixmap myMap;
	
	if (!myMap.load("arrow.jpg", 0, Qt::AutoColor))
		qDebug() << "Error - unable to load pixmap";
	
	// Create QLabel and set Pixmap into QLabel
	QLabel myLabel;
	myLabel.setPixmap(myMap);
	myLabel.show();
	
	return myApp.exec();
}
