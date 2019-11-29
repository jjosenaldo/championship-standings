MACHINE
    Team_ctx
SETS 
    TEAM
CONSTANTS
    teamseq, teamsize
PROPERTIES
    // teamsize
    teamsize : NAT & teamsize = card(TEAM) &

    // teamseq
    teamseq : 0..4 --> TEAM  & teamseq[1..card(TEAM)] = TEAM 
END

