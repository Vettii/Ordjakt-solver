#pragma once
#include "std_lib_facilities.h"
#include "ownpoint.h"
#include "rute.h"
#include "uti.h"

class StarterRute
{
public:
char c ;
Point pos ;
vector<Rute> ledigeRuter;
vector<string> aktOrd;

StarterRute() {};
StarterRute(char c, Point pos) : c(c), pos(pos) {
    aktOrd = aktFraOrdbok(c, Ordliste);
    finnLedigeRuter(ruteMapOrd);
};

void finnLedigeRuter(map<Point, char> rM);
vector<string> aktFraOrdbok(char c, vector<string> Ordliste);



};