#include "read.h"
#include "print.h"
#include "write.h"
#include "del.h"


int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file("model.dxf");
	ofstream output("edited_model.dxf", ios_base::out | ios_base::trunc);
	vector<Shape*> container;

	read(file, container);

	printInfo(container);
	cout << '\n';
	printDetailInfo(container);

	for (int i = 0; i < container.size(); i++) {
		container[i]->getToCenter();
	}

	write(output, container);

	del(container);

	return 0;
}
