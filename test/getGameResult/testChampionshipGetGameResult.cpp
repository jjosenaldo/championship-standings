#include "testChampionship.h"

#define G1 3
#define G2 4

TEST_GROUP_BASE(ChampionshipTestGroupGetGameResult, BaseTest){
    array<Team, 2> teams;

     TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        teams[0] = ajax;
        teams[1] = valencia;
        ADDGAME(teams[0], teams[1], G1, G2);
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

TEST(ChampionshipTestGroupGetGameResult, championshipTestGroupGetGameResult){
    int r1, r2;
    GETRESULT(teams[0], teams[1], r1, r2);
    CHECK_EQUAL(r1, G1);
    CHECK_EQUAL(r2, G2);
}