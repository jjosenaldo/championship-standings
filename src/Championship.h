#ifndef _Championship_h
#define _Championship_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Game_ctx.h"
#include "Team_ctx.h"

/* Clause IMPORTS */
#include "Game_editor.h"
#include "Team_position.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void Championship__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Championship__teamPosition(Team_ctx__TEAM tt, int32_t *pos);
extern void Championship__addNewGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);
extern void Championship__editGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Championship_h */
