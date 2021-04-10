#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Shape {
public:
	string id;
	int layer;
	string subclass;
	float m_x, m_y, m_z;
	float ext_x, ext_y, ext_z;

	Shape();

	Shape(string _id, int _layer, string _sub, float _m_x, float _m_y, float _m_z, float _ext_x, float _ext_y, float _ext_z);

	virtual string name() = 0;
	virtual void printParams() = 0;
	virtual void writeParams(ofstream& file) = 0;

	virtual void getToCenter();

	virtual ~Shape();
};