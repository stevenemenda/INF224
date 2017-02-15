
#include "managemedia.h"


ManageMedia::ManageMedia()
{
    mediaGroup.clear();
    mediaList.clear();
}

videoPtr ManageMedia::createVideo(string media, string pathMedia, int duration)
{
    videoPtr tempPtr(new Video(media, pathMedia, duration));
    mediaList[media] = tempPtr;
    return tempPtr;
}

filmPtr ManageMedia::createFilm(string media, string pathMedia, int duration, intPtr table, int nChapitre)
{
    filmPtr tempPtr(new Film(media, pathMedia, duration, table, nChapitre));
    mediaList[media] = tempPtr;
    return tempPtr;
}

photoPtr ManageMedia::createPhoto(string media, string pathMedia, double longitude, double latitude)
{
    photoPtr tempPtr(new Inf_Photo(media, pathMedia, longitude, latitude));
    mediaList[media] = tempPtr;
    return tempPtr;
}

mGroupPtr ManageMedia::createMGroup(string groupName)
{
    mGroupPtr tempPtr(new MediaGroup(groupName));
    mediaGroup[groupName] = tempPtr;
    return tempPtr;
}


map<string,mediaPtr>::const_iterator ManageMedia::findMedia(string mediaName) const
{
    map<string, mediaPtr>::const_iterator i = this->mediaList.find(mediaName);
    if(i != mediaList.end()){
        (i->second)->display(cout);
    }else{
        cout << "No such media named " << mediaName << ". ";
    }
    return i;
}

map<string,mGroupPtr>::const_iterator ManageMedia::findMGroup(string mGroupName) const
{
//    map<string,mGroupPtr>::const_iterator i = this->mediaGroup.find(mGroupName);
    map<string,mGroupPtr>::const_iterator i = this->mediaGroup.begin();
    if(i != mediaGroup.end()){
        (i->second)->display(cout);


    }else{
        cout << "No such media group named " << mGroupName << ". ";
    }
    return i;
}

bool ManageMedia::endMGroup(const map<string,mGroupPtr>::const_iterator &it) const
{
    if(it == mediaGroup.end()){
        return true;
    }else{
        return false;
    }
}

bool ManageMedia::endMList(const map<string,mediaPtr>::const_iterator &it) const
{
    if(it == mediaList.end()){
        return true;
    }else{
        return false;
    }
}

void ManageMedia::play(string mediaName) const
{
    map<string,mediaPtr>::const_iterator i = findMedia(mediaName);
    if(i != mediaList.end()){
        (i->second)->play();

    }
}

ManageMedia::~ManageMedia()
{

}
