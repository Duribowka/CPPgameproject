#include <string>
#include <cstdlib>

using namespace std;


class Pet{
    private:
        string name;
        int happines; // 1000
        int hunger;
        int attractivenes; // 1000
        bool isAlive = true;

    public:

        Pet()
        {
            this->happines = rand() % 1001;
            this->hunger = 10 + rand() % 91;
            this->attractivenes = rand() % 1001;
        }

        Pet(int attractivenes, int hunger, int happines)
        {
            this->happines = happines;
            this->hunger = hunger;
            this->attractivenes = attractivenes;
        }

        void name_pet(string name)
        {
            this->name = name;
        }

        void increase_happines(int amount)
        {
            this->happines += amount;
            if(this->happines > 1000)
            {
                this->happines = 1000;
            }
        }

        void update_happines()
        {
            this->happines--;
            if(this->happines < 0)
            {
               this->happines = 0;
            }
        }

        void feed(int amount)
        {
            this->hunger -= amount;
            if(this->hunger < 0)
            {
                this->hunger = 0;
            }
        }

        void update_hunger()
        {
            this->hunger++;
            if(this->hunger >= 100)
            {
                this->isAlive = false;
            }
        }

        void update_attractivenes()
        {
            this->attractivenes--;
            if(this->attractivenes < 0)
            {
                this->attractivenes = 0;
            }
        }

        void groom(){this->attractivenes = 1000;}
        int get_attractivenes(){return this->attractivenes;}
        int get_hunger(){return this->hunger;}
        int get_happines(){return this->happines;}



};
