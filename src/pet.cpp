#include "../headers/pet.hpp"
#include <fstream>
vector<string> Pet::names;

//This function creates a pet with randomly generated stats
Pet::Pet(const string& id, const string& name) : Entity(id,name)
{
    this->happines = rand() % 1001;
    this->hunger = 10 + rand() % 91;
    this->attractivenes = rand() % 1001;
}

//This function creates a pet with given stats, it also ensures that dead pets stay dead after loading
Pet::Pet(const string& id, const string& name, int attractivenes, int hunger, int happines) 
: Entity(id,name), attractivenes(attractivenes), hunger(hunger), happines(happines)
{
    if(this->hunger>=100)
    {
        this->isAlive = false;
        this->hunger = 100;
    }
}

//This function allows naming the pet after creation, however it is not used as of right now
void Pet::name_pet(string name)
{
    this->name = name;
}

//This function reads pet names from a file and stores them for random name assignment, however it is not used as of right now
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

//This function raises happiness via the task, happiness is capped at 1000
void Pet::increase_happines(int amount)
{
    if(this->isAlive)
    {
        this->happines += amount;
        if(this->happines > 1000)
        {
            this->happines = 1000;
        }
    }
}

//This function decreases happiness over time, happiness cannot go below 0
void Pet::update_happines()
{
    if(this->isAlive)
    {
        this->happines--;
        if(this->happines < 0)
        {
            this->happines = 0;
        }
    }
}

//This function reduces hunger via feed task, hunger cannot go below 0
void Pet::feed(int amount)
{

    if(this->isAlive)
    {
        this->hunger -= amount;
        if(this->hunger < 0)
        {
            this->hunger = 0;
        }
    }
}

//This function increases hunger over time, if hunger reaches 100 the pet dies permanently
void Pet::update_hunger()
{
    if(this->isAlive)
    {
        this->hunger++;
        if(this->hunger >= 100)
        {
            this->isAlive = false;
            this->hunger = 100;
        }
    }
}

//This function decreases attractiveness over time, attractiveness cannot go below 0
void Pet::update_attractivenes()
{
    if(this->isAlive)
    {
        this->attractivenes--;
        if(this->attractivenes < 0)
        {
            this->attractivenes = 0;
        }
    }
}
