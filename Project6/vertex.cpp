#include <iostream>
#include <Windows.h>
#include "vertex.h"
Vertex::Vertex(int x, int y)
{
	this->x = x;
	this->y = y;
}
Vertex::~Vertex(){}
int Vertex::getX() const {
	return x;
}
int Vertex::getY() const {
	return y;
}
void Vertex::setX(unsigned x) {
	this->x = x;
}
void Vertex::setY(unsigned y) {
	this->y = y;
}
bool Vertex::operator== (const Vertex &point) const {
	return (this->x == point.getX()) && (this->y == point.getY());
}
