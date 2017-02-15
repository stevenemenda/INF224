#ifndef COMMERESOURCE_H
#define COMMERESOURCE_H

#include<iostream>
using namespace std;

template <typename T>
struct array_deleter
{
  void operator ()(T* p){
//      cout << "delete array of integer!" << endl;
      delete [] p;
  }   
};

#endif // COMMERESOURCE_H
