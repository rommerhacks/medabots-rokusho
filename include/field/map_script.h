#ifndef GUARD_FIELD_MAP_SCRIPT_H
#define GUARD_FIELD_MAP_SCRIPT_H

// Map script interpreter: gMapScriptCommands handlers, the script byte reader and the map object / script
// variable helpers the commands use

u8 read_map_script_byte(void);
void read_map_script_bytes(u8 n);
u32 sub_0804B6EC(void);
void map_script_run_command(void);
struct MapObject *battle_find_entity_by_id(u16 id);
void sub_0804DB68(u8 i);
void sub_0804DB84(u8 i, u8 v);
u32 sub_0804DBA4(u8 i);

#endif // GUARD_FIELD_MAP_SCRIPT_H
