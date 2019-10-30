#include <iostream>
#include <Windows.h>
#include "Square.h"

// Creates a square and associated behaviour provided by externally created random number and draw objects.
// Initialises the rnd and draw attributes using the : rnd(rnd), draw(draw) syntax.
Square::Square(RandomNumber &rnd, Draw &draw) : rnd(rnd), draw(draw)
{
	// initialise the length of the square using the random number generator
	this->length = rnd.random(5, 10);

	// initialise the centroid (centre point) of the square)
	this->centroid = Vertex(rnd.random(10, 20), rnd.random(10, 20));
	// generate and add the vertices for the square using the length and centroid values
	vertices.push_back(Vertex(centroid.getX() - (length / 2), centroid.getY() - (length / 2)));
	vertices.push_back(Vertex(centroid.getX() + (length / 2), centroid.getY() - (length / 2)));
	vertices.push_back(Vertex(centroid.getX() + (length / 2), centroid.getY() + (length / 2)));
	vertices.push_back(Vertex(centroid.getX() - (length / 2), centroid.getY() + (length / 2)));

}

// call the draw shape method provided by the draw class and pass the list of vertices as a parameter
void Square::display()
{
	draw.drawShape(vertices);
}

Vertex Square::getCentroid()
{
	return this->centroid;
}
