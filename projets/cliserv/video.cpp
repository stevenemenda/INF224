#include "video.h"


int Video::getDuration() const
{
    return duration;
}

void Video::setDuration(int duration)
{
    this->duration = duration;
}

void Video::display(ostream &out) const
{
    Inf_multimedia::display(out);
    out << "Duration:"<< this->duration << ";";

}

void Video::play() const
{
    string pathComplete = "mpv " + this->getPathMedia() + this->getMedia() + " &";
    const char * path = pathComplete.c_str();
    system(path);
}


Video::~Video()
{
    cout << "The Video instance of " << this->getMedia() <<" is destroyed!" << endl;
}
