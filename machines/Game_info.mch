MACHINE 
    Game_info   

SEES
    Team_ctx

VARIABLES
    gi_gameResult

INVARIANT
    gi_gameResult : TEAM*TEAM-id(TEAM) +-> NAT * NAT

INITIALISATION
    gi_gameResult := {}

OPERATIONS
    gg <-- getGoals1(t1,t2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1 /= t2
    THEN
        gg := prj1(NAT,NAT)(gi_gameResult(t1,t2))
    END;

    gg <-- getGoals2(t1,t2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1 /= t2
    THEN
        gg := prj2(NAT,NAT)(gi_gameResult(t1,t2))
    END;

    addResult(t1,t2,g1,g2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1|->t2 /: dom(gi_gameResult) & g1 : NAT & g2 : NAT
    THEN
        gi_gameResult(t1|->t2) := g1|->g2
    END;

    editResult (t1,t2,g1,g2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1|->t2 : dom(gi_gameResult) & g1 : NAT & g2 : NAT
    THEN
        gi_gameResult(t1|->t2) := g1|->g2
    END
END