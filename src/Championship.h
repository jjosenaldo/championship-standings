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

extern void Championship__getGameResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t *g1, int32_t *g2);
extern void Championship__getPoints(Team_ctx__TEAM t1, int32_t *pp);
extern void Championship__getWins(Team_ctx__TEAM t1, int32_t *ww);
extern void Championship__getDraws(Team_ctx__TEAM t1, int32_t *dd);
extern void Championship__getLosses(Team_ctx__TEAM t1, int32_t *ll);
extern void Championship__getGoalsFor(Team_ctx__TEAM t1, int32_t *gf);
extern void Championship__getGoalsAgainst(Team_ctx__TEAM t1, int32_t *ga);
extern void Championship__getGoalDiff(Team_ctx__TEAM t1, int32_t *gd);
extern void Championship__teamPosition(Team_ctx__TEAM tt, int32_t *pos);
extern void Championship__addNewGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);
extern void Championship__removeGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2);
extern void Championship__editGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Championship_h */
