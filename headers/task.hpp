#pragma once
#include <string>
#include <ctime>

using namespace std;


enum Task_type
{
    GROOM,
    ADVERTISE,
    TAKE_CARE,
    FEED

};

inline string enum_to_string(Task_type task)
{
    switch(task)
    {
        case Task_type::GROOM: return "GROOM";
        case Task_type::ADVERTISE: return "ADVERTISE";
        case Task_type::TAKE_CARE: return "TAKE_CARE";
    }
    return NULL;
}

class Task{
    
    public:
        string id;
        string employee_id;
        Task_type task_type;
        int duration;    
        Task(const string& id, const string& employee_id, Task_type task_type, int duration):
        id(id), employee_id(employee_id), task_type(task_type), duration(duration){}
        bool operator==(const Task& other) const {return id == other.id;}
        


};

