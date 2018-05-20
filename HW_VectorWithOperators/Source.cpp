#include"vector.h"
#include"library.h"
int main()
{
	setlocale(LC_ALL, "ru");
	Vector V, V2;
	V.push_back(10);
	V.push_back(11);
	V.push_back(18);
	V.push_back(1);
	V.push_back(4);
	V2.push_back(15);
	V2.push_back(12);
	V2.push_back(25);
	V2.push_back(18);
	V2.push_back(19);
	cout << "Первый вектор: " << endl;
	V.print();
	cout << "\nВторой вектор: " << endl;
	V2.print();
	cout << "\nОператор []: " << endl;
	cout << "Элемент под индексом 1= " << V[1] << endl;
	V[2] = 33;
	V.print();
	cout << "\nОператор+: " << endl;
	V + V2;
	V.print();
	cout << "\nОператор-: " << endl;
	cout << "Первый вектор: " << endl;
	V.print();
	cout << "\nВторой вектор: " << endl;
	V2.print();
	cout << endl;
	V - V2;
	V.print();

	cout << "\nOperator<< \n";

	V2.print();
	int a = V2 << 1;
	cout << endl;
	cout << a << endl;
	V2.print();

	cout << "\nOperator >> \n";

	V2 >> 55;
	V2.print();

	cout << "\nOperator == \n";
	cout << (V == V2) << endl;

	cout << "\nOperator != \n";
	cout << (V != V2) << endl;

	//V >> 555;


	system("pause");
	return 0;
}