#include "testChampionship.h"

#define G1 5
#define G2 3

TEST_GROUP_BASE(ChampionshipTestGroupRemoveGameGetGoals, BaseTest){
    array<Team, 2> teams;

    TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        teams[0] = ajax;
        teams[1] = valencia;
        ADDGAME(teams[0], teams[1], G1,G2);
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

TEST(ChampionshipTestGroupRemoveGameGetGoals, championshipTestRemoveGameGetGoalsFor){
    CHECK_EQUAL(0, teams[0].gf);
    CHECK_EQUAL(0, teams[1].gf);
}

TEST(ChampionshipTestGroupRemoveGameGetGoals, championshipTestRemoveGameGetGoalsAgainst){
    CHECK_EQUAL(0, teams[0].ga);
    CHECK_EQUAL(0, teams[1].ga);
}

TEST(ChampionshipTestGroupRemoveGameGetGoals, championshipTestRemoveGameGetGoalDiff){
    CHECK_EQUAL(0, teams[0].gd);
    CHECK_EQUAL(0, teams[1].gd);
}