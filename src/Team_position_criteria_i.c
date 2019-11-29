/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Team_position_criteria.h"

/* Clause SEES */
#include "Team_ctx.h"
#include "Team_info.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

/* Clause INITIALISATION */
void Team_position_criteria__INITIALISATION(void)
{
    
}

/* Clause OPERATIONS */

void Team_position_criteria__isBetterTeam(Team_ctx__TEAM t1, Team_ctx__TEAM t2, bool *tt)
{
    {
        int32_t pt1;
        int32_t pt2;
        
        Team_info__getPoints(t1, &pt1);
        Team_info__getPoints(t2, &pt2);
        if((pt1) > (pt2))
        {
            (*tt) = true;
        }
        else if((pt1) < (pt2))
        {
            (*tt) = false;
        }
        else
        {
            {
                int32_t ww1;
                int32_t ww2;
                
                Team_info__getWins(t1, &ww1);
                Team_info__getWins(t2, &ww2);
                if((ww1) > (ww2))
                {
                    (*tt) = true;
                }
                else if((ww1) < (ww2))
                {
                    (*tt) = false;
                }
                else
                {
                    {
                        int32_t gd1;
                        int32_t gd2;
                        
                        Team_info__getGoalDiff(t1, &gd1);
                        Team_info__getGoalDiff(t2, &gd2);
                        if((gd1) > (gd2))
                        {
                            (*tt) = true;
                        }
                        else if((gd1) < (gd2))
                        {
                            (*tt) = false;
                        }
                        else
                        {
                            {
                                int32_t gf1;
                                int32_t gf2;
                                
                                Team_info__getGoalsFor(t1, &gf1);
                                Team_info__getGoalsFor(t2, &gf2);
                                if((gf1) > (gf2))
                                {
                                    (*tt) = true;
                                }
                                else
                                {
                                    (*tt) = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

