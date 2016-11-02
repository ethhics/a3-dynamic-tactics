hint "Started! Getting settings...";
// _params = call compile preprocessFileLineNumbers "set\settings.sqf";
_map_size = 500; // _this select 0, etc. for all of these eventually

_unit_b_num = 1;
_unit_i_num = 0;
_unit_o_num = 1;
// [Armored, Infantry, Mechanized, Motorized, SpecOps, Support]
_unit_b_comp = [0, 1, 0, 0, 0, 0, 0];
_unit_i_comp = [0, 1, 0, 0, 0, 0, 0];
_unit_o_comp = [0, 1, 0, 0, 0, 0, 0];
// ATTACK=0, DEFENSE=1, ENCOUNTER=2
_strat_b = 2;
_strat_i = 1;
_strat_o = 2;

_params = [_map_size, _unit_b_num, _unit_i_num, _unit_o_num,
           _unit_b_comp, _unit_i_comp, _unit_o_comp,
           _strat_b, _strat_i, _strat_o];
sleep 1;

hint "Got settings. Generating mission...";
_params = _params call compile preprocessFileLineNumbers "gen\generate.sqf";
sleep 1;

hint "Mission generated. Adjusting units...";
nul = _params call compile preprocessFileLineNumbers "adj\adjust.sqf";
sleep 1;

hint "We're good to go!";