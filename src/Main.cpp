#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Championship.h"

#define ADDGAME(t1,t2,g1,g2) Championship__addNewGame(t1.id, t2.id, g1,g2)
#define POS(t) Championship__teamPosition(t.id, &t.pos)
#define PTS(t) Championship__getPoints(t.id, &t.pt)
#define WINS(t) Championship__getWins(t.id, &t.w)
#define DRAWS(t) Championship__getDraws(t.id, &t.d)
#define LOSSES(t) Championship__getLosses(t.id, &t.l)
#define GF(t) Championship__getGoalsFor(t.id, &t.gf)
#define GA(t) Championship__getGoalsAgainst(t.id, &t.ga)
#define GD(t) Championship__getGoalDiff(t.id, &t.gd)

using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::sort;
using std::string;
using std::vector;

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

    Team(int id, string name){
        this->id = id;
        this->name = name;
        pos = pt = w = d = l = gf = ga = gd = 0;
    }
};


bool comp(Team& t1, Team& t2){
    if(t1.pt < t2.pt) return true;
    if(t1.pt > t2.pt) return false;
    if(t1.w < t2.w) return true;
    if(t1.w > t2.w) return false;
    if(t1.gd < t2.gd) return true;
    if(t1.gd > t2.gd) return false;
    if(t1.gf < t2.gf) return true;
    if(t1.gf > t2.gf) return false;
    return false;
}

int main(){
    // Creates teams
    Team ajax = Team(0, "Ajax");
    Team valencia = Team(1, "Valencia");
    Team chelsea = Team(2, "Chelsea");
    Team lille = Team(3, "Lille");
    vector<Team> teams = {ajax,valencia,chelsea,lille};

    // Adds games
    ADDGAME(chelsea, valencia, 0, 1);
    ADDGAME(ajax, lille, 3, 0);

    ADDGAME(valencia, ajax, 0,3);
    ADDGAME(lille,chelsea,1,2);

    ADDGAME(ajax,chelsea,0,1);
    ADDGAME(lille,valencia,1,1);

    ADDGAME(chelsea,ajax,4,4);
    ADDGAME(valencia, lille, 4,1);

    ADDGAME(valencia,chelsea,2,2);
    ADDGAME(lille,ajax,0,2);

    for(auto& team : teams){
        POS(team);
        PTS(team);
        WINS(team);
        DRAWS(team);
        LOSSES(team);
        GF(team);
        GA(team);
        GD(team);
    }

    sort(teams.begin(), teams.end(), comp);

    int pos = 0;
    for(auto it = teams.end()-1; it >= teams.begin(); --it){
        const auto team = *it;
        cout << ++pos << " ";
        cout << left << setw(8) << team.name << right << "   " << setw(3) << team.pt << " | " << setw(3) << team.w << " | " << setw(3) << team.d << " | " << setw(3) << team.l << " | " << setw(3) << team.gf << " | " << setw(3) << team.ga << " | " << setw(4) << team.gd <<  endl;
    }

    return 0;
}