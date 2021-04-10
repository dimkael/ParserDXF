#include "read.h"
#include "readCircle.h"
#include "readPolyline.h"
#include "readEllipse.h"
#include "readPoint.h"

void readCodes(ifstream& file, string* str) {
	for (int i = 0; i < 2; i++) {
		file >> str[i];
	}
}


void read(ifstream& file, vector<Shape*>& container) {
	string* str = new string[2];

	while (!file.eof()) {
		readCodes(file, str);
		if (str[0] == "0" && str[1] == "SECTION") {
			readCodes(file, str);
			if (str[0] == "2" && str[1] == "ENTITIES") {
				readCodes(file, str);
				while (str[1] != "ENDSEC") {
					if (str[0] == "0") {
						if (str[1] == "CIRCLE")
							readCircle(file, container);
						else if (str[1] == "POLYLINE")
							readPolyline(file, container);
						else if (str[1] == "ELLIPSE")
							readEllipse(file, container);
						else if (str[1] == "POINT")
							readPoint(file, container);
					}
					readCodes(file, str);
				}
			}
		}
		else
			readCodes(file, str);
	}

	delete[] str;
}