#pragma once

#include <string>
using namespace std;


class Vertex {
public:
	string id;
	int layer;
	string subclass;
	float m_x, m_y, m_z;
	float start_w, end_w;
	float bulge;
	int flag;

	Vertex();

	Vertex(string _id, int _layer, string _subclass, float _m_x, float _m_y, float _m_z, float _start_w, float _end_w, float _bulge, int _flag);

	string name();

	void getToCenter();

	void writeParams(ofstream& file);

	~Vertex();
};