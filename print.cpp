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

	cout << "����� ���������� �������������� ����������: " << v.size() << '\n';

	cout << "���������� �������� Circle: " << circles << '\n';
	cout << "���������� �������� Polyline: " << polylines << '\n';
	cout << "���������� �������� Ellipse: " << ellipses << '\n';
	cout << "���������� �������� Point: " << points << '\n';
}


void printDetailInfo(vector <Shape*>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << "������: " << v[i]->name() << '\n';
		cout << "Id: " << v[i]->id << '\n';
		cout << "����: " << v[i]->layer << '\n';
		cout << "��������: " << v[i]->subclass << '\n';
		cout << "����������: " << v[i]->m_x << ", " << v[i]->m_y << '\n';
		v[i]->printParams();
		cout << '\n';
	}
}