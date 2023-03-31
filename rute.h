#pragma once
#include "std_lib_facilities.h"
#include "ownpoint.h"
#include "uti.h"

class Rute
{

public:
string s;
Point pos ;
vector<Rute> forrigeRuter;
bool letVidere ;
vector<string> aktOrd ;
vector<Rute> ledigeRuter ;

Rute() {};

Rute(string s, Point pos, vector<Rute> forrigeRuter = {}, bool letVidere = true, vector<string> aktOrd = {}) : 
s(s), pos(pos), forrigeRuter(forrigeRuter), letVidere(letVidere), aktOrd(aktOrd) {
    if(letVidere) {
        finnLedigeRuter(ruteMapOrd);
    }

};

void finnLedigeRuter(map<Point, char> rM);
vector<string> aktFraForrige(vector<string> forrige_aktOrd);


};