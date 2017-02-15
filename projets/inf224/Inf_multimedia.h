#ifndef INF_MULTIMEDIA_H
#define INF_MULTIMEDIA_H
#include<iostream>
#include<string>

using namespace std;

class Inf_multimedia{

private:

    string media;
    string pathMedia;

public:

    Inf_multimedia();

    Inf_multimedia(string media, string pathMedia);

    virtual string getMedia() const;

    virtual void setMedia(string media);

    virtual string getPathMedia() const;

    virtual void setPathMedia(string pathMedia);

    virtual void display(ostream& out) const;

    virtual void play() const = 0;

    virtual ~Inf_multimedia();

};

#endif // INF_MULTIMEDIA_H
