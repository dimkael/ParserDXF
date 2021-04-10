#include "classVertex.h"
#include "functions.h"


Vertex::Vertex() : id(""), layer(0), subclass(""), m_x(0.0), m_y(0.0), m_z(0.0), start_w(0), end_w(0), bulge(0), flag(0) {}

Vertex::Vertex(string _id, int _layer, string _subclass, float _m_x, float _m_y, float _m_z, float _start_w, float _end_w, float _bulge, int _flag) :
	id(_id), layer(_layer), subclass(_subclass), m_x(_m_x), m_y(_m_y), m_z(_m_z), start_w(_start_w), end_w(_end_w), bulge(_bulge), flag(_flag) {}

string Vertex::name() {
	return "Vertex";
}

void Vertex::getToCenter() {
	m_x += -m_x;
	m_y += -m_y;
	m_z += -m_z;
}

void Vertex::writeParams(ofstream& file) {
	file << "  0\n";
	file << to_upper(name()) << '\n';
	file << "  5\n" << id << '\n';
	file << "100\nAcDbEntity\n";
	file << "  8\n" << layer << '\n';
	file << "100\nAcDbVertex\n";
	file << "100\n" << subclass << '\n';
	file << " 10\n" << m_x << '\n';
	file << " 20\n" << m_y << '\n';
	file << " 30\n" << m_z << '\n';
}

Vertex::~Vertex() {}