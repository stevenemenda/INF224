//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include <vector>
#include "../inf224/managemedia.h"

using namespace std;
using namespace cppu;

const int PORT = 50001;

class MyBase {
private:
    shared_ptr<ManageMedia> manageMedia;
    vector<string> params;
    char delim;

public:
    MyBase(){

        manageMedia.reset(new ManageMedia());
        params.clear();
        delim = ';';

    }

    string ansRequest(){
        string response = "";
        stringstream ss;
        ss.clear();
        ss.str("");
        int size = params.size();

        if(size > 0){// check request type.
            string funcName = params.at(0);
//                cerr << funcName << endl;
            if(funcName == "findMedia"){
                if(size >= 2){
                    string mediaName = params.at(1);
//                        cerr << mediaName << endl;
                    map<string,mediaPtr>::const_iterator it = manageMedia->findMedia(mediaName);
                    if(!manageMedia->endMList(it)){
                        it->second->display(ss);
                        response = ss.str();
                    }else{
                        response = "No such media named: " + mediaName + " !";
                    }
                }else{
                    response = "give the name of media!";
                }

            }else if(funcName == "findMGroup"){
                if(size >= 2){
                    string mGroupName = params.at(1);
                    map<string,mGroupPtr>::const_iterator it = manageMedia->findMGroup(mGroupName);
                    if(manageMedia->endMGroup(it)){
                        (it->second)->display(ss);
                        response = ss.str();
                    }else{
                        response = "No such media group named: " + mGroupName + " !";
                    }
                }else{
                    response = "Please give the name of media group!";
                }
            }else if(funcName == "createMGroup"){
                if(size >= 2){
                   string mGroupName = params.at(1);
                   manageMedia->createMGroup(mGroupName);
                   response = "Media group named " + mGroupName + " CREATE SUCCEEDED!";
                }else{
                    response = "Please give the name of media group you want to create!";
                }
            }else if(funcName == "createPhoto"){
                if(size >= 5){
                    photoPtr photo = manageMedia->createPhoto(params.at(1), params.at(2), stod(params.at(3)), stod(params.at(4)));
                    photo->display(ss);
                    response = ss.str() + " CREATE SUCCEEDED!";
                 }else{
                     response = "To use createPhoto service, FOUR parametres are needed!\
                             They are: the name of photo(string), the path(string), the longitude(double) and the latitude(double). Please try again!";
                 }


            }else if(funcName == "createVideo"){
                if(size >= 4){
                    videoPtr video = manageMedia->createVideo(params.at(1), params.at(2), stoi(params.at(3)));
                    video->display(ss);
                    response = ss.str() + " CREATE SUCCEEDED!";
                 }else{
                     response = "To use createVideo service, THREE parametres are needed!\
                             They are: the name of video(string), the path(string) and the duration(integer). Please try again!";
                 }


            }else if(funcName == "createFilm"){
                if(size >= 5){
                    vector<int> vtable;
                    vtable.clear();
                    intPtr table;
                    stringstream ssInts;
                    ssInts.str(params.at(4));
                    string each = "";
                    while(std::getline(ssInts, each, ',')) {
                        vtable.push_back(stoi(each));
                    }
                    if(vtable.size()){
                        table.reset(new int[vtable.size()]);
                        for(unsigned int i = 0; i < vtable.size(); i++){
                            table.get()[i] = vtable.at(i);
                        }
                    }
                    filmPtr film = manageMedia->createFilm(params.at(1), params.at(2), stoi(params.at(3)), table, vtable.size());
                    film->display(ss);
                    response = ss.str() + " CREATE SUCCEEDED!";


                 }else{
                     response = "To use createFilm service, FOUR parametres are needed!\
                             They are: the name of Film(string), the path(string) and the duration(integer) and a table of integer(int[]).\
                             Please try again!";
                 }


            }else if(funcName == "play"){
                if(size >= 2){
                    string mediaName = params.at(1);
//                        cerr << mediaName << endl;
                    map<string,mediaPtr>::const_iterator it = manageMedia->findMedia(mediaName);
                    if(!manageMedia->endMList(it)){
                        it->second->play();
                        response = "Media named " + mediaName + " is playing! Enjoy it!";
                    }else{
                        response = "No such media named: " + mediaName + " !";
                    }
                }else{
                    response = "Please give the name of media!";
                }
            }else{
                response = "Please give the right name of service you need!";

            }


        }else{

            response = "Nothing to do!";
        }

        return response;
    }

    // protocole:
    // séparer les paramètres dans la requête par ':';
    // on définit les significances de chaque paramètre:
    // nom_de_function:paramètre1:paramètre2...

  /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
   * puisse y accéder.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   *
   * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
   * un thread par client).
   *
   * Pour eviter les problemes de concurrence on peut créer un verrou en creant
   * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
   * si la fonction modifie les donnees.
   */
  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
      cerr << "\nRequest: '" << request << "'" << endl;

      stringstream ss;
      ss.clear();
      ss.str("");
      string param = "";
      ss.str(request);
      params.clear();
      while(getline(ss,param,delim)){
          params.push_back(param);
          cerr << param << endl;
      }
      if(params.size()){
          response = ansRequest();
      }



    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
    
    
    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);

    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    
//    response = "OK: " + request;
//    cerr << "response: " << response << endl;
    
    // renvoyer false si on veut clore la connexion avec le client

    return true;
  }

  char getDelim() const{
      return delim;
  }
  void setDelim(char delim){
      this->delim = delim;
  }
};


int main(int argc, char* argv[])
{
    // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());
  
  // cree l'objet qui gère les données
  shared_ptr<MyBase> base(new MyBase());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &MyBase::processRequest);
  
  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
  
  return 0;
}
