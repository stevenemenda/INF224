
#include "managemedia.h"
#include <fstream>
#include<vector>
#include<iostream>
using namespace std;

ManageMedia::ManageMedia()
{
    mediaGroup.clear();
    mediaList.clear();
    fstream fin;
    fin.open(listMedia,ios_base::in);
    readFile(fin);
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

void ManageMedia::readFile(fstream &fs)
{
    string data = fs.read();
    stringstream ss;
    ss.clear();
    ss.str("");
    string param = "";
    string delim = ";";
    ss.str(data);
    vector<string> params;
    params.clear();
    while(getline(ss,param,delim)){
        if(param.find("className:")){
            if(params.size()){
                reCreObj(params);
            }
            params.clear();
        }
        params.push_back(param);
    }
}

void ManageMedia::reCreObj(vector<string> params)
{
    vector<string> info;

    // parametres

    // mediaName: pathName: Duration: nChapitre: duration: latitude: longitude:

    string className = "";
    string mediaName = "StarWar.jpeg";
    string pathName = "/cal/homes/lguo/Downloads/INF224/projets/";

    double longitude = 0;
    double latitude = 0;

    int duration;
    intPtr table;
    vector<int> vtable;
    int nChapitre;

    stringstream ss;
    string param = "";
    string delim = ":";

    for(int i; i < params.size(); i++){
        ss.clear();
        ss.str(params[i]);
        while(getline(ss, param, delim)){

            info.push_back(param);

        }

        if(info[0] == "mediaName"){
            mediaName = info[1];
        }else if(info[0] == "pathName"){
            pathName = info[1];
        }else if(info[0] == "Duration"){
            duration = info[1];
        }else if(info[0] == "duration"){
            vtable.push_back(info[1]);
        }else if(info[0] == "nChapitre"){
            nChapitre = info[1];
        }else if(info[0] == "latitude"){
            latitude = info[1];
        }else if(info[0] == "longitude"){
            longitude = info[1];
        }else{
            cerr << "no match parametre!" << endl;
        }

        info.clear();
    }

    if(className == "Video"){
        listMedia[mediaName] = createVideo(mediaName, pathName, duration);
    }else if(className == "Film"){
        if(vtable.size()){
            table.reset(new int[vtable.size()]);
            for(int i = 0; i < vtable.size(); i++){
                table.get()[i] = vtable[i];
            }
        }else{
            table.reset(nullptr);
        }
        listMedia[mediaName] = createFilm(mediaName, pathName, duration, table, nChapitre);
    }else if(className == "Photo"){
        listMedia[mediaName] = createPhoto(mediaName, pathName, longitude, latitude);
    }else{
       cerr << "class name n'exite pas!" << endl;
    }

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
