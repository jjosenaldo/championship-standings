/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Team_position.h"

/* Clause SEES */
#include "Team_info.h"
#include "Team_ctx.h"

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

