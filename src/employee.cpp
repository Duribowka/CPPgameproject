#include "employee.hpp"
#include <fstream>
vector<string> Employee::names;

void Employee::work(int hours)
        {
            work_capacity -= hours;
            if (work_capacity < 0)
            {
                work_capacity = 0;
            }
        }
        
void Employee:: assignTask(int work_cost, time_t startTime)
        {
            this->work_cost = work_cost;
            this->last_order_given = startTime;
            this->isFree = false;
        }
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
