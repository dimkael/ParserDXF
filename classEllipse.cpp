#include "classEllipse.h"
#include "functions.h"


Ellipse::Ellipse() : end_x(0.0), end_y(0.0), end_z(0.0), ratio(0.0), begin(0.0), end(0.0) {}

Ellipse::Ellipse(string _id, int _layer, string _sub, float thick, float _m_x, float _m_y, float _m_z, float _end_x, float _end_y, float _end_z,
	float _ratio, float _begin, float _end, float _ext_x, float _ext_y, float _ext_z) :
	end_x(_end_x), end_y(_end_y), end_z(_end_z), ratio(_ratio), begin(_begin), end(_end), Shape(_id, _layer, _sub, _m_x, _m_y, _m_z, _ext_x, _ext_y, _ext_z) {}

string Ellipse::name() {
	return "Ellipse";
}

void Ellipse::printParams() {
	cout << "Соотношение фокусов: " << ratio << '\n';
	cout << "Конечные координаты осей: " << end_x << ", " << end_y << '\n';
	cout << "Начало эллиптической дуги: " << begin << '\n';
	cout << "Начало эллиптической дуги: " << end << '\n';
}

void Ellipse::writeParams(ofstream& file) {
	file << "  0\n";
	file << to_upper(name()) << '\n';
	file << "  5\n" << id << '\n';
	file << "100\nAcDbEntity\n";
	file << "  8\n" << layer << '\n';
	file << "100\n" << subclass << '\n';
	file << " 10\n" << m_x << '\n';
	file << " 20\n" << m_y << '\n';
	file << " 30\n" << m_z << '\n';
	file << " 11\n" << end_x << '\n';
	file << " 21\n" << end_y << '\n';
	file << " 31\n" << end_z << '\n';
	file << "210\n" << ext_x << '\n';
	file << "220\n" << ext_y << '\n';
	file << "230\n" << ext_z << '\n';
	file << " 40\n" << ratio << '\n';
	file << " 41\n" << begin << '\n';
	file << " 42\n" << end << '\n';
}

Ellipse::~Ellipse() {}