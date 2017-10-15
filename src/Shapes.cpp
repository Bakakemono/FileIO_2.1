
#include <iostream>
#include "Shapes.h"

Shape::Shape(double x, double y) : x(x), y(y) {}

Rectangle::Rectangle(double x, double y, double sz_x, double sz_y) : Shape(x, y), size_x(sz_x), size_y(sz_y) {}








bool Rectangle::isColliding(Shape * shp)
{
	if (dynamic_cast<Rectangle*>(shp))
	{
		return Rectangle::isColliding(dynamic_cast<Rectangle*>(shp));
	}
	if (dynamic_cast<Circle*>(shp))
	{
		return Rectangle::isColliding(dynamic_cast<Circle*>(shp));
	}
}

bool Rectangle::isColliding(Circle * circ)
{
	double distance_circle_x = std::abs(circ->x - this->x);
	double distance_circle_y = std::abs(circ->y - this->y);

	if (distance_circle_x > (this->size_x / 2 + circ->size_r) ||
		distance_circle_y > (this->size_y / 2 + circ->size_r))
	{
		return false;
	}
	if (distance_circle_x <= (this->size_x / 2) ||
		distance_circle_y <= (this->size_y / 2))
	{
		return true;
	}


	double distance_corner = (distance_circle_x - this->size_x)*(distance_circle_x - this->size_x) +
		(distance_circle_y - this->size_y)*(distance_circle_y - this->size_y);
	return (distance_corner <= (circ->size_r*circ->size_r));

}


bool Rectangle::isColliding(Rectangle * rect)
{
	if (this->x < rect->x + rect->size_x &&
		this->x + this->size_x > rect->x &&
		this->y < rect->y + rect->size_y &&
		this->y + this->size_y > rect->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Circle::Circle(double x, double y, double sz_r) : Shape(x, y), size_r(sz_r) {}

bool Circle::isColliding(Shape * shp)
{
	if (dynamic_cast<Rectangle*>(shp))
	{
		return Circle::isColliding(dynamic_cast<Rectangle*>(shp));
	}
	if (dynamic_cast<Circle*>(shp))
	{
		return Circle::isColliding(dynamic_cast<Circle*>(shp));
	}
}

bool Circle::isColliding(Circle * circ)
{
	if (this->x + this->size_r >= circ->x - circ->size_r &&  this->y + this->size_r >= circ->y - circ->size_r ||
		circ->x + circ->size_r >= this->x - this->size_r &&  circ->y + circ->size_r >= this->y - this->size_r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Circle::isColliding(Rectangle * rect)
{
	double distance_circle_x = std::abs(this->x - rect->x);
	double distance_circle_y = std::abs(this->y - rect->y);

	if (distance_circle_x > (rect->size_x / 2 + this->size_r) ||
		distance_circle_y > (rect->size_y / 2 + this->size_r))
	{
		return false;
	}
	if (distance_circle_x <= (rect->size_x / 2) ||
		distance_circle_y <= (rect->size_y / 2))
	{
		return true;
	}

	double distance_corner = (distance_circle_x - rect->size_x)*(distance_circle_x - rect->size_x) +
		(distance_circle_y - rect->size_y)*(distance_circle_y - rect->size_y);
	return (distance_corner <= (this->size_r*this->size_r));

}
