hint "Started! Getting settings...";
disableSerialization;
_params = call compile preprocessFileLineNumbers "set\settings.sqf";
//systemChat str(_params);
sleep 1;

hint "Got settings. Generating mission...";
_params = _params call compile preprocessFileLineNumbers "gen\generate.sqf";
sleep 1;

hint "Mission generated. Adjusting units...";
nul = _params call compile preprocessFileLineNumbers "adj\adjust.sqf";
sleep 1;

hint "We're good to go!";