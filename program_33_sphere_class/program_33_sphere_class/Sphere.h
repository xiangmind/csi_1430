//Author: Xiang Zhao
//Assignment Title:  Sphere class
//Assignment Description:
// Sphere class with a equal method
//Due Date: 4/8/2021
//Date Created: 4/8/2021
//Date Last Modified: 4/8/2021
//Data Abstraction:
// double string
//Input:
//  radius color
//Process:
//  Declare a class Sphere
//Output:
//  the sphere class
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#ifndef Sphere_h
#define Sphere_h

#include <string>
using namespace std;

class Sphere {
    private:
        const double PI = 3.14159;
        double radius;
        string color;
    
    public:
        Sphere();
        Sphere(double r);
        Sphere(double r, string c);
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        void setRadius(double radius);
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        void setColor(string color);
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        double getRadius() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        string getColor() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        double area() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        double volume() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        bool isEqual(const Sphere other) const;
    
};










#endif /* Sphere_h */
