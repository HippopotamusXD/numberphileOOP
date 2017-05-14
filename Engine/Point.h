#pragma once
#include "MainWindow.h"

class Point {
public:
	Point(MainWindow& wnd);
	Point(int in_x, int in_y);
	int x;
	int y;
};