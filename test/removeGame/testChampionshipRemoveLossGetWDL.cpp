#include "testChampionship.h"


TEST_GROUP_BASE(ChampionshipTestGroupRemoveLossGetWDL, BaseTest){
    array<Team, 2> teams;

    TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        teams[0] = ajax;
        teams[1] = valencia;
        ADDGAME(teams[0], teams[1], 1, 3);
        setTeamsInfo();
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

TEST(ChampionshipTestGroupRemoveLossGetWDL, championshipTestRemoveLossGetPoints){
    CHECK_EQUAL(0, teams[0].pt);
    CHECK_EQUAL(0, teams[1].pt);
}

TEST(ChampionshipTestGroupRemoveLossGetWDL, championshipTestRemoveLossGetWins){
    CHECK_EQUAL(0, teams[0].w);
    CHECK_EQUAL(0, teams[1].w);
}

TEST(ChampionshipTestGroupRemoveLossGetWDL, championshipTestRemoveLossGetDraws){
    CHECK_EQUAL(0, teams[0].d);
    CHECK_EQUAL(0, teams[1].d);
}

TEST(ChampionshipTestGroupRemoveLossGetWDL, championshipTestRemoveLossGetLosses){
    CHECK_EQUAL(0, teams[0].l);
    CHECK_EQUAL(0, teams[1].l);
}