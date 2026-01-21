#pragma once
#include <string>
#include <ctime>

using namespace std;


enum Task_type
{
    GROOM,
    ADVERTISE,
    TAKE_CARE

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
    string id;
    string employee_id;
    string pet_id;
    Task_type task_type;
    time_t start_time;
    int duration;
};
