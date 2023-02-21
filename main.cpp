/* CSCI 261 Final Project: Solar System Planet Library
 * Author: Joshua Munich Teves
 * A program that shows various information to the user about the solar system using a Planet and Atmosphere class.
 * The program requires an input file which will read in the different information for each planet.
 * Various interactions exist with the private data members of the Planet (and Atmosphere) class.
 * An option to output specific information of each planet exists for users.
 */

#include "Planet.h"

int main() {
    // Introduction & opening input file
    printWelcome(); // prints welcome message
    ifstream fileIn("planetinformation.txt");
    if (fileIn.fail()) {
        cerr << "Failed to read in planetinformation.txt." << endl;
        return -1;
    }
    // reading in planet information
    int i; // looping variable
    int numPlanets; // holds number of planets to read in
    fileIn >> numPlanets; // reads in number of planets
    vector<Planet> planetVector(numPlanets); // creates a vector of planet objects

    // variables for reading in planet information
    // Planet class
    char charPlanetName;
    string planetName;
    double radius, mass, density, surfaceGravity, dayLength, perihelion, aphelion, orbitalPeriod;
    int numSatellites, systemPosition;
    bool hasRings;

    // Atmosphere class
    bool hasAtmosphere;
    string element1, element2, element3;
    char charElement1, charElement2, charElement3;
    double percentElement1, percentElement2, percentElement3;

    for (i = 0; i < numPlanets; ++i) { // loop to read in planet information
        fileIn >> charPlanetName;
        getline(fileIn, planetName);
        planetName = charPlanetName + planetName;

        fileIn >> radius >> mass >> density >> surfaceGravity >> dayLength >> perihelion >> aphelion >> orbitalPeriod
        >> numSatellites >> systemPosition >> hasRings >> hasAtmosphere;

        if (hasAtmosphere) { // if the planet has an atmosphere, read in additional information
            fileIn >> charElement1;
            getline(fileIn, element1);
            element1 = charElement1 + element1;
            fileIn >> charElement2;
            getline(fileIn, element2);
            element2 = charElement2 + element2;
            fileIn >> charElement3;
            getline(fileIn, element3);
            element3 = charElement3 + element3;
            fileIn >> percentElement1 >> percentElement2 >> percentElement3;
            Atmosphere atmosphereObject(hasAtmosphere, element1, element2, element3, percentElement1,
                                        percentElement2, percentElement3);
            Planet planetObject(planetName, radius, mass, density, surfaceGravity, dayLength, perihelion,
                                aphelion, orbitalPeriod, numSatellites, systemPosition, hasRings, atmosphereObject);
            planetVector.at(i) = planetObject;
        }
        else { // if the planet has no atmosphere, do not read in additional information
            Atmosphere atmosphereObject;
            Planet planetObject(planetName, radius, mass, density, surfaceGravity, dayLength, perihelion,
                                aphelion, orbitalPeriod, numSatellites, systemPosition, hasRings, atmosphereObject);
            planetVector.at(i) = planetObject; // change current planet object to planet object w/ information
        }
    }
    fileIn.close(); // closes planet information file

    // create an output file, which the user may or may not choose to output information on
    ofstream fileOut("planetinformationoutput.txt");
    if (fileOut.fail()) {
        cerr << "Failed to create planetinformationoutput.txt file." << endl;
        return -1;
    }

    // various variables used for the main program
    bool endProgram, optionOne, optionTwo, chosePlanet = false;
    bool badInput;
    string userInput, tempString, planetInput;
    char userInputChar;

    // while loop to execute main body of the program, runs until user exits
    while (!endProgram) {
        printMainMenu(); // prints the main menu
        userInput = userInputMenuSelection();
        if (userInput == "9") {
            cout << "Please enter a valid integer." << endl;
            cout << endl;
            continue;
        }

        else if (userInput == "1") {
            optionOne = true;
            while (optionOne) {
                cout << "The following planets are available to view: " << endl;
                for (i = 0; i < planetVector.size(); ++i) {
                    if (i == planetVector.size() - 1) {
                        cout << "(" << planetVector.at(i).getSystemPosition()
                        << ") " << planetVector.at(i).getName() << endl;
                        cout << endl;
                    }
                    else {
                        cout << "(" << planetVector.at(i).getSystemPosition()
                             << ") " << planetVector.at(i).getName() << ", ";
                    }
                }
                cout << "You may enter 0 at any time to exit and return to the previous menu." << endl;
                cout << "Enter the corresponding integer of the planet you would like to view: ";
                planetInput = userInputMenuSelection();
                if (planetInput == "9") {
                    cout << "Please enter a valid integer." << endl;
                    cout << endl;
                    continue;
                }

                else if (planetInput == "0") {
                    optionOne = false;
                }

                else if (stoi(planetInput) > 0 && stoi(planetInput) <= planetVector.size()) {
                    chosePlanet = true;
                    fileOut << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
                    fileOut << planetVector.at(stoi(planetInput) - 1).getName() << endl;
                    fileOut << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
                    while (chosePlanet) {
                        cout << endl;
                        cout << "You have chosen to view " << planetVector.at(stoi(planetInput) - 1).getName() << "!" << endl;
                        cout << "You can enter 0 at any time to exit and return to the previous menu." << endl;
                        cout << "What facts would you like to view for " << planetVector.at(stoi(planetInput) - 1).getName()
                        << "?" << endl;
                        planetVector.at(stoi(planetInput) - 1).displayOptions();
                        userInput = userInputMenuSelection();

                        if (userInput == "9") {
                            cout << "Please enter a valid integer." << endl;
                            cout << endl;
                            continue;
                        }
                        else if (userInput == "0") {
                            chosePlanet = false;
                        }
                        else if (userInput == "1") {
                            while (true) {
                                //badInput = false;
                                cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s radius: "
                                     << planetVector.at(stoi(planetInput) - 1).getRadius() << " km" << endl;
                                cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                userInputChar = userInputPrintSelection();
                                cout << endl;
                                /*
                                while (cin.fail()) {
                                    cin.clear(); // clear bad input flag
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    badInput = true; // set bad input to true
                                }
                                if (badInput) { // go back to the beginning of the current while loop
                                    continue;
                                } */

                                if (tolower(userInputChar) == 'y') {
                                    fileOut << "Radius" << endl;
                                    fileOut << planetVector.at(stoi(planetInput) - 1).getRadius() << " km" << endl;
                                    fileOut << "----------------------" << endl;
                                    cout << "Successfully outputted information!" << endl;
                                    break;
                                }
                                else if (tolower(userInputChar) == 'n') {
                                    cout << "Returning to previous menu..." << endl;
                                    break;
                                }
                                else {
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    continue;
                                }
                            }
                        }
                        else if (userInput == "2") {
                            while (true) {
                                cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s mass: "
                                     << planetVector.at(stoi(planetInput) - 1).getMass() << " 10^24 kg" << endl;
                                cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                userInputChar = userInputPrintSelection();
                                cout << endl;

                                if (tolower(userInputChar) == 'y') {
                                    fileOut << "Mass" << endl;
                                    fileOut << planetVector.at(stoi(planetInput) - 1).getMass() << " 10^24 kg" << endl;
                                    fileOut << "----------------------" << endl;
                                    cout << "Successfully outputted information!" << endl;
                                    break;
                                }
                                else if (tolower(userInputChar) == 'n') {
                                    cout << "Returning to previous menu..." << endl;
                                    break;
                                }
                                else {
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    continue;
                                }
                            }
                        }
                        else if (userInput == "3") {
                            while (true) {
                                cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s density: "
                                     << planetVector.at(stoi(planetInput) - 1).getDensity() << " kg/m^3" << endl;
                                cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                userInputChar = userInputPrintSelection();
                                cout << endl;

                                if (tolower(userInputChar) == 'y') {
                                    fileOut << "Density" << endl;
                                    fileOut << planetVector.at(stoi(planetInput) - 1).getDensity() << " kg/m^3" << endl;
                                    fileOut << "----------------------" << endl;
                                    cout << "Successfully outputted information!" << endl;
                                    break;
                                }
                                else if (tolower(userInputChar) == 'n') {
                                    cout << "Returning to previous menu..." << endl;
                                    break;
                                }
                                else {
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    continue;
                                }
                            }
                        }
                        else if (userInput == "4") {
                            while (true) {
                                cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s surface gravity: "
                                     << planetVector.at(stoi(planetInput) - 1).getSurfaceGravity() << " m/s^2" << endl;
                                cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                userInputChar = userInputPrintSelection();
                                cout << endl;

                                if (tolower(userInputChar) == 'y') {
                                    fileOut << "Surface Gravity" << endl;
                                    fileOut << planetVector.at(stoi(planetInput) - 1).getSurfaceGravity() << " m/s^2" << endl;
                                    fileOut << "----------------------" << endl;
                                    cout << "Successfully outputted information!" << endl;
                                    break;
                                }
                                else if (tolower(userInputChar) == 'n') {
                                    cout << "Returning to previous menu..." << endl;
                                    break;
                                }
                                else {
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    continue;
                                }
                            }
                        }
                        else if (userInput == "5") {
                            while (true) {
                                cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s length of day: "
                                     << planetVector.at(stoi(planetInput) - 1).getDayLength() << " hrs" << endl;
                                cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                userInputChar = userInputPrintSelection();
                                cout << endl;

                                if (tolower(userInputChar) == 'y') {
                                    fileOut << "Length of Day" << endl;
                                    fileOut << planetVector.at(stoi(planetInput) - 1).getDayLength() << " hrs" << endl;
                                    fileOut << "----------------------" << endl;
                                    cout << "Successfully outputted information!" << endl;
                                    break;
                                }
                                else if (tolower(userInputChar) == 'n') {
                                    cout << "Returning to previous menu..." << endl;
                                    break;
                                }
                                else {
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    continue;
                                }
                            }
                        }
                        else if (userInput == "6") {
                            while (true) {
                                cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s perihelion: "
                                     << planetVector.at(stoi(planetInput) - 1).getPerihelion() << " 10^6 km" << endl;
                                cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                userInputChar = userInputPrintSelection();
                                cout << endl;

                                if (tolower(userInputChar) == 'y') {
                                    fileOut << "Perihelion" << endl;
                                    fileOut << planetVector.at(stoi(planetInput) - 1).getPerihelion() << " 10^6 km" << endl;
                                    fileOut << "----------------------" << endl;
                                    cout << "Successfully outputted information!" << endl;
                                    break;
                                }
                                else if (tolower(userInputChar) == 'n') {
                                    cout << "Returning to previous menu..." << endl;
                                    break;
                                }
                                else {
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    continue;
                                }
                            }
                        }
                        else if (userInput == "7") {
                            while (true) {
                                cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s aphelion: "
                                     << planetVector.at(stoi(planetInput) - 1).getAphelion() << " 10^6 km" << endl;
                                cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                userInputChar = userInputPrintSelection();
                                cout << endl;

                                if (tolower(userInputChar) == 'y') {
                                    fileOut << "Aphelion" << endl;
                                    fileOut << planetVector.at(stoi(planetInput) - 1).getAphelion() << " 10^6 km" << endl;
                                    fileOut << "----------------------" << endl;
                                    cout << "Successfully outputted information!" << endl;
                                    break;
                                }
                                else if (tolower(userInputChar) == 'n') {
                                    cout << "Returning to previous menu..." << endl;
                                    break;
                                }
                                else {
                                    cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                    continue;
                                }
                            }
                        }
                        else if (userInput == "8") {
                            planetVector.at(stoi(planetInput) - 1).displayOptions2();
                            userInput = userInputMenuSelection();
                            if (userInput == "9") {
                                cout << "Please enter a valid integer." << endl;
                                cout << endl;
                                continue;
                            }
                            else if (userInput == "0") {
                                chosePlanet = false;
                            }
                            else if (userInput == "1") {
                                while (true) {
                                    cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s orbital period: "
                                         << planetVector.at(stoi(planetInput) - 1).getOrbitalPeriod() << " days" << endl;
                                    cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                    userInputChar = userInputPrintSelection();
                                    cout << endl;

                                    if (tolower(userInputChar) == 'y') {
                                        fileOut << "Orbital Period" << endl;
                                        fileOut << planetVector.at(stoi(planetInput) - 1).getOrbitalPeriod() << " days" << endl;
                                        fileOut << "----------------------" << endl;
                                        cout << "Successfully outputted information!" << endl;
                                        break;
                                    }
                                    else if (tolower(userInputChar) == 'n') {
                                        cout << "Returning to previous menu..." << endl;
                                        break;
                                    }
                                    else {
                                        cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                        continue;
                                    }
                                }
                            }
                            else if (userInput == "2") {
                                while (true) {
                                    cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s number of satellites: "
                                         << planetVector.at(stoi(planetInput) - 1).getNumSatellites() << " satellites" << endl;
                                    cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                    userInputChar = userInputPrintSelection();
                                    cout << endl;

                                    if (tolower(userInputChar) == 'y') {
                                        fileOut << "Number of Satellites" << endl;
                                        fileOut << planetVector.at(stoi(planetInput) - 1).getNumSatellites() << " satellites" << endl;
                                        fileOut << "----------------------" << endl;
                                        cout << "Successfully outputted information!" << endl;
                                        break;
                                    }
                                    else if (tolower(userInputChar) == 'n') {
                                        cout << "Returning to previous menu..." << endl;
                                        break;
                                    }
                                    else {
                                        cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                        continue;
                                    }
                                }
                            }
                            else if (userInput == "3") {
                                while (true) {
                                    cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s system position: "
                                         << planetVector.at(stoi(planetInput) - 1).getSystemPosition() << " in the solar system"
                                         << endl;
                                    cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                    userInputChar = userInputPrintSelection();
                                    cout << endl;

                                    if (tolower(userInputChar) == 'y') {
                                        fileOut << "Position in the Solar System" << endl;
                                        fileOut << planetVector.at(stoi(planetInput) - 1).getSystemPosition() <<
                                                " in the solar system" << endl;
                                        fileOut << "----------------------" << endl;
                                        cout << "Successfully outputted information!" << endl;
                                        break;
                                    }
                                    else if (tolower(userInputChar) == 'n') {
                                        cout << "Returning to previous menu..." << endl;
                                        break;
                                    }
                                    else {
                                        cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                        continue;
                                    }
                                }
                            }
                            else if (userInput == "4") {
                                while (true) {
                                    cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s ring status: ";
                                    if (planetVector.at(stoi(planetInput) - 1).getHasRings()) {
                                        cout << "rings present." << endl;
                                    }
                                    else {
                                        cout << "no rings present." << endl;
                                    }
                                    cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                    userInputChar = userInputPrintSelection();
                                    cout << endl;

                                    if (tolower(userInputChar) == 'y') {
                                        if (planetVector.at(stoi(planetInput) - 1).getHasRings()) {
                                            fileOut << "Ring Status" << endl;
                                            fileOut << planetVector.at(stoi(planetInput) - 1).getName() << " has rings" << endl;
                                            fileOut << "----------------------" << endl;
                                            cout << "Successfully outputted information!" << endl;
                                            break;
                                        }
                                        else {
                                            fileOut << "Ring Status" << endl;
                                            fileOut << planetVector.at(stoi(planetInput) - 1).getName() << " has no rings" << endl;
                                            fileOut << "----------------------" << endl;
                                            cout << "Successfully outputted information!" << endl;
                                            break;
                                        }
                                    }
                                    else if (tolower(userInputChar) == 'n') {
                                        cout << "Returning to previous menu..." << endl;
                                        break;
                                    }
                                    else {
                                        cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                        continue;
                                    }
                                }
                            }
                            else if (userInput == "5") {
                                while (true) {
                                    cout << planetVector.at(stoi(planetInput) - 1).getName() << "'s atmosphere status: ";
                                    if (planetVector.at(stoi(planetInput) - 1).getAtmosphere().getHasAtmosphere()) {
                                        cout << "present." << endl;
                                        cout << "Atmosphere composition:" << endl;
                                        cout << "Element 1: " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getElement1()
                                             << " at " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getPercentElement1()
                                             << "%" << endl;
                                        cout << "Element 2: " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getElement2()
                                             << " at " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getPercentElement2()
                                             << "%" << endl;
                                        cout << "Element 3: " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getElement3()
                                             << " at " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getPercentElement3()
                                             << "%" << endl;
                                    }
                                    else {
                                        cout << "no atmosphere." << endl;
                                    }
                                    cout << "Would you like to output this statistic to a file? (y/n)" << endl;
                                    userInputChar = userInputPrintSelection();
                                    cout << endl;

                                    if (tolower(userInputChar) == 'y') {
                                        if (planetVector.at(stoi(planetInput) - 1).getAtmosphere().getHasAtmosphere()) {
                                            fileOut << planetVector.at(stoi(planetInput) - 1).getName() << " has an atmosphere"
                                                    << endl;
                                            fileOut << "Atmosphere composition:" << endl;
                                            fileOut << "Element 1: " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getElement1()
                                                    << " at " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getPercentElement1()
                                                    << "%" << endl;
                                            fileOut << "Element 2: " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getElement2()
                                                    << " at " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getPercentElement2()
                                                    << "%" << endl;
                                            fileOut << "Element 3: " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getElement3()
                                                    << " at " << planetVector.at(stoi(planetInput) - 1).getAtmosphere().getPercentElement3()
                                                    << "%" << endl;
                                            fileOut << "----------------------" << endl;
                                            cout << "Successfully outputted information!" << endl;
                                            break;
                                        }
                                        else {
                                            fileOut << planetVector.at(stoi(planetInput) - 1).getName() << " has no atmosphere"
                                                    << endl;
                                            fileOut << "----------------------" << endl;
                                            cout << "Successfully outputted information!" << endl;
                                            break;
                                        }
                                    }
                                    else if (tolower(userInputChar) == 'n') {
                                        cout << "Returning to previous menu..." << endl;
                                        break;
                                    }
                                    else {
                                        cout << "Invalid input; please re-enter a valid character corresponding to an option." << endl;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    cout << "Returning to the previous menu..." << endl;
                }
            }
            cout << "Returning to the previous menu..." << endl;
        }

        else if (userInput == "2") {
            optionTwo = true;
            while (optionTwo) {
                cout << "Which planet would you like to see a picture of?" << endl;
                for (i = 0; i < planetVector.size(); ++i) {
                    if (i == planetVector.size() - 1) {
                        cout << "(" << planetVector.at(i).getSystemPosition()
                             << ") " << planetVector.at(i).getName() << endl;
                        cout << endl;
                    }
                    else {
                        cout << "(" << planetVector.at(i).getSystemPosition()
                             << ") " << planetVector.at(i).getName() << ", ";
                    }
                }
                cout << "You may enter 0 at any time to exit and return to the previous menu." << endl;
                cout << "Enter the corresponding integer of the planet you would like to view: ";
                planetInput = userInputMenuSelection();
                if (planetInput == "9") {
                    cout << "Please enter a valid integer." << endl;
                    cout << endl;
                    continue;
                }

                else if (planetInput == "0") {
                    optionTwo = false;
                }
                else if (stoi(planetInput) > 0 && stoi(planetInput) <= planetVector.size()) {
                    cout << "Here is a photo of " << planetVector.at(stoi(planetInput) - 1).getName() << "." << endl;
                    cout << endl;
                    // create a window of size 640x640 titled "Planet Picture"
                    RenderWindow window( VideoMode(640, 640), "Planet Photo");
                    Texture planetPhoto;
                    if (stoi(planetInput) == 1) {
                        if (!planetPhoto.loadFromFile("data/mercury.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }
                    else if (stoi(planetInput) == 2) {
                        if (!planetPhoto.loadFromFile("data/venus.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }
                    else if (stoi(planetInput) == 3) {
                        if (!planetPhoto.loadFromFile("data/earth.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }
                    else if (stoi(planetInput) == 4) {
                        if (!planetPhoto.loadFromFile("data/mars.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }
                    else if (stoi(planetInput) == 5) {
                        if (!planetPhoto.loadFromFile("data/jupiter.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }
                    else if (stoi(planetInput) == 6) {
                        if (!planetPhoto.loadFromFile("data/saturn.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }
                    else if (stoi(planetInput) == 7) {
                        if (!planetPhoto.loadFromFile("data/uranus.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }
                    else if (stoi(planetInput) == 8) {
                        if (!planetPhoto.loadFromFile("data/neptune.jpg")) {
                            cerr << "Could not load the planet photo." << endl;
                            return -1;
                        }
                    }

                    while( window.isOpen() ) {
                        window.clear( Color::Black ); // clear the contents of the old frame by setting window to black

                        Sprite planetSprite;
                        planetSprite.setTexture(planetPhoto);
                        if (stoi(planetInput) == 1) {
                            planetSprite.setPosition(100, 100);
                            planetSprite.setScale(0.2, 0.2);
                        }
                        else if (stoi(planetInput) == 2) {
                            planetSprite.setPosition(100, 100);
                            planetSprite.setScale(0.1, 0.1);
                        }
                        else if (stoi(planetInput) == 3) {
                            planetSprite.setPosition(120, 100);
                            planetSprite.setScale(0.4, 0.4);
                        }
                        else if (stoi(planetInput) == 4) {
                            planetSprite.setPosition(100, 100);
                            planetSprite.setScale(0.1, 0.1);
                        }
                        else if (stoi(planetInput) == 5) {
                            planetSprite.setPosition(100, 100);
                            planetSprite.setScale(0.4, 0.4);
                        }
                        else if (stoi(planetInput) == 6) {
                            planetSprite.setPosition(100, 100);
                            planetSprite.setScale(0.4, 0.4);
                        }
                        else if (stoi(planetInput) == 7) {
                            planetSprite.setPosition(100, 100);
                            planetSprite.setScale(0.25, 0.25);
                        }
                        else if (stoi(planetInput) == 8) {
                            planetSprite.setPosition(100, 100);
                            planetSprite.setScale(0.2, 0.2);
                        }
                        window.draw(planetSprite); // draw the planet

                        window.display(); // display the window

                        //****************************************
                        // HANDLE EVENTS BELOW HERE
                        //****************************************

                        Event event;
                        while( window.pollEvent(event) ) {      // ask the window if any events occurred
                            if( event.type == Event::Closed ) { // if event type is a closed event
                                // i.e. they clicked the X on the window
                                window.close();                 // then close our window
                            }
                        }
                    }
                }
            }
        }
        else if (userInput == "0") {
            endProgram = true; // ends the while loop
            fileOut.close(); // closes the planetinformationoutput.txt file
            cout << "Thank you for visiting the Solar System Planet Library!" << endl;
            cout << "Safe travels!" << endl;
        }
    }

    return 0;
}