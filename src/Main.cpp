#include "Championship.h"
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#define ID_AJAX 1
#define ID_CHELSEA 2
#define ID_LILLE 3
#define ID_VALENCIA 4

#define NAME_AJAX "Ajax"
#define NAME_CHELSEA "Chelsea"
#define NAME_LILLE "Lille"
#define NAME_VALENCIA "Valencia"

using namespace std;

struct Team{
    int id;
    string name;
    int pos;
    int pt;
    int w;
    int d;
    int l;
    int gf;
    int ga;
    int gd;
};

// < position , Team >
map<int, int> positions;

int main(){
    int posAjax, posChelsea, posLille, posValencia;
    int ptAjax, ptChelsea, ptLille, ptValencia;
    int wAjax, wChelsea, wLille, wValencia;
    int dAjax, dChelsea, dLille, dValencia;
    int lAjax, lChelsea, lLille, lValencia;
    int gfAjax, gfChelsea, gfLille, gfValencia;
    int gaAjax, gaChelsea, gaLille, gaValencia;
    int gdAjax, gdChelsea, gdLille, gdValencia;

    // Adds games
    Championship__addNewGame(ID_CHELSEA,ID_VALENCIA,0,1);
    Championship__addNewGame(ID_AJAX, ID_LILLE, 3,0);

    Championship__addNewGame(ID_LILLE,ID_CHELSEA,1,2);
    Championship__addNewGame(ID_VALENCIA, ID_AJAX, 0,3);

    Championship__addNewGame(ID_AJAX,ID_CHELSEA,0,1);
    Championship__addNewGame(ID_LILLE, ID_VALENCIA, 1,1);

    Championship__addNewGame(ID_CHELSEA,ID_AJAX,4,4);
    Championship__addNewGame(ID_VALENCIA, ID_LILLE, 4,1);

    //Championship__editGame(ID_CHELSEA, ID_AJAX, 1,4);

    // Computes positions
    Championship__teamPosition(ID_AJAX,&posAjax);
    Championship__teamPosition(ID_CHELSEA,&posChelsea);
    Championship__teamPosition(ID_LILLE,&posLille);
    Championship__teamPosition(ID_VALENCIA,&posValencia);


    // Orders positions
    positions[posAjax] = ID_AJAX;
    positions[posChelsea] = ID_CHELSEA;
    positions[posLille] = ID_LILLE;
    positions[posValencia] = ID_VALENCIA;

    // Gets points
    Championship__getPoints(ID_AJAX, &ptAjax);
    Championship__getPoints(ID_CHELSEA, &ptChelsea);
    Championship__getPoints(ID_LILLE, &ptLille);
    Championship__getPoints(ID_VALENCIA, &ptValencia);

    // Get wins
    Championship__getWins(ID_AJAX, &wAjax);
    Championship__getWins(ID_CHELSEA, &wChelsea);
    Championship__getWins(ID_LILLE, &wLille);
    Championship__getWins(ID_VALENCIA, &wValencia);

    // Get draws
    Championship__getDraws(ID_AJAX, &dAjax);
    Championship__getDraws(ID_CHELSEA, &dChelsea);
    Championship__getDraws(ID_LILLE, &dLille);
    Championship__getDraws(ID_VALENCIA, &dValencia);

    // Get losses
    Championship__getLosses(ID_AJAX, &lAjax);
    Championship__getLosses(ID_CHELSEA, &lChelsea);
    Championship__getLosses(ID_LILLE, &lLille);
    Championship__getLosses(ID_VALENCIA, &lValencia);

    // Get goals for
    Championship__getGoalsFor(ID_AJAX, &gfAjax);
    Championship__getGoalsFor(ID_CHELSEA, &gfChelsea);
    Championship__getGoalsFor(ID_LILLE, &gfLille);
    Championship__getGoalsFor(ID_VALENCIA, &gfValencia);

    // Get goals against
    Championship__getGoalsAgainst(ID_AJAX, &gaAjax);
    Championship__getGoalsAgainst(ID_CHELSEA, &gaChelsea);
    Championship__getGoalsAgainst(ID_LILLE, &gaLille);
    Championship__getGoalsAgainst(ID_VALENCIA, &gaValencia);

    // Get goal difference
    Championship__getGoalDiff(ID_AJAX, &gdAjax);
    Championship__getGoalDiff(ID_CHELSEA, &gdChelsea);
    Championship__getGoalDiff(ID_LILLE, &gdLille);
    Championship__getGoalDiff(ID_VALENCIA, &gdValencia);

    for(auto it : positions){
        cout << it.first << " ";
        if(it.second == ID_AJAX)
            cout << left << setw(8) << NAME_AJAX << right << "   " << setw(3) << ptAjax << " | " << setw(3) << wAjax << " | " << setw(3) << dAjax << " | " << setw(3) << lAjax << " | " << setw(3) << gfAjax << " | " << setw(3) << gaAjax << " | " << setw(4) << gdAjax <<  endl;
        else if(it.second == ID_CHELSEA)
            cout << left << setw(8) << NAME_CHELSEA << right << "   " << setw(3) << ptChelsea << " | " << setw(3) << wChelsea << " | " << setw(3) << dChelsea << " | " << setw(3) << lChelsea << " | " << setw(3) << gfChelsea << " | " << setw(3) << gaChelsea << " | " << setw(4) << gdChelsea <<  endl;
        else if(it.second == ID_LILLE)
            cout << left << setw(8) << NAME_LILLE << right << "   " << setw(3) << ptLille << " | " << setw(3) << wLille << " | " << setw(3) << dLille << " | " << setw(3) << lLille << " | " << setw(3) << gfLille << " | " << setw(3) << gaLille << " | " << setw(4) << gdLille <<  endl;
        else if(it.second == ID_VALENCIA)
            cout << left << setw(8) << NAME_VALENCIA << right << "   " << setw(3) << ptValencia << " | " << setw(3) << wValencia << " | " << setw(3) << dValencia << " | " << setw(3) << lValencia << " | " << setw(3) << gfValencia << " | " << setw(3) << gaValencia << " | " << setw(4) << gdValencia <<  endl;
    }

    return 0;
}