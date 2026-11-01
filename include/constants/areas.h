#ifndef GUARD_CONSTANTS_AREAS_H
#define GUARD_CONSTANTS_AREAS_H

// Field area ids (gFieldWork.area_id): the index into gAreaWarps, gAreaCollisionMaps, gAreaSongs and the other
// per-area tables. Each name comes from playing the game: the walkthrough reads the area id at that place.
// Areas not listed here have not been visited (or not identified) yet.

// Riverview
#define AREA_RIVERVIEW 0
#define AREA_SCHOOLYARD 1
#define AREA_SCHOOL_1F 2
#define AREA_SCHOOL_2F 9
#define AREA_CLASSROOM 13
#define AREA_IKKIS_HOUSE_1F 16
#define AREA_IKKIS_ROOM 17
#define AREA_ERIKAS_HOUSE 18
#define AREA_LAB 23 // Dr. Aki's lab: where a new game starts (new_game_init)
#define AREA_LAB_HALL 24
#define AREA_DR_AKIS_OFFICE 25
#define AREA_NAES_ROOM 26
#define AREA_MEDAL_ROOM 27
#define AREA_WAREHOUSE 29
#define AREA_DOCKS 188 // the boat to Medabot Island

// Mt. Odoro
#define AREA_MT_ODORO 33
#define AREA_MT_ODORO_LEFT 34
#define AREA_CAVE_2F 36
#define AREA_ODORO_MARSH 37
#define AREA_CAVE_1F_B 38
#define AREA_STOREROOM 39
#define AREA_DOWNSTREAM 40
#define AREA_KANNIES_HOUSE 41
#define AREA_RIVER 42

// Medabot Island
#define AREA_SHIP 45
#define AREA_ARCADE 56
#define AREA_PARK 57
#define AREA_TOURNAMENT_HALL 64
#define AREA_LOCKER_ROOM 65
#define AREA_MEDACOASTER 67
#define AREA_WITCHS_CASTLE 68
#define AREA_CASTLE_JAIL 69
#define AREA_CASTLE_1F 70
#define AREA_DARK_MASTERS_ROOM 71
#define AREA_CASTLE_2F 73
#define AREA_SUN_ROOM 74
#define AREA_MOON_ROOM 75
#define AREA_STAR_MAZE 76
#define AREA_CASTLE_LIFT 79
#define AREA_DPAD_REMAP_ROOM 83 // the only area with D-pad remapping tiles (gArea53DpadTiles); not visited yet
#define AREA_MEDABOT_ISLAND_PIER 189

// Medaropolis
#define AREA_MEDAROPOLIS 85
#define AREA_MEDASHOP_1F 87
#define AREA_MEDASHOP_2F 88 // the Medalink floor
#define AREA_SELECT_CORPS_HQ 90
#define AREA_RESIDENTIAL 101
#define AREA_ROSEWOOD_1F 102 // Rosewood Private School
#define AREA_ROSEWOOD_2F 112
#define AREA_PRINCIPALS_OFFICE 113
#define AREA_PRINCIPALS_SECRET_ROOM 114
#define AREA_TEACHERS_LOUNGE 115
#define AREA_A_CLASS 116
#define AREA_KOJIS_HOUSE_1F 119
#define AREA_KOJIS_ROOM 120
#define AREA_KARINS_HOUSE 121
#define AREA_AWANO_HOUSE_1F 122 // garden and ground floor
#define AREA_AWANO_HOUSE_2F 123
#define AREA_RESIDENTIAL_SOUTH 128

#endif // GUARD_CONSTANTS_AREAS_H
