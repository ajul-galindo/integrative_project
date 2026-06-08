//
// Created by ajuli on 04/06/2026.
//

#include "Movies.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

Movies::Movies() : Video() {
}

Movies::Movies(string id, string name, string genre, int length, float rating):Video(id,name,genre,length) {
}

void Movies::displayInfo() {
    cout<<"ID: "<<id<<" Name: "<<name<<" Length: "<<length<<" Genre: "<<genre;
    if (votes>0) {
        cout<<" Rating: "<< averageRating()<<endl;
    }else {
        cout<<" No rating"<<endl;
    }
}

bool loadMovies(string fileName, Movies *movieArray, unsigned int arraySize) {
    ifstream		file(fileName);
    string			line;
    unsigned int	size = 0;

    if (!file.is_open()) {
        cerr << "Could not open file: " << fileName << endl;
        return false;
    }

    // Saltar el encabezado, que pasa si no hay encabezado? se salta la primera linea?
    if(!getline(file, line)) {
        cerr << "File does not have header" << endl;
        file.close();
        return false;
    }

    cout << "Loading file: " << fileName << endl;

    while (getline(file, line)) {
        Movies			newMovie;
        stringstream	ss(line);
        string			cell;
        int 			campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if(!cell.length())
                errores++;

            switch(campo) {
                case 0:
                    newMovie.setId(cell);
                    break;
                case 1:
                    newMovie.setName(cell);
                    break;
                case 2:
                    newMovie.setLength(stoi(cell));
                    break;
                case 3:
                    newMovie.setGenre(cell);
                    break;
                default:
                    errores++;
                    break;
            }
            campo++;
        }


        if (errores || campo != MOVIES_SIZE) {
            cerr << "Error en la line:\n" << line << endl;
            file.close();
            return false;
        }

        if(size < arraySize) {
            movieArray[size] = newMovie;
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

int countMoviesLines(string fileName) {
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
