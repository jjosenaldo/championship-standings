#ifndef _Team_ctx_h
#define _Team_ctx_h

#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define Team_ctx__TEAM__max 4
/* Clause SETS */
typedef int Team_ctx__TEAM;

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

#define Team_ctx__teamsize 4
/* Array and record constants */
extern const Team_ctx__TEAM Team_ctx__teamseq[5];

extern void Team_ctx__INITIALISATION(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Team_ctx_h */
