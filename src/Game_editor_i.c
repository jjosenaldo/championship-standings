/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Game_editor.h"

/* Clause SEES */
#include "Team_ctx.h"
#include "Game_ctx.h"

/* Clause IMPORTS */
#include "Game_info.h"
#include "Team_info.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

/* Clause INITIALISATION */
void Game_editor__INITIALISATION(void)
{
    
    Game_info__INITIALISATION();
    Team_info__INITIALISATION();
}

/* Clause OPERATIONS */

void Game_editor__ge_addNewGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2)
{
    Team_info__ti_addNewGame(t1, t2, g1, g2);
    Game_info__addResult(t1, t2, g1, g2);
}

void Game_editor__ge_editGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2)
{
    {
        int32_t oldG1;
        int32_t oldG2;
        
        Game_info__getGoals1(t1, t2, &oldG1);
        Game_info__getGoals2(t1, t2, &oldG2);
        Team_info__ti_editGame(t1, t2, g1, g2, oldG1, oldG2);
    }
    Game_info__editResult(t1, t2, g1, g2);
}

