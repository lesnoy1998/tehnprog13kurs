#include "Cat.h"

Cat::Cat()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*Вы наблюдаете рождение кошки*\n";
	owner = new char[MAX_LEN_STR];
	name = new char[MAX_LEN_STR];
	owner[0] = '\0';
	name[0] = '\0';
}
Cat::~Cat()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*Кошка исчезла у вас на глазах*\n";
	delete[] name;
	delete[] owner;
}
void Cat::inform()
{
	setlocale(LC_ALL, "ru");
	cout << "Данные о кошке таковы:\n" << getPoroda() << " - порода\n" << getColor() << " - окрас\n" << name << " - кличка\n" << owner << " - хозяин\n";
}


void Cat::edit()
{
	
	getchar();
	char* ccc = new char[100];
	setlocale(LC_ALL, "ru");
	cout << "Введите породу кошки\n";
	gets_s(ccc, 100);
	this->setPoroda(ccc);
	cout << "Введите окрас кошки\n";
	gets_s(ccc, 100);
	this->setColor(ccc);
	cout << "Введите ФИО хозяина кошки\n";
	gets_s(ccc, 100);
	strcpy(owner, ccc);
	cout << "Укажите кличку кошки\n";
	gets_s(ccc, 100);
	strcpy(name, ccc);
	delete[] ccc;
}
int Cat::id()
{
	return 2;
}

void Cat::save(char* str)
{
	sprintf(str, "%s|%s|%s|%s\n", this->getPoroda(), this->getColor(), owner, name);
}

void Cat::read(char* str)
{
	char temp_str_num[100];
	int spc, k;
	spc = 0; k = 0;
	for (int j = 0; j < 100; j++)
	{
		if ((str[j] != '|') && (str[j] != '\n'))
		{
			switch (spc)
			{
			case 0: temp_str_num[k] = str[j]; k++; break; //schet nomera zapisi
			case 1:
				temp_str_num[k] = str[j]; k++; break;//schet mesta otpravleniya
			case 2:
				temp_str_num[k] = str[j]; k++; break;//schet mesta naznacheniya
			case 3:
				temp_str_num[k] = str[j]; k++; break;//schet vremeni v polete
			default:
				break;
			}
		}
		else
		{
			switch (spc)
			{
			case 0: temp_str_num[k] = '\0'; setPoroda(temp_str_num); break;
			case 1: temp_str_num[k] = '\0'; setColor(temp_str_num); break;
			case 2: temp_str_num[k] = '\0'; strcpy(owner, temp_str_num); break;
			case 3: temp_str_num[k] = '\0'; strcpy(name, temp_str_num); break;
			default:
				break;
			}
			spc++; k = 0;
		}
		if (spc > 3) { break; }
	}
}
void Cat::edit1()
{
	setlocale(LC_ALL, "ru");
	cout << "Что именно вы хотите изменить?\n1 - порода\n2 - окрас\n3 - ФИО хозяина\n4 - кличку\n";
	int n;
	cin >> n;
	getchar();
	char* ccc = new char[100];
	switch (n)
	{
	case 1:
		cout << "Введите породу кошки\n";
		gets_s(ccc, 100);
		this->setPoroda(ccc);
		break;
	case 2:
		cout << "Введите окрас кошки\n";
		gets_s(ccc, 100);
		this->setColor(ccc);
		break;
	case 3:
		cout << "Введите ФИО хозяина кошки\n";
		gets_s(ccc, 100);
		strcpy(owner, ccc);
		break;
	case 4:
		cout << "Введите кличку кошки\n";
		gets_s(ccc, 100);
		strcpy(name, ccc);
		break;
	default:
		break;
	}
	delete[] ccc;
}
