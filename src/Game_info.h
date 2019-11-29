#ifndef _Game_info_h
#define _Game_info_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Team_ctx.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void Game_info__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Game_info__getGoals1(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t *gg);
extern void Game_info__getGoals2(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t *gg);
extern void Game_info__addResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);
extern void Game_info__editResult(Team_ctx__TEAM t1, Team_ctx__TEAM t2, int32_t g1, int32_t g2);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Game_info_h */
