#include "Bird.h"
Bird::Bird()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*Вы наблюдаете рождение птицы*\n";
	sreda_obitaniya = new char[MAX_LEN_STR];
	t4em_pitaetsya = new char[MAX_LEN_STR];
	sreda_obitaniya[0] = '\0';
	t4em_pitaetsya[0] = '\0';
}
Bird::~Bird()
{
	setlocale(LC_ALL, "ru");
	cout << "\n*Птица исчезла у вас на глазах*\n";
	delete[] t4em_pitaetsya;
	delete[] sreda_obitaniya;
}
void Bird::inform()
{
	setlocale(LC_ALL, "ru");
	cout << "Данные о птице таковы:\n" << getPoroda() << " - порода\n" << getColor() << " - окрас\n" << sreda_obitaniya << " - среда обитания\n" << t4em_pitaetsya << " - чем питается\n";
}
void Bird::edit()
{
	getchar();
	setlocale(LC_ALL, "ru");
		char* ccc = new char[100];

		cout << "Введите породу птицы\n";
		gets_s(ccc, 100);
		this->setPoroda(ccc);
		cout << "Введите окрас птицы\n";
		gets_s(ccc, 100);
		this->setColor(ccc);
		cout << "Введите среду обитания птицы\n";
		gets_s(ccc, 100);
		strcpy(sreda_obitaniya, ccc);
		cout << "Укажите чем питается птица\n";
		gets_s(ccc, 100);
		strcpy(t4em_pitaetsya, ccc);
		delete[] ccc;
}
int Bird::id()
{
	return 1;
}
void Bird::save(char* str)
{
	sprintf(str, "%s|%s|%s|%s\n", this->getPoroda(), this->getColor(), sreda_obitaniya, t4em_pitaetsya);
}
void Bird::read(char* str)
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
			case 0: temp_str_num[k] = '\0';
				setPoroda(temp_str_num); 
				break;
			case 1: temp_str_num[k] = '\0'; setColor(temp_str_num); break;
			case 2: temp_str_num[k] = '\0'; strcpy(sreda_obitaniya, temp_str_num); break;
			case 3: temp_str_num[k] = '\0'; strcpy(t4em_pitaetsya, temp_str_num); break;
			default:
				break;
			}
			spc++; k = 0;
		}
		if (spc > 3) { break; }
	}
}
void Bird::edit1()
{
	setlocale(LC_ALL, "ru");
	cout << "Что именно вы хотите изменить?\n1 - порода\n2 - окрас\n3 - среда обитания\n4 - чем питается\n";
	int n;
	cin >> n;
	getchar();
	char* ccc = new char[100];
	switch (n)
	{case 1:
		cout << "Введите породу птицы\n";
		gets_s(ccc, 100);
		this->setPoroda(ccc);
		break;
	case 2:
		cout << "Введите окрас птицы\n";
		gets_s(ccc, 100);
		this->setColor(ccc);
		break;
	case 3:
		cout << "Введите среду обитания птицы\n";
		gets_s(ccc, 100);
		strcpy(sreda_obitaniya, ccc);
		break;
	case 4:
		cout << "Введите чем питается птица\n";
		gets_s(ccc, 100);
		strcpy(t4em_pitaetsya, ccc);
		break;
	default:
		break;
	}
	delete[] ccc;
}