#include "Point.h"
#include "MainWindow.h"

Point::Point(MainWindow& wnd)
{
	x = wnd.mouse.GetPosX();
	y = wnd.mouse.GetPosY();
}

Point::Point(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}
