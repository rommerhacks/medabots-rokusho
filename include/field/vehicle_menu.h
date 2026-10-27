#ifndef GUARD_FIELD_VEHICLE_MENU_H
#define GUARD_FIELD_VEHICLE_MENU_H

// Vehicle menu: mode-1 handler 2 (gVehicleMenuStates sub-states), vehicle checks, cursor

// Menu entries, in screen order (names from the vehicle items; see the guides)
enum VehicleId {
    VEHICLE_MINI_S_WHEEL,  // item 0x12, Landmotor: player_form 1 (car)
    VEHICLE_SILVER_LOCKET, // item 0x18: the time-travel warp
    VEHICLE_WINGS_OF_WIND, // item 0x19, Femjet: fly through the town map
    VEHICLE_PERISCOPE,     // item 0x26, Aquamar: player_form 2 (swim)
    VEHICLE_COUNT
};

// vehicle_check_usable results
enum VehicleUse {
    VEHICLE_USABLE,
    VEHICLE_NOT_OWNED,       // no item: the entry is drawn blank
    VEHICLE_BOT_INCOMPLETE,  // the team lacks one of the Medabot's 4 parts
    VEHICLE_AREA_FORBIDS,    // area_allows_vehicle() is 0 here
    VEHICLE_BLOCKED,         // useBlockFlags bit set by a map script
    VEHICLE_FORM_CONFLICT,   // already in another vehicle form
    VEHICLE_NOT_FACING_WATER // Periscope: the tile ahead is not water (3)
};

#endif // GUARD_FIELD_VEHICLE_MENU_H
