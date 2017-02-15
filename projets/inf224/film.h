#ifndef FILE_H
#define FILE_H
#include<memory>
#include"video.h"
#include"inf_photo.h"
#include"CommeResource.h"

using namespace std;

using intPtr = shared_ptr<int>;

class Film : public Video
{
private:
    intPtr table;
    int nChapitre;
public:
    Film():Video(){
        this->table = 0;
        nChapitre = 0;

    }
    Film(Film & film):Video(film.getMedia(), film.getPathMedia(), film.getDuration()){

        setTable(table, nChapitre);
//        Inf_Photo* p = new Inf_Photo("StarWar.jpeg");
//        delete p;
    }
    Film(string media = "StarWars2.mp4", string pathMedia = "/cal/homes/lguo/Downloads/INF224/projets/",
         int duration = 0, intPtr table = 0, int nChapitre = 0):Video(media, pathMedia, duration){

        setTable(table, nChapitre);

    }
    
    virtual void display(ostream & out) const;
    
    virtual void setTable(intPtr table, int nChapitre);

    virtual int getNChapitre() const;

    virtual const intPtr getTable() const;

    virtual ~Film();
    virtual Film& operator = (const Film & film);
    
    
      
};

#endif // FILE_H
