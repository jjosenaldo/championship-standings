#include <iostream>
#include "testChampionship.h"

#define EDITGAMEGOALS(g1,g2) EDITGAME(teams[0], teams[1], g1,g2)

#define OLD_G1 3
#define OLD_G2 1

#define NEW_W_G1 5
#define NEW_W_G2 4

#define NEW_D_G 4

#define NEW_L_G1 2
#define NEW_L_G2 7

TEST_GROUP(ChampionshipTestGroupEditGameGetWDL){
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

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToWinGetPoints){
    EDITGAMEGOALS(NEW_W_G1,NEW_W_G2);
    setTeamsInfo();
    CHECK_EQUAL(PT_WIN, teams[0].pt);
    CHECK_EQUAL(0, teams[1].pt);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToWinGetWins){
    EDITGAMEGOALS(NEW_W_G1,NEW_W_G2);
    setTeamsInfo();
    CHECK_EQUAL(1, teams[0].w);
    CHECK_EQUAL(0, teams[1].w);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToWinGetDraws){
    EDITGAMEGOALS(NEW_W_G1,NEW_W_G2);
    setTeamsInfo();
    CHECK_EQUAL(0, teams[0].d);
    CHECK_EQUAL(0, teams[1].d);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToWinGetLosses){
    EDITGAMEGOALS(NEW_W_G1,NEW_W_G2);
    setTeamsInfo();
    CHECK_EQUAL(0, teams[0].l);
    CHECK_EQUAL(1, teams[1].l);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToDrawGetPoints){
    EDITGAMEGOALS(NEW_D_G,NEW_D_G);
    setTeamsInfo();
    CHECK_EQUAL(PT_DRAW, teams[0].pt);
    CHECK_EQUAL(PT_DRAW, teams[1].pt);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToDrawGetWins){
    EDITGAMEGOALS(NEW_D_G,NEW_D_G);
    setTeamsInfo();
    CHECK_EQUAL(0, teams[0].w);
    CHECK_EQUAL(0, teams[1].w);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToDrawGetDraws){
    EDITGAMEGOALS(NEW_D_G,NEW_D_G);
    setTeamsInfo();
    CHECK_EQUAL(1, teams[0].d);
    CHECK_EQUAL(1, teams[1].d);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToDrawGetLosses){
    EDITGAMEGOALS(NEW_D_G,NEW_D_G);
    setTeamsInfo();
    CHECK_EQUAL(0, teams[0].l);
    CHECK_EQUAL(0, teams[1].l);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToLossGetPoints){
    EDITGAMEGOALS(NEW_L_G1,NEW_L_G2);
    setTeamsInfo();
    CHECK_EQUAL(0, teams[0].pt);
    CHECK_EQUAL(PT_WIN, teams[1].pt);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToLossGetWins){
    EDITGAMEGOALS(NEW_L_G1,NEW_L_G2);
    setTeamsInfo();
    CHECK_EQUAL(0, teams[0].w);
    CHECK_EQUAL(1, teams[1].w);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToLossGetDraws){
    EDITGAMEGOALS(NEW_L_G1,NEW_L_G2);
    setTeamsInfo();
    CHECK_EQUAL(0, teams[0].d);
    CHECK_EQUAL(0, teams[1].d);
}

TEST(ChampionshipTestGroupEditGameGetWDL, championshipTestEditToLossGetLosses){
    EDITGAMEGOALS(NEW_L_G1,NEW_L_G2);
    setTeamsInfo();
    CHECK_EQUAL(1, teams[0].l);
    CHECK_EQUAL(0, teams[1].l);
}