#include <iostream>
using namespace std;
#include "Episodes.h"
#include "Movies.h"
#define MOVIES_FILE "movies.csv"
#define SERIES_FILE "seriesfile.csv"

//hacer dos archivos y cargarlos al mismo arreglo

int main() {
    Video **videosArray = nullptr;
    Movies *moviesArray = nullptr;
    Episodes *episodesArray = nullptr;
    int moviesSize = 0;
    int episodesSize = 0;
    int totalSize = 0;
    int count = 0;

    moviesSize = countMoviesLines(MOVIES_FILE);
    episodesSize = countEpisodesLines(SERIES_FILE);

    if (moviesSize == -1 && episodesSize == -1) {
        cerr<<"Files could not be loaded"<<endl;
        return 0;
    } else {
        cout<<"Files can be loaded"<<endl;
    }

    totalSize = moviesSize + episodesSize;

    moviesArray = new(nothrow) Movies[moviesSize];
    episodesArray = new(nothrow) Episodes[episodesSize];

    if (!moviesArray || !episodesArray) {
        cout<<"Could not create arrays"<<endl;
        delete [] moviesArray;
        delete [] episodesArray;
        return 1;
    }

    if (!loadMovies("movies.csv", moviesArray, moviesSize)) {
        cerr<<"Could not load movies file"<<endl;
        delete[] moviesArray;
        return 1;
    }

    if (!loadEpisodes("seriesfile.csv", episodesArray, episodesSize)) { //
        cerr<<"Could not load episodes file"<<endl;
        delete [] episodesArray;
        return 1;
    }

    videosArray = new(nothrow) Video *[totalSize];
    if (!videosArray) {
        cout<<"Could not create videos array"<<endl;
        delete [] moviesArray;
        delete [] episodesArray;
        return 1;
    }

    for (unsigned int i = 0; i < totalSize; i++) {
        videosArray[i] = nullptr;
    }

    for (unsigned int i = 0; i < moviesSize; i++) {
        videosArray[count] = &moviesArray[i];
        count++;
    }

    for (unsigned int i = 0; i < episodesSize; i++) {
        videosArray[count] = &episodesArray[i];
        count++;
    }

    for (unsigned int i = 0; i < totalSize; i++) {
        if (videosArray[i]) {
            videosArray[i] -> displayInfo();
        }
    }

    delete [] moviesArray;
    moviesArray = nullptr;
    delete [] episodesArray;
    episodesArray = nullptr;
    delete[] videosArray;
    videosArray = nullptr;
    return 0;
}