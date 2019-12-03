#include <array>
#include <string>

#include "CppUTest/TestHarness.h"
#include "Championship.h"

#define N 4
#define ADDGAME(t1,t2,g1,g2) Championship__addNewGame(t1.id, t2.id, g1,g2)
#define POS(t) Championship__teamPosition(t.id, &t.pos)
#define PTS(t) Championship__getPoints(t.id, &t.pt)
#define WINS(t) Championship__getWins(t.id, &t.w)
#define DRAWS(t) Championship__getDraws(t.id, &t.d)
#define LOSSES(t) Championship__getLosses(t.id, &t.l)
#define GF(t) Championship__getGoalsFor(t.id, &t.gf)
#define GA(t) Championship__getGoalsAgainst(t.id, &t.ga)
#define GD(t) Championship__getGoalDiff(t.id, &t.gd)

using std::array;
using std::string;

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

    Team() : Team(0, ""){}
};

TEST_GROUP(ChampionshipTestGroup){
    array<Team, N> teams;

    TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        Team chelsea = Team(3, "Chelsea");
        Team lille = Team(4, "Lille");
        teams = {ajax, valencia, chelsea, lille};
    }

    void setTeamsInfo(){
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
    }
};

TEST(ChampionshipTestGroup, championshipTestAddWin){
    
}