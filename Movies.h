//
// Created by ajuli on 04/06/2026.
//
#pragma once
#ifndef INTEGRATIVE_PROJECT_MOVIES_H
#define INTEGRATIVE_PROJECT_MOVIES_H
#include "Video.h"
#define MOVIES_SIZE 4

class Movies : public Video{
public:
    void displayInfo() override;
    Movies();
    Movies(std::string id, std::string name, std::string genre, int length, float rating);
};

bool loadMovies(std::string fileName, Movies *moviesArray, unsigned int arraySize);
int countMoviesLines(std::string fileName);

#endif //INTEGRATIVE_PROJECT_MOVIES_H