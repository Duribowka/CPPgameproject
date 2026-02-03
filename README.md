***WELCOME TO A SHELTER BASED GAME ABOUT KEEPING MANY PETS AND TAKING CARE OF THEM BY HIRING STAFF***

*brief description*
This CPP game project can be compared to a well known tamagotchi game but instead of having a single pet that you need to take care of, in this shelter game you run an authority which keeps many pets in a safe environment with working personel. The game includes stat based and time record which means that it's not played in real-time but the program records hours since last login and based on how many time have passed changes game data.

**SECTION 1 - GAME's COMPONENTS**

The game is written on C++ and includes:
    1. A headers folder with most of the program's function prototypes and classes, it contains header files;
    2. Src folder with main game logics, it contains cpp code files;
    3. Text files with pet and employee names which are selected randomly when creating a new one (future game mechanic, not fully implemented as of right now);
    4. "game_data.txt" which holds data for the game to run: time since last run, incomes, bank account, number of pets and their stats, employees and their stats as well;
    5. Makefile which automates compilation, linking and cleaning procceses. Makefile can compile and link --> creates object file and executable and it has the ability to delete them if needed;
    6. And lastly an executable which is the game itself that can be runned and played with;


Visualised program structure:

>headers  <-- folder that contains header files
    employee.hpp  <-- contains a worker's classes with stats and abilities
    entity.hpp  <-- includes class with npc's id and name + random name selector(not fully implemented right now)
    pet.hpp  <-- includes class with pet's stats and prototypes for functions that change these stats
    shelter.hpp  <-- includes a class with 'time_t' functions which are responsible for recording passed time, income
                     functions and all the other functions for managing the entire game
    task.hpp  <-- defines tasks for employee npc's

>src  <-- folder that contains all c++ source files
    employee.cpp  <-- manages all employees: calculates their salary, gives them task skills and gives them names
    main.cpp  <-- entry point, creates entities, updates shelter, loads game data from 'game_data.txt', runs user interractions
                  and saves game's progress
    pet.cpp  <-- pet stats handling and task completion logic
    shelter.cpp  <-- executes tasks, calculates income and payments and prints game data

employee_names.txt  <-- a list of possible names for employees
game  <-- executable, the game itself
game_data.txt  <-- data saving file, contains pet and employee stats as well as last login time
Makefile  <-- automatization of compiling and linking procceses
pet_names.txt  <-- a list of possible names for pets
README.md  <-- you are here :>

**SECTION 2 - MAIN GAME MECHANICS**

In this section I will tell you about core game mechanics and what makes it unique in its own way!

1. Real life time based simulator
    the game uses real system time when calculating progress, progress is calculated once program is launched and it compares last system's time to a new one. Pet stats and task progress are determined by how many hours have passed since last login while finances are triggered by a real life calendar month change.

2. Save file world
    Entire game data and information is stored in 'game_data.txt' and is accessed by 'main.cpp' to load last save and modify it based on how much real life time have passed since last execution.

3. Stat system
    pets have 4 stats and they change after time, hunger accelerates if pet is not fed, attractivenes is lowered if pet is not advertised and happiness lowers if it's not groomed or taken care of.

4. Pet death
    if pet's hunger grows all the way up to 100(max value), the pet is considered dead and it's permanent. The only way to revert this is by going to --> game_data.txt and manualy changing hunger to number lower than 100, then it's considered alive. Any stats cannot be changed if pet is considered dead.

5. Skill system
    when employee is created, he gets a random skill levels which means that some tasks can be performed more efficiently than others. It's a great practice to assign worker to a taks he is best at.

6. Tasks
    tasks are assigned to workers individually and require an amount of hours which means that an employee will perform one task for as long as he was assigned. Task affects all pets at once, if worker is assigned to 'feed' taks, all pets must be fed.

7. Adoption
    