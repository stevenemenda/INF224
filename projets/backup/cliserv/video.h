#ifndef VIDEO_H
#define VIDEO_H

#include"Inf_multimedia.h"
#include<string>

class Video : public Inf_multimedia
{
private:
    int duration;

public:

//    Video(int duration):Inf_multimedia(){
//        this->duration = duration;

//    }

    Video(string media = "StarWars.mp4", string pathMedia = "/cal/homes/lguo/Downloads/INF224/projets/",
          int duration = 0):Inf_multimedia( media, pathMedia){

        this->duration = duration;

    }

    virtual int getDuration() const;

    virtual void setDuration(int duration);

    virtual void display(ostream &out ) const;

    virtual void play() const;

    virtual ~Video();
};


#endif // VIDEO_H
