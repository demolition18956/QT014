// Graphics Example 9

#include <QApplication>
#include "widget.h"

int main(int argc, char* argv[])

{
	QApplication a(argc, argv);				
	Widget w;
	w.show();
	return a.exec();
}
