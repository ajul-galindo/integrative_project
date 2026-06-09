#include <iostream>
using namespace std;
#include "Episodes.h"
#include "Movies.h"
#include <typeinfo>
#define MOVIES_FILE "movies.csv"
#define SERIES_FILE "seriesfile.csv"

int main() {
    Video **videosArray = nullptr;
    Movies *moviesArray = nullptr;
    Episodes *episodesArray = nullptr;
    int moviesSize = 0;
    int episodesSize = 0;
    int totalSize = 0;
    int count = 0;
    int decision;

    moviesSize = countMoviesLines(MOVIES_FILE);
    episodesSize = countEpisodesLines(SERIES_FILE);

    do {
        cout<<"Menu"<<endl;
        cout<<"1. Load files"<<endl;
        cout<<"2. Show data"<<endl;
        cout<<"3. Show videos with a certain rating/genre"<<endl;
        cout<<"4. Show episodes from a certain series with a certain rating"<<endl;
        cout<<"5. Show movies with a certain rating"<<endl;
        cout<<"6. Rate a video"<<endl;
        cout<<"0. Exit"<<endl;

        cin>>decision;

        switch (decision) {
            case 1:

                if (videosArray) {
                    delete [] moviesArray;
                    delete [] episodesArray;
                    delete [] moviesArray;
                    moviesArray = nullptr;
                    episodesArray = nullptr;
                    moviesArray = nullptr;
                }

                if (moviesSize == -1 && episodesSize == -1) {
                    cerr<<"Files could not be loaded"<<endl;
                    return 0;
                }else {
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

                break;
            case 2:
                for (unsigned int i = 0; i < totalSize; i++) {
                    if (videosArray[i]) {
                        videosArray[i] -> displayInfo();
                    }
                }
                break;
            case 3: {
                float findRating;
                string findGenre;
                string option;
                cout<<"Choose an option (g for genre / r for rating)"<<endl;
                cin>>option;
                if (option == "g" || option == "G") {
                    cout<<"Enter a genre: "<<endl;
                    cin>>findGenre;

                    for (unsigned int i = 0; i < totalSize; i++) {
                        if (videosArray[i]) {  //revisar que si haya algo ahí
                            if (videosArray[i] -> getGenre() == findGenre) {
                                videosArray[i] -> displayInfo();
                            }
                        }
                    }

                }
                if (option == "r" || option == "R") {
                    cout<<"Enter a rating (from 1 to 5): "<<endl;
                    cin>>findRating;
                    for (unsigned int i = 0; i < totalSize; i++) {
                        if (videosArray[i]) {  //revisar que si haya algo ahí
                            if (videosArray[i] -> averageRating() == findRating) {
                                videosArray[i] -> displayInfo();
                            }
                        }
                    }
                }
                break;
            }
            case 4: {
                string Series;
                float epRating;
                cin.ignore();
                cout<<"Enter the series name: "<<endl;
                getline(cin, Series);
                cout<<"Enter the rating"<<endl;
                cin>>epRating;
                for (unsigned int i = 0; i < totalSize; i++) {
                    if (videosArray[i]) {
                        if (typeid(*videosArray[i]) == typeid(Episodes)) {
                            if (videosArray[i] -> getName() == Series && videosArray[i] -> averageRating() == epRating) {
                                videosArray[i] -> displayInfo();
                            }
                        }
                    }
                }

                break;
            }
            case 5:
                break;
            case 6:
                break;
        }
    }while (decision != 0);

    for (unsigned int i = 0; i < totalSize; i++) {
        delete videosArray[i];
    }

    delete [] moviesArray;
    moviesArray = nullptr;
    delete [] episodesArray;
    episodesArray = nullptr;
    delete[] videosArray;
    videosArray = nullptr;
    return 0;
}