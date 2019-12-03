/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Game_info.h"

/* Clause SEES */
#include "Team_ctx.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static int32_t Game_info__gameResult1[Team_ctx__TEAM__max+1][Team_ctx__TEAM__max+1];
static int32_t Game_info__gameResult2[Team_ctx__TEAM__max+1][Team_ctx__TEAM__max+1];
/* Clause INITIALISATION */
void Game_info__INITIALISATION(void)
{
    
    unsigned int i = 0, j= 0;
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        for(j = 0; j <= Team_ctx__TEAM__max-1;j++)
        {
            Game_info__gameResult1[i][j] = -1;
        }
    }
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        for(j = 0; j <= Team_ctx__TEAM__max-1;j++)
        {
            Game_info__gameResult2[i][j] = -1;
        }
    }
}

/* Clause OPERATIONS */

void Game_info__gi_getGameResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t *g1, int32_t *g2)
{
    (*g1) = Game_info__gameResult1[t1][t2];
    (*g2) = Game_info__gameResult2[t1][t2];
}

void Game_info__getGoals1(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t *gg)
{
    (*gg) = Game_info__gameResult1[t1][t2];
}

void Game_info__getGoals2(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t *gg)
{
    (*gg) = Game_info__gameResult2[t1][t2];
}

void Game_info__addResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2)
{
    Game_info__gameResult1[t1][t2] = g1;
    Game_info__gameResult2[t1][t2] = g2;
}

void Game_info__editResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2)
{
    Game_info__gameResult1[t1][t2] = g1;
    Game_info__gameResult2[t1][t2] = g2;
}

void Game_info__removeResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2)
{
    Game_info__gameResult1[t1][t2] = -1;
    Game_info__gameResult2[t1][t2] = -1;
}

