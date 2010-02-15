/*
 * Created: 02/15/10-13:16:19
 * Author: keras
 */
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QPushButton hello("Hello world!");

	hello.show();
	return app.exec();
}
