#include "Bird.h"
#include "Fish.h"
#include "Cat.h"
#include "Keeper.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Keeper amogus;
	FILE* f1 = fopen("amogus.txt", "r");
	if (f1 != NULL)
	{
		cout << "Хотите загрузить данные с файла?\n1 - да\n2 - нет\n";
		int pp;
		cin >> pp;
		if (pp == 1)
		{
			fclose(f1);
			amogus.backup();


			
		}
	}
	
	
	int flag = 0;
	while (flag == 0)
	{
		cout << "Что вы хотите сделать?\n1 - добавить элемент\n2 - показать все элементы архива\n3 - удалить элем\n4 - сохран\n";
		int n;
		_flushall();
		cin >> n;
		
		switch (n)
		{
		case 1:
			amogus.addNew();
			break;
		case 2:
			amogus.show();
			break;
		case 3:
			amogus.removeOld();
			break;
		case 4:
			amogus.save();
			break;
		case 5:
			flag = 1;
			break;
		default:
			break;
		}
	}
	


}