/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Team_position.h"

/* Clause SEES */
#include "Team_ctx.h"
#include "Team_info.h"

/* Clause IMPORTS */
#include "Team_position_criteria.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

/* Clause INITIALISATION */
void Team_position__INITIALISATION(void)
{
    
    Team_position_criteria__INITIALISATION();
}

/* Clause OPERATIONS */

void Team_position__tp_getPoints(Team_ctx__TEAM tt, int32_t *pt)
{
    Team_info__ti_getPoints(tt, pt);
}

void Team_position__tp_getWins(Team_ctx__TEAM tt, int32_t *ww)
{
    Team_info__ti_getWins(tt, ww);
}

void Team_position__tp_getDraws(Team_ctx__TEAM tt, int32_t *dd)
{
    Team_info__ti_getDraws(tt, dd);
}

void Team_position__tp_getLosses(Team_ctx__TEAM tt, int32_t *ll)
{
    Team_info__ti_getLosses(tt, ll);
}

void Team_position__tp_getGoalsFor(Team_ctx__TEAM tt, int32_t *gf)
{
    Team_info__ti_getGoalsFor(tt, gf);
}

void Team_position__tp_getGoalsAgainst(Team_ctx__TEAM tt, int32_t *ga)
{
    Team_info__ti_getGoalsAgainst(tt, ga);
}

void Team_position__tp_getGoalDiff(Team_ctx__TEAM tt, int32_t *gd)
{
    Team_info__ti_getGoalDiff(tt, gd);
}

void Team_position__tp_teamPosition(Team_ctx__TEAM tt, int32_t *pos)
{
    (*pos) = 1;
    {
        int32_t ii;
        int32_t NN;
        
        ii = 0;
        NN = Team_ctx__teamsize;
        while((ii) < (NN))
        {
            ii = ii+1;
            {
                Team_ctx__TEAM otherTeam;
                
                otherTeam = Team_ctx__teamseq[ii];
                {
                    bool betterTeamRes;
                    
                    Team_position_criteria__isBetterTeam(otherTeam, tt, &betterTeamRes);
                    if(betterTeamRes == true)
                    {
                        (*pos) = (*pos)+1;
                    }
                }
            }
        }
    }
}

