#pragma once
#include <string>
#include <cstdlib>
#include "entity.hpp"
#include <vector>
using namespace std;


class Pet : public Entity{
    public:
        static vector<string> names;
    private:
        int happines; // 1000
        int hunger;
        int attractivenes; // 1000
        bool isAlive = true;
    public:
        Pet(string& id, string& name);
        Pet(string& id, string& name, int attractivenes, int hunger, int happines); 
        void name_pet(string name);
        void increase_happines(int amount);
        void update_happines();
        void feed(int amount);
        void update_hunger();
        void update_attractivenes();
        void groom(){this->attractivenes = 1000;}
        int get_attractivenes(){return this->attractivenes;}
        int get_hunger(){return this->hunger;}
        int get_happines(){return this->happines;}
        static void get_names_from_file();



};
