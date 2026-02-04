#include "../headers/shelter.hpp"

//This function is the constructor for the Shelter, restoring its saved state
Shelter::Shelter(time_t prev_time, time_t current_time, time_t prev_income_time,
                 int bank_account, int montly_income)
{
    this->prev_time = prev_time;
    this->current_time = current_time;
    this->prev_income_time = prev_income_time;
    this->bank_account = bank_account;
    this->monthly_income = monthly_income;
}

//This function adds a pet to the shelter's list of pets
void Shelter::addPet(Pet* pet)
{
    pets.push_back(pet);
}

//This function adds an employee to the shelter's list of employees
void Shelter::addEmployee(Employee* employee)
{
    employes.push_back(employee);
}

//This function updates the state of the shelter based on the time passed since the last update
bool Shelter::update()
{
    //Calculating the number of hours passed since the last update by converting real world seconds into hours
    time_t deltaTime = (current_time - prev_time) / 3600;
    cout << "hours since last enterence: " << deltaTime << endl;

    if (deltaTime > 0)
    {
        //This loop updates each pet's stats for every hour that has passed (pet decay)
        for (int i = 0; i < deltaTime; i++)
            for (Pet* pet : pets)
            {
                pet->update_attractivenes();
                pet->update_hunger();
                pet->update_happines();
            }

        //Store tasks that are completed to delete them after processing
        vector<Task*> tasks_to_delete;

        for (Task* task : tasks)
        {
            //Find the employee assigned to the current task
            Employee curr_employee;

            for (Employee* temp_emp : employes)
            {
                if (temp_emp->get_id().compare(task->employee_id) == 0)
                    curr_employee = *temp_emp;
            }

            //Determine how much time the employee mustg spend on the task
            int passed_time_spent_on_work = 0;
            passed_time_spent_on_work =
                (deltaTime >= task->duration) ? task->duration : deltaTime;

            switch (task->task_type)
            {
                //If attractiveness is below 900, pet will be groomed --> increased attractiveness
                case GROOM:
                {
                    for (Pet* pet : pets)
                    {
                        int curr_attr = pet->get_attractivenes();
                        cout << "current attractiveness: " << curr_attr << endl;

                        if (curr_attr < 900)
                        {
                            if (deltaTime >= task->duration)
                            {
                                passed_time_spent_on_work = task->duration;
                                deltaTime -= task->duration;
                            }
                            else
                            {
                                passed_time_spent_on_work = deltaTime;
                                deltaTime = 0;
                            }

                            int lacking_attr = 1000 - curr_attr;
                            cout << "lacking attractiveness: " << lacking_attr << endl;

                            if (lacking_attr / 100 <= passed_time_spent_on_work)
                            {
                                pet->groom(
                                    lacking_attr *
                                    (curr_employee.get_grooming_skill_level() / 10.0)
                                );
                                task->duration -= lacking_attr / 100;
                            }
                            else
                            {
                                pet->groom(
                                    passed_time_spent_on_work * 100 *
                                    (curr_employee.get_grooming_skill_level() / 10.0)
                                );
                                task->duration -= passed_time_spent_on_work;
                            }
                        }

                        // FIXED: logical OR
                        if (task->duration <= 0 || deltaTime <= 0)
                            break;
                    }
                    break;
                }

                //If attractiveness and happiness are high, pet may get adopted --> removed from shelter, either way, income might be increased
                case ADVERTISE:
                {
                    float mark_coef =
                        curr_employee.get_marketing_skill_level() / 10.0;

                    for (int i = 0; i < passed_time_spent_on_work; i++)
                    {
                        float rand_val = rand() * 1.0f / RAND_MAX;

                        if (rand_val < mark_coef)
                        {
                            if (rand() * 1.0f / RAND_MAX > 0.01)
                            {
                                int mood = rand() % 2000;

                                for (Pet* pet : pets)
                                {
                                    if (mood <
                                        (pet->get_attractivenes() +
                                         pet->get_happines()))
                                    {
                                        pets.erase(
                                            find(pets.begin(), pets.end(), pet)
                                        );
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                this->monthly_income +=
                                    curr_employee.get_marketing_skill_level();
                            }
                        }
                    }
                    break;
                }

                //Pets happiness is increased until it reaches 1000
                case TAKE_CARE:
                {
                    for (Pet* pet : pets)
                    {
                        pet->increase_happines(
                            passed_time_spent_on_work * 100 *
                            (curr_employee.get_caretaking_skill_level() / 10.0)
                        );
                    }
                    task->duration -= passed_time_spent_on_work;
                    break;
                }

                //Pets hunger is decreased until it reaches 0
                case FEED:
                {
                    for (Pet* pet : pets)
                    {
                        pet->feed(passed_time_spent_on_work * 10);
                    }
                    task->duration -= passed_time_spent_on_work;
                    break;
                }
            }

            //Mark task for deletion if it's completed
            if (task->duration <= 0)
                tasks_to_delete.push_back(task);
        }

        for (Task* task : tasks_to_delete)
        {
            tasks.erase(find(tasks.begin(), tasks.end(), task));
        }

        struct tm* tm_prev_inc = localtime(&prev_income_time);
        struct tm* tm_cur_time = localtime(&current_time);

        //If month has changed, update bank account with income and salaries
        if (abs(tm_cur_time->tm_mon - tm_prev_inc->tm_mon) > 0)
        {
            bank_account += monthly_income;

            tm_prev_inc->tm_mon++;
            prev_income_time = mktime(tm_prev_inc);

            for (Employee* temp_emp : employes)
            {
                bank_account -= temp_emp->get_salary();
            }
        }
        
        //Time has been successfully processed
        return true;
    }
    //No update
    return false;
}

//This function displays the stats of a pet
void Shelter::show_pet_stats(Pet* pet)
{
    cout << "Alive: " << pet->get_alive_status() << endl;
    cout << "attractivenes: " << pet->get_attractivenes() << endl;
    cout << "hunger: " << pet->get_hunger() << endl;
    cout << "happines: " << pet->get_happines() << endl;
}

//This function displays the stats of all pets in the shelter
void Shelter::show_pets_stats()
{
    int i = 1;
    for (Pet* pet : pets)
    {
        cout << "pet number: " << i++ << endl;
        show_pet_stats(pet);
    }
}

//this function adds a new task to an employee if they are free
void Shelter::addNewTask(const string& employee_id,
                         Task_type task_type,
                         int duration)
{
    for (Task* temp_task : tasks)
    {   
        //Check if employee is already assigned to a task
        if (temp_task->employee_id.compare(employee_id) == 0)
        {
            cout << "Current Employee is already bussy" << endl;
            return;
        }
    }

    tasks.push_back(
        new Task(to_string(tasks.size()),
                 employee_id,
                 task_type,
                 duration)
    );
}

//This function displays all current tasks in the shelter
void Shelter::showTasks()
{
    for (Task* task : tasks)
    {
        cout << task->id << " "
             << task->employee_id << " "
             << enum_to_string(task->task_type) << " "
             << task->duration << endl;
    }
}

//This function displays all employees in the shelter
void Shelter::show_employes()
{
    for (Employee* empl : employes)
    {
        cout << "id: " << empl->get_id() << endl;
        cout << "name: " << empl->get_name() << endl;
        cout << "grooming skill: "
             << empl->get_grooming_skill_level() << endl;
        cout << "marketing skill: "
             << empl->get_marketing_skill_level() << endl;
        cout << "caretaking skill: "
             << empl->get_caretaking_skill_level() << endl;
    }
}