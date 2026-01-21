#include "shelter.hpp"

Shelter::Shelter(time_t prev_time, time_t current_time)
{
    this->prev_time = prev_time;
    this->current_time = current_time;
}
void Shelter::addPet(Pet* pet)
{
    pets.push_back(pet);
}
void Shelter::addEmployee(Employee* employee)
{
    employes.push_back(employee);
}

bool Shelter::update()
{

    time_t deltaTime = (current_time - prev_time)/3600;
    cout << "hours since last enterence: " << deltaTime << endl;
    if(deltaTime > 0)
    {
        //upadete pets stats
        for(int i = 0; i < deltaTime; i++)
        for(Pet* pet : pets)
        {
            pet->update_attractivenes();
            pet->update_hunger();
            pet->update_happines();
        }
        return true;
    }
    return false;
    
}

void Shelter::show_pet_stats(Pet* pet)
{
    cout <<"attractivenes: " << pet->get_attractivenes() << endl;
    cout <<"hunger: " << pet->get_hunger() << endl;
    cout <<"happines: " << pet->get_happines() << endl;
}

void Shelter::show_pets_stats()
{   int i = 1;
    for(Pet* pet : pets)
    {   
        cout << "pet number: " << i++ << endl;
        show_pet_stats(pet);
    }
}
vector<Pet*> Shelter::get_pets()
{
    return this->pets;
}
