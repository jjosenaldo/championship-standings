#include "testChampionship.h"

#define EDITGAMEGOALS(g1,g2) EDITGAME(teams[0], teams[1], g1,g2)

#define OLD_G1 2
#define OLD_G2 4

#define NEW_G1 1
#define NEW_G2 8

TEST_GROUP(ChampionshipTestGroupEditGameGetGoals){
    array<Team, 2> teams;
    int newG1;
    int newG2;

    TEST_SETUP(){
        Team ajax = Team(1, "Ajax");
        Team valencia = Team(2, "Valencia");
        teams[0] = ajax;
        teams[1] = valencia;
        ADDGAME(teams[0], teams[1], OLD_G1, OLD_G2);
        setTeamsInfo();
        EDITGAMEGOALS(NEW_G1,NEW_G2);
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

TEST(ChampionshipTestGroupEditGameGetGoals, championshipTestEditGameGetGoalsFor){
    CHECK_EQUAL(NEW_G1, teams[0].gf);
    CHECK_EQUAL(NEW_G2, teams[1].gf);
}

TEST(ChampionshipTestGroupEditGameGetGoals, championshipTestEditGameGetGoalsAgainst){
    CHECK_EQUAL(NEW_G2, teams[0].ga);
    CHECK_EQUAL(NEW_G1, teams[1].ga);
}

TEST(ChampionshipTestGroupEditGameGetGoals, championshipTestEditGameGetGoalDiff){
    CHECK_EQUAL(NEW_G1-NEW_G2, teams[0].gd);
    CHECK_EQUAL(NEW_G2-NEW_G1, teams[1].gd);
}