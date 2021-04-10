#pragma once
#include "classShape.h"


class Point : public Shape {
public:
	float thickness;

	Point();

	Point(string _id, int _layer, string _sub, float thick, float _m_x, float _m_y, float _m_z, float _ext_x, float _ext_y, float _ext_z);

	string name();

	void printParams();

	void writeParams(ofstream& file);

	~Point();
};