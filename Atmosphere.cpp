/* CSCI 261 Final Project: Solar System Planet Library
 * Author: Joshua Munich Teves
 */

#include "Atmosphere.h"

Atmosphere::Atmosphere() {
    this-> _hasAtmosphere = false;
    this-> _element1 = "None.";
    this-> _element2 = "None.";
    this-> _element3 = "None.";
    this-> _percentElement1 = 0;
    this-> _percentElement2 = 0;
    this-> _percentElement3 = 0;
}

Atmosphere::Atmosphere(bool hasAtmosphere, string &element1, string &element2, string &element3, double percentElement1,
                       double percentElement2, double percentElement3) {
    this-> _hasAtmosphere = hasAtmosphere;
    this-> _element1 = element1;
    this-> _element2 = element2;
    this-> _element3 = element3;
    this-> _percentElement1 = percentElement1;
    this-> _percentElement2 = percentElement2;
    this-> _percentElement3 = percentElement3;
}

// get functions
bool Atmosphere::getHasAtmosphere() const {
    return this-> _hasAtmosphere;
}
string Atmosphere::getElement1() const {
    return this-> _element1;
}
string Atmosphere::getElement2() const {
    return this-> _element2;
}
string Atmosphere::getElement3() const {
    return this-> _element3;
}
double Atmosphere::getPercentElement1() const {
    return this-> _percentElement1;
}
double Atmosphere::getPercentElement2() const {
    return this-> _percentElement2;
}
double Atmosphere::getPercentElement3() const {
    return this-> _percentElement3;
}

// set functions
void Atmosphere::setHasAtmosphere(bool hasAtmosphere) {
    this-> _hasAtmosphere = hasAtmosphere;
}

void Atmosphere::setElement1(string &element1) {
    this-> _element1 = element1;
}

void Atmosphere::setElement2(string &element2) {
    this-> _element2 = element2;
}

void Atmosphere::setElement3(string &element3) {
    this-> _element3 = element3;
}

void Atmosphere::setPercentElement1(double percentElement1) {
    this-> _percentElement1 = percentElement1;
}

void Atmosphere::setPercentElement2(double percentElement2) {
    this-> _percentElement2 = percentElement2;
}

void Atmosphere::setPercentElement3(double percentElement3) {
    this-> _percentElement3 = percentElement3;
}
