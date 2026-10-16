	.syntax unified

	thumb_func_start init_battle_sprite_entry_08040B90
	.global init_battle_sprite_entry_08040B90
init_battle_sprite_entry_08040B90: @ 0x08040B90
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r2, _08040BC0 @ =0x03002C30
	lsls r0, r4, #6
	adds r3, r0, r2
	adds r0, r3, #0
	adds r0, #0x20
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r6, r2, #0
_08040BB0:
	adds r3, r5, r1
	ldrb r0, [r3]
	cmp r0, #0xfa
	bls _08040BC4
	adds r0, r1, #3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _08040BB0
	.align 2, 0
_08040BC0: .4byte 0x03002C30
_08040BC4:
	lsls r2, r4, #6
	adds r2, r2, r6
	ldrb r1, [r3, #1]
	lsls r1, r1, #8
	ldrb r0, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
