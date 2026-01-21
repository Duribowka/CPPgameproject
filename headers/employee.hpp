#pragma once
#include <ctime>
#include "entity.hpp"
#include <vector>

class Employee : public Entity
{   
    public:
        static vector<string> names;
    private: 
        float salary;
        int grooming_skill_level;
        int marketing_skill_level;
        int caretaking_skill_level;
        int work_capacity = 8;
        bool isFree = true;
        time_t last_order_given;
        int work_cost;

    public:
        void work(int hours);
        void assignTask(int work_cost, time_t startTime);
        static void get_names_from_file();
};
