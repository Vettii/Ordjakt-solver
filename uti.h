#pragma once
#include "std_lib_facilities.h"
#include "ownpoint.h"

string makeLower(string s);

string delOrd(string s, int lengde);

vector<string> lagNyOrdListe(string filnavn);

bool sjekkGyldigliste(string ord, vector<string> gl);

extern vector<string> gyldigeOrd;

extern vector<string> Ordliste;

extern map<string, vector<string>> funnetLister;

extern map<Point, char> ruteMapOrd;

void printList(vector<string> liste);

int binarySearchVecString(vector<string> liste, string x);

vector<string> fortsettOrdListe(string tempOrd, vector<string> tempListe);
