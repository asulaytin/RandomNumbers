#pragma once

#include "console.h"
#include "vertex.h"
#include <list>
using namespace std;

class Draw
{
	// Here we use composition to get access to behaviour available from another class
	// Console's existence is dependent on the draw class.
	Console console;
public:
	// draws the shape by drawing lines between the current and previous vertices
	// and then drawing the last line between the current and first vertices
	void drawShape(list<Vertex> &vertices);

	// Bresenham's line algorithm
	// draws an approximation of a line between two points in 2D space
	void drawLine(const Vertex &p1, const Vertex &p2);
};
