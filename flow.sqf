hint "Started! Getting settings...";
// _params = call compile preprocessFileLineNumbers "set\settings.sqf";
_map_size = 500; // _this select 0, etc. for all of these eventually

_unit_b_num = 20;
_unit_i_num = 15;
_unit_o_num = 20;
// [Armored, Infantry, Mechanized, Motorized, SpecOps, Support]
_unit_b_comp = [.005, .80, .025, .07, .05, .05];
_unit_i_comp = [.005, .75, .025, .08, .05, .09];
_unit_o_comp = [.005, .75, .025, .05, .09, .08];
// ATTACK=0, DEFENSE=1, ENCOUNTER=2
_strat_b = 1;
_strat_i = 2;
_strat_o = 0;

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