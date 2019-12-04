#include <utility>
#include <vector>
#include "testChampionship.h"

using std::make_pair;
using std::pair;
using std::vector;

#include <iostream>
using std::cout;
using std::endl;
TEST_GROUP(ChampionshipTestGroupTeamPosition){
    array<Team, 4> teams;
    vector<pair<long unsigned int,long unsigned int>> games;

    TEST_SETUP(){
        Team barca = Team(1, "Barcelona");
        Team inter = Team(2, "Inter");
        Team borussia = Team(3, "Borussia Dortmund");
        Team prague = Team(4, "Slavia Prague");
        teams[0] = barca;
        teams[1] = inter;
        teams[2] = borussia;
        teams[3] = prague;
    }

    TEST_TEARDOWN(){
        for(auto p : games)
            REMOVEGAME(teams[p.first], teams[p.second]);
        games.clear();
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

    games.push_back(make_pair(1,3));
    games.push_back(make_pair(2,0));
    games.push_back(make_pair(3,2));
    games.push_back(make_pair(0,1));
    games.push_back(make_pair(3,0));
    games.push_back(make_pair(1,2));
    games.push_back(make_pair(0,3));
    games.push_back(make_pair(2,1));
    games.push_back(make_pair(0,2));
    games.push_back(make_pair(3,1));

    setTeamsInfo();

    CHECK_EQUAL(1, teams[0].pos);
    CHECK_EQUAL(2, teams[1].pos);
    CHECK_EQUAL(3, teams[2].pos);
    CHECK_EQUAL(4, teams[3].pos);
}

TEST(ChampionshipTestGroupTeamPosition, championshipTestGroupTeamPositionSamePointsDiffWins){
    //               P  W 
    // 1 barcelona   8  2
    // 2 inter       6  1
    // 3 prague      3  1
    // 4 borussia    3  3
    ADDGAME(teams[1], teams[2], 0, 0);
    ADDGAME(teams[0], teams[3], 2, 0);

    ADDGAME(teams[3], teams[2], 2, 0);
    ADDGAME(teams[1], teams[0], 1, 1);

    ADDGAME(teams[0], teams[2], 0, 0);
    ADDGAME(teams[1], teams[3], 5, 0);

    ADDGAME(teams[2], teams[1], 0, 0);
    ADDGAME(teams[3], teams[0], 1, 2);
    
    games.push_back(make_pair(1,2));
    games.push_back(make_pair(0,3));
    games.push_back(make_pair(3,2));
    games.push_back(make_pair(1,0));
    games.push_back(make_pair(0,2));
    games.push_back(make_pair(1,3));
    games.push_back(make_pair(2,1));
    games.push_back(make_pair(3,0));

    setTeamsInfo();

    CHECK_EQUAL(1, teams[0].pos);
    CHECK_EQUAL(2, teams[1].pos);
    CHECK_EQUAL(3, teams[3].pos);
    CHECK_EQUAL(4, teams[2].pos);
}

TEST(ChampionshipTestGroupTeamPosition, championshipTestGroupTeamPositionSamePointsWinsGdDiffGd){
    ADDGAME(teams[0], teams[1], 2, 1);
    ADDGAME(teams[2], teams[3], 3, 2);

    ADDGAME(teams[0], teams[2], 0, 0);

    games.push_back(make_pair(0,1));
    games.push_back(make_pair(2,3));
    games.push_back(make_pair(0,2));

    setTeamsInfo();

    CHECK_EQUAL(1, teams[2].pos);
    CHECK_EQUAL(2, teams[0].pos);
}