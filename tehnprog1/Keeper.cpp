#include "Keeper.h"
Keeper::Keeper()
{
	archive = 0;
	cnt = 0;
	flag = 1;
}
Keeper::~Keeper()
{
	for (int i = 0; i < cnt; i++)
	{
		delete archive[i];
	}
	if (cnt != 0) delete[] archive;
	cnt = 0;
}






void Keeper::addNew()
{
	setlocale(LC_ALL, "ru");
	cout << "Какое животное вы хотите добавить в список?\n1 - Птица\n2 - Рыба\n3 - Кошка\n";
	int n;
	cin >> n;
	cnt++;
	if (flag == 1)
	{
		archive = new Animal * [cnt];
		flag = 0;
	}
	else
	{
		Animal** tmp = new Animal * [cnt];
		for (int i = 0; i < cnt-1; i++)
		{
			tmp[i] = archive[i];
		}
		delete[] archive;
		archive = tmp;
	}
	switch (n)
	{
	case 1:
		archive[cnt - 1] = new Bird;
		archive[cnt - 1]->edit();
		break;
	case 2:
		archive[cnt - 1] = new Fish;
		archive[cnt - 1]->edit();
		break;
	case 3:
		archive[cnt - 1] = new Cat;
		archive[cnt - 1]->edit();
		break;
	default:
		break;
	}
}
void Keeper::show()
{
	setlocale(LC_ALL, "ru");
	for (int i = 0; i < cnt; i++)
	{
		cout << "------------------------" << i+1 << "------------------------";
		archive[i]->inform();
		cout << "------------------------" << "-------------------------\n";
	}
}

void Keeper::removeOld()
{
	getchar();
	if (cnt == 0) { return; }
	setlocale(LC_ALL, "ru");
	this->show();
	cout << "Какой номер желаете удалить?\n";
	int n;
	cin >> n;
	if ((n > cnt) || (n < 1))
	{
		return;
	}
	Animal** tmp = new Animal * [cnt-1];
	int dpi = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (i == n - 1) { continue; }
		tmp[dpi] = archive[i];
		dpi++;
	}
	cnt--;
	delete[] archive;
	if (cnt == 0) { flag = 1; delete[] tmp; return; }
	archive = tmp;
}

void Keeper::save()
{
	if (cnt == 0) { return; }
	FILE* p1 = 0;
	p1 = fopen("amogus.txt", "w");
	char* str = new char[100];
	sprintf(str, "%d\n", cnt);
	fputs(str, p1);
	for (int i = 0; i < cnt; i++)
	{
		sprintf(str, "%d\n", archive[i]->id());
		fputs(str, p1);
		archive[i]->save(str);
		fputs(str, p1);
	}


	fclose(p1);
	delete[] str;
}

void Keeper::backup()
{
	FILE* f1 = fopen("amogus.txt", "r");
	char* str = new char[100];
	fgets(str, 100, f1);
	cnt = atoi(str);
	archive = new Animal * [cnt];
	int tmp;
	for (int i = 0; i < cnt; i++)
	{
		fgets(str, 100, f1);
		tmp = atoi(str);
		fgets(str, 100, f1);
		switch (tmp)
		{
		case 1:
			archive[i] = new Bird;
			break;
		case 2:
			archive[i] = new Cat;
			break;
		case 3:
			archive[i] = new Fish;
			break;
		}

		archive[i]->read(str);
	}
	flag = 0;


	delete[] str;




	fclose(f1);
}
void Keeper::edit1()
{
	cout << "Введите номер элемента?\n";
	int ns, n1;
	cin >> ns;
	if ((ns < 1) || (ns > cnt)) { return; }
	cout << "Вы хотите изменить животное под этим номером?\n1 - да\n2 - нет\n";
	cin >> n1;
	if ((n1 < 1) || (n1 > 2)) { return; }
	if (n1 == 2)
	{
		archive[ns - 1]->edit1();
	}
	else
	{
		cout << "Какое животное вы хотите добавить в список?\n1 - Птица\n2 - Рыба\n3 - Кошка\n";
		int n;
		cin >> n;
		
		switch (n)
		{
		case 1:
			delete archive[ns-1];
			archive[ns-1] = new Bird;
			archive[ns-1]->edit();
			break;
		case 2:
			delete archive[ns-1];
			archive[ns-1] = new Fish;
			archive[ns-1]->edit();
			break;
		case 3:
			delete archive[ns-1];
			archive[ns-1] = new Cat;
			archive[ns-1]->edit();
			break;
		default:
			break;
		}
	}
}