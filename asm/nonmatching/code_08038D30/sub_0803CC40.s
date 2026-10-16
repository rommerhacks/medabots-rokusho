	.syntax unified

	thumb_func_start sub_0803CC40
sub_0803CC40: @ 0x0803CC40
	push {r4, r5, lr}
	ldr r2, _0803CC7C @ =0x083B5F80
	ldr r4, _0803CC80 @ =0x03002C30
	ldr r0, _0803CC84 @ =0x03000440
	ldr r1, _0803CC88 @ =0x0000012F
	adds r5, r0, r1
	ldrb r1, [r5]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldrb r1, [r5]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0803CC76
	adds r0, r1, #0
	movs r1, #1
	bl clear_battle_sprite_slot
_0803CC76:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CC7C: .4byte 0x083B5F80
_0803CC80: .4byte 0x03002C30
_0803CC84: .4byte 0x03000440
_0803CC88: .4byte 0x0000012F
	.syntax divided
