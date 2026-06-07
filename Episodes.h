//
// Created by ajuli on 04/06/2026.
//

#ifndef INTEGRATIVE_PROJECT_EPISODES_H
#define INTEGRATIVE_PROJECT_EPISODES_H
#include "Video.h"
#define EPISODES_SIZE 6

class Episodes : public Video{
private:
    std::string title;
    int season;
public:
    Episodes();
    Episodes(std::string id, std::string name, std::string genre, float length, float rating, std::string title, int season);

    void setTitle(std::string title);
    std::string getTitle();

    void setSeason(int season);
    int getSeason();

    void displayInfo() override;
};

bool loadEpisodes(std::string fileName, Episodes *episodeArray, unsigned int arraySize);
int countEpisodesLines(std::string fileName);

#endif //INTEGRATIVE_PROJECT_EPISODES_H