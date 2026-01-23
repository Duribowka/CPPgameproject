#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "headers/shelter.hpp"

using namespace std;

int main(int argc, char** argv)
{
    string line;
    ifstream game_data;

    Pet::get_names_from_file();
    Employee::get_names_from_file();

    game_data.open("game_data.txt");
    if (!game_data.is_open())
    {
        cerr << "Error: could not open game_data.txt" << endl;
        return 1;
    }

    time_t prev_time = 0;
    time_t timestamp;
    time(&timestamp);

    if (!getline(game_data, line))
    {
        cerr << "Error: missing timestamp" << endl;
        return 1;
    }

    try
    {
        prev_time = static_cast<time_t>(stoi(line));
    }
    catch (...)
    {
        cerr << "Error: invalid timestamp" << endl;
        return 1;
    }

    Shelter shelter(prev_time, timestamp);

    int pet_count = 0;
    if (!getline(game_data, line))
    {
        cerr << "Error: missing pet count" << endl;
        return 1;
    }

    try
    {
        pet_count = stoi(line);
    }
    catch (...)
    {
        cerr << "Error: invalid pet count" << endl;
        return 1;
    }

    for (int i = 0; i < pet_count; ++i)
    {
        string id, name;
        int at, hun, hap;

        if (!getline(game_data, id)) break;
        if (!getline(game_data, name)) break;
        if (!getline(game_data, line)) break;
        at = stoi(line);
        if (!getline(game_data, line)) break;
        hun = stoi(line);
        if (!getline(game_data, line)) break;
        hap = stoi(line);

        shelter.addPet(new Pet(id, name, at, hun, hap));
    }

    int employee_count = 0;
    if (!getline(game_data, line))
    {
        cerr << "Error: missing employee count" << endl;
        return 1;
    }

    try
    {
        employee_count = stoi(line);
    }
    catch (...)
    {
        cerr << "Error: invalid employee count" << endl;
        return 1;
    }

    for (int i = 0; i < employee_count; ++i)
    {
        string id, name;
        int gr, mr, ct, sl;

        if (!getline(game_data, id)) break;
        if (!getline(game_data, name)) break;
        if (!getline(game_data, line)) break;
        gr = stoi(line);
        if (!getline(game_data, line)) break;
        mr = stoi(line);
        if (!getline(game_data, line)) break;
        ct = stoi(line);
        if (!getline(game_data, line)) break;
        sl = stoi(line);

        shelter.addEmployee(new Employee(id, name, gr, mr, ct, sl));
    }

    if (getline(game_data, line))
    {
        int task_count = 0;
        try
        {
            task_count = stoi(line);
        }
        catch (...)
        {
            task_count = 0;
        }

        for (int i = 0; i < task_count; ++i)
        {
            string task_id;
            string employee_id;
            Task_type task_type;
            int duration;

            if (!getline(game_data, task_id)) break;
            if (!getline(game_data, employee_id)) break;
            if (!getline(game_data, line)) break;
            task_type = Task_type(stoi(line));
            if (!getline(game_data, line)) break;
            duration = stoi(line);

            shelter.addNewTask(employee_id, task_type, duration);
        }
    }

    game_data.close();

    if (argc >= 2)
    {
        string command = argv[1];

        if (command == "feed")
        {
            auto employees = shelter.get_employes();

            if (!employees.empty())
            {
                shelter.addNewTask(
                    employees[0]->get_id(),
                    Task_type::FEED,
                    1
                );
            }
            else
            {
                cerr << "Warning: no employees available" << endl;
            }
        }
        else
        {
            cerr << "Warning: unknown command '" << command << "'" << endl;
        }
    }

    bool update = shelter.update();

    ofstream out("game_data.txt", ios::out | ios::trunc);
    if (!out.is_open())
    {
        cerr << "Error: could not save game data" << endl;
        return 1;
    }

    out << (update ? timestamp : prev_time) << endl;

    out << shelter.get_pets().size() << endl;
    for (Pet* pet : shelter.get_pets())
    {
        out << pet->get_id() << endl;
        out << pet->get_name() << endl;
        out << pet->get_attractivenes() << endl;
        out << pet->get_hunger() << endl;
        out << pet->get_happines() << endl;
    }

    out << shelter.get_employes().size() << endl;
    for (Employee* employee : shelter.get_employes())
    {
        out << employee->get_id() << endl;
        out << employee->get_name() << endl;
        out << employee->get_grooming_skill_level() << endl;
        out << employee->get_marketing_skill_level() << endl;
        out << employee->get_caretaking_skill_level() << endl;
        out << employee->get_salary() << endl;
    }

    if (!shelter.getTasks().empty())
    {
        out << shelter.getTasks().size() << endl;
        for (Task task : shelter.getTasks())
        {
            out << task.id << endl;
            out << task.employee_id << endl;
            out << task.task_type << endl;
            out << task.duration << endl;
        }
    }

    out.close();

    shelter.show_pets_stats();
    shelter.show_employes();
    shelter.showTasks();

    return 0;
}