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
        
        vector<Task> tasks_to_delete;
        for(Task task: tasks)
        {
            int passed_time_spent_on_work = 0;
            if(deltaTime >= task.duration)
            {
                passed_time_spent_on_work = task.duration;
            }
            else if(deltaTime < task.duration)
            {
                passed_time_spent_on_work = deltaTime;
            }
            if(task.task_type == FEED)
            {
                for(Pet* pet : pets)
                {
                    
                    pet->feed(passed_time_spent_on_work * 10);
            
                }
            }
            task.duration-=passed_time_spent_on_work;
            if(task.duration == 0)
            {
                tasks_to_delete.push_back(task);
            }
        }
        for(Task task: tasks_to_delete)
        {
            tasks.erase(find(tasks.begin(),tasks.end(),task));
        }
        return true;
    }
    return false;
    
}

void Shelter::show_pet_stats(Pet* pet)
{
    cout << "Alive: " << pet->get_alive_status() << endl;
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

void Shelter::addNewTask(const string& employee_id, Task_type task_type, int duration)
{
    
    this->tasks.push_back(Task(to_string(this->tasks.size()),employee_id,task_type,duration));

}

void Shelter::showTasks()
{
    for(Task task: tasks)
    {    
        cout << task.id << " " << task.employee_id << " " << task.task_type << " "  << task.duration << endl;
    }
}

void Shelter::show_employes()
{

    for(Employee* empl : employes)
    {
        cout << "id: " << empl->get_id() <<endl;
        cout << "name: " << empl->get_name() <<endl;
        cout << "grooming skill: " << empl->get_grooming_skill_level() <<endl;
        cout << "marketing skill: " << empl->get_marketing_skill_level() <<endl;
        cout << "caretaking skill: " << empl->get_caretaking_skill_level() <<endl;
    }
}
