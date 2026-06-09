//
// Created by ajuli on 04/06/2026.
//

#include "Video.h"
using namespace std;
#include <iostream>

Video::Video() {
    length = 0;
    genre = "NA";
    name = "NA";
    id = "NA";
    rating = 0.0;
}

Video::Video(std::string id, std::string name, std::string genre, int length, float rating) {
    this -> length = length;
    this -> name = name;
    this -> genre = genre;
    this -> id = id;
    this -> rating = rating;
}

Video::~Video() {}

void Video::setId(string id) {
    this -> id = id;
}

string Video::getId() {
    return this -> id;
}

void Video::setName(string name) {
    this -> name = name;
}

string Video::getName() {
    return this -> name;
}

void Video::setGenre(string genre) {
    this -> genre = genre;
}

string Video::getGenre() {
    return this -> genre;
}

void Video::setLength(int length) {
    this -> length = length;
}

int Video::getLength() {
    return this -> length;
}

void Video::setRating(float rating) {
    this -> rating = rating;
}

float Video::getRating() {
    return this -> rating;
}

