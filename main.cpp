#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "shelter.cpp"
#include "task.cpp"


using namespace std;

int main()
{   
      
    
    string line;
    ifstream game_data;
    game_data.open("game_data.txt");
    

    getline(game_data,line);

    time_t prev_time = stoi(line,0,10);
    time_t timestamp; 
    time(&timestamp);

    Shelter shelter(prev_time,timestamp);

    while(1)
    {   
        int temp_at;
        int temp_hun;
        int temp_hap;
        if(getline(game_data,line)){temp_at = stoi(line);}else{break;}
        if(getline(game_data,line)){temp_hun = stoi(line);}else{break;}
        if(getline(game_data,line)){temp_hap = stoi(line);}else{break;}
        Pet* test_pet = new Pet(temp_at,temp_hun,temp_hap);
        shelter.addPet(test_pet);

    }
    game_data.close();
    if(shelter.update())
    {
        ofstream game_data;
        game_data.open("game_data.txt", ios::out | ios::trunc);
        game_data << timestamp << endl;
        for(Pet* pet: shelter.get_pets())
        {
            game_data << pet->get_attractivenes() << endl;
            game_data << pet->get_hunger() << endl;
            game_data << pet->get_happines() << endl;
        }
        game_data.close();
    }
    shelter.show_pets_stats();
    
    enum Task_type task = GROOM;
    
    cout << enum_to_string(task) << endl;

    return 0;

}
