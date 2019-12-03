#include <iostream>
#include "testChampionship.h"

#define G1 5
#define G2 3

TEST_GROUP(ChampionshipTestGroupAddGameGetGoals){
    array<Team, 2> teams;

    TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        teams[0] = ajax;
        teams[1] = valencia;
        ADDGAME(teams[0], teams[1], G1,G2);
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

TEST(ChampionshipTestGroupAddGameGetGoals, championshipTestAddGameGetGoalsFor){
    CHECK_EQUAL(G1, teams[0].gf);
    CHECK_EQUAL(G2, teams[1].gf);
}

TEST(ChampionshipTestGroupAddGameGetGoals, championshipTestAddGameGetGoalsAgainst){
    CHECK_EQUAL(G2, teams[0].ga);
    CHECK_EQUAL(G1, teams[1].ga);
}

TEST(ChampionshipTestGroupAddGameGetGoals, championshipTestAddGameGetGoalDiff){
    CHECK_EQUAL(G1-G2, teams[0].gd);
    CHECK_EQUAL(G2-G1, teams[1].gd);
}