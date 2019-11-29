#ifndef _Game_editor_h
#define _Game_editor_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Team_ctx.h"
#include "Game_ctx.h"

/* Clause INCLUDES */
#include "Team_info.h"
#include "Game_info.h"

/* Clause IMPORTS */
#include "Game_info.h"
#include "Team_info.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void Game_editor__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Game_editor__ge_addNewGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);
extern void Game_editor__ge_editGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Game_editor_h */
