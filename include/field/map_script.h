#ifndef GUARD_FIELD_MAP_SCRIPT_H
#define GUARD_FIELD_MAP_SCRIPT_H

// Map script interpreter: gMapScriptCommands handlers and the script byte reader

u8 read_map_script_byte(void);
void read_map_script_bytes(u8 n);
u32 sub_0804B6EC(void);
void map_script_run_command(void);

#endif // GUARD_FIELD_MAP_SCRIPT_H
