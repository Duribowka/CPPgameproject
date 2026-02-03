#include "../headers/employee.hpp"
#include <fstream>
vector<string> Employee::names;

//This function creates an employee with random skill levels and salary based on their skill levels + random factor :D
Employee::Employee(const string& id, const string& name) : Entity(id,name)
{
    
    this->grooming_skill_level = 1 + (rand() % 10);
    this->marketing_skill_level = 1 + (rand() % 10);
    this->caretaking_skill_level = 1 + (rand() % 10);
    

    this->salary = (
        this->grooming_skill_level + 
        this->marketing_skill_level + 
        this->caretaking_skill_level + 
        (-10 + (rand() % 21))
    ) * 100;
}

//This function creates an employee with given skill levels and salary, as a result saved employees are saved correctly
Employee::Employee(const string& id, const string& name, int grooming_skill_level, int marketing_skill_level, int caretaking_skill_level, int salary) : 
    Entity(id,name), 
    grooming_skill_level(grooming_skill_level), 
    marketing_skill_level(marketing_skill_level), 
    caretaking_skill_level(caretaking_skill_level),
    salary(salary){};

//This function reduces the work capacity of the employee when they work by tracking hours worked
void Employee::work(int hours)
        {
            work_capacity -= hours;
            if (work_capacity < 0)
            {
                work_capacity = 0;
            }
        }

//This function assigns a task to the employee, setting their work cost and the time the task was assigned, however it is not used as of right now
void Employee:: assignTask(int work_cost, time_t startTime)
        {
            this->work_cost = work_cost;
            this->last_order_given = startTime;
            this->isFree = false;
        }

//This function reads employee names from a file and stores them for random name assignment, however it is not used as of right now
void Employee::get_names_from_file()
{
    ifstream employee_names_file;
    employee_names_file.open("employee_names.txt");
    string line;
    while(getline(employee_names_file,line))
    {
        Employee::names.push_back(line);
    }
}
