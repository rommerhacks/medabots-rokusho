	.syntax unified

	thumb_func_start battle_transition_animate_step
battle_transition_animate_step: @ 0x0806D718
	push {r4, lr}
	sub sp, #4
	ldr r0, _0806D760 @ =0x03001800
	ldr r4, [r0, #8]
	cmp r4, #0
	bne _0806D768
	movs r1, #0xcc
	lsls r1, r1, #8
	movs r2, #0x89
	lsls r2, r2, #2
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r3, #6
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806D764 @ =0x03002C30
	movs r0, #0x78
	strh r0, [r1, #2]
	movs r0, #0x3c
	strh r0, [r1, #4]
	movs r0, #0x10
	strb r0, [r1, #0xb]
	movs r0, #1
	movs r1, #0
	bl sub_0806DF80
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	b _0806D79E
	.align 2, 0
_0806D760: .4byte 0x03001800
_0806D764: .4byte 0x03002C30
_0806D768:
	cmp r4, #0x20
	bne _0806D79E
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #3
	str r0, [sp]
	movs r0, #1
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806D7EC @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x42
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x3c
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x4b
	strb r4, [r0]
	movs r0, #2
	movs r1, #1
	bl sub_0806DF80
_0806D79E:
	ldr r0, _0806D7EC @ =0x03002C30
	adds r0, #0x20
	ldrb r2, [r0]
	cmp r2, #0
	bne _0806D800
	ldr r1, _0806D7F0 @ =0x03001800
	movs r0, #6
	strh r0, [r1, #4]
	str r2, [r1, #8]
	ldr r2, _0806D7F4 @ =0x00007FFF
	movs r0, #4
	movs r1, #4
	bl setup_screen_transition_effect_080682CC
	movs r0, #1
	bl sub_0806B584
	movs r1, #0xc4
	lsls r1, r1, #8
	ldr r2, _0806D7F8 @ =0x0000021B
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806D7FC @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	b _0806D808
	.align 2, 0
_0806D7EC: .4byte 0x03002C30
_0806D7F0: .4byte 0x03001800
_0806D7F4: .4byte 0x00007FFF
_0806D7F8: .4byte 0x0000021B
_0806D7FC: .4byte 0x0300137C
_0806D800:
	ldr r1, _0806D810 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
_0806D808:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806D810: .4byte 0x03001800
	.syntax divided
