/* CSCI 261 Final Project: Solar System Planet Library
 * Author: Joshua Munich Teves
 */

#ifndef SFML_TEMPLATE_ATMOSPHERE_H
#define SFML_TEMPLATE_ATMOSPHERE_H

#include <iostream>
#include <string>
using namespace std;

class Atmosphere {
public:
    Atmosphere(); // default constructor: planet has no atmosphere
    Atmosphere(bool hasAtmosphere, string& element1, string& element2, string& element3,
               double percentElement1, double percentElement2, double percentElement3);
    // parameterized constructor: if planet has an atmosphere

    // get functions
    bool getHasAtmosphere() const; // returns TRUE if planet has an atmosphere, else false
    string getElement1() const; // returns name of element one
    string getElement2() const; // returns name of element two
    string getElement3() const; // returns name of element three
    double getPercentElement1() const; // returns % composition of element one in the atmosphere
    double getPercentElement2() const; // returns % composition of element two in the atmosphere
    double getPercentElement3() const; // returns % composition of element three in the atmosphere

    // set functions: allows to set values for atmosphere, if _hasAtmosphere is true
    void setHasAtmosphere(bool hasAtmosphere);
    void setElement1(string& element1);
    void setElement2(string& element2);
    void setElement3(string& element3);
    void setPercentElement1(double percentElement1);
    void setPercentElement2(double percentElement2);
    void setPercentElement3(double percentElement3);
private:
    bool _hasAtmosphere; // whether a planet has an atmosphere
    string _element1; // name of element one
    string _element2; // name of element two
    string _element3; // name of element three
    double _percentElement1; // % composition of element one in the atmosphere
    double _percentElement2; // % composition of element two in the atmosphere
    double _percentElement3; // % composition of element three in the atmosphere
};


#endif //SFML_TEMPLATE_ATMOSPHERE_H
