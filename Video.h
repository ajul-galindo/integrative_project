//
// Created by ajuli on 04/06/2026.
//

#ifndef INTEGRATIVE_PROJECT_VIDEO_H
#define INTEGRATIVE_PROJECT_VIDEO_H
#include <string>

class Video {
protected:
    std::string id;
    std::string name;
    std::string genre;
    int length;
    float rating;

public:
    Video();
    Video(std::string id, std::string name, std::string genre, int length, float rating);
    virtual void displayInfo() = 0;
    virtual ~Video();

    void setId(std::string id);
    std::string getId();

    void setName(std::string name);
    std::string getName();

    void setGenre(std::string genre);
    std::string getGenre();

    void setLength(int length);
    int getLength();

    void setRating(float rating);
    float getRating();
};



#endif //INTEGRATIVE_PROJECT_VIDEO_H