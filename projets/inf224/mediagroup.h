#ifndef MEDIAGROUP_H
#define MEDIAGROUP_H
#include<iostream>
#include<string>
#include<list>
#include"Inf_multimedia.h"
#include<memory>
using namespace std;

using mediaPtr = shared_ptr<Inf_multimedia>;
//template <typename T>

//class MediaGroup : public list<T>
class MediaGroup : public list<mediaPtr>
{
private:
    string groupName = "";
public:
    MediaGroup(string groupName) : list<mediaPtr>::list(){
        this->groupName = groupName;

    }

    virtual string getGroupName() const{
        return this->groupName;
    }

    virtual void setGroupName(const string &groupName){
        this->groupName = groupName;
    }

    virtual void display(ostream & out) const{
        cout << "The name of this media group is: " << this->groupName << ". ";
        cout << "In this group: ";
        if(this->size() > 0){
//            for(typename list<T>::const_iterator i = this->begin(); i != this->end(); i++){
            for(list<mediaPtr>::const_iterator i = this->begin(); i != this->end(); i++){
                 (*i)->display(out);
            }
        }else{
            cout << "Empty!" << ". ";
        }

    }

    virtual ~MediaGroup(){

    }
};

#endif // MEDIAGROUP_H
