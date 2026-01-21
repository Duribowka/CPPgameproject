#include "pet.hpp"
#include <fstream>
vector<string> Pet::names;

Pet::Pet(string& id, string& name) : Entity(id,name)
{
    this->happines = rand() % 1001;
    this->hunger = 10 + rand() % 91;
    this->attractivenes = rand() % 1001;
}

Pet::Pet(string& id, string& name, int attractivenes, int hunger, int happines) 
: Entity(id,name), attractivenes(attractivenes), hunger(hunger), happines(happines){}

void Pet::name_pet(string name)
{
    this->name = name;
}

void Pet::get_names_from_file()
{
    ifstream pet_names_file;
    pet_names_file.open("pet_names.txt");
    string line;
    while(getline(pet_names_file,line))
    {
        Pet::names.push_back(line);
    }
}

void Pet::increase_happines(int amount)
{
    this->happines += amount;
    if(this->happines > 1000)
    {
        this->happines = 1000;
    }
}

void Pet::update_happines()
{
    this->happines--;
    if(this->happines < 0)
    {
        this->happines = 0;
    }
}

void Pet::feed(int amount)
{
    this->hunger -= amount;
    if(this->hunger < 0)
    {
        this->hunger = 0;
    }
}

void Pet::update_hunger()
{
    this->hunger++;
    if(this->hunger >= 100)
    {
        this->isAlive = false;
    }
}

void Pet::update_attractivenes()
{
    this->attractivenes--;
    if(this->attractivenes < 0)
    {
        this->attractivenes = 0;
    }
}
