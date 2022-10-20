#include "Fish.h"
Fish::Fish()
{
	tip_pitaniya = new char[MAX_LEN_STR];
	tip_pitaniya[0] = '\0';
}
Fish::~Fish()
{
	delete[] tip_pitaniya;
}

void Fish::inform()
{
	setlocale(LC_ALL, "ru");
	cout << "������ � ����� ������:\n" << getPoroda() << " - ������\n" << getColor() << " - �����\n" << tip_pitaniya << " - ��� �������\n";
}



void Fish::edit()
{
	getchar();
	setlocale(LC_ALL, "ru");
	char* ccc = new char[100];

	cout << "������� ������ ����\n";
	cin >> ccc;
	this->setPoroda(ccc);
	cout << "������� ����� ����\n";
	cin >> ccc;
	this->setColor(ccc);
	cout << "������� ��� ������� ����\n";
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
