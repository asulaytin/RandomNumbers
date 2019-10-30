#pragma once

#include "randomnumber.h"
#include "vertex.h"
#include "draw.h"
#include <list>

using namespace std;

class Square
{
	RandomNumber &rnd;
	Draw &draw;
	Vertex centroid;
	int length;
	list<Vertex> vertices;
public:
	// Creates a square and associated behaviour provided by externally created 
	// random number and draw objects.
	Square(RandomNumber &rnd, Draw &draw);

	// call the draw shape method provided by the draw class and pass the list 
	// of vertices as a parameter
	void display();

	// getter
	Vertex getCentroid();
};
