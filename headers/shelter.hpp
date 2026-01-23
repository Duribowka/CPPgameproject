#pragma once
#include <vector>
#include "pet.hpp"
#include "employee.hpp"
#include "task.hpp"
#include <ctime>
#include <iostream>
#include <algorithm>

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
        void show_employes();
        void addNewTask(const string& employee_id, Task_type task_type, int duration);
        void showTasks();
        vector<Task> getTasks(){return this->tasks;};
        vector<Pet*> get_pets(){return this->pets;};
        vector<Employee*> get_employes(){return this->employes;};


};
