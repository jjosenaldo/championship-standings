#ifndef _Team_info_h
#define _Team_info_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Team_ctx.h"
#include "Game_ctx.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void Team_info__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Team_info__ti_addNewGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);
extern void Team_info__ti_editGame(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2, int32_t oldG1, int32_t oldG2);
extern void Team_info__getPoints(Team_ctx__TEAM tt, int32_t *pt);
extern void Team_info__getWins(Team_ctx__TEAM tt, int32_t *ww);
extern void Team_info__getDraws(Team_ctx__TEAM tt, int32_t *dd);
extern void Team_info__getLosses(Team_ctx__TEAM tt, int32_t *ll);
extern void Team_info__getGoalsFor(Team_ctx__TEAM tt, int32_t *gf);
extern void Team_info__getGoalsAgainst(Team_ctx__TEAM tt, int32_t *ga);
extern void Team_info__getGoalDiff(Team_ctx__TEAM tt, int32_t *gd);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Team_info_h */
