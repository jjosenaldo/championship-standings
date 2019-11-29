MACHINE 
    Team_position_criteria

SEES
    Team_ctx, Team_info

OPERATIONS
    tt <-- isBetterTeam(t1,t2) = 
    PRE
        t1 : TEAM & t2 : TEAM
    THEN
        IF ti_points(t1) > ti_points(t2) THEN
            tt := TRUE
        ELSIF ti_points(t1) = ti_points(t2) & ti_wins(t1) > ti_wins(t2) THEN
            tt := TRUE
        ELSIF ti_points(t1) = ti_points(t2) & ti_wins(t1) = ti_wins(t2) & ti_goalDiff(t1) > ti_goalDiff(t2) THEN
            tt := TRUE
        ELSIF ti_points(t1) = ti_points(t2) & ti_wins(t1) = ti_wins(t2) & ti_goalDiff(t1) = ti_goalDiff(t2) & ti_goalsFor(t1) > ti_goalsFor(t2) THEN
            tt := TRUE
        ELSE
            tt := FALSE
        END
    END
END