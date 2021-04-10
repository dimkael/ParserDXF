#include "write.h"


void write(ofstream& file, vector<Shape*> v) {
	file << "  0\nSECTION\n  2\nENTITIES\n";
	for (int i = 0; i < v.size(); i++) {
		v[i]->writeParams(file);
	}
	file << "  0\nENDSEC\n  0\nEOF";
}