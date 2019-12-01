MACHINE 
	Team_position

SEES
	Team_ctx,Team_info

OPERATIONS
  pt <-- tp_getPoints(tt) = 
  PRE
      tt : TEAM
  THEN
      pt := ti_points(tt)
  END;

  ww <-- tp_getWins(tt) = 
  PRE
      tt : TEAM
  THEN
      ww := ti_wins(tt)
  END;

  dd <-- tp_getDraws(tt) = 
  PRE
      tt : TEAM
  THEN
      dd := ti_draws(tt)
  END;

  ll <-- tp_getLosses(tt) = 
  PRE
      tt : TEAM
  THEN
      ll := ti_losses(tt)
  END;

  gf <-- tp_getGoalsFor(tt) = 
  PRE
      tt : TEAM
  THEN
      gf := ti_goalsFor(tt)
  END;

  ga <-- tp_getGoalsAgainst(tt) = 
  PRE
      tt : TEAM
  THEN
      ga := ti_goalsAgainst(tt)
  END;

  gd <-- tp_getGoalDiff(tt) = 
  PRE
      tt : TEAM
  THEN
      gd := ti_goalDiff(tt)
  END;

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