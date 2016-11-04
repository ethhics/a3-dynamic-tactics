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
_noesckey = _display displayAddEventHandler ["KeyDown", "if ((_this select 1) == 1) then { true }"]; 
waitUntil { intelComplete }; // Will be set to true when next is pressed
_display displayRemoveEventHandler ["KeyDown", _noesckey];
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
if (_p_class == 6) then { _p_class = selectRandom [0, 1, 2, 3, 4, 5]; };

_p_command = cbChecked _p_command_obj;

// Set the intel values
nul = [_overcast, _daytime, _bi_affil, _oi_affil] call compile preprocessFileLineNumbers "set\settingsIntel.sqf";

// -----------------------------------------------------------------------------
// Do it all over again, but with the unit screen
createDialog "Units_dialog";
_display = findDisplay 43;

_unit_b_num_obj = _display displayCtrl 1101;
_unit_i_num_obj = _display displayCtrl 1201;
_unit_o_num_obj = _display displayCtrl 1301;
_unit_b0_obj = _display displayCtrl 2110;
_unit_b1_obj = _display displayCtrl 2120;
_unit_b2_obj = _display displayCtrl 2130;
_unit_b3_obj = _display displayCtrl 2140;
_unit_b4_obj = _display displayCtrl 2150;
_unit_b5_obj = _display displayCtrl 2160;
_unit_i0_obj = _display displayCtrl 2210;
_unit_i1_obj = _display displayCtrl 2220;
_unit_i2_obj = _display displayCtrl 2230;
_unit_i3_obj = _display displayCtrl 2240;
_unit_i4_obj = _display displayCtrl 2250;
_unit_i5_obj = _display displayCtrl 2260;
_unit_o0_obj = _display displayCtrl 2310;
_unit_o1_obj = _display displayCtrl 2320;
_unit_o2_obj = _display displayCtrl 2330;
_unit_o3_obj = _display displayCtrl 2340;
_unit_o4_obj = _display displayCtrl 2350;
_unit_o5_obj = _display displayCtrl 2360;
_generate_obj = _display displayCtrl 4000;

_balanced_setup = [.5, 80, 2.5, 7, 5, 5];

{
    _x sliderSetRange [0, 100];
    _x sliderSetPosition (_balanced_setup select (_forEachIndex % 6));
} forEach [_unit_b0_obj, _unit_b1_obj, _unit_b2_obj,
           _unit_b3_obj, _unit_b4_obj, _unit_b5_obj,
           _unit_i0_obj, _unit_i1_obj, _unit_i2_obj,
           _unit_i3_obj, _unit_i4_obj, _unit_i5_obj,
           _unit_o0_obj, _unit_o1_obj, _unit_o2_obj,
           _unit_o3_obj, _unit_o4_obj, _unit_o5_obj];

{
    _obj = _x;
    {
        _obj lbAdd _x;
        _obj lbSetValue [_forEachIndex, _forEachIndex];
    } forEach ["1", "2", "3", "4", "5",
               "6", "7", "8", "9", "10",
               "11", "12", "13", "14", "15",
               "16", "17", "18", "19", "20",
               "RANDOM"];
    _obj lbSetCurSel 20; // Start off random
} forEach [_unit_b_num_obj, _unit_i_num_obj,_unit_o_num_obj];

unitsComplete = false;
_noesckey = _display displayAddEventHandler ["KeyDown", "if ((_this select 1) == 1) then { true }"]; 
waitUntil { unitsComplete }; // Will be set to true when generate is pressed
_display displayRemoveEventHandler ["KeyDown", _noesckey];
_display closeDisplay 1;

_unit_b_num = lbCurSel _unit_b_num_obj + 1; // 0-indexed
_unit_i_num = lbCurSel _unit_i_num_obj + 1;
_unit_o_num = lbCurSel _unit_o_num_obj + 1;

// Select a random number if random is selected
_one_to_twenty = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20];
if (_unit_b_num == 21) then { _unit_b_num = selectRandom _one_to_twenty; };
if (_unit_i_num == 21) then { _unit_i_num = selectRandom _one_to_twenty; };
if (_unit_o_num == 21) then { _unit_o_num = selectRandom _one_to_twenty; };

// [Armored, Infantry, Mechanized, Motorized, SpecOps, Support]
/*
_unit_b_comp = [.005, .80, .025, .07, .05, .05];
_unit_i_comp = [.005, .75, .025, .08, .05, .09];
_unit_o_comp = [.005, .75, .025, .05, .09, .08];*/
_unit_b_comp = [sliderPosition _unit_b0_obj, sliderPosition _unit_b1_obj,
                sliderPosition _unit_b2_obj, sliderPosition _unit_b3_obj,
                sliderPosition _unit_b4_obj, sliderPosition _unit_b5_obj];
_unit_i_comp = [sliderPosition _unit_i0_obj, sliderPosition _unit_i1_obj,
                sliderPosition _unit_i2_obj, sliderPosition _unit_i3_obj,
                sliderPosition _unit_i4_obj, sliderPosition _unit_i5_obj];
_unit_o_comp = [sliderPosition _unit_o0_obj, sliderPosition _unit_o1_obj,
                sliderPosition _unit_o2_obj, sliderPosition _unit_o3_obj,
                sliderPosition _unit_o4_obj, sliderPosition _unit_o5_obj];

// Return our values needed for generation
[_map_size, _unit_b_num, _unit_i_num, _unit_o_num,
_unit_b_comp, _unit_i_comp, _unit_o_comp,
_strat_b, _strat_i, _strat_o, _p_class, _p_command];