#pragma once
#include "Animal.h"
class Cat :
    public Animal
{
private:
    
    char* owner;
    char* name;
public:
    Cat();
    ~Cat();
    void inform();
    void edit();
    int id();

    void save(char* str);
    void read(char* str);
    void edit1();
};

