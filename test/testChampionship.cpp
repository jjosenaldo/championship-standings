#include "testChampionship.h"

int initFlag = 0;

void init(){
    if(initFlag == 0){
        INIT;
        initFlag = 1;
    }    
}

Team::Team() : Team(0, ""){}

Team::Team(int id, string name){
    this->id = id;
    this->name = name;
    pos = pt = w = d = l = gf = ga = gd = 0;
}

string Team::toString(){
    return "{" + to_string(pos) + " " + name + " " + to_string(pt) + " " +  to_string(w) + " " + to_string(d) + " " + to_string(l) + " " + to_string(gf) + " " + to_string(ga) + " "  + to_string(gd) + "}";
}

BaseTest::BaseTest(){
    init();
}