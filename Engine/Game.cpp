/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <vector>
#include <cstdlib>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	leftClick();
	rightClick();
}


void Game::ComposeFrame()
{
	calcPos();
	display();
}

void Game::leftClick()
{
	if (!initialSet) {
		if (wnd.mouse.LeftIsPressed() && !clicked) {
			clicked = true;
			Point Point(wnd);
			Points.push_back(Point);
			staticNum++;
		}
		if (!wnd.mouse.LeftIsPressed()) {
			clicked = false;
		}
	}
}

void Game::rightClick()
{
	if (wnd.mouse.RightIsPressed() && !wnd.mouse.LeftIsPressed() && !initialSet) {
		initialSet = true;
		Point Point(wnd);
		Points.push_back(Point);
	}
}

void Game::display()
{
	for (int i = 0; i < Points.size(); i++) {
		gfx.PutPixel(Points[i].x, Points[i].y, 255, 255, 255);
	}
}

void Game::calcPos()
{
	if (initialSet) {
		int nextPoint = rand() % staticNum;
		int max = Points.size() - 1;
		int newX = Points[nextPoint].x - ((Points[nextPoint].x - Points[max].x) / (staticNum - 1));
		int newY = Points[nextPoint].y - ((Points[nextPoint].y - Points[max].y) / (staticNum - 1));
		Point Dot(newX, newY);
		Points.push_back(Dot);
	}
}