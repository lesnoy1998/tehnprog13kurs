#pragma once
#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

#define MAX_LEN_STR 100
#define MAX_LEN_CLR 15

class Animal
{
private:
	char* poroda;
	char* color;
public:
	Animal();
	~Animal();
	void setPoroda(char* prd);
	void setColor(char* clr);
	char* getColor();
	char* getPoroda();
	virtual void inform();
	virtual void edit();
	virtual int id() = 0;


	virtual void save(char* str) = 0;
	virtual void read(char* str) = 0;
	
};

