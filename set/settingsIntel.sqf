params ["_overcast", "_daytime", "_BLU_IND_relations", "_OPF_IND_relations"];

skipTime -24;
86400 setOvercast _overcast;
skipTime 24;
nul = [] spawn { sleep 0.1; simulWeatherSync; };

setDate [2035, 7, 22, _daytime, 0];

WEST setFriend [INDEPENDENT, parseNumber _BLU_IND_relations];
EAST setFriend [INDEPENDENT, parseNumber _OPF_IND_relations];