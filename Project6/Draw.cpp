#include <iostream>
#include <Windows.h>
#include "Draw.h"

// draws the shape by drawing lines between the current and previous vertices
// and then drawing the last line between the current and first vertices
void Draw::drawShape(list<Vertex> &vertices)
{
	list<Vertex>::iterator current = vertices.begin();
	list<Vertex>::iterator previous = vertices.begin();
	while (current != vertices.end())
	{
		if (current != vertices.begin())
			drawLine(*current, *previous);
		previous = current;
		current++;
	}
	drawLine(vertices.back(), vertices.front());
	console.gotoXY(25, 25);
}

// Bresenham's line algorithm
// Draws a line between two vertices.
void Draw::drawLine(const Vertex &p1, const Vertex &p2)
{
	int x1 = p1.getX();
	int y1 = p1.getY();
	int x2 = p2.getX();
	int y2 = p2.getY();
	bool steep = (abs(y2 - y1) > abs(x2 - x1));
	if (steep)
	{
		swap(x1, y1);
		swap(x2, y2);
	}
	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	int dx = x2 - x1;
	int dy = abs(y2 - y1);
	float error = dx / 2.0f;
	int ystep = (y1 < y2) ? 1 : -1;
	int y = y1;
	int maxX = x2;

	for (int x = x1; x <= maxX; x++)
	{
		if (steep)
		{
			console.gotoXY(y, x);	cout << "*";
		}
		else
		{
			console.gotoXY(x, y);	cout << "*";
		}
		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
	}
}
