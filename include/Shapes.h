#ifndef SHAPE_H
#define SHAPE_H

class Circle;

class Shape
{

public:

	Shape(double x, double y);


	virtual bool isColliding(Shape*) = 0;

	double x, y;
};

class Rectangle : public Shape
{

public:

	Rectangle(double x, double y, double sz_x, double sz_y);

	bool isColliding(Shape*);
	bool isColliding(Circle*);
	bool isColliding(Rectangle*);

	double size_x, size_y;
};

class Circle : public Shape
{
public:
	Circle(double x, double y, double sz_r);

	bool isColliding(Shape*);
	bool isColliding(Circle*);
	bool isColliding(Rectangle*);

	double size_r;
};
#endif