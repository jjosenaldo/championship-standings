#ifndef _Team_position_h
#define _Team_position_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Team_ctx.h"
#include "Team_info.h"

/* Clause IMPORTS */
#include "Team_position_criteria.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void Team_position__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Team_position__tp_getPoints(Team_ctx__TEAM tt, int32_t *pt);
extern void Team_position__tp_getWins(Team_ctx__TEAM tt, int32_t *ww);
extern void Team_position__tp_getDraws(Team_ctx__TEAM tt, int32_t *dd);
extern void Team_position__tp_getLosses(Team_ctx__TEAM tt, int32_t *ll);
extern void Team_position__tp_getGoalsFor(Team_ctx__TEAM tt, int32_t *gf);
extern void Team_position__tp_getGoalsAgainst(Team_ctx__TEAM tt, int32_t *ga);
extern void Team_position__tp_getGoalDiff(Team_ctx__TEAM tt, int32_t *gd);
extern void Team_position__tp_teamPosition(Team_ctx__TEAM tt, int32_t *pos);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Team_position_h */
