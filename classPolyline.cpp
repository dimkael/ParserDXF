#include "classPolyline.h"
#include "functions.h"


Polyline::Polyline() : thickness(0.0), start_w(0.0), end_w(0.0), followflag(0), polyflag(0), polymeshM(0), polymeshN(0), surfdensityM(0), surfdensityN(0), surftype(0), vertex(0) {}

Polyline::Polyline(string _id, int _layer, string _sub, float thick, float _m_x, float _m_y, float _m_z, float _start_w, float _end_w, int _followflag,
	int _polyflag, int _polymeshM, int _polymeshN, int _surfdensityM, int _surfdensityN, int _surftype, float _ext_x, float _ext_y, float _ext_z) :
	start_w(_start_w), end_w(_end_w), followflag(_followflag), polyflag(_polyflag), polymeshM(_polymeshM), polymeshN(_polymeshN), surfdensityM(_surfdensityM),
	surfdensityN(_surfdensityN), surftype(_surftype), thickness(thick), Shape(_id, _layer, _sub, _m_x, _m_y, _m_z, _ext_x, _ext_y, _ext_z) {}

string Polyline::name() {
	return "Polyline";
}

void Polyline::getToCenter() {
	if (followflag) {
		float min_x = vertex[0].m_x;
		float min_y = vertex[0].m_y;
		float max_x = vertex[0].m_x;
		float max_y = vertex[0].m_y;
		float cx, cy;

		for (int i = 1; i < vertex.size(); i++) {
			if (vertex[i].m_x < min_x)
				min_x = vertex[i].m_x;
			if (vertex[i].m_x > max_x)
				max_x = vertex[i].m_x;
			if (vertex[i].m_y < min_y)
				min_y = vertex[i].m_y;
			if (vertex[i].m_y > max_y)
				max_y = vertex[i].m_y;
		}

		cx = min_x + (max_x - min_x) / 2;
		cy = min_y + (max_y - min_y) / 2;

		for (int i = 0; i < vertex.size(); i++) {
			vertex[i].m_x -= cx;
			vertex[i].m_y -= cy;
		}
	}
	else {
		m_x += -m_x;
		m_y += -m_y;
		m_z += -m_z;
	}
}

void Polyline::printParams() {
	cout << "Количество вершин: " << vertex.size() << '\n';
	for (int i = 0; i < vertex.size(); i++) {
		cout << "    " << "Vertex " << i << '\n';
		cout << "    " << "Id: " << vertex[i].id << '\n';
		/*cout << "    " << "Слой: " << vertex[i]->layer << '\n';
		cout << "    " << "Подкласс: " << vertex[i]->subclass << '\n';*/
		cout << "    " << "Координаты: " << vertex[i].m_x << ", " << vertex[i].m_y << '\n';
		cout << '\n';
	}
}

void Polyline::writeParams(ofstream& file) {
	file << "  0\n";
	file << to_upper(name()) << '\n';
	file << "  5\n" << id << '\n';
	file << "100\nAcDbEntity\n";
	file << "  8\n" << layer << '\n';
	file << "100\n" << subclass << '\n';
	file << " 66\n     " << followflag << '\n';
	file << " 10\n" << m_x << '\n';
	file << " 20\n" << m_y << '\n';
	file << " 30\n" << m_z << '\n';
	file << " 70\n     " << polyflag << '\n';

	if (followflag) {
		for (int i = 0; i < vertex.size(); i++) {
			vertex[i].writeParams(file);
		}
	}

	file << "  0\nSEQEND\n";
}

Polyline::~Polyline() {}