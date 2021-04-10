#pragma once

#include "classShape.h"
#include "classVertex.h"


class Polyline : public Shape {
public:
	float start_w, end_w;
	int followflag;
	int polyflag;
	int polymeshM, polymeshN;
	int surfdensityM, surfdensityN, surftype;
	float thickness;
	vector<Vertex> vertex;

	Polyline();

	Polyline(string _id, int _layer, string _sub, float thick, float _m_x, float _m_y, float _m_z, float _start_w, float _end_w, int _followflag,
		int _polyflag, int _polymeshM, int _polymeshN, int _surfdensityM, int _surfdensityN, int _surftype, float _ext_x, float _ext_y, float _ext_z);

	string name();

	void getToCenter();

	void printParams();

	void writeParams(ofstream& file);

	~Polyline();
};