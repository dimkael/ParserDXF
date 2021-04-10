#include "readVertex.h"

void readVertex(ifstream& file, Polyline* polyline) {
	int code;

	string id;
	int layer = 0;
	string subclass = "";
	float m_x = 0.0, m_y = 0.0, m_z = 0.0;
	float start_w = 0.0, end_w = 0.0;
	float bulge = 0.0;
	int flag = 0;

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
		case 10:
			file >> m_x;
			break;
		case 20:
			file >> m_y;
			break;
		case 30:
			file >> m_z;
			break;
		case 40:
			file >> start_w;
			break;
		case 41:
			file >> end_w;
			break;
		case 42:
			file >> bulge;
			break;
		case 70:
			file >> flag;
		}
	} while (code != 0);

	polyline->vertex.push_back(Vertex(id, layer, subclass, m_x, m_y, m_z, start_w, end_w, bulge, flag));

	file.seekg(-1, ios::cur);
}