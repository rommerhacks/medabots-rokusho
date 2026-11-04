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
#define AREA_STATION_SQUARE 95 // the train station; the dog statue hides the stairs to the sewer
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

// Under Medaropolis
#define AREA_SEWER 142              // the Rubberobo costume goes on here; the Manhole Key opens a cover to 146
#define AREA_SQUIDGUTS_ROOM 145     // its ladder comes up in AREA_RESIDENTIAL_SOUTH
#define AREA_MEETING_PLACE 146      // the Rubberobo meeting place: the stage, six seats and the statue
#define AREA_UNDERGROUND_COLONY 147 // below the meeting place's statue (the ant colony)
#define AREA_ANT_QUEENS_ROOM 148    // behind the colony's door guards: four chests and the Ant Statue
#define AREA_COLONY_ROCK_MAZE 149   // east of the tech area: the Blasto / Arma-Head rocks, Gillgirl in the centre
#define AREA_UNDERWATER_ROOM 150 // below the rock maze's floor after Gillgirl: the doors' light, the time warp platform
// The Fiyun crystal sits on AREA_COLONY_CENTRE_ROOM's pedestal after the Fiyun bosses (the last Dr. Armond boss is
// fought there), and the tech area is also reached through AREA_FIYUN_CENTRAL_SQUARE's south doors.
#define AREA_COLONY_CENTRE_ROOM 172 // the tech area's middle door: the empty pedestal where the tag game starts
#define AREA_COLONY_TECH_AREA 186   // through the Queen's room's top door once the Ant Statue is melted

// Kodine Kingdom (the past)
#define AREA_KODINE_PALACE_SQUARE 151  // outside the palace: the houses, the prison stairs, the guarded west exit
#define AREA_KODINE_SUMMONING_ROOM 152 // where the Oracle summons the Great Hero (the time warp lands here)
#define AREA_KODINE_PALACE_ROOMS 153 // through the summoning room's top doors: Ikki's room (the meal), the red crystal
#define AREA_KODINE_BACK_ROOMS 154   // past the palace rooms' guarded top doors: the Chancellor's stools
#define AREA_MARGARITAS_ROOM 155     // the back rooms' top door: the Princess's notebook on the desk
#define AREA_KODINE_PRISON 156       // down the stairs east of the palace: the jailer and the cell
#define AREA_KODINE_NORTHWEST_HOUSE 158 // where the first Rubberobo hides
#define AREA_KODINE_SHORE 161 // the palace square's east exit: the sleeping guard, the Princess, a Female Tinpet chest
#define AREA_KODINE_OCEAN 162 // the palace square's guarded west exit: the beach, the crates Rubberobos hide in
#define AREA_KODINE_OCEAN_DIVE 163 // the ocean's top-left exit: three Rubberobos explain, Ikki dives in
#define AREA_CAFE_OLE_ISLAND 164   // where the dive lands: Cafe Ole (Margarita's Medabot) challenges Ikki

// The Floating Fortress Fiyun (walkthrough segment 78: leaving Nae's room with the Femjet assembled flies here).
// After the last Dr. Armond boss (segment 82) the cockpit's six seats are filled: the top-centre Medabot gives the
// Alien Medal, then Ikki sends Karin, a flying Medabot from the landing zone and one from the living quarters, and
// takes the last (top-left) seat himself. The techno room's stairs lead up into AREA_FIYUN_SIDE_ROOM.
// After the crash (segment 83: the Select 3 Robattle in the square) the landing zone's north side leads outside
// (AREA_FIYUN_CRASH_SITE), whose north exit ends the chapter back home in Riverview.
#define AREA_FIYUN_FACTORY 165         // the oil cans; the left one at the centre holds a male Tinpet
#define AREA_FIYUN_LANDING 166         // where the Wings of Wind land: one corridor down to the techno room
#define AREA_FIYUN_TECHNO_ROOM 167     // pink floor, three Air Medabots in the way, the greenhouse (the Lemon)
#define AREA_FIYUN_GARDEN_ROOM 168     // behind the living quarters' guarded door: walled gardens, each with a guard
#define AREA_FIYUN_LIVING_QUARTERS 169 // library, beds and the computer; a bookshelf makes the Lemon Battery
#define AREA_FIYUN_CENTRAL_SQUARE 170  // the garden ring where Harvey leads the Medabots; two south doors to 186
#define AREA_FIYUN_COCKPIT 171         // Dr. Armond's control room; the garden room's stairs play a short scene here
#define AREA_FIYUN_SIDE_ROOM 184       // through the cockpit's left door: a pipe maze with the Spydertrap chest
#define AREA_FIYUN_TANK_ROOM 185       // after the stairs scene: tank-type Medabots, the Digmole trio, Hat Trick
#define AREA_FIYUN_CRASH_SITE 187      // the landed fortress among tree stumps: Captain Awamori holds Dr. Armond

// gAreaTypes: the region of each area (0 Riverview, 1-2 Mt. Odoro and its caves, 3-6 Medaropolis, 9 Medabot Island,
// ...). Region 10 holds the areas with no Town Map region: the river (40-44), the sewer, the Rubberobo base, the
// colony and the Kodine Kingdom (142-164) and the island pier (189). The Town Map and the Wings of Wind refuse them.
#define AREA_TYPE_NO_TOWN_MAP 10

#endif // GUARD_CONSTANTS_AREAS_H
