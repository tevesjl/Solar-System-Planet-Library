/* CSCI 261 Final Project: Solar System Planet Library
 * Author: Joshua Munich Teves
 */

#ifndef SOLAR_SYSTEM_LIBRARY_PLANET_H
#define SOLAR_SYSTEM_LIBRARY_PLANET_H

#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Atmosphere.h"
using namespace sf;

// prints welcome message
void printWelcome();

// prints options for main menu
void printMainMenu();

// user input functions
int userInputMenuSelection(); // returns an int (based on user input) to decide what menu option to select
// while browsing the library. the function makes sure that any extra numbers (whether an integer or double/float)
// do not cause the input request to repeat. HOWEVER, this has a limit of 8 options (integers) to use as menu options.
// As a result, any integers above 8 will not cause the program to fail, however this function will return 57
// which is ASCII for "9". In that case, make sure to create another menu (like what was done with additional
// information for each planet since there were 12 options to choose from). That way, this function can still be used.

char userInputPrintSelection(); // returns a character (based on user input) to decide whether or not to output info
// of a planet's specific statistic.
// this function makes sure that any extra characters (if there is more than one) doesn't repeat the input request

class Planet {
public:
    // default constructor
    Planet();
    // parameterized constructor
    Planet(string& name, double radius, double mass, double density, double gravity, double dayLength,
           double perihelion, double aphelion, double orbitalPeriod, int numSatellites, int systemPosition,
           bool hasRings, Atmosphere& atmosphereObject);

    // functions
    void displayOptions() const; // displays options to view different statistics of a planet
    void displayOptions2() const; // displays more options to view different statistics of a planet

    // get functions
    string getName() const;
    double getRadius() const;
    double getMass() const;
    double getDensity() const;
    double getSurfaceGravity() const;
    double getDayLength() const;
    double getPerihelion() const;
    double getAphelion() const;
    double getOrbitalPeriod() const;
    int getNumSatellites() const;
    int getSystemPosition() const;
    bool getHasRings() const;
    Atmosphere getAtmosphere() const;
    // set functions were not found to be necessary
private:
    string _name;
    double _radius;
    double _mass;
    double _density;
    double _surfaceGravity;
    double _dayLength;
    double _perihelion;
    double _aphelion;
    double _orbitalPeriod;
    int _numSatellites;
    int _systemPosition;
    bool _hasRings;
    Atmosphere _atmosphere;
};

#endif //SOLAR_SYSTEM_LIBRARY_PLANET_H
