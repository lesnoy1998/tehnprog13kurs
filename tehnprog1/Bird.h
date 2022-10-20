#pragma once
#include "Animal.h"
class Bird :
    public Animal
{
private:
    char* sreda_obitaniya;
    char* t4em_pitaetsya;
public:
	Bird();
	~Bird();
	void inform();
	void edit();
	int id();

	void save(char* str);
	void read(char* str);
};

