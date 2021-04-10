#include "del.h"


void del(vector<Shape*> v) {
	for (int i = 0; i < v.size(); i++)
		delete v[i];
}