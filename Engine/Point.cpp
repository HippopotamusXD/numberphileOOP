#include "Point.h"
#include "MainWindow.h"

Point::Point(MainWindow& wnd)
{
	x = wnd.mouse.GetPosX();
	y = wnd.mouse.GetPosY();
}
