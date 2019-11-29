MACHINE
    Game_editor 

SEES
    Team_ctx, Game_ctx

INCLUDES
    // Needed so that the invariant may refer to the variables of Team_info and Game_info
    Team_info, Game_info

INVARIANT
    // Conditions that refer to both states of Team_info and Game_info, so they cannot be in either of these machines

    // Number of wins
    !(tt).(tt : TEAM => ti_wins(tt) = card( {game | game : dom(gi_gameResult) & prj1(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gi_gameResult(game)) >     prj2(NAT,NAT)(gi_gameResult(game)) } \/ {game | game : dom(gi_gameResult) & prj2(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gi_gameResult(game)) < prj2(NAT,NAT)(gi_gameResult(game)) } )  ) &
    
    // Number of losses
    !(tt).(tt : TEAM => ti_losses(tt) = card( {game | game : dom(gi_gameResult) & prj1(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gi_gameResult(game)) < prj2(NAT,NAT)(gi_gameResult(game)) } \/ {game | game : dom(gi_gameResult) & prj2(TEAM,TEAM)(game) = tt & prj1(NAT,NAT)(gi_gameResult(game)) > prj2(NAT,NAT)(gi_gameResult(game)) } )  ) &
    
    // Number of draws
    !(tt).(tt : TEAM => ti_draws(tt) = card( {game | game : dom(gi_gameResult) & (prj1(TEAM,TEAM)(game) = tt or prj2(TEAM,TEAM)(game) = tt)& prj1(NAT,NAT)(gi_gameResult(game)) = prj2(NAT,NAT)(gi_gameResult(game)) } )  ) &
    
    // Number of goals for
    !(tt).(tt : TEAM => ti_goalsFor(tt) = SIGMA(game).( game:dom(gi_gameResult) & tt = prj1(TEAM,TEAM)(game) | prj1(NAT,NAT)(gi_gameResult(game))) + SIGMA(game).( game:dom(gi_gameResult) & tt = prj2(TEAM,TEAM)(game) | prj2(NAT,NAT)(gi_gameResult(game)))) &
    
    // Number of goals against
    !(tt).(tt : TEAM => ti_goalsAgainst(tt) = SIGMA(game).( game:dom(gi_gameResult) & tt = prj1(TEAM,TEAM)(game) | prj2(NAT,NAT)(gi_gameResult(game))) + SIGMA(game).( game:dom(gi_gameResult) & tt = prj2(TEAM,TEAM)(game) | prj1(NAT,NAT)(gi_gameResult(game)))) &
    
    // Number of games
    !(tt).(tt : TEAM => ti_wins(tt)+ti_draws(tt)+ti_losses(tt) = card({game | game:dom(gi_gameResult) & (prj1(TEAM,TEAM)(game)=tt or prj2(TEAM,TEAM)(game)=tt)}))

OPERATIONS
    ge_addNewGame(t1, t2, g1, g2) = 
    PRE
        t1 : TEAM & t2 : TEAM & t1 /= t2 & g1 : NAT & g2 : NAT & not ( t1|->t2 : dom(gi_gameResult) ) 
    THEN
        // Adds the new result 
        addResult(t1,t2,g1,g2) ||
        ti_addNewGame(t1,t2,g1,g2)
    END;
    
    ge_editGame(t1, t2, g1, g2) = 
    PRE
        t1 : TEAM & t2 : TEAM & g1 : NAT & g2 : NAT & t1|->t2 : dom(gi_gameResult)
    THEN
        // Updates the result
        editResult(t1,t2,g1,g2) ||
        ti_editGame(t1,t2,g1,g2, prj1(NAT,NAT)(gi_gameResult(t1,t2)), prj2(NAT,NAT)(gi_gameResult(t1,t2)))
    END
END