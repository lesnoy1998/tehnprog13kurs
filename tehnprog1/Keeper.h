#pragma once
#include "Bird.h"
#include "Fish.h"
#include "Cat.h"
class Keeper
{
private:
	Animal** archive = 0;
	int cnt = 0;
	int flag;
public:
	Keeper();
	~Keeper();
	void addNew();
	void removeOld();
	void show();

	void save();
	void backup();
};

