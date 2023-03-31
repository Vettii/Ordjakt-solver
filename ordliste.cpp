#include "std_lib_facilities.h"
#include "ordliste.h"
#include "starterrute.h"
#include "rute.h"
#include "uti.h"

/*
æ = {
ø = |
å = ~ 
*/

vector<vector<char>>bokstavGrid= {
{'k', 'm', 'n', 'i'},
{'o', 'o', 'b', 'e'},
{'c', 'f', 'e', 'r'},
{'e', 'e', 's', '~'},
};

//---------Init Lister------------

vector<string> Ordliste = lagNyOrdListe("ordlisten.txt");

vector<string> muligeOrd;

vector<StarterRute> starterRuterList;

map<Point, char> ruteMapOrd;

map<string, vector<string>> funnetLister;

//-------------Funksjoner---------

void lagEnkeltBokLister() {
    
}

void kjor() {

cout << "Starter klokke \n";
auto start = chrono::high_resolution_clock::now();

cout << "Lager map... ";
//initiere 4x4 grid med bokstaver, lage map
for (int i = 0; i < static_cast<int>(bokstavGrid.size()); i++) {
    for (int j = 0; j < static_cast<int>(bokstavGrid[0].size()); j++) {
        char c = bokstavGrid[i][j];
        Point pos = {j,i};
        ruteMapOrd.insert(pair<Point, char>(pos, c));
    };
};
cout << " ... map ferdig\n ";

// Lager startruter

cout << "\nLager StarterRuter... \n";
for (int i = 0; i < static_cast<int>(bokstavGrid.size()); i++) {
    for (int j = 0; j < static_cast<int>(bokstavGrid[0].size()); j++) {
        char c = bokstavGrid[i][j];
        Point pos = {j,i};
        cout << "StarterRute " << c << " (pos: " << pos << ") blir bygget... \n";
        StarterRute sr = {c, pos};
        starterRuterList.push_back(sr);
        cout << "... ferdig\n";

    };
};
cout << "... alle StarterRuter er ferdig bygget \n";


//lage loop som går igjennom hver bokstav som startpunkt (med starter rute)

cout << "\n Finner ord for alle starterruter: \n";
for (int k = 0; k < static_cast<int>(starterRuterList.size()); k++) {
    //egen funksjon for loopen fra starterrute og alle "grener"
    cout << "STARTERRUTE: " << starterRuterList[k].c << " pos (" << starterRuterList[k].pos << ") finner alle ord ... " << "(" << static_cast<int>(starterRuterList[k].ledigeRuter.size()) << " gydlige ruter rundt)\n";
    for (int l = 0; l < static_cast<int>(starterRuterList[k].ledigeRuter.size()); l++) {
        Rute r = starterRuterList[k].ledigeRuter[l];
        r.finnLedigeRuter(ruteMapOrd);
    }
    cout << " ... FERDIG \n";
}

cout << "\nPrinter sortert liste: \n";
printList(gyldigeOrd);

auto stop = chrono::high_resolution_clock::now();
chrono::duration<double> tid = stop - start;

cout << "Programmet brukte " << tid.count() << " sekunder \n";

}
