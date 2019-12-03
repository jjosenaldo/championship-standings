/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Championship.h"

/* Clause SEES */
#include "Game_ctx.h"
#include "Team_ctx.h"

/* Clause IMPORTS */
#include "Game_editor.h"
#include "Team_position.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

/* Clause INITIALISATION */
void Championship__INITIALISATION(void)
{
    
    Game_editor__INITIALISATION();
    Team_position__INITIALISATION();
}

/* Clause OPERATIONS */

void Championship__getGameResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t *g1, int32_t *g2)
{
    Game_editor__ge_getGameResult(t1, t2, g1, g2);
}

void Championship__getPoints(Team_ctx__TEAM t1, int32_t *pp)
{
    Team_position__tp_getPoints(t1, pp);
}

void Championship__getWins(Team_ctx__TEAM t1, int32_t *ww)
{
    Team_position__tp_getWins(t1, ww);
}

void Championship__getDraws(Team_ctx__TEAM t1, int32_t *dd)
{
    Team_position__tp_getDraws(t1, dd);
}

void Championship__getLosses(Team_ctx__TEAM t1, int32_t *ll)
{
    Team_position__tp_getLosses(t1, ll);
}

void Championship__getGoalsFor(Team_ctx__TEAM t1, int32_t *gf)
{
    Team_position__tp_getGoalsFor(t1, gf);
}

void Championship__getGoalsAgainst(Team_ctx__TEAM t1, int32_t *ga)
{
    Team_position__tp_getGoalsAgainst(t1, ga);
}

void Championship__getGoalDiff(Team_ctx__TEAM t1, int32_t *gd)
{
    Team_position__tp_getGoalDiff(t1, gd);
}

void Championship__teamPosition(Team_ctx__TEAM tt, int32_t *pos)
{
    Team_position__tp_teamPosition(tt, pos);
}

void Championship__addNewGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2)
{
    Game_editor__ge_addNewGame(t1, t2, g1, g2);
}

void Championship__editGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2)
{
    Game_editor__ge_editGame(t1, t2, g1, g2);
}

void Championship__removeGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2)
{
    Game_editor__ge_removeGame(t1, t2);
}

