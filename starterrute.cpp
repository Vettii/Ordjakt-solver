#include "std_lib_facilities.h"
#include "starterrute.h"
#include "ordliste.h"
#include "rute.h"
#include "uti.h"

vector<string> StarterRute::aktFraOrdbok(char c, vector<string> Ordliste) {
    string s(1,c);
    vector<string> sortertOrdliste = fortsettOrdListe(s, Ordliste);

    return sortertOrdliste;
}

void StarterRute::finnLedigeRuter(map<Point, char> rM) {
    string gammelbok;
    gammelbok += c;
    cout << " -lager kopi- ";
    Rute gammelrute = {gammelbok, pos, {}, false};
    cout << " -kopi ferdig- ";
    vector<Rute> forrRute = {gammelrute};
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if(j!=0 || i!=0) {
                if (-1 < pos.x+j && pos.x+j < 4 && -1 < pos.y+i && pos.y+i < 4) {
                    Point ledPos = {pos.x+j,pos.y+i};
                    char cPos = rM[ledPos];
                    string ord;
                    ord += c;
                    ord += cPos;
                    vector<string> aktuellOrdliste = fortsettOrdListe(ord, aktOrd);
                    
                    if (static_cast<int>(aktuellOrdliste.size()) != 0) {
                        cout << " -lager neste rute- ";
                        Rute nyrute = {ord, ledPos, forrRute, false, aktuellOrdliste};
                        ledigeRuter.push_back(nyrute);
                        cout << " -ferdig neste rute- ";
                    };
                };
            };
        };
    };
}
