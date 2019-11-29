#include "Championship.h"
#include <iostream>
#include <map>
#include <iomanip>

#define ID_AJAX 1
#define ID_CHELSEA 2
#define ID_LILLE 3
#define ID_VALENCIA 4

#define NAME_AJAX "Ajax"
#define NAME_CHELSEA "Chelsea"
#define NAME_LILLE "Lille"
#define NAME_VALENCIA "Valencia"

using namespace std;

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
    Team_info__getPoints(ID_AJAX, &ptAjax);
    Team_info__getPoints(ID_CHELSEA, &ptChelsea);
    Team_info__getPoints(ID_LILLE, &ptLille);
    Team_info__getPoints(ID_VALENCIA, &ptValencia);

    // Get wins
    Team_info__getWins(ID_AJAX, &wAjax);
    Team_info__getWins(ID_CHELSEA, &wChelsea);
    Team_info__getWins(ID_LILLE, &wLille);
    Team_info__getWins(ID_VALENCIA, &wValencia);

    // Get draws
    Team_info__getDraws(ID_AJAX, &dAjax);
    Team_info__getDraws(ID_CHELSEA, &dChelsea);
    Team_info__getDraws(ID_LILLE, &dLille);
    Team_info__getDraws(ID_VALENCIA, &dValencia);

    // Get losses
    Team_info__getLosses(ID_AJAX, &lAjax);
    Team_info__getLosses(ID_CHELSEA, &lChelsea);
    Team_info__getLosses(ID_LILLE, &lLille);
    Team_info__getLosses(ID_VALENCIA, &lValencia);

    // Get goals for
    Team_info__getGoalsFor(ID_AJAX, &gfAjax);
    Team_info__getGoalsFor(ID_CHELSEA, &gfChelsea);
    Team_info__getGoalsFor(ID_LILLE, &gfLille);
    Team_info__getGoalsFor(ID_VALENCIA, &gfValencia);

    // Get goals against
    Team_info__getGoalsAgainst(ID_AJAX, &gaAjax);
    Team_info__getGoalsAgainst(ID_CHELSEA, &gaChelsea);
    Team_info__getGoalsAgainst(ID_LILLE, &gaLille);
    Team_info__getGoalsAgainst(ID_VALENCIA, &gaValencia);

    // Get goal difference
    Team_info__getGoalDiff(ID_AJAX, &gdAjax);
    Team_info__getGoalDiff(ID_CHELSEA, &gdChelsea);
    Team_info__getGoalDiff(ID_LILLE, &gdLille);
    Team_info__getGoalDiff(ID_VALENCIA, &gdValencia);

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