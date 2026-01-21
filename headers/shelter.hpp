#pragma once
#include <vector>
#include "pet.hpp"
#include "employee.hpp"
#include "task.hpp"
#include <ctime>
#include <iostream>

using namespace std;

class Shelter{

    private:
        vector<Pet*> pets;
        vector<Employee*> employes;
        vector<Task> tasks;
        time_t prev_time;
        time_t current_time;
    public:
        Shelter(time_t prev_time, time_t current_time);
        void addPet(Pet* pet);
        void addEmployee(Employee* employee);
        bool update();
        void show_pet_stats(Pet* pet);
        void show_pets_stats();
        vector<Pet*> get_pets();


};
