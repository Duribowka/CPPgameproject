#include <ctime>

class Employee
{
    private: 
        int id;
        float salary;
        int grooming_skill_level;
        int marketing_skill_level;
        int caretaking_skill_level;
        int work_capacity = 8;
        bool isFree = true;
        time_t last_order_given;
        int work_cost;

    public:
        void work(int hours)
        {
            work_capacity -= hours;
            if (work_capacity < 0)
            {
                work_capacity = 0;
            }
        }
        
        void assignTask(int work_cost, time_t startTime)
        {
            this->work_cost = work_cost;
            this->last_order_given = startTime;
            this->isFree = false;
        }
};

// employee // pet // task_type // start_time // work_time //
