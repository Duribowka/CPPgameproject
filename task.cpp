#include <string>
using namespace std;


enum Task_type
{
    GROOM,
    ADVERTISE,
    TAKE_CARE

};

string enum_to_string(Task_type task)
{
    switch(task)
    {
        case Task_type::GROOM: return "GROOM";
        case Task_type::ADVERTISE: return "ADVERTISE";
        case Task_type::TAKE_CARE: return "TAKE_CARE";
    }
    return NULL;
}

