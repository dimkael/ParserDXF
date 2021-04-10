#pragma once
#include "classShape.h"


class Circle : public Shape {
public:
	float rad;
	float thickness;

	Circle();

	Circle(string _id, int _layer, string _sub, float thick, float _m_x, float _m_y, float _m_z, float _rad, float _ext_x, float _ext_y, float _ext_z);

	string name();

	void printParams();

	void writeParams(ofstream& file);

	~Circle();
};
