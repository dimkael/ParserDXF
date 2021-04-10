#include "print.h"


void printInfo(vector <Shape*>& v) {
	int circles = 0, ellipses = 0, points = 0, polylines = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i]->name() == "Circle")
			circles++;
		else if (v[i]->name() == "Polyline") {
			polylines++;
		}
		else if (v[i]->name() == "Ellipse")
			ellipses++;
		else if (v[i]->name() == "Point")
			points++;
	}

	cout << "Общее количество геометрических примитивов: " << v.size() << '\n';

	cout << "Количество объектов Circle: " << circles << '\n';
	cout << "Количество объектов Polyline: " << polylines << '\n';
	cout << "Количество объектов Ellipse: " << ellipses << '\n';
	cout << "Количество объектов Point: " << points << '\n';
}


void printDetailInfo(vector <Shape*>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << "Объект: " << v[i]->name() << '\n';
		cout << "Id: " << v[i]->id << '\n';
		cout << "Слой: " << v[i]->layer << '\n';
		cout << "Подкласс: " << v[i]->subclass << '\n';
		cout << "Координаты: " << v[i]->m_x << ", " << v[i]->m_y << '\n';
		v[i]->printParams();
		cout << '\n';
	}
}