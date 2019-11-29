MACHINE 
	Team_position

SEES
	Team_ctx, Team_info

OPERATIONS
	pos <-- tp_teamPosition(tt) = 
    PRE
        tt : TEAM
    THEN
        pos := card({ betterTeam | betterTeam : TEAM & ti_points(tt) < ti_points(betterTeam)}) + 
               card({ betterTeam | betterTeam : TEAM & ti_points(tt) = ti_points(betterTeam) & ti_wins(tt)<ti_wins(betterTeam)}) + 
               card({ betterTeam | betterTeam : TEAM & ti_points(tt) = ti_points(betterTeam) & ti_wins(tt)=ti_wins(betterTeam) & ti_goalDiff(tt)<ti_goalDiff(betterTeam)}) +
               card({ betterTeam | betterTeam : TEAM & ti_points(tt) = ti_points(betterTeam) & ti_wins(tt)=ti_wins(betterTeam) & ti_goalDiff(tt)=ti_goalDiff(betterTeam) & ti_goalsFor(tt)<ti_goalsFor(betterTeam)})+1
    END 

  END