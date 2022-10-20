#include "Fish.h"
Fish::Fish()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*Вы наблюдаете рождение рыбы*\n";
	tip_pitaniya = new char[MAX_LEN_STR];
	tip_pitaniya[0] = '\0';
}
Fish::~Fish()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*Рыба исчезла у вас на глазах*\n";
	delete[] tip_pitaniya;
}

void Fish::inform()
{
	setlocale(LC_ALL, "ru");
	cout << "Данные о рыбке таковы:\n" << getPoroda() << " - порода\n" << getColor() << " - окрас\n" << tip_pitaniya << " - тип питания\n";
}



void Fish::edit()
{
	getchar();
	setlocale(LC_ALL, "ru");
	char* ccc = new char[100];

	cout << "Введите породу рыбы\n";
	cin >> ccc;
	this->setPoroda(ccc);
	cout << "Введите окрас рыбы\n";
	cin >> ccc;
	this->setColor(ccc);
	cout << "Укажите тип питания рыбы\n";
	cin >> ccc;
	strcpy(tip_pitaniya, ccc);
	delete[] ccc;
}
int Fish::id()
{
	return 3;
}

void Fish::save(char* str)
{
	sprintf(str, "%s|%s|%s\n", this->getPoroda(), this->getColor(), tip_pitaniya);
}

void Fish::read(char* str)
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
			case 0: temp_str_num[k] = str[j]; k++; break; 
			case 1:
				temp_str_num[k] = str[j]; k++; break;
			case 2:
				temp_str_num[k] = str[j]; k++; break;
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
			case 2: temp_str_num[k] = '\0'; strcpy(tip_pitaniya, temp_str_num); break;
			default:
				break;
			}
			spc++; k = 0;
		}
		if (spc > 2) { break; }
	}
}
void Fish::edit1()
{
	setlocale(LC_ALL, "ru");
	cout << "Что именно вы хотите изменить?\n1 - порода\n2 - окрас\n3 - тип питания\n";
	int n;
	cin >> n;
	getchar();
	char* ccc = new char[100];
	switch (n)
	{
	case 1:
		cout << "Введите породу рыбы\n";
		gets_s(ccc, 100);
		this->setPoroda(ccc);
		break;
	case 2:
		cout << "Введите окрас рыбы\n";
		gets_s(ccc, 100);
		this->setColor(ccc);
		break;
	case 3:
		cout << "Введите тип питания рыбы\n";
		gets_s(ccc, 100);
		strcpy(tip_pitaniya, ccc);
		break;
	default:
		break;
	}
	delete[] ccc;
}