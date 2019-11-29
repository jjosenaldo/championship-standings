/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Team_info.h"

/* Clause SEES */
#include "Team_ctx.h"
#include "Game_ctx.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static int32_t Team_info__points_i[Team_ctx__TEAM__max+1];
static int32_t Team_info__wins_i[Team_ctx__TEAM__max+1];
static int32_t Team_info__draws_i[Team_ctx__TEAM__max+1];
static int32_t Team_info__losses_i[Team_ctx__TEAM__max+1];
static int32_t Team_info__goalsFor_i[Team_ctx__TEAM__max+1];
static int32_t Team_info__goalsAgainst_i[Team_ctx__TEAM__max+1];
static int32_t Team_info__goalDiff_i[Team_ctx__TEAM__max+1];
/* Clause INITIALISATION */
void Team_info__INITIALISATION(void)
{
    
    unsigned int i = 0;
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        Team_info__points_i[i] = 0;
    }
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        Team_info__wins_i[i] = 0;
    }
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        Team_info__draws_i[i] = 0;
    }
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        Team_info__losses_i[i] = 0;
    }
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        Team_info__goalsFor_i[i] = 0;
    }
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        Team_info__goalsAgainst_i[i] = 0;
    }
    for(i = 0; i <= Team_ctx__TEAM__max-1;i++)
    {
        Team_info__goalDiff_i[i] = 0;
    }
}

/* Clause OPERATIONS */

void Team_info__ti_addNewGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2)
{
    if((g1) < (g2))
    {
        Team_info__points_i[t2] = Team_info__points_i[t2]+Game_ctx__winpts;
        Team_info__wins_i[t2] = Team_info__wins_i[t2]+1;
        Team_info__losses_i[t1] = Team_info__losses_i[t1]+1;
    }
    else if((g1) > (g2))
    {
        Team_info__points_i[t1] = Team_info__points_i[t1]+Game_ctx__winpts;
        Team_info__wins_i[t1] = Team_info__wins_i[t1]+1;
        Team_info__losses_i[t2] = Team_info__losses_i[t2]+1;
    }
    else
    {
        Team_info__points_i[t1] = Team_info__points_i[t1]+Game_ctx__drawpts;
        Team_info__points_i[t2] = Team_info__points_i[t2]+Game_ctx__drawpts;
        Team_info__draws_i[t1] = Team_info__draws_i[t1]+1;
        Team_info__draws_i[t2] = Team_info__draws_i[t2]+1;
    }
    Team_info__goalsFor_i[t1] = Team_info__goalsFor_i[t1]+g1;
    Team_info__goalsFor_i[t2] = Team_info__goalsFor_i[t2]+g2;
    Team_info__goalsAgainst_i[t1] = Team_info__goalsAgainst_i[t1]+g2;
    Team_info__goalsAgainst_i[t2] = Team_info__goalsAgainst_i[t2]+g1;
    Team_info__goalDiff_i[t1] = Team_info__goalDiff_i[t1]+g1-g2;
    Team_info__goalDiff_i[t2] = Team_info__goalDiff_i[t2]+g2-g1;
}

void Team_info__ti_editGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2, int32_t oldG1, int32_t oldG2)
{
    Team_info__goalsFor_i[t1] = Team_info__goalsFor_i[t1]-oldG1+g1;
    Team_info__goalsFor_i[t2] = Team_info__goalsFor_i[t2]-oldG2+g2;
    Team_info__goalsAgainst_i[t1] = Team_info__goalsAgainst_i[t1]-oldG2+g2;
    Team_info__goalsAgainst_i[t2] = Team_info__goalsAgainst_i[t2]-oldG1+g1;
    Team_info__goalDiff_i[t1] = Team_info__goalDiff_i[t1]-(oldG1-oldG2)+g1-g2;
    Team_info__goalDiff_i[t2] = Team_info__goalDiff_i[t2]-(oldG2-oldG1)+g2-g1;
    if((g1) > (g2))
    {
        if(oldG1 == oldG2)
        {
            Team_info__points_i[t1] = Team_info__points_i[t1]+Game_ctx__winpts-Game_ctx__drawpts;
            Team_info__points_i[t2] = Team_info__points_i[t2]-Game_ctx__drawpts;
            Team_info__wins_i[t1] = Team_info__wins_i[t1]+1;
            Team_info__draws_i[t1] = Team_info__draws_i[t1]-1;
            Team_info__draws_i[t2] = Team_info__draws_i[t2]-1;
            Team_info__losses_i[t2] = Team_info__losses_i[t2]+1;
        }
        else if((oldG1) < (oldG2))
        {
            Team_info__points_i[t1] = Team_info__points_i[t1]+Game_ctx__winpts;
            Team_info__points_i[t2] = Team_info__points_i[t2]-Game_ctx__winpts;
            Team_info__wins_i[t1] = Team_info__wins_i[t1]+1;
            Team_info__wins_i[t2] = Team_info__wins_i[t2]-1;
            Team_info__losses_i[t1] = Team_info__losses_i[t1]-1;
            Team_info__losses_i[t2] = Team_info__losses_i[t2]+1;
        }
    }
    else if((g1) < (g2))
    {
        if(oldG1 == oldG2)
        {
            Team_info__points_i[t1] = Team_info__points_i[t1]-Game_ctx__drawpts;
            Team_info__points_i[t2] = Team_info__points_i[t2]+Game_ctx__winpts-Game_ctx__drawpts;
            Team_info__wins_i[t2] = Team_info__wins_i[t2]+1;
            Team_info__draws_i[t1] = Team_info__draws_i[t1]-1;
            Team_info__draws_i[t2] = Team_info__draws_i[t2]-1;
            Team_info__losses_i[t1] = Team_info__losses_i[t1]+1;
        }
        else if((oldG1) > (oldG2))
        {
            Team_info__points_i[t1] = Team_info__points_i[t1]-Game_ctx__winpts;
            Team_info__points_i[t2] = Team_info__points_i[t2]+Game_ctx__winpts;
            Team_info__wins_i[t1] = Team_info__wins_i[t1]-1;
            Team_info__wins_i[t2] = Team_info__wins_i[t2]+1;
            Team_info__losses_i[t1] = Team_info__losses_i[t1]+1;
            Team_info__losses_i[t2] = Team_info__losses_i[t2]-1;
        }
    }
    else
    {
        if((oldG1) < (oldG2))
        {
            Team_info__points_i[t1] = Team_info__points_i[t1]+Game_ctx__drawpts;
            Team_info__points_i[t2] = Team_info__points_i[t2]-(Game_ctx__winpts-Game_ctx__drawpts);
            Team_info__wins_i[t2] = Team_info__wins_i[t2]-1;
            Team_info__draws_i[t1] = Team_info__draws_i[t1]+1;
            Team_info__draws_i[t2] = Team_info__draws_i[t2]+1;
            Team_info__losses_i[t1] = Team_info__losses_i[t1]-1;
        }
        else if((oldG1) > (oldG2))
        {
            Team_info__points_i[t1] = Team_info__points_i[t1]-(Game_ctx__winpts-Game_ctx__drawpts);
            Team_info__points_i[t2] = Team_info__points_i[t2]+Game_ctx__drawpts;
            Team_info__wins_i[t1] = Team_info__wins_i[t1]-1;
            Team_info__draws_i[t1] = Team_info__draws_i[t1]+1;
            Team_info__draws_i[t2] = Team_info__draws_i[t2]+1;
            Team_info__losses_i[t2] = Team_info__losses_i[t2]-1;
        }
    }
}

void Team_info__getPoints(Team_ctx__TEAM tt, int32_t *pt)
{
    (*pt) = Team_info__points_i[tt];
}

void Team_info__getWins(Team_ctx__TEAM tt, int32_t *ww)
{
    (*ww) = Team_info__wins_i[tt];
}

void Team_info__getDraws(Team_ctx__TEAM tt, int32_t *dd)
{
    (*dd) = Team_info__draws_i[tt];
}

void Team_info__getLosses(Team_ctx__TEAM tt, int32_t *ll)
{
    (*ll) = Team_info__losses_i[tt];
}

void Team_info__getGoalsFor(Team_ctx__TEAM tt, int32_t *gf)
{
    (*gf) = Team_info__goalsFor_i[tt];
}

void Team_info__getGoalsAgainst(Team_ctx__TEAM tt, int32_t *ga)
{
    (*ga) = Team_info__goalsAgainst_i[tt];
}

void Team_info__getGoalDiff(Team_ctx__TEAM tt, int32_t *gd)
{
    (*gd) = Team_info__goalDiff_i[tt];
}

