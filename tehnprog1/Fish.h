#pragma once
#include "Animal.h"
class Fish :
    public Animal
{
private:
    
    char* tip_pitaniya;
public:
    Fish();
    ~Fish();
    void inform();
    void edit();
    int id();

    void save(char* str);
    void read(char* str);
};

