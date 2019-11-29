MACHINE
    Team_info

SEES
    Team_ctx, Game_ctx

VARIABLES
    ti_points, ti_wins, ti_draws, ti_losses, ti_goalsFor, ti_goalsAgainst, ti_goalDiff

INVARIANT    
    // Typing
    ti_points : TEAM --> NAT &
    ti_wins : TEAM --> NAT &
    ti_draws : TEAM --> NAT &
    ti_losses : TEAM --> NAT &
    ti_goalsFor : TEAM --> NAT &
    ti_goalsAgainst : TEAM --> NAT &
    ti_goalDiff : TEAM --> INT  &

    // Number of points
    !(tt).(tt : TEAM => ti_points(tt) = winpts*ti_wins(tt)+drawpts*ti_draws(tt)) &

    // Goal difference
    !(tt).(tt : TEAM => ti_goalDiff(tt) = ti_goalsFor(tt)-ti_goalsAgainst(tt)) 

INITIALISATION
    ti_points := TEAM * {0} ||
    ti_wins := TEAM * {0} ||
    ti_draws := TEAM * {0} ||
    ti_losses := TEAM * {0} || 
    ti_goalsFor := TEAM * {0} || 
    ti_goalsAgainst := TEAM * {0} || 
    ti_goalDiff := TEAM * {0} 

OPERATIONS
    ti_addNewGame(t1, t2, g1, g2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1 /= t2 & g1 : NAT & g2 : NAT
    THEN
        // Updates the points/wins/draws/losses of each team
        IF g1 < g2 THEN 
            ti_points(t2) := ti_points(t2) + winpts || 
            ti_wins(t2) := ti_wins(t2) + 1 || 
            ti_losses(t1) := ti_losses(t1) + 1 
        ELSIF g1 > g2 THEN 
            ti_points(t1) := ti_points(t1) + winpts ||
            ti_wins(t1) := ti_wins(t1) + 1 || 
            ti_losses(t2) := ti_losses(t2) + 1
        ELSE 
            ti_points := ti_points <+ {t1 |-> ti_points(t1)+drawpts,t2 |-> ti_points(t2)+1} || 
            ti_draws := ti_draws <+ {t1 |-> ti_draws(t1)+drawpts,t2 |-> ti_draws(t2)+1}
        END END ||
        
        // Adds the goals of each team
        ti_goalsFor := ti_goalsFor <+ {t1 |-> ti_goalsFor(t1)+g1,
            t2 |-> ti_goalsFor(t2)+g2} ||
        ti_goalsAgainst := ti_goalsAgainst <+ {t1 |-> ti_goalsAgainst(t1)+g2,
            t2 |-> ti_goalsAgainst(t2)+g1} ||
        ti_goalDiff := ti_goalDiff <+ {t1 |-> ti_goalDiff(t1)+g1-g2,
            t2 |-> ti_goalDiff(t2)+g2-g1}      
    END;

    ti_editGame(t1,t2,g1,g2,oldG1,oldG2) = 
    PRE
        t1 : TEAM & t2 : TEAM & g1 : NAT & g2 : NAT & oldG1 : NAT & oldG2 : NAT
    THEN
        // Updates the goals for/against and the goal difference
        ti_goalsFor := ti_goalsFor <+ {t1 |-> ti_goalsFor(t1) - oldG1 + g1, 
            t2 |-> ti_goalsFor(t2) - oldG2 + g2} ||
        ti_goalsAgainst := ti_goalsAgainst <+ {t1 |-> ti_goalsAgainst(t1) - oldG2 + g2, 
            t2 |-> ti_goalsAgainst(t2) - oldG1 + g1} ||
        ti_goalDiff := ti_goalDiff <+ {t1 |-> ti_goalDiff(t1) - (oldG1 - oldG2) 
            + g1 - g2,
            t2 |-> ti_goalDiff(t2) - (oldG2 - oldG1) 
            + g2 - g1} ||
        
        // Updates the points/wins/draws/losses of both TEAM
        IF g1 > g2 THEN
            IF oldG1 = oldG2 THEN
                ti_points := ti_points <+ {t1 |-> ti_points(t1) + winpts - drawpts, t2 |-> ti_points(t2) - drawpts} ||
                ti_wins(t1) := ti_wins(t1)+1 || 
                ti_draws := ti_draws <+ {t1 |-> ti_draws(t1)-1, t2 |-> ti_draws(t2)-1} ||
                ti_losses(t2) := ti_losses(t2)+1
            ELSIF oldG1 < oldG2 THEN
                ti_points := ti_points <+ {t1 |-> ti_points(t1) + winpts, t2 |-> ti_points(t2) - winpts} ||
                ti_wins := ti_wins <+ {t1 |-> ti_wins(t1)+1, t2 |-> ti_wins(t2)-1} ||
                ti_losses := ti_losses <+ {t1 |-> ti_losses(t1)-1, t2 |-> ti_losses(t2)+1}
            END
        ELSIF g1 < g2 THEN 
            IF oldG1 = oldG2 THEN
                ti_points := ti_points <+ {t1 |-> ti_points(t1) -drawpts, t2 |-> ti_points(t2) + winpts - drawpts} ||
                ti_wins(t2) := ti_wins(t2)+1 ||
                ti_draws := ti_draws <+ {t1 |-> ti_draws(t1)-1, t2 |-> ti_draws(t2)-1} ||
                ti_losses(t1) := ti_losses(t1)+1
            ELSIF oldG1 > oldG2 THEN
                ti_points := ti_points <+ {t1 |-> ti_points(t1) - winpts, t2 |-> ti_points(t2) + winpts} ||
                ti_wins := ti_wins <+ {t1 |-> ti_wins(t1)-1, t2 |-> ti_wins(t2)+1} ||
                ti_losses := ti_losses <+ {t1 |-> ti_losses(t1)+1, t2 |-> ti_losses(t2)-1}
            END
        ELSE
            IF oldG1 < oldG2 THEN
                ti_points := ti_points <+ {t1 |-> ti_points(t1) + drawpts, t2 |-> ti_points(t2) - (winpts - drawpts)} ||
                ti_wins(t2) := ti_wins(t2)-1 ||
                ti_draws := ti_draws <+ {t1 |-> ti_draws(t1)+1, t2 |-> ti_draws(t2)+1} ||
                ti_losses(t1) := ti_losses(t1)-1 
            ELSIF oldG1 > oldG2 THEN
                ti_points := ti_points <+ {t2 |-> ti_points(t2) + drawpts, t1 |-> ti_points(t1) - (winpts - drawpts)} ||
                ti_wins(t1) := ti_wins(t1)-1 ||
                ti_draws := ti_draws <+ {t2 |-> ti_draws(t2)+1, t1 |-> ti_draws(t1)+1} ||
                ti_losses(t2) := ti_losses(t2)-1 
            END
        END 
    END;

    pt <-- ti_getPoints(tt) = 
    PRE
        tt : TEAM
    THEN
        pt := ti_points(tt)
    END;

    ww <-- ti_getWins(tt) = 
    PRE
        tt : TEAM
    THEN
        ww := ti_wins(tt)
    END;

    dd <-- ti_getDraws(tt) = 
    PRE
        tt : TEAM
    THEN
        dd := ti_draws(tt)
    END;

    ll <-- ti_getLosses(tt) = 
    PRE
        tt : TEAM
    THEN
        ll := ti_losses(tt)
    END;

    gf <-- ti_getGoalsFor(tt) = 
    PRE
        tt : TEAM
    THEN
        gf := ti_goalsFor(tt)
    END;

    ga <-- ti_getGoalsAgainst(tt) = 
    PRE
        tt : TEAM
    THEN
        ga := ti_goalsAgainst(tt)
    END;

    gd <-- ti_getGoalDiff(tt) = 
    PRE
        tt : TEAM
    THEN
        gd := ti_goalDiff(tt)
    END
END