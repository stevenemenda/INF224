#ifndef MANAGEMEDIA_H
#define MANAGEMEDIA_H

#include"Inf_multimedia.h"
#include<memory>
#include"film.h"
#include"video.h"
#include"inf_photo.h"
#include"mediagroup.h"
#include<map>
#include<vector>
using namespace std;

using mediaPtr = std::shared_ptr<Inf_multimedia>;
using filmPtr = std::shared_ptr<Film>;
using videoPtr = std::shared_ptr<Video>;
using photoPtr = std::shared_ptr<Inf_Photo>;
using mGroupPtr = std::shared_ptr<MediaGroup>;

class ManageMedia
{
private:
    string listMedia = "listMedia.txt";
    string listGroup = "listGroup.txt";
    map<string, mediaPtr> mediaList;
    map<string, mGroupPtr> mediaGroup;
public:

    ManageMedia();

// what should we do, if there are some medias having the same name?
//    virtual void addMedia(mediaPtr media);
    virtual videoPtr createVideo(string media = "StarWars2.mp4", string pathMedia = "/cal/homes/lguo/Downloads/INF224/projets/",
                                 int duration = 0);
    virtual filmPtr createFilm(string media = "StarWars2.mp4", string pathMedia = "/cal/homes/lguo/Downloads/INF224/projets/",
                               int duration = 0, intPtr table = 0, int nChapitre = 0);
    virtual photoPtr createPhoto(string media = "StarWar.jpeg", string pathMedia = "/cal/homes/lguo/Downloads/INF224/projets/",
                                 double longitude = 0, double latitude = 0);

    virtual mGroupPtr createMGroup(string groupName);
    virtual void readFile(fstream & fs);
    virtual void reCreObj(vector<string>);
    virtual map<string,mediaPtr>::const_iterator findMedia(string mediaName) const;
    virtual map<string,mGroupPtr>::const_iterator findMGroup(string mGroupName) const;
    // check if it == mediaGroup->end()
    virtual bool endMGroup(const map<string, mGroupPtr>::const_iterator& it) const;
    // check if it == mediaList->end()
    virtual bool endMList(const map<string, mediaPtr>::const_iterator& it) const;
    virtual void play(string mediaName) const;
    virtual ~ManageMedia();

};

#endif // MANAGEMEDIA_H
