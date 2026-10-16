	.syntax unified

	thumb_func_start sub_08068104
sub_08068104: @ 0x08068104
	push {r4, lr}
	bl update_battle_sprite_explosions
	ldr r0, _0806813C @ =0x08485788
	ldr r0, [r0, #0x44]
	bl run_message
	cmp r0, #0
	beq _08068178
	ldr r4, _08068140 @ =0x03006F74
	ldr r0, [r4]
	ldrh r1, [r0, #0x3a]
	adds r2, r1, #1
	strh r2, [r0, #0x3a]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x77
	ble _08068178
	subs r1, #0x78
	cmp r1, #0x80
	bgt _08068148
	ldr r0, _08068144 @ =0x00007FFF
	asrs r1, r1, #2
	movs r2, #1
	bl blend_obj_palettes_to_color_0803F998
	b _08068178
	.align 2, 0
_0806813C: .4byte 0x08485788
_08068140: .4byte 0x03006F74
_08068144: .4byte 0x00007FFF
_08068148:
	ldr r2, _08068180 @ =0x03000BE0
	ldr r0, _08068184 @ =0x030017EC
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrb r2, [r1, #1]
	ldr r3, _08068188 @ =0x083AC494
	lsls r0, r2, #2
	adds r0, r0, r2
	ldrb r1, [r1, #8]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r1, _0806818C @ =0x06010000
	bl lz_decompress_dispatch
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #0x3a]
	ldr r1, _08068190 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08068178:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08068180: .4byte 0x03000BE0
_08068184: .4byte 0x030017EC
_08068188: .4byte 0x083AC494
_0806818C: .4byte 0x06010000
_08068190: .4byte 0x0300137C
	.syntax divided
