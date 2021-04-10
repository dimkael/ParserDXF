#include "readPoint.h"


void readPoint(ifstream& file, vector <Shape*>& container) {
	int code;

	string id;
	int layer = 0;
	string subclass = "";
	float thickness = 0.0;
	float m_x = 0.0, m_y = 0.0, m_z = 0.0;
	float ext_x = 0.0, ext_y = 0.0, ext_z = 1.0;

	do {
		file >> code;
		switch (code) {
		case 5:
			file >> id;
			break;
		case 8:
			file >> layer;
			break;
		case 100:
			file >> subclass;
			break;
		case 39:
			file >> thickness;
			break;
		case 10:
			file >> m_x;
			break;
		case 20:
			file >> m_y;
			break;
		case 30:
			file >> m_z;
			break;
		case 210:
			file >> ext_x;
			break;
		case 220:
			file >> ext_y;
			break;
		case 230:
			file >> ext_z;
		}
	} while (code != 0);


	container.push_back(new Point(id, layer, subclass, thickness, m_x, m_y, m_z, ext_x, ext_y, ext_z));

	file.seekg(-1, ios::cur);
}