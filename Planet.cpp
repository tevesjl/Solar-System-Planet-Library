/* CSCI 261 Final Project: Solar System Planet Library
 * Author: Joshua Munich Teves
 */

#include "Planet.h"

void printWelcome() {
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Welcome to the Solar System Planet Library!" << endl;
    cout << "Now reading in the input file..." << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

void printMainMenu() {
    cout << "Please enter an integer corresponding to the option you would like to select below." << endl;
    cout << "(0) Exit the program." << endl;
    cout << "(1) Explore various facts about each planet in the solar system." << endl;
    cout << "(2) See a picture of each planet." << endl;
}

int userInputMenuSelection() {
    string userInput;
    getline(cin, userInput);

    if (userInput.size() > 1) {
        //cout << "Returning statement 1" << endl;
        return 57;
    }
    else if (userInput.empty()) {
        return 57;
    }
    else if (isdigit(userInput.at(0))) {
        //cout << "Returning statement 2" << endl;
        return userInput.at(0);
    }
    else {
        //cout << "Returning statement 3" << endl;
        return 57;
    }
}

char userInputPrintSelection() {
    string userInput;
    getline(cin, userInput);

    if (userInput.size() > 1) {
        return 'x';
    }
    else if (userInput.empty()) {
        return 'x';
    }
    else if (isalpha(userInput.at(0))) {
        return userInput.at(0);
    }
    else {
        return 'x';
    }
}

Planet::Planet() {
    this-> _name = "Empty";
}

Planet::Planet(string &name, double radius, double mass, double density, double gravity, double dayLength,
               double perihelion, double aphelion, double orbitalPeriod, int numSatellites, int systemPosition,
               bool hasRings, Atmosphere &atmosphereObject) {
    this-> _name = name;
    this-> _radius = radius;
    this-> _mass = mass;
    this-> _density = density;
    this-> _surfaceGravity = gravity;
    this-> _dayLength = dayLength;
    this-> _perihelion = perihelion;
    this-> _aphelion = aphelion;
    this-> _orbitalPeriod = orbitalPeriod;
    this-> _numSatellites = numSatellites;
    this-> _systemPosition = systemPosition;
    this-> _hasRings = hasRings;
    this-> _atmosphere = atmosphereObject;
}

string Planet::getName() const {
    return this-> _name;
}

double Planet::getRadius() const {
    return this-> _radius;
}

double Planet::getMass() const {
    return this-> _mass;
}

double Planet::getDensity() const {
    return this-> _density;
}

double Planet::getSurfaceGravity() const {
    return this-> _surfaceGravity;
}

double Planet::getDayLength() const {
    return this-> _dayLength;
}

double Planet::getPerihelion() const {
    return this-> _perihelion;
}

double Planet::getAphelion() const {
    return this-> _aphelion;
}

double Planet::getOrbitalPeriod() const {
    return this-> _orbitalPeriod;
}

int Planet::getNumSatellites() const {
    return this-> _numSatellites;
}

int Planet::getSystemPosition() const {
    return this-> _systemPosition;
}

bool Planet::getHasRings() const {
    return this-> _hasRings;
}

Atmosphere Planet::getAtmosphere() const {
    return this-> _atmosphere;
}

void Planet::displayOptions() const {
    cout << "(1) " << _name << ": radius" << endl;
    cout << "(2) " << _name << ": mass" << endl;
    cout << "(3) " << _name << ": density" << endl;
    cout << "(4) " << _name << ": surface gravity" << endl;
    cout << "(5) " << _name << ": length of day" << endl;
    cout << "(6) " << _name << ": perihelion" << endl;
    cout << "(7) " << _name << ": aphelion" << endl;
    cout << "(8) Show more options." << endl; // the input function has a limit of 8 options, so this is used
    // to view more options
}

void Planet::displayOptions2() const { // called when 8 is input from the displayOptions function
    cout << "(1) " << _name << ": orbital period" << endl;
    cout << "(2) " << _name << ": number of satellites (moons)" << endl;
    cout << "(3) " << _name << ": position in the solar system" << endl;
    cout << "(4) " << _name << ": does it have rings?" << endl;
    cout << "(5) " << _name << ": atmosphere (if applicable)" << endl;
}

/*
void Planet::Print() {
    cout << "Planet Name: " << _name << endl;
    cout << "Planet Radius: " << _radius << endl;
    cout << "Planet Mass: " << _mass << endl;
    cout << "Planet Density: " << _density << endl;
    cout << "Planet Surface Gravity: " << _surfaceGravity << endl;
    cout << "Planet Day Length: " << _dayLength << endl;
    cout << "Planet Perihelion: " << _perihelion << endl;
    cout << "Planet Aphelion: " << _aphelion << endl;
    cout << "Planet Orbital Period: " << _orbitalPeriod << endl;
    cout << "Planet Number of Satellites: " << _numSatellites << endl;
    cout << "Planet System Position: " << _systemPosition << endl;
    cout << "Does the planet have rings? " << _hasRings << endl;
    if (_atmosphere.getHasAtmosphere()) {
        cout << "Planet has an atmosphere!" << endl;
        cout << "Element 1: " << _atmosphere.getElement1() << "  " << _atmosphere.getPercentElement1() << endl;
        cout << "Element 2: " << _atmosphere.getElement2() << "  " << _atmosphere.getPercentElement2() << endl;
        cout << "Element 3: " << _atmosphere.getElement3() << "  " << _atmosphere.getPercentElement3() << endl;
    }
    else {
        cout << "Planet does not have an atmosphere!" << endl;
    }
}
 */
