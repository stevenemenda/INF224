#ifndef INF_PHOTO_H
#define INF_PHOTO_H
#include"Inf_multimedia.h"

using namespace std;

class Inf_Photo : public Inf_multimedia
{

private:
    double longitude;
    double latitude;
    string className = "Photo";
public:
    Inf_Photo():Inf_multimedia(){
        this->longitude = 0;
        this->latitude = 0;

    }

    Inf_Photo(string media = "StarWar.jpeg", string pathMedia = "/cal/homes/lguo/Downloads/INF224/projets/",
          double longitude = 0, double latitude = 0):Inf_multimedia( media, pathMedia){

        this->longitude = longitude;
        this->latitude = latitude;

    }
    virtual string getClassName() const;

    virtual double getLongitude() const;

    virtual void setLongitude(double value);

    virtual double getLatitude() const;

    virtual void setLatitude(double value);

    virtual void display(ostream &out ) const;
    virtual void play() const;
    virtual ~Inf_Photo();

};

#endif // INF_PHOTO_H
