#include "Cat.h"

Cat::Cat()
{
	owner = new char[MAX_LEN_STR];
	name = new char[MAX_LEN_STR];
	owner[0] = '\0';
	name[0] = '\0';
}
Cat::~Cat()
{
	delete[] name;
	delete[] owner;
}
void Cat::inform()
{
	setlocale(LC_ALL, "ru");
	cout << "ƒанные о кошке таковы:\n" << getPoroda() << " - порода\n" << getColor() << " - окрас\n" << name << " - кличка\n" << owner << " - хоз€ин\n";
}


void Cat::edit()
{
	
	getchar();
	char* ccc = new char[100];
	setlocale(LC_ALL, "ru");
	cout << "¬ведите породу кошки\n";
	gets_s(ccc, 100);
	this->setPoroda(ccc);
	cout << "¬ведите окрас кошки\n";
	gets_s(ccc, 100);
	this->setColor(ccc);
	cout << "¬ведите ‘»ќ хоз€ина кошки\n";
	gets_s(ccc, 100);
	strcpy(owner, ccc);
	cout << "”кажите кличку кошки\n";
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