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

