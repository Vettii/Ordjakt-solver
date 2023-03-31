#include "std_lib_facilities.h"
#include "uti.h"

string makeLower(string s) {
    string data = s;
    transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return tolower(c); });
    return data;
}

string delOrd(string s, int lengde) {
    string temp;
    if (static_cast<int>(s.length()) < lengde) {
        lengde = static_cast<int>(s.length());
    }
    for (int i = 0; i < lengde; i++)    {
        string c(1,s.at(i));
        temp.append(c);
    }
    return temp;
}

vector<string> lagNyOrdListe(string filnavn) {
    cout << "Leser ordliste... ";
    ifstream readFile(filnavn);
    vector<string> liste;

    //readFile.imbue(locale(readFile.getloc(), new codecvt_utf16<wchar_t, 0x10ffff, consume_header>));

    string linje;
    if (!readFile){
        throw runtime_error("Could not open file!");
    }
    while (getline(readFile,linje)) {
    liste.push_back(linje);
    }
    cout << " ... ordliste ferdig lest \n";
    return liste;
}

bool sjekkGyldigliste(string ord, vector<string> gl) {
    for (int i = 0; i < static_cast<int>(gl.size()); i++) {
        if (ord == gl[i]) {
            return false;
            break;
        }
    }
    return true;
}

void printList(vector<string> liste) {
    vector<string> tL;
    for (int j = 16; j > 0; j--) {
        for (int k = 0; k < static_cast<int>(liste.size()); k++) {
            if (j == static_cast<int>(liste[k].size())) {
                tL.push_back(liste[k]);
            }
        }
    }
    for (int i = 0; i < static_cast<int>(tL.size()); i++) {
        cout << "Ord nr: " << i << " - " << tL[i] << "\n";
    }
}

int binarySearchVecString(vector<string> liste, string x) {
        bool test = false;
        if (x == "kofec") {
            test = true;
        }
        int n = static_cast<int>(liste.size());
        int l = 0 ;
        int r = n - 1;
        string deltListeOrd;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (test) {
            cout << m << "<- m og r -> " << r << " l -> " << l << "\n";
        }
        string listeOrd = makeLower(liste.at(m));

        if(m == 0) {
            return -1;
        }
        deltListeOrd = delOrd(listeOrd,x.length());
        if ((x == deltListeOrd)) {
            return m;
        }
        // If x greater, ignore left half
        if (x > deltListeOrd) {
            l = m + 1;
        }
        // If x is smaller, ignore right half
        else {
            r = m - 1;
        }
    }
    return -1;
}

vector<string> fortsettOrdListe(string tempOrd, vector<string> tempListe) {
    vector<string> nyTempListe = {};
    if (funnetLister.find(tempOrd) == funnetLister.end()) {
        cout << "Ordsok: (" << tempOrd << ", Lengde: " << tempListe.size() << ").. ";
        int i =  binarySearchVecString(tempListe, tempOrd);
        if (i != -1) {

            int k = i;
            int p = i-1;
            string listeOrd = makeLower(tempListe.at(k));

            while (tempOrd.length() <= listeOrd.length() && tempOrd == delOrd(listeOrd,tempOrd.length())){
                if (sjekkGyldigliste(tempOrd, gyldigeOrd) && listeOrd == tempOrd) {
                gyldigeOrd.push_back(tempOrd);
                }
                nyTempListe.push_back(listeOrd);
                k = k + 1;
                if (k != static_cast<int>(tempListe.size())) {
                    listeOrd = makeLower(tempListe.at(k));
                }
                else {
                    break;
                }
            }
            cout << "_";
            listeOrd = makeLower(tempListe.at(p));
            reverse(nyTempListe.begin(), nyTempListe.end());
            while (tempOrd.length() <= listeOrd.length() && tempOrd == delOrd(listeOrd,tempOrd.length())){
                if (sjekkGyldigliste(tempOrd, gyldigeOrd) && listeOrd == tempOrd) {
                gyldigeOrd.push_back(tempOrd);
                }
                nyTempListe.push_back(listeOrd);
                p = p - 1;
                if (p > 0) {
                    listeOrd = makeLower(tempListe.at(p));
                }
                else {
                    break;
                }
            }
            reverse(nyTempListe.begin(), nyTempListe.end());
        }

        funnetLister.insert(pair<string, vector<string>>(tempOrd, tempListe));
        cout << " .. liste ut: " << nyTempListe.size() << "\n";
    }
    else {
        cout << "Ordsok: (" << tempOrd << ", Lengde: " << tempListe.size() << ") Allerede funnet\n";
        nyTempListe = funnetLister.at(tempOrd);
    }
    return nyTempListe;
};