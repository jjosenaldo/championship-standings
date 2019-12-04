#ifndef TEST_CHAMPIONSHIP_H
#define TEST_CHAMPIONSHIP_H

#include <array>
#include <string>

#include "CppUTest/TestHarness.h"
#include "Championship.h"

using std::array;
using std::string;
using std::to_string;

#define PT_WIN 3
#define PT_DRAW 1

#define INIT INITCHAMP;INITGAMECTX;INITTEAMCTX;
#define INITCHAMP Championship__INITIALISATION() 
#define INITGAMECTX Game_ctx__INITIALISATION() 
#define INITTEAMCTX Team_ctx__INITIALISATION()
#define ADDGAME(t1,t2,g1,g2) Championship__addNewGame(t1.id, t2.id, g1,g2)
#define EDITGAME(t1,t2,g1,g2) Championship__editGame(t1.id, t2.id, g1,g2)
#define REMOVEGAME(t1,t2) Championship__removeGame(t1.id, t2.id)
#define GETRESULT(t1,t2,r1,r2) Championship__getGameResult(t1.id, t2.id,&r1,&r2)
#define TEAMPOS(t) Championship__teamPosition(t.id, &t.pos)
#define POS(t) Championship__teamPosition(t.id, &t.pos)
#define PTS(t) Championship__getPoints(t.id, &t.pt)
#define WINS(t) Championship__getWins(t.id, &t.w)
#define DRAWS(t) Championship__getDraws(t.id, &t.d)
#define LOSSES(t) Championship__getLosses(t.id, &t.l)
#define GF(t) Championship__getGoalsFor(t.id, &t.gf)
#define GA(t) Championship__getGoalsAgainst(t.id, &t.ga)
#define GD(t) Championship__getGoalDiff(t.id, &t.gd)

extern int initFlag;

void init();

struct Team{
    int id;
    string name;
    int pos;
    int pt;
    int w;
    int d;
    int l;
    int gf;
    int ga;
    int gd;

    Team(int id, string name);

    Team() : Team(0, ""){}

    string toString();
};

#endif