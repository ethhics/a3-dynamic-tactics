// Get our params passed from generation.
params ["_b_num", "_i_num", "_o_num",
        "_b_strat", "_i_strat", "_o_strat"];

// Go through and assign preliminary waypoints to all units.
{
    if (side _x == WEST) then {
        switch (_b_strat) do {
            case 0: // Attack = seek&destroy waypoint towards center
                {
                    _wp = _x addWaypoint [getMarkerPos "DYNTAC_AO_MARKER", 200];
                    _wp setWaypointType "SAD";
                };
            case 1: // Defend = guard waypoint around HQ
                {
                    _wp = _x addWaypoint [getMarkerPos "DYNTAC_B_HQ", 200];
                    _wp setWaypointType "GUARD";
                };
            case 2: // Encounter = move waypoint towards opposite side of circle
                {
                    _vec = (getMarkerPos "DYNTAC_AO_MARKER") vectorDiff (getMarkerPos "DYNTAC_B_HQ");
                    _vec = _vec vectorMultiply 2;
                    _pos = _vec vectorAdd (getMarkerPos "DYNTAC_B_HQ");
                    _wp = _x addWaypoint [_pos, 200];
                    _wp setWaypointType "MOVE";
                };
        };
    };
    if (side _x == INDEPENDENT) then {
        switch (_i_strat) do {
            case 0: // Attack = seek&destroy waypoint towards center
                {
                    _wp = _x addWaypoint [getMarkerPos "DYNTAC_AO_MARKER", 200];
                    _wp setWaypointType "SAD";
                };
            case 1: // Defend = guard waypoint around HQ
                {
                    _wp = _x addWaypoint [getMarkerPos "DYNTAC_I_HQ", 200];
                    _wp setWaypointType "GUARD";
                };
            case 2: // Encounter = move waypoint towards opposite side of circle
                {
                    _vec = (getMarkerPos "DYNTAC_AO_MARKER") vectorDiff (getMarkerPos "DYNTAC_I_HQ");
                    _vec = _vec vectorMultiply (vectorMagnitude _vec * 2);
                    _pos = _vec vectorAdd (getMarkerPos "DYNTAC_I_HQ");
                    _wp = _x addWaypoint [_pos, 200];
                    _wp setWaypointType "MOVE";
                };
        };
    };
    if (side _x == EAST) then {
        switch (_o_strat) do {
            case 0: // Attack = seek&destroy waypoint towards center
                {
                    _wp = _x addWaypoint [getMarkerPos "DYNTAC_AO_MARKER", 200];
                    _wp setWaypointType "SAD";
                };
            case 1: // Defend = guard waypoint around HQ
                {
                    _wp = _x addWaypoint [getMarkerPos "DYNTAC_O_HQ", 200];
                    _wp setWaypointType "GUARD";
                };
            case 2: // Encounter = move waypoint towards opposite side of circle
                {
                    _vec = (getMarkerPos "DYNTAC_AO_MARKER") vectorDiff (getMarkerPos "DYNTAC_O_HQ");
                    _vec = _vec vectorMultiply (vectorMagnitude _vec * 2);
                    _pos = _vec vectorAdd (getMarkerPos "DYNTAC_O_HQ");
                    _wp = _x addWaypoint [_pos, 200];
                    _wp setWaypointType "MOVE";
                };
        };
    };
} forEach allGroups;