#ifndef GUARD_CONSTANTS_VEHICLES_H
#define GUARD_CONSTANTS_VEHICLES_H

// The key items of the Vehicle menu and the Medabot models they need (vehicle_check_usable): a vehicle with a model
// is usable only when the team has all four of that model's parts equipped (walkthrough segment 64: the Landmotor
// rebuild in the sewer; without it the menu says the Medabot "LANDMOTOR" isn't assembled yet).

#define ITEM_MINI_S_WHEEL 0x12
#define ITEM_SILVER_LOCKET 0x18
#define ITEM_WINGS_OF_WIND 0x19
#define ITEM_PERISCOPE 0x26

#define MODEL_FEMJET 0x0B    // Wings of Wind
#define MODEL_LANDMOTOR 0x55 // Mini S. Wheel
#define MODEL_AQUAMAR 0x6B   // Periscope

#endif // GUARD_CONSTANTS_VEHICLES_H
