params ["_b_num", "_i_num", "_o_num",
        "_b_comp", "_i_comp", "_o_comp",
        "_b_strat", "_i_strat", "_o_strat"];

while {_b_num > 0} do { // Generate all BLUFOR units
    // Find a composition for the unit to be, according to our weights
    private _base_config = configFile/"CfgGroups"/"West"/"BLU_F";
    private _type = [[_base_config/"Armored", _base_config/"Infantry",
              _base_config/"Mechanized", _base_config/"Motorized",
              _base_config/"SpecOps", _base_config/"Support"],
            _b_comp] call BIS_fnc_selectRandomWeighted;
    private _composition = selectRandom ("true" configClasses _type);
    // Spawn up to 100m away
    private _dist = random 100;
    private _angle = random 360;
    private _pos_hq = getMarkerPos "DYNTAC_B_HQ";
    private _pos = [(_pos_hq select 0) + _dist*cos(_angle),
                    (_pos_hq select 1) + _dist*sin(_angle),
                    0];
    // Now spawn the group!
    [_pos, WEST, _composition] call BIS_fnc_spawnGroup;
    _b_num = _b_num - 1;
};
while {_i_num > 0} do { // Generate all INDFOR units
    private _base_config = configFile/"CfgGroups"/"Indep"/"IND_F";
    private _type = [[_base_config/"Armored", _base_config/"Infantry",
              _base_config/"Mechanized", _base_config/"Motorized",
              _base_config/"SpecOps", _base_config/"Support"],
            _i_comp] call BIS_fnc_selectRandomWeighted;
    private _composition = selectRandom ("true" configClasses _type);

    private _dist = random 100;
    private _angle = random 360;
    private _pos_hq = getMarkerPos "DYNTAC_I_HQ";
    private _pos = [(_pos_hq select 0) + _dist*cos(_angle),
                    (_pos_hq select 1) + _dist*sin(_angle),
                    0];

    [_pos, INDEPENDENT, _composition] call BIS_fnc_spawnGroup;
    _i_num = _i_num - 1;
};
while {_o_num > 0} do { // Generate all OPFOR units
    private _base_config = configFile/"CfgGroups"/"East"/"OPF_F";
    private _type = [[_base_config/"Armored", _base_config/"Infantry",
              _base_config/"Mechanized", _base_config/"Motorized_MTP",
              _base_config/"SpecOps", _base_config/"Support"],
            _o_comp] call BIS_fnc_selectRandomWeighted;
    private _composition = selectRandom ("true" configClasses _type);

    private _dist = random 100;
    private _angle = random 360;
    private _pos_hq = getMarkerPos "DYNTAC_O_HQ";
    private _pos = [(_pos_hq select 0) + _dist*cos(_angle),
                    (_pos_hq select 1) + _dist*sin(_angle),
                    0];

    [_pos, EAST, _composition] call BIS_fnc_spawnGroup;
    _o_num = _o_num - 1;
};