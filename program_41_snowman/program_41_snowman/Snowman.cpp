//Author: Xiang Zhao
//Assignment Title:  Snowman
//Assignment Description:
// Sort a array of Snowman objects
//Due Date: 4/23/2021
//Date Created: 4/22/2021
//Date Last Modified: 4/22/2021



#include "Snowman.h"


Snowman::Snowman() {
    height = 5.0; //ft
    weight = 300.0; // lbs
    temperature = 29.80; // F
    hasHat = true;
    scarfColor = "RED";
}


Snowman::Snowman(double height, double weight,
                 double temperature, bool hasHat,
                 string scarfColor) {    
    this->height = height; //ft
    this->weight = weight; // lbs
    this->temperature = temperature; // F
    this->hasHat = hasHat;
    this->scarfColor = scarfColor;

}



void Snowman::setHeight(double height) {
    this->height = height;
}
void Snowman::setWeight(double weight) {
    this->weight = weight;
}
void Snowman::setTemperature(double temperature) {
    this->temperature = temperature;
}
void Snowman::setHasHat(bool hasHat) {
    this->hasHat = hasHat;
}
void Snowman::setScarfColor(string scarfColor) {
    this->scarfColor = scarfColor;
}


double Snowman::getHeight() const {
    return height;
}
double Snowman::getWeight() const {
    return weight;
}
double Snowman::getTemperature() const {
    return temperature;
}
bool   Snowman::getHasHat() const {
    return hasHat;
}
string Snowman::getScarfColor() const {
    return scarfColor;
}


double Snowman::Volume() const {
    double PI = 3.14159;
    return PI * height*height*height / 36.0;
}
