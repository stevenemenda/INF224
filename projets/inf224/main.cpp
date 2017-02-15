#include<iostream>
#include<string>
#include"Inf_multimedia.h"
#include<fstream>
#include<sstream>
#include"inf_photo.h"
#include"video.h"
#include"film.h"
#include"mediagroup.h"
#include<memory>
#include <limits>
#include"CommeResource.h"
#include"managemedia.h"
//#include<sstream>
using namespace std;
int main(void){

    string filePath = "/cal/homes/lguo/Downloads/INF224/projets/inf224.txt";
    string fileDir = "/cal/homes/lguo/Downloads/INF224/projets/";

    int iFile = 7;

    string tFile[iFile];
    tFile[0] = "Pont.jpeg";
    tFile[1] = "StarWars.mp4";
    tFile[2] = "LostTale.mp4";
    tFile[3] = "Flower.jpeg";
    tFile[4] = "Emoji.mp4";
    tFile[5] = "SpiderMan.mp4";
    tFile[6] = "Lac.jpeg";
    
    

    const int iTest = std::numeric_limits<int>::max();
    int step = iTest;

    switch (step){
    case iTest:
        {
        cout << atoi(" 123") << endl;
        cout << atoi("123") << endl;
        // function atoi() will ignore the blanks in the string to be converted to integer!
//        atoi("123");
//            stringstream ss;
//            shared_ptr<ManageMedia> mPtr;
//            mPtr.reset(new ManageMedia());
//            map<string,mediaPtr>::const_iterator it = mPtr->findMedia("guo");

//            if(!mPtr->endMList(it)){
//                it->second->display(ss);
//                cout << ss.str() <<endl;
//            }
//            videoPtr v(new Video(tFile[2]));

//            v->display(ss);
//            cout << ss.str() << endl;
//            ss.clear();
//            ss.str("");
//            string input = "";
//            char delim = ';';

//            while (getline(cin, input)) {
//                ss.clear();
//                ss.str("");
//                ss << input;
//                if(input == "end"){
//                    cout << ss.str() << endl;
//                    cout << "end of program!" << endl;
//                    break;
//                }else{

//                    cout << ss.str() << endl;
//                    string token = "";
//                    while(std::getline(ss, token, delim)) {
//                        std::cout << token << '\n';
//                        if(token == "end") break;
//                    }
//                }



//            }
        }
        break;
    case 11:
        {

        }
        break;
    case 10:
        {
        using filmPtr = std::shared_ptr<Film>;
        using videoPtr = std::shared_ptr<Video>;
        using photoPtr = std::shared_ptr<Inf_Photo>;
        using mGroupPtr = shared_ptr<MediaGroup>;

        ManageMedia manageMedia;

        videoPtr mv = manageMedia.createVideo(tFile[1], fileDir, 0);
        videoPtr mv1 = manageMedia.createVideo(tFile[2], fileDir, 0);
        videoPtr mv2 = manageMedia.createVideo(tFile[4], fileDir, 0);


        photoPtr mP = manageMedia.createPhoto( tFile[0], fileDir);
        photoPtr mP1 = manageMedia.createPhoto( tFile[3], fileDir);
        photoPtr mP2 = manageMedia.createPhoto( tFile[6], fileDir);

        int nChapitre = 3;
        // the three sentences have the same function.
        //            intPtr table(new int[nChapitre],std::default_delete<int []>());
        intPtr table(new int[nChapitre],array_deleter<int>());
        //            intPtr table(new int[nChapitre],[] (int * p){delete [ ] p;});
        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 100 + i * i;
        }

        filmPtr mF = manageMedia.createFilm(tFile[1], fileDir, 0, table, nChapitre);

        nChapitre = 4;
        table.reset(new int[nChapitre]);

        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 50 + i * i;
        }

        filmPtr mF1 = manageMedia.createFilm(tFile[2], fileDir, 0, table, nChapitre);


        nChapitre = 5;
        table.reset(new int[nChapitre]);

        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 25 + i * i;
        }

        filmPtr mF2 = manageMedia.createFilm(tFile[4], fileDir, 0, table, nChapitre);

        mGroupPtr mGroup = manageMedia.createMGroup("entretainment");

        mGroup->push_back(mv);
        mGroup->push_back(mv1);
        mGroup->push_back(mv2);

        mGroup->push_back(mP);
        mGroup->push_back(mP1);
        mGroup->push_back(mP2);

        mGroup->push_back(mF);
        mGroup->push_back(mF1);
        mGroup->push_back(mF2);

        mGroup->display(cout);

        manageMedia.play(tFile[1]);
        manageMedia.findMGroup("entretainment");
        manageMedia.findMedia(tFile[2]);
        }
        break;
    case 9:
        {
//            using mediaPtr = std::shared_ptr<Inf_multimedia>;
            using filmPtr = std::shared_ptr<Film>;
            using videoPtr = std::shared_ptr<Video>;
            using photoPtr = std::shared_ptr<Inf_Photo>;

            ManageMedia manageMedia;

            videoPtr mv = manageMedia.createVideo(tFile[1], fileDir, 0);
            videoPtr mv1 = manageMedia.createVideo(tFile[2], fileDir, 0);
            videoPtr mv2 = manageMedia.createVideo(tFile[4], fileDir, 0);


            photoPtr mP = manageMedia.createPhoto( tFile[0], fileDir);
            photoPtr mP1 = manageMedia.createPhoto( tFile[3], fileDir);
            photoPtr mP2 = manageMedia.createPhoto( tFile[6], fileDir);

            
            // the shared_ptr table and pointer "new int[*]" point to the same location in memory!!
            // the unique_ptr allows only one unique_ptr  pointing to one resource.
            // the shared_ptr allows many shared_ptrs pointing  to one resource.


            int nChapitre = 3;
            // the three sentences have the same function.
            //            intPtr table(new int[nChapitre],std::default_delete<int []>());
            intPtr table(new int[nChapitre],array_deleter<int>());
            //            intPtr table(new int[nChapitre],[] (int * p){delete [ ] p;});
            for(int i = 0; i < nChapitre; i++){
                table.get()[i] = 100 + i * i;
            }

            filmPtr mF = manageMedia.createFilm(tFile[1], fileDir, 0, table, nChapitre);

            nChapitre = 4;
            table.reset(new int[nChapitre]);

            for(int i = 0; i < nChapitre; i++){
                table.get()[i] = 50 + i * i;
            }

            filmPtr mF1 = manageMedia.createFilm(tFile[2], fileDir, 0, table, nChapitre);


            nChapitre = 5;
            table.reset(new int[nChapitre]);

            for(int i = 0; i < nChapitre; i++){
                table.get()[i] = 25 + i * i;
            }

            filmPtr mF2 = manageMedia.createFilm(tFile[4], fileDir, 0, table, nChapitre);

            mGroupPtr mGroup = manageMedia.createMGroup("entretainment");
            mGroup->push_back(mv);
            mGroup->push_back(mv1);
            mGroup->push_back(mv2);

            mGroup->push_back(mP);
            mGroup->push_back(mP1);
            mGroup->push_back(mP2);

            mGroup->push_back(mF);
            mGroup->push_back(mF1);
            mGroup->push_back(mF2);

            mGroup->display(cout);

            // table will be deleted! Because it will be not used!

            //            using mGroupPtr = std::shared_ptr<MediaGroup>;

            // the smart pointer solves the problem of the leak of memory, but doesn't change any thing to
            // the problem of passing variable by pointer.

        }
        break;
    case 8:
        {
//        using mediaPtr = std::shared_ptr<Inf_multimedia>;
        using filmPtr = std::shared_ptr<Film>;
        using videoPtr = std::shared_ptr<Video>;
        using photoPtr = std::shared_ptr<Inf_Photo>;

        ManageMedia manageMedia;

        videoPtr mv = manageMedia.createVideo(tFile[1], fileDir, 0);
        videoPtr mv1 = manageMedia.createVideo(tFile[2], fileDir, 0);
        videoPtr mv2 = manageMedia.createVideo(tFile[4], fileDir, 0);


        photoPtr mP = manageMedia.createPhoto( tFile[0], fileDir);
        photoPtr mP1 = manageMedia.createPhoto( tFile[3], fileDir);
        photoPtr mP2 = manageMedia.createPhoto( tFile[6], fileDir);


        // the shared_ptr table and pointer "new int[*]" point to the same location in memory!!
        // the unique_ptr allows only one unique_ptr  pointing to one resource.
        // the shared_ptr allows many shared_ptrs pointing  to one resource.


        int nChapitre = 3;
        // the three sentences have the same function.
        //            intPtr table(new int[nChapitre],std::default_delete<int []>());
        intPtr table(new int[nChapitre],array_deleter<int>());
        //            intPtr table(new int[nChapitre],[] (int * p){delete [ ] p;});
        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 100 + i * i;
        }

        filmPtr mF = manageMedia.createFilm(tFile[1], fileDir, 0, table, nChapitre);

        nChapitre = 4;
        table.reset(new int[nChapitre]);

        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 50 + i * i;
        }

        filmPtr mF1 = manageMedia.createFilm(tFile[2], fileDir, 0, table, nChapitre);


        nChapitre = 5;
        table.reset(new int[nChapitre]);

        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 25 + i * i;
        }

        filmPtr mF2 = manageMedia.createFilm(tFile[4], fileDir, 0, table, nChapitre);

        mGroupPtr mGroupVideo = manageMedia.createMGroup("Video");
        mGroupPtr mGroupPhoto = manageMedia.createMGroup("Photo");
        mGroupPtr mGroupFilm = manageMedia.createMGroup("Film");

        mGroupVideo->push_back(mv);
        mGroupVideo->push_back(mv1);
        mGroupVideo->push_back(mv2);

        mGroupPhoto->push_back(mP);
        mGroupPhoto->push_back(mP1);
        mGroupPhoto->push_back(mP2);

        mGroupFilm->push_back(mF);
        mGroupFilm->push_back(mF1);
        mGroupFilm->push_back(mF2);

        mGroupVideo->display(cout);
        mGroupPhoto->display(cout);
        mGroupFilm->display(cout);

        manageMedia.play(tFile[1]);

        manageMedia.findMGroup("entretainment");
        manageMedia.findMGroup("Film");
        // table will be deleted! Because it will be not used!

        //            using mGroupPtr = std::shared_ptr<MediaGroup>;

        // the smart pointer solves the problem of the leak of memory, but doesn't change any thing to
        // the problem of passing variable by pointer.
        }
        break;

    case 7:
        {
        int nChapitre = 3;
        intPtr table(new int[nChapitre],array_deleter<int>());
        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 100 + i * i;
        }

        Film f(tFile[5]);
        f.display(cout);
        filmPtr fp (new Film(tFile[2], fileDir, 10, table, nChapitre));

        nChapitre = 4;
        table.reset(new int[nChapitre]);
        for(int i = 0; i < nChapitre; i++){
            table.get()[i] = 100 + i * i;
        }
        filmPtr cf (new Film(tFile[1], fileDir, 20, table, nChapitre));
        f = *(fp.get());
        f.display(cout);
        f = *(cf.get());
        f.display(cout);
        }
        break;

    case 6:
        {
        // when we finish passing a table, we should delete it. Or we should delete the pointer for the
        // seek of avoiding modifying or deleting the table out of a function or an object.
           int nChapitre = 5;
           intPtr table (new int[nChapitre]);
           for(int i = 0; i < nChapitre; i++){
               table.get()[i] = 100 + i * i;
           }

           Film * film = new Film(tFile[2], fileDir, 0, 0, 0);
           film->setTable(table, nChapitre);



           film->display(cout);
           film->play();
           // when we get a return variable by pointer, if it has key word "const", then we can't change any
           // thing to it, and we can only call the const function of it.
           const intPtr tTable = film->getTable();

           int tNChapitre = film->getNChapitre();
           for(int i = 0;i < tNChapitre; i++){
               cout << "GET: The duration of Chapitre " << i + 1 << " is: " << tTable.get()[i]<<endl;
           }
//           delete [] tTable;
//           tTable = 0;

           delete film;
           film = 0;
        }
        break;

    case 5:
        {
            // declare a array of pointers of Inf_multimedia
            Inf_multimedia ** tInfMedia = new Inf_multimedia * [iFile];


            // initialise each pointer in pointer-array
            // for each pointer, we can use it to  point an array of objects, like this: tInfMedia[0] = new Inf_Photo(tFile[0])[6];
            tInfMedia[0] = new Inf_Photo(tFile[0], fileDir, 0, 0);

            tInfMedia[1] = new Video(tFile[1], fileDir, 0);

            tInfMedia[2] = new Video(tFile[2], fileDir, 0);

            tInfMedia[3] = new Inf_Photo(tFile[3], fileDir, 0, 0);

            tInfMedia[4] = new Video(tFile[4], fileDir, 0);

            tInfMedia[5] = new Video(tFile[5], fileDir, 0);

            tInfMedia[6] = new Inf_Photo(tFile[6], fileDir, 0, 0);


            for(int i = 0; i < iFile; i++){

                tInfMedia[i]->setPathMedia(fileDir);
                tInfMedia[i]->display(cout);
                tInfMedia[i] ->play();

            }

            // delete the objects that are pointed by tInfMedia
            // delete the object that is pointed by each pointer

            for(int i = 0; i < iFile; i++){

                delete tInfMedia[i];

            }

            // delete the array, not the objects that they point to!
            delete [] tInfMedia;
            tInfMedia = NULL;
        }
        break;

    case 4:
        {
            // test two subclass: Video and Photo
            Video * video = new Video(tFile[1], fileDir, 0);
            video->play();
            Inf_Photo * photo =  new Inf_Photo(tFile[0], fileDir, 0, 0);
            photo->play();

            delete video;
            video = 0;
            delete photo;
            photo = 0;
        }
        break;
    case 3:

        {
            // test base class: Inf_multimedia
            Video * video = new Video(tFile[1], fileDir, 0);
            // output to terminal
            video->display(cout);
            // output to file
            fstream fout;
            fout.open(filePath,ios_base::out);
            video->display(fout);

            fout.close();
            delete video;
        }
        break;

    case 2:
        break;

    case 1:
        {
            // for test something!
            int n = 4;
//            Inf_multimedia ** tInfMedia = new Inf_multimedia *[2];
//            tInfMedia[0] = new Video [n];
//            for(int i = 0; i < n; i++){
//                tInfMedia[0][i].setPathMedia(fileDir);
//                tInfMedia[0][i].setMedia(tFile[i]);
//                tInfMedia[0][i].display(cout);

//            }

//           // delete [] tInfMedia[0];
//            delete [] tInfMedia;
            // for operation of pointer, we should make sure that the type of pointer is the same as the type of array!!
            // but, we could use the parent's pointer to call the 'same' virtual function of subclass.
            // if all the parametre of constructor have  a default value and we don't passe any value to the constructor, then default values will be used.

            Video * tInfMedia = new Video[n];
            Inf_multimedia * p;
            for(int i = 0; i < n; i++){
//                tInfMedia[i] = new Video();
                p = & tInfMedia[i];
                p->display(cout);
//                tInfMedia[i].setPathMedia(fileDir);
//                tInfMedia[i].setMedia(tFile[i]);
//                tInfMedia[i].display(cout);
            }

//           // delete [] tInfMedia[0];
//            delete [] tInfMedia;

        // test for pointer-array
//            int * count = new int[4];
//            for(int i = 0; i < 4; i++){
//                count[i] = i + 3 * i;
//                cout << i << endl;
//            }
//            delete [] count;
        }

        break;

    default:

        break;
    }

    return 0;
}
