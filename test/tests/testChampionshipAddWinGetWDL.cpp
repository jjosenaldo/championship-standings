#include <iostream>
#include "testChampionship.h"


TEST_GROUP(ChampionshipTestGroupAddWinGetWDL){
    array<Team, 2> teams;

    TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        teams[0] = ajax;
        teams[1] = valencia;
        ADDGAME(teams[0], teams[1], 3, 1);
        setTeamsInfo();
    }

    TEST_TEARDOWN(){
        REMOVEGAME(teams[0], teams[1]);
        setTeamsInfo();
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

TEST(ChampionshipTestGroupAddWinGetWDL, championshipTestAddWinGetPoints){
    CHECK_EQUAL(PT_WIN, teams[0].pt);
    CHECK_EQUAL(0, teams[1].pt);
}

TEST(ChampionshipTestGroupAddWinGetWDL, championshipTestAddWinGetWins){
    CHECK_EQUAL(1, teams[0].w);
    CHECK_EQUAL(0, teams[1].w);
}

TEST(ChampionshipTestGroupAddWinGetWDL, championshipTestAddWinGetDraws){
    CHECK_EQUAL(0, teams[0].d);
    CHECK_EQUAL(0, teams[1].d);
}

TEST(ChampionshipTestGroupAddWinGetWDL, championshipTestAddWinGetLosses){
    CHECK_EQUAL(0, teams[0].l);
    CHECK_EQUAL(1, teams[1].l);
}