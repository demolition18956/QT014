// Graphics Example 1

#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <QLabel>

int main(int argc, char* argv[])

{
	QApplication myApp(argc, argv);				
	
QPixmap myMap(400,300);									// Establish 400 x 300 pixmap
	
	QPainter p(&myMap);									// QPainter class attached to QPixmap
	p.setRenderHint(QPainter::Antialiasing, true);		// Enable antialiasing
	
	// Draw rect frame ('380 x 280' vs. '400 x 300')
	p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::SquareCap));
	p.drawRect(10,10,380,280);							// Drawing begins at (10, 10)
	
	
	// Vary Cap Style and Pen Color
	p.setPen(QPen(Qt::blue, 10, Qt::SolidLine, Qt::SquareCap));	// Blue and Square Cap
	QRect rect1(25,25,50,30);							// New 50 x 30 QRect object at (25,25)
	p.drawRect(rect1);
	
	p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));	// Red and Round Cap
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	p.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::FlatCap));	// Green and Flat Cap
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	
	// Vary Join Style
	p.setPen(QPen(Qt::blue, 10, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));	// Blue and MiterJoin
	rect1.translate(-200,75);							// Translate rect left by 200 and down 75
	p.drawRect(rect1);									
	
	p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin));	// Red and BevelJoin
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	p.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));	// Green and RoundJoin
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	
	// Vary Join Style
	p.setPen(QPen(Qt::blue, 2, Qt::DashLine, Qt::SquareCap));	// Blue and Dashed Line
	rect1.translate(-200,75);							// Translate rect left by 200 and down 75
	p.drawRect(rect1);									
	
	p.setPen(QPen(Qt::red, 2, Qt::DotLine, Qt::RoundCap));	// Red and Dotted Line
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	p.setPen(QPen(Qt::green, 2, Qt::DashDotLine, Qt::FlatCap));	// Green and Dash/Dotted Line
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	
	// Vary Brush Style
	p.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::SquareCap));	// Blue
	p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));				// and Solid Pattern Brush
	rect1.translate(-200,75);							// Translate rect left by 200 and down 75
	p.drawRect(rect1);									
	
	p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap));		// Red
	p.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));			// and Diagonal Cross Brush
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));	// Green
	p.setBrush(QBrush(Qt::green, Qt::VerPattern));				// and Vertical Pattern Brush
	rect1.translate(100,0);								// Translate rect right by 100
	p.drawRect(rect1);
	
	// Create QLabel and set Pixmap into QLabel
	QLabel myLabel;
	myLabel.setPixmap(myMap);
	myLabel.show();
	
	return myApp.exec();
}
