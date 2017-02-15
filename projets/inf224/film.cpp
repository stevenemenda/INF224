#include "film.h"



void Film::display(ostream & out) const
{
    Video::display(out);

    out << "The numbre of chapites of " << this->getMedia() << " is: " << this->nChapitre << ". ";

    for(int i = 0; i < this->nChapitre; i++){
        out << "The duration of Chapitre " << i + 1 << " is: " << this->table.get()[i]<< ". ";
    }

}


void Film::setTable(intPtr table, int nChapitre)
{
    this->nChapitre = nChapitre;
    if(this->nChapitre > 0){
        this->table.reset(new int[this->nChapitre],[](int * p){ delete [] p;});
        for(int i = 0; i < this->nChapitre; i++){
            this->table.get()[i] = table.get()[i];
        }
    }else{
        this->table = 0;
        this->nChapitre = 0;
    }
}

Film::~Film()
{

//    we don't have to make sure that this->table is null or not!
//      delete [] this->table;
//

    cout << "The Film instance of " << this->getMedia() <<" is destroyed!" << endl;

}

Film& Film::operator =(const Film & film)
{
    Video::operator = (film);

    setTable(film.getTable(), film.getNChapitre());

    return *this;
}

int Film::getNChapitre() const
{
    return this->nChapitre;
}

const intPtr Film::getTable() const
{
//    int * table = new int[this->nChapitre];
//    for(int i = 0; i < this->nChapitre; i++){
//        table[i] = this->table[i];
//    }
    return this->table;

}
