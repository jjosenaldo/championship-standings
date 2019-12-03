#include <iostream>
#include "testChampionship.h"


TEST_GROUP(ChampionshipTestGroupAddDraw){
    array<Team, 2> teams;

    TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        teams[0] = ajax;
        teams[1] = valencia;
        ADDGAME(teams[0], teams[1], 2, 2);
        setTeamsInfo();
    }

    TEST_TEARDOWN(){
        REMOVEGAME(teams[0], teams[1]);
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

TEST(ChampionshipTestGroupAddDraw, championshipTestAddDrawGetPoints){
    CHECK_EQUAL(PT_DRAW, teams[0].pt);
    CHECK_EQUAL(PT_DRAW, teams[1].pt);
}

TEST(ChampionshipTestGroupAddDraw, championshipTestAddDrawGetWins){
    CHECK_EQUAL(0, teams[0].w);
    CHECK_EQUAL(0, teams[1].w);
}

TEST(ChampionshipTestGroupAddDraw, championshipTestAddDrawGetDraws){
    CHECK_EQUAL(1, teams[0].d);
    CHECK_EQUAL(1, teams[1].d);
}

TEST(ChampionshipTestGroupAddDraw, championshipTestAddDrawGetLosses){
    CHECK_EQUAL(0, teams[0].l);
    CHECK_EQUAL(0, teams[1].l);
}