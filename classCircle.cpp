#include "classCircle.h"
#include "functions.h"


Circle::Circle() : rad(0), thickness(0) {}

Circle::Circle(string _id, int _layer, string _sub, float thick, float _m_x, float _m_y, float _m_z, float _rad, float _ext_x, float _ext_y, float _ext_z) :
	rad(_rad), thickness(thick), Shape(_id, _layer, _sub, _m_x, _m_y, _m_z, _ext_x, _ext_y, _ext_z) {}

string Circle::name() {
	return "Circle";
}

void Circle::printParams() {
	cout << "Радиус: " << rad << '\n';
}

void Circle::writeParams(ofstream& file) {
	file << "  0\n";
	file << to_upper(name()) << '\n';
	file << "  5\n" << id << '\n';
	file << "100\nAcDbEntity\n";
	file << "  8\n" << layer << '\n';
	file << "100\n" << subclass << '\n';
	file << " 10\n" << m_x << '\n';
	file << " 20\n" << m_y << '\n';
	file << " 30\n" << m_z << '\n';
	file << " 40\n" << rad << '\n';
}

Circle::~Circle() {}