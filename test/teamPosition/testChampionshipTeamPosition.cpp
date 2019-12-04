#include "testChampionship.h"

TEST_GROUP(ChampionshipTestGroupTeamPosition){
    array<Team, 4> teams;

    TEST_SETUP(){
        Team barca = Team(1, "Barcelona");
        Team inter = Team(2, "Inter");
        Team borussia = Team(3, "Borussia Dortmund");
        Team prague = Team(4, "Slavia Prague");
        teams[0] = barca;
        teams[1] = inter;
        teams[2] = borussia;
        teams[3] = prague;

        ADDGAME(teams[1], teams[3], 1, 1);
        ADDGAME(teams[2], teams[0], 0, 0);

        ADDGAME(teams[3], teams[2], 0, 2);
        ADDGAME(teams[0], teams[1], 2, 1);

        ADDGAME(teams[3], teams[0], 1, 2);
        ADDGAME(teams[1], teams[2], 2, 0);

        ADDGAME(teams[0], teams[3], 0, 0);
        ADDGAME(teams[2], teams[1], 3, 2);

        ADDGAME(teams[0], teams[2], 3, 1);
        ADDGAME(teams[3], teams[1], 1, 3);

        setTeamsInfo();
    }

    TEST_TEARDOWN(){
        REMOVEGAME(teams[1], teams[3]);
        REMOVEGAME(teams[2], teams[0]);
        REMOVEGAME(teams[3], teams[2]);
        REMOVEGAME(teams[0], teams[1]);
        REMOVEGAME(teams[3], teams[0]);
        REMOVEGAME(teams[1], teams[2]);
        REMOVEGAME(teams[0], teams[3]);
        REMOVEGAME(teams[2], teams[1]);
        REMOVEGAME(teams[0], teams[2]);
        REMOVEGAME(teams[3], teams[1]);
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

TEST(ChampionshipTestGroupTeamPosition, championshipTestGroupTeamPosition){
    CHECK_EQUAL(1, teams[0].pos);
    CHECK_EQUAL(2, teams[1].pos);
    CHECK_EQUAL(3, teams[2].pos);
    CHECK_EQUAL(4, teams[3].pos);
}