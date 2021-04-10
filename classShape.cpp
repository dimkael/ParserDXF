#include "classShape.h"


Shape::Shape() : id(""), layer(0), subclass(""), m_x(0.0), m_y(0.0), m_z(0.0), ext_x(0.0), ext_y(0.0), ext_z(1.0) {}

Shape::Shape(string _id, int _layer, string _sub, float _m_x, float _m_y, float _m_z, float _ext_x, float _ext_y, float _ext_z) :
	id(_id), layer(_layer), subclass(_sub), m_x(_m_x), m_y(_m_y), m_z(_m_z), ext_x(_ext_x), ext_y(_ext_y), ext_z(_ext_z) {}

void Shape::getToCenter() {
	m_x += -m_x;
	m_y += -m_y;
	m_z += -m_z;
}

Shape::~Shape() {}