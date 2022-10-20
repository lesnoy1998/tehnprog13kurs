#include "Animal.h"



Animal::Animal()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*����! ���-�� ����������...*";
	poroda = new char[MAX_LEN_STR];
	color = new char[MAX_LEN_CLR];
	poroda[0] = '\0';
	color[0] = '\0';
}
Animal::~Animal()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*����! ���-�� ��������...*";
	delete[] poroda;
	delete[] color;
}

void Animal::setPoroda(char* prd)
{
	strcpy(poroda, prd);
}
void Animal::setColor(char* clr)
{
	strcpy(color, clr);
}
char* Animal::getColor()
{
	return color;
}
char* Animal::getPoroda()
{
	return poroda;
}
void Animal::inform()
{
	setlocale(LC_ALL, "ru");
	cout << "������ � �������� ������:\n" << poroda << " - ������\n" << color << " - �����\n";
}

void Animal::edit()
{
	char* ccc = new char[15];

	cout << "������� ������ ���������\n";
	cin >> ccc;
	strcpy(poroda, ccc);
	cout << "������� ����� ���������\n";
	cin >> ccc;
	strcpy(color, ccc);

}