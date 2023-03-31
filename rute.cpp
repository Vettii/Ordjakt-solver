#include "rute.h"
#include "uti.h"
#include "std_lib_facilities.h"

vector<string> gyldigeOrd;

void Rute::finnLedigeRuter(map<Point, char> rM) {
    cout << " -lager kopi- ";
    Rute denneruta = {s, pos, forrigeRuter, false, aktOrd};
    vector<Rute> nyforrRute = forrigeRuter;
    nyforrRute.push_back(denneruta);
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if(j!=0 || i!=0) {
                if (-1 < pos.x+j && pos.x+j < 4 && -1 < pos.y+i && pos.y+i < 4) {
                    cout << " -lager point- ";
                    Point ledPos = {pos.x+j,pos.y+i};
                    char cPos = rM[ledPos];
                    bool gyldigRute = true;
                    
                    for (int k = 0; k < static_cast<int>(forrigeRuter.size()); k++) {
                        if(forrigeRuter[k].pos.x == ledPos.x && forrigeRuter[k].pos.y == ledPos.y) {
                            gyldigRute = false;
                            break;
                        }
                    };
                    
                    if (gyldigRute) {
                        string ord;
                        ord += s;
                        ord += cPos;
                        vector<string> aktuellOrdliste = fortsettOrdListe(ord, aktOrd);

                        if  (aktuellOrdliste.size() != 0) {
                            cout << " -lager ny " << aktuellOrdliste.size() << "- ";
                            Rute nyrute = {ord, ledPos, nyforrRute, false, aktuellOrdliste};
                            ledigeRuter.push_back(nyrute);
                        }
                    }  
                }
            }
        };
    };
    for (int p = 0; p < static_cast<int>(ledigeRuter.size()); p++) {
        if (ledigeRuter.size() != 0) {
            ledigeRuter[p].finnLedigeRuter(rM);
        }
    }
}