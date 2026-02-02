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
    shelter.hpp  <-- 
    task.hpp

>src
    employee.cpp
    main.cpp
    pet.cpp
    shelter.cpp

employee_names.txt
game
game_data.txt
Makefile
pet_names.txt
README.md