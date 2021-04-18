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


#include "Sphere.h"
using namespace std;




Sphere::Sphere() {
    radius = 1.0;
    color = "green";
}

Sphere::Sphere(double r) {
    radius = r;
    color = "green";
}

Sphere::Sphere(double r, string c) {
    radius = r;
    color = c;
}

void Sphere::setRadius(double radius) {
    this->radius = radius;
}
void Sphere::setColor(string color) {
    this->color =color;
}
double Sphere::getRadius() const {
    return radius;
}
string Sphere::getColor() const {
    return color;
}

double Sphere::area() const {
    return 4.0 * PI * radius * radius;
}

double Sphere::volume() const {
    return 4.0/3.0 * PI * radius * radius * radius;
}

bool Sphere::isEqual(const Sphere other) const {
    bool ret = false;
    if (radius == other.getRadius() && color == other.getColor())
        ret = true;
    return ret;
}
