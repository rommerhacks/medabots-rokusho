	.syntax unified

	thumb_func_start sub_0803E03C
sub_0803E03C: @ 0x0803E03C
	push {lr}
	bl sub_0803E894
	ldr r2, _0803E084 @ =0x083B5F80
	ldr r0, _0803E088 @ =0x03001800
	movs r1, #0xd1
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x75
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #4
	bl process_sprite_anim_commands
	ldr r1, _0803E08C @ =0x03002C30
	movs r2, #0x91
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0803E080
	adds r1, #0xc6
	ldr r0, _0803E090 @ =0x00008505
	strh r0, [r1]
	movs r0, #0x54
	bl play_sound_effect
	ldr r1, _0803E094 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E080:
	pop {r0}
	bx r0
	.align 2, 0
_0803E084: .4byte 0x083B5F80
_0803E088: .4byte 0x03001800
_0803E08C: .4byte 0x03002C30
_0803E090: .4byte 0x00008505
_0803E094: .4byte 0x0300137C
	.syntax divided
