#include "readPolyline.h"


void readPolyline(ifstream& file, vector<Shape*>& container) {
	int code;
	string str;

	string id;
	int layer = 0;
	string subclass = "";
	int followflag = 0;
	float thickness = 0.0;
	float m_x = 0.0, m_y = 0.0, m_z = 0.0;
	float start_w = 0.0, end_w = 0.0;
	int polyflag = 0;
	int polymeshM = 0, polymeshN = 0;
	int surfdensityM = 0, surfdensityN = 0, surftype = 0;
	float ext_x = 0.0, ext_y = 0.0, ext_z = 1.0;
	vector <Vertex> vertex;

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
		case 66:
			file >> followflag;
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
		case 40:
			file >> start_w;
			break;
		case 41:
			file >> end_w;
			break;
		case 70:
			file >> polyflag;
			break;
		case 71:
			file >> polymeshM;
			break;
		case 72:
			file >> polymeshN;
			break;
		case 73:
			file >> surfdensityM;
			break;
		case 74:
			file >> surfdensityN;
			break;
		case 75:
			file >> surftype;
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

	file.seekg(-1, ios::cur);

	Polyline* polyline = new Polyline(id, layer, subclass, thickness, m_x, m_y, m_z, start_w, end_w, followflag, polyflag, polymeshM, polymeshN,
		surfdensityM, surfdensityN, surftype, ext_x, ext_y, ext_z);

	if (followflag) {
		do {
			file >> code;
			file >> str;
			if (code == 0 && str == "VERTEX")
				readVertex(file, polyline);
		} while (str != "SEQEND");
	}

	container.push_back(polyline);
}