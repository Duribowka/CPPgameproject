#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "shelter.hpp"

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
    
    getline(game_data,line);
    int pet_count = stoi(line,0,10);
    for(int i = 0; i< pet_count; i++)
    {   
        int temp_at;
        int temp_hun;
        int temp_hap;
        string temp_id;
        string temp_name;
        if(getline(game_data,line)){temp_id = stoi(line);}else{break;}
        if(getline(game_data,line)){temp_name = line;}else{break;}
        if(getline(game_data,line)){temp_at = stoi(line);}else{break;}
        if(getline(game_data,line)){temp_hun = stoi(line);}else{break;}
        if(getline(game_data,line)){temp_hap = stoi(line);}else{break;}
        Pet* test_pet = new Pet(temp_id, temp_name, temp_at,temp_hun,temp_hap);
        shelter.addPet(test_pet);

    }
    game_data.close();

    
    if(shelter.update())
    {
        ofstream game_data;
        game_data.open("game_data.txt", ios::out | ios::trunc);
        game_data << timestamp << endl;
        game_data << shelter.get_pets().size() << endl;
        for(Pet* pet: shelter.get_pets())
        {   
            game_data << pet->get_id() << endl;
            game_data << pet->get_name() << endl;
            game_data << pet->get_attractivenes() << endl;
            game_data << pet->get_hunger() << endl;
            game_data << pet->get_happines() << endl;
        }
        game_data.close();
    }
    shelter.show_pets_stats();


    return 0;

}
