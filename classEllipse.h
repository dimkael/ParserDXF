#pragma once
#include "classShape.h"


class Ellipse : public Shape {
public:
	float end_x, end_y, end_z;
	float ratio;
	float begin, end;

	Ellipse();

	Ellipse(string _id, int _layer, string _sub, float thick, float _m_x, float _m_y, float _m_z, float _end_x, float _end_y, float _end_z,
		float _ratio, float _begin, float _end, float _ext_x, float _ext_y, float _ext_z);

	string name();

	void printParams();

	void writeParams(ofstream& file);

	~Ellipse();
};