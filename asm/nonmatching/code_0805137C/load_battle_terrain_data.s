	.syntax unified

	thumb_func_start load_battle_terrain_data
	.global load_battle_terrain_data
load_battle_terrain_data: @ 0x080532C0
	push {r4, lr}
	ldr r4, _080532F8 @ =0x030057E0
	ldr r1, _080532FC @ =0x00000C28
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _08053300 @ =0x083D2918
	adds r0, r0, r1
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r2, #8
	bl memcpy_u8
	ldr r1, _08053304 @ =0x03002C30
	ldr r2, _08053308 @ =0x083D2908
	ldr r0, _0805330C @ =0x00000C5C
	adds r4, r4, r0
	ldrb r0, [r4]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r2, _08053310 @ =0x00000BEA
	adds r1, r1, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080532F8: .4byte 0x030057E0
_080532FC: .4byte 0x00000C28
_08053300: .4byte 0x083D2918
_08053304: .4byte 0x03002C30
_08053308: .4byte 0x083D2908
_0805330C: .4byte 0x00000C5C
_08053310: .4byte 0x00000BEA
	.syntax divided
