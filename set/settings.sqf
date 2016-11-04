createDialog "Intel_dialog";
_display = findDisplay 42;

// Get references to our objects
_map_size_obj = _display displayCtrl 1010;
_overcast_obj = _display displayCtrl 1020;
_daytime_obj = _display displayCtrl 1030;
_b_strat_obj = _display displayCtrl 2101;
_i_strat_obj = _display displayCtrl 2201;
_o_strat_obj = _display displayCtrl 2301;
_bi_affil_obj = _display displayCtrl 2102;
_oi_affil_obj = _display displayCtrl 2302;
_p_class_obj = _display displayCtrl 3010;
_p_command_obj = _display displayCtrl 3020;
_next_obj = _display displayCtrl 4000;

// Set some initial values, populate some lists
_map_size_obj sliderSetRange [500, 2500];
_map_size_obj sliderSetPosition 1000;
_overcast_obj sliderSetRange [0, 1];
_overcast_obj sliderSetPosition 0.5;
_daytime_obj sliderSetRange [0, 24];
_daytime_obj sliderSetPosition 12;

{
    _obj = _x;
    {
        _obj lbAdd _x;
        _obj lbSetValue [_forEachIndex, _forEachIndex];
    } forEach ["ATTACK", "DEFENSE", "ENCOUNTER", "RANDOM"];
    _obj lbSetCurSel 3; // Start off random
} forEach [_b_strat_obj, _i_strat_obj, _o_strat_obj];

{
    _p_class_obj lbAdd _x;
    _p_class_obj lbSetValue [_forEachIndex, _forEachIndex];
} forEach ["Armored", "Infantry", "Mechanized", "Motorized", "SpecOps", "Support", "Random"];
_p_class_obj lbSetCurSel 6; // Start off random

// Wait for next to be pressed. Don't allow escape key
intelComplete = false;
//_noesckey = _display displayAddEventHandler ["KeyDown", "if ((_this select 1) == 1) then { true }"]; 
waitUntil { intelComplete }; // Will be set to true when next is pressed
//_display displayRemoveEventHandler ["KeyDown", _noesckey];
_display closeDisplay 1;

// Yay. Get our variable values now.

// -----------------------------------------------------------------------------

_map_size = sliderPosition _map_size_obj;
_overcast = sliderPosition _overcast_obj;
_daytime = sliderPosition _daytime_obj;

_strat_b = lbCurSel _b_strat_obj; // Thank goodness value==index for these!
_strat_i = lbCurSel _i_strat_obj;
_strat_o = lbCurSel _o_strat_obj;

// Select a random situation if random is selected
if (_strat_b == 3) then { _strat_b = selectRandom [0, 1, 2]; };
if (_strat_i == 3) then { _strat_i = selectRandom [0, 1, 2]; };
if (_strat_o == 3) then { _strat_o = selectRandom [0, 1, 2]; };

_bi_affil = cbChecked _bi_affil_obj;
_oi_affil = cbChecked _oi_affil_obj;

_p_class = lbCurSel _p_class_obj;

_p_command = cbChecked _p_command_obj;

// -----------------------------------------------------------------------------
// Do it all over again, but with the unit screen

_unit_b_num = 20;
_unit_i_num = 15;
_unit_o_num = 20;
// [Armored, Infantry, Mechanized, Motorized, SpecOps, Support]
_unit_b_comp = [.005, .80, .025, .07, .05, .05];
_unit_i_comp = [.005, .75, .025, .08, .05, .09];
_unit_o_comp = [.005, .75, .025, .05, .09, .08];

// Return our values
[_map_size, _unit_b_num, _unit_i_num, _unit_o_num,
_unit_b_comp, _unit_i_comp, _unit_o_comp,
_strat_b, _strat_i, _strat_o];