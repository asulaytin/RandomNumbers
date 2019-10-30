#pragma once
class Vertex
{
	int x;
	int y;
public:
	Vertex(int x = 10, int y = 10);
	~Vertex();
	int getX() const;
	int getY() const;
	void setX(unsigned x);
	void setY(unsigned y);
	bool operator== (const Vertex &p2) const;
};
