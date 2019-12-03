/* ChampionshipStandings
 * Author: junho
 * Creation date: 09/09/2019
 */
MACHINE
    Championship

SEES
    Team_ctx, Game_ctx

VARIABLES
    gameResult,  points, wins, draws, losses, goalsFor, goalsAgainst, goalDiff
    
INVARIANT
    // Typing
    points : TEAM --> NAT &
    wins : TEAM --> NAT &
    draws : TEAM --> NAT &
    losses : TEAM --> NAT &
    goalsFor : TEAM --> NAT &
    goalsAgainst : TEAM --> NAT &
    goalDiff : TEAM --> INT &
    gameResult : TEAM*TEAM-id(TEAM) +-> NAT * NAT &
    
    // Number of points
    !(tt).(tt : TEAM => points(tt) = winpts*wins(tt)+drawpts*draws(tt)) &
    
    // Number of wins
    !(tt).(tt : TEAM => wins(tt) = card( {game | game : dom(gameResult) & prj1(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gameResult(game)) >     prj2(NAT,NAT)(gameResult(game)) } \/ {game | game : dom(gameResult) & prj2(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gameResult(game)) < prj2(NAT,NAT)(gameResult(game)) } )  ) &
    
    // Number of losses
    !(tt).(tt : TEAM => losses(tt) = card( {game | game : dom(gameResult) & prj1(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gameResult(game)) < prj2(NAT,NAT)(gameResult(game)) } \/ {game | game : dom(gameResult) & prj2(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gameResult(game)) > prj2(NAT,NAT)(gameResult(game)) } )  ) &
    
    // Number of draws
    !(tt).(tt : TEAM => draws(tt) = card( {game | game : dom(gameResult) & (prj1(TEAM,TEAM)(game) = tt or prj2(TEAM,TEAM)(game) = tt)& prj1(NAT,NAT)(gameResult(game)) = prj2(NAT,NAT)(gameResult(game)) } )  ) &
    
    // Number of goals for
    !(tt).(tt : TEAM => goalsFor(tt) = SIGMA(game).( game:dom(gameResult) & tt = prj1(TEAM,TEAM)(game) | prj1(NAT,NAT)(gameResult(game))) + SIGMA(game).( game:dom(gameResult) & tt = prj2(TEAM,TEAM)(game) | prj2(NAT,NAT)(gameResult(game)))) &
    
    // Number of goals against
    !(tt).(tt : TEAM => goalsAgainst(tt) = SIGMA(game).( game:dom(gameResult) & tt = prj1(TEAM,TEAM)(game) | prj2(NAT,NAT)(gameResult(game))) + SIGMA(game).( game:dom(gameResult) & tt = prj2(TEAM,TEAM)(game) | prj1(NAT,NAT)(gameResult(game)))) &
    
    // Goal difference
    !(tt).(tt : TEAM => goalDiff(tt) = goalsFor(tt)-goalsAgainst(tt)) & 
    
    // Number of games
    !(tt).(tt : TEAM => wins(tt)+draws(tt)+losses(tt) = card({game | game:dom(gameResult) & (prj1(TEAM,TEAM)(game)=tt or prj2(TEAM,TEAM)(game)=tt)}))
    
INITIALISATION
    gameResult := {} || 
    points := TEAM * {0} ||
    wins := TEAM * {0} ||
    draws := TEAM * {0} ||
    losses := TEAM * {0} || 
    goalsFor := TEAM * {0} || 
    goalsAgainst := TEAM * {0} || 
    goalDiff := TEAM * {0} 

OPERATIONS
    g1,g2 <-- getGameResult(t1, t2) = 
    PRE 
        t1 : TEAM & t2 : TEAM & t1|->t2 : dom(gameResult)
    THEN
        LET res BE res=gameResult(t1|->t2) IN 
            g1 := prj1(NAT,NAT)(res) || g2 := prj1(NAT,NAT)(res)
        END
    END;        

    pp <-- getPoints(t1) = 
    PRE 
        t1 : TEAM 
    THEN 
        pp := points(t1)
    END ;

    ww <-- getWins(t1) = 
    PRE 
        t1 : TEAM 
    THEN 
        ww := wins(t1)
    END ;

    dd <-- getDraws(t1) = 
    PRE 
        t1 : TEAM 
    THEN 
        dd := draws(t1)
    END ;

    ll <-- getLosses(t1) = 
    PRE 
        t1 : TEAM 
    THEN 
        ll := losses(t1)
    END ;

    gf <-- getGoalsFor(t1) = 
    PRE 
        t1 : TEAM 
    THEN 
        gf := goalsFor(t1)
    END ;

    ga <-- getGoalsAgainst(t1) = 
    PRE 
        t1 : TEAM 
    THEN 
        ga := goalsAgainst(t1)
    END ;

    gd <-- getGoalDiff(t1) = 
    PRE 
        t1 : TEAM 
    THEN 
        gd := goalDiff(t1)
    END ;

    pos <-- teamPosition(tt) = 
    PRE
        tt : TEAM
    THEN
        pos := card({ betterTeam | betterTeam : TEAM & points(tt) < points(betterTeam)}) + 
               card({ betterTeam | betterTeam : TEAM & points(tt) = points(betterTeam) & wins(tt)<wins(betterTeam)}) + 
               card({ betterTeam | betterTeam : TEAM & points(tt) = points(betterTeam) & wins(tt)=wins(betterTeam) & goalDiff(tt)<goalDiff(betterTeam)}) +
               card({ betterTeam | betterTeam : TEAM & points(tt) = points(betterTeam) & wins(tt)=wins(betterTeam) & goalDiff(tt)=goalDiff(betterTeam) & goalsFor(tt)<goalsFor(betterTeam)})+1
    END ;
    
    addNewGame(t1, t2, g1,g2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1 /= t2 & 
        g1 : NAT & g2 : NAT & 
        not ( t1|->t2 : dom(gameResult) ) 
    THEN
        // Adds the new result 
        gameResult(t1|->t2) := g1|->g2 ||
        
        // Updates the points/wins/draws/losses of each team
        IF g1 < g2 THEN 
            points(t2) := points(t2) + winpts || 
            wins(t2) := wins(t2) + 1 || 
            losses(t1) := losses(t1) + 1 
        ELSIF g1 > g2 THEN 
            points(t1) := points(t1) + winpts ||
            wins(t1) := wins(t1) + 1 || 
            losses(t2) := losses(t2) + 1
        ELSE 
            points := points <+ {t1 |-> points(t1)+drawpts,t2 |-> points(t2)+drawpts} || 
            draws := draws <+ {t1 |-> draws(t1)+1,t2 |-> draws(t2)+1}
        END ||
        
        // Adds the goals of each team
        goalsFor := goalsFor <+ {t1 |-> goalsFor(t1)+g1,
            t2 |-> goalsFor(t2)+g2} ||
        goalsAgainst := goalsAgainst <+ {t1 |-> goalsAgainst(t1)+g2,
            t2 |-> goalsAgainst(t2)+g1} ||
        goalDiff := goalDiff <+ {t1 |-> goalDiff(t1)+g1-g2,
            t2 |-> goalDiff(t2)+g2-g1}
           
    END;

    removeGame(t1, t2) = 
    PRE 
        t1 : TEAM & t2 : TEAM & t1|->t2 : dom(gameResult) 
    THEN 
        // Removes the result
        gameResult := {t1|->t2} <<| gameResult ||

        // Updates the goals for/against and the goal difference
        goalsFor := goalsFor <+ {t1 |-> goalsFor(t1) - prj1(NAT,NAT)(gameResult(t1,t2)), 
            t2 |-> goalsFor(t2) - prj2(NAT,NAT)(gameResult(t1,t2))} ||
        goalsAgainst := goalsAgainst <+ {t1 |-> goalsAgainst(t1) - prj2(NAT,NAT)(gameResult(t1,t2)), 
            t2 |-> goalsAgainst(t2) - prj1(NAT,NAT)(gameResult(t1,t2))} ||
        goalDiff := goalDiff <+ {t1 |-> goalDiff(t1) - (prj1(NAT,NAT)(gameResult(t1,t2)) - prj2(NAT,NAT)(gameResult(t1,t2))),
            t2 |-> goalDiff(t2) - (prj2(NAT,NAT)(gameResult(t1,t2)) - prj1(NAT,NAT)(gameResult(t1,t2))) } ||

        // Updates the points/wins/draws/losses of both TEAM
        // The game was a draw
        IF prj1(NAT,NAT)(gameResult(t1,t2)) = prj2(NAT,NAT)(gameResult(t1,t2)) THEN
            points := points <+ {t1 |-> points(t1) - drawpts, t2 |-> points(t2) - drawpts} ||
            draws := draws <+ {t1 |-> draws(t1)-1, t2 |-> draws(t2)-1} 
        // t2 won
        ELSIF prj1(NAT,NAT)(gameResult(t1,t2)) < prj2(NAT,NAT)(gameResult(t1,t2)) THEN
            points := points <+ {t2 |-> points(t2) - winpts} ||
            wins := wins <+ {t2 |-> wins(t2)-1} ||
            losses(t1) := losses(t1) - 1
        // t1 won
        ELSE
            points := points <+ {t1 |-> points(t1) - winpts} ||
            wins := wins <+ {t1 |-> wins(t1)-1} ||
            losses(t2) := losses(t2) - 1
        END 
    END ;

    editGame(t1, t2, g1,g2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1|->t2 : dom(gameResult) & 
        g1 : NAT & g2 : NAT
    THEN
        // Updates the result
        gameResult(t1,t2) := g1|->g2 ||
        
        // Updates the goals for/against and the goal difference
        goalsFor := goalsFor <+ {t1 |-> goalsFor(t1) - prj1(NAT,NAT)(gameResult(t1,t2)) + g1, 
            t2 |-> goalsFor(t2) - prj2(NAT,NAT)(gameResult(t1,t2)) + g2} ||
        goalsAgainst := goalsAgainst <+ {t1 |-> goalsAgainst(t1) - prj2(NAT,NAT)(gameResult(t1,t2)) + g2, 
            t2 |-> goalsAgainst(t2) - prj1(NAT,NAT)(gameResult(t1,t2)) + g1} ||
        goalDiff := goalDiff <+ {t1 |-> goalDiff(t1) - (prj1(NAT,NAT)(gameResult(t1,t2)) - prj2(NAT,NAT)(gameResult(t1,t2))) 
            + g1 - g2,
            t2 |-> goalDiff(t2) - (prj2(NAT,NAT)(gameResult(t1,t2)) - prj1(NAT,NAT)(gameResult(t1,t2))) 
            + g2 - g1} ||
        
        // Updates the points/wins/draws/losses of both TEAM
        IF g1 > g2 THEN
            IF prj1(NAT,NAT)(gameResult(t1,t2)) = prj2(NAT,NAT)(gameResult(t1,t2)) THEN
                points := points <+ {t1 |-> points(t1) + winpts - drawpts, t2 |-> points(t2) - drawpts} ||
                wins(t1) := wins(t1)+1 || 
                draws := draws <+ {t1 |-> draws(t1)-1, t2 |-> draws(t2)-1} ||
                losses(t2) := losses(t2)+1
            ELSIF prj1(NAT,NAT)(gameResult(t1,t2)) < prj2(NAT,NAT)(gameResult(t1,t2)) THEN
                points := points <+ {t1 |-> points(t1) + winpts, t2 |-> points(t2) - winpts} ||
                wins := wins <+ {t1 |-> wins(t1)+1, t2 |-> wins(t2)-1} ||
                losses := losses <+ {t1 |-> losses(t1)-1, t2 |-> losses(t2)+1}
            END
        ELSIF g1 < g2 THEN 
            IF prj1(NAT,NAT)(gameResult(t1,t2)) = prj2(NAT,NAT)(gameResult(t1,t2)) THEN
                points := points <+ {t1 |-> points(t1) -drawpts, t2 |-> points(t2) + winpts - drawpts} ||
                wins(t2) := wins(t2)+1 ||
                draws := draws <+ {t1 |-> draws(t1)-1, t2 |-> draws(t2)-1} ||
                losses(t1) := losses(t1)+1
            ELSIF prj1(NAT,NAT)(gameResult(t1,t2)) > prj2(NAT,NAT)(gameResult(t1,t2)) THEN
                points := points <+ {t1 |-> points(t1) - winpts, t2 |-> points(t2) + winpts} ||
                wins := wins <+ {t1 |-> wins(t1)-1, t2 |-> wins(t2)+1} ||
                losses := losses <+ {t1 |-> losses(t1)+1, t2 |-> losses(t2)-1}
            END
        ELSE
            IF prj1(NAT,NAT)(gameResult(t1,t2)) < prj2(NAT,NAT)(gameResult(t1,t2)) THEN
                points := points <+ {t1 |-> points(t1) + drawpts, t2 |-> points(t2) - (winpts - drawpts)} ||
                wins(t2) := wins(t2)-1 ||
                draws := draws <+ {t1 |-> draws(t1)+1, t2 |-> draws(t2)+1} ||
                losses(t1) := losses(t1)-1 
            ELSIF prj1(NAT,NAT)(gameResult(t1,t2)) > prj2(NAT,NAT)(gameResult(t1,t2)) THEN
                points := points <+ {t2 |-> points(t2) + drawpts, t1 |-> points(t1) - (winpts - drawpts)} ||
                wins(t1) := wins(t1)-1 ||
                draws := draws <+ {t2 |-> draws(t2)+1, t1 |-> draws(t1)+1} ||
                losses(t2) := losses(t2)-1 
            END
        END    
    END
END



