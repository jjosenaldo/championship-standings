#ifndef _Team_position_criteria_h
#define _Team_position_criteria_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Team_ctx.h"
#include "Team_info.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void Team_position_criteria__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Team_position_criteria__isBetterTeam(Team_ctx__TEAM t1, Team_ctx__TEAM t2, bool *tt);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Team_position_criteria_h */
