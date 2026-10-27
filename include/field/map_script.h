#ifndef GUARD_FIELD_MAP_SCRIPT_H
#define GUARD_FIELD_MAP_SCRIPT_H

// Map script interpreter: gMapScriptCommands handlers, the script byte reader and the map object / script
// variable helpers the commands use

u8 read_map_script_byte(void);
void read_map_script_bytes(u8 n);
u32 map_script_always_zero(void);
void map_script_run_command(void);
struct MapObject *map_object_find_by_id(u16 id);
void script_object_free_slot(u8 i);
void script_object_set_slot(u8 i, u8 v);
u32 script_object_slot(u8 i);

#endif // GUARD_FIELD_MAP_SCRIPT_H
