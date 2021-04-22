//Author: Xiang Zhao
//Assignment Title:  Snowman
//Assignment Description:
// Sort a array of Snowman objects
//Due Date: 4/23/2021
//Date Created: 4/22/2021
//Date Last Modified: 4/22/2021




#ifndef Snowman_hpp
#define Snowman_hpp
#include <string>
using namespace std;


class Snowman{
    private:
        double height;
        double weight;
        double temperature;
        bool   hasHat;
        string scarfColor;
    public:
        Snowman ();  //default constructor
        Snowman(double, double, double, bool, string);
        
        void setHeight(double);
        void setWeight(double);
        void setTemperature(double);
        void setHasHat(bool);
        void setScarfColor(string);

        double getHeight() const;
        double getWeight() const;
        double getTemperature() const;
        bool   getHasHat() const;
        string getScarfColor() const;

        double Volume() const;
};

#endif /* Snowman_hpp */
