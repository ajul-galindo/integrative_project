//
// Created by ajuli on 04/06/2026.
//

#include "Episodes.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

Episodes::Episodes() : Video(){
    this -> title = "NA";
    this -> season = 0;
}

Episodes::Episodes(string id, string name, string genre, float length, float rating, string title, int season):Video(id,name,genre,length, rating) {
    this -> title = title;
    this -> season = season;
}

void Episodes::setTitle(std::string title) {
    this -> title = title;
}

string Episodes::getTitle() {
    return this -> title;
}

void Episodes::setSeason(int season) {
    this -> season = season;
}

int Episodes::getSeason() {
    return this -> season;
}

void Episodes::displayInfo() {
    cout<<"ID: "<<id<<" Name: "<<name<<" Length: "<<length<<" Genre: "<<genre;
    if (rating) {
        cout<<" Rating: "<< getRating();
    }else {
        cout<<" No rating";
    }
    cout<<" Episode: "<<title<<" Season: "<<season<<endl;
}



bool loadEpisodes(string fileName, Episodes *episodeArray, unsigned int arraySize) {
    ifstream		file(fileName);
    string			line;
    unsigned int	size = 0;

    if (!file.is_open()) {
        cerr << "Could not open file: " << fileName << endl;
        return false;
    }

    // Saltar el encabezado //que pasa si no hay encabezado? se salta la primera linea?
    if(!getline(file, line)) {
        cerr << "File does not have header" << endl;
        file.close();
        return false;
    }

    cout << "Loading file: " << fileName << endl;

    while (getline(file, line)) {
        Episodes			newEpisode;
        stringstream	ss(line);
        string			cell;
        int 			campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if(!cell.length())
                errores++;

            switch(campo) {
                case 0:
                    newEpisode.setId(cell);
                    break;
                case 1:
                    newEpisode.setName(cell);
                    break;
                case 2:
                    newEpisode.setLength(stoi(cell));
                    break;
                case 3:
                    newEpisode.setGenre(cell);
                    break;
                case 4:
                    newEpisode.setTitle(cell);
                    break;
                case 5:
                    newEpisode.setSeason(stoi(cell));
                    break;
                default:
                    errores++;
                    break;
            }
            campo++;
        }

        if (errores || campo != EPISODES_SIZE) {
            cerr << "Error en la line:\n" << line << endl;
            file.close();
            return false;
        }

        if(size < arraySize) {
            episodeArray[size] = newEpisode;
            size++;
        }
        else {
            cerr << "Error, the array is too small" << endl;
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}

int countEpisodesLines(string fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error opening the file: " << fileName << endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        cerr << "File does not have header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas
    while(getline(file, line)) {
        lineCount++;
    }

    file.close();
    return lineCount;
}
