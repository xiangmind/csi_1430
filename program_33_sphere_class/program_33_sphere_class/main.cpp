//
//  main.cpp
//  program_33_sphere_class
//
//  Created by depplenny on 4/8/21.
//

#include <iostream>
#include <cmath>
#include "Sphere.h"


int main(int argc, const char * argv[]) {
    
    cout << "Test the default constructor:\n";
    Sphere s1;
    Sphere s2;
    if (s1.isEqual(s2))
        cout << "s1==s2, it's a successful test.\n";
    else
        cout << "s1!=s2, it's a failed test.\n";
    cout << "Test ends\n";
    
    
    cout << "Test other constructors:\n";
    Sphere s3(3.0);
    Sphere s4(3.0, "green");
    if (s3.isEqual(s4))
        cout << "s3==s4, it's a successful test.\n";
    else
        cout << "s3!=s4, it's a failed test.\n";
    cout << "Test ends\n";
    
    
    cout << "Test setter/getter:\n";
    Sphere s5;
    s5.setRadius(10.0);
    s5.setColor("blue");
    assert(s5.getRadius()==10.0);
    assert(s5.getColor()=="blue");
    cout << "Test ends\n";
    
    cout << "Test area()/volume():\n";
    Sphere s6(10.0, "red");
    assert(s6.area()==1256.636);
    assert(fabs(s6.volume()-4188.78666667)<=1.0e-4);
    cout << "Test ends\n";
    return 0;
}
