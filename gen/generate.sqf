_actual_map_size = 8192; // Size of Stratis map

// Get our settings passed from settings page.
params ["_map_size", "_unit_b_num", "_unit_i_num", "_unit_o_num",
           "_unit_b_comp", "_unit_i_comp", "_unit_o_comp",
           "_strat_b", "_strat_i", "_strat_o"];

// Generation loop
private _done = false;
while {not _done} do {
    // Generate an area somewhere on the map, but entirely within the map area
    private _min_mid_max = [_map_size,
                            (_actual_map_size - _map_size) / 2,
                            _actual_map_size - _map_size];
    _x_pos = random _min_mid_max;
    _y_pos = random _min_mid_max;
    // Now put our trigger and markers there.
    DYNTAC_AO_TRIGGER setPos [_x_pos, _y_pos, 0];
    "DYNTAC_AO_MARKER" setMarkerPos [_x_pos, _y_pos, 0];
    "DYNTAC_AO_MARKER" setMarkerSize [_map_size, _map_size];
    
    // Now, find HQs based on the situation.
    switch (_strat_b) do {
        case 0;
        case 2: // If attacking/encountering, put on the outside of the AO.
            {
                private _angle = random 360;
                "DYNTAC_B_HQ" setMarkerPos [_x_pos+_map_size*sin(_angle),
                                    _y_pos+_map_size*cos(_angle),
                                    0];
            };
        case 1: // If defending, put HQ inside the AO.
            {"DYNTAC_B_HQ" setMarkerPos (["DYNTAC_AO_MARKER"] call BIS_fnc_randomPosTrigger);}
    };
    switch (_strat_i) do {
        case 0;
        case 2:
            {
                private _angle = random 360;
                "DYNTAC_I_HQ" setMarkerPos [_x_pos+_map_size*sin(_angle),
                                    _y_pos+_map_size*cos(_angle),
                                    0];
            };
        case 1:
            {"DYNTAC_I_HQ" setMarkerPos (["DYNTAC_AO_MARKER"] call BIS_fnc_randomPosTrigger);}
    };
    switch (_strat_o) do {
        case 0;
        case 2:
            {
                private _angle = random 360;
                "DYNTAC_O_HQ" setMarkerPos [_x_pos+_map_size*sin(_angle),
                                    _y_pos+_map_size*cos(_angle),
                                    0];
            };
        case 1:
            {"DYNTAC_O_HQ" setMarkerPos (["DYNTAC_AO_MARKER"] call BIS_fnc_randomPosTrigger);}
    };
    
    // If HQs are too close together, or are in water, regenerate.
    if (getMarkerPos "DYNTAC_B_HQ" distance getMarkerPos "DYNTAC_I_HQ" < (_map_size / 2) ||
        getMarkerPos "DYNTAC_I_HQ" distance getMarkerPos "DYNTAC_O_HQ" < (_map_size / 2) ||
        getMarkerPos "DYNTAC_O_HQ" distance getMarkerPos "DYNTAC_B_HQ" < (_map_size / 2) ||
        getTerrainHeightASL getMarkerPos "DYNTAC_B_HQ" < 0 ||
        getTerrainHeightASL getMarkerPos "DYNTAC_I_HQ" < 0 ||
        getTerrainHeightASL getMarkerPos "DYNTAC_O_HQ" < 0) then {
        _done = false;
    } else {
        _done = true;
    }
};

// Now, put down units.
nul = [_unit_b_num, _unit_i_num, _unit_o_num, _unit_b_comp, _unit_i_comp, _unit_o_comp,
 _strat_b, _strat_i, _strat_o] call compile preprocessFileLineNumbers "gen\generateUnits.sqf";
 
DYNTAC_PLAYER setPos getMarkerPos "DYNTAC_B_HQ"; // For testing, move the player
// TODO: Find out how to recenter the map on the new position

// Return the params needed for the adjust section
[_unit_b_num, _unit_i_num, _unit_o_num, _strat_b, _strat_i, _strat_o];