	.syntax unified

	thumb_func_start init_battle_sprite_entry_0801BC04
	.global init_battle_sprite_entry_0801BC04
init_battle_sprite_entry_0801BC04: @ 0x0801BC04
	push {r4, r5, lr}
	ldr r5, _0801BC50 @ =0x03002C30
	adds r2, r0, #0
	adds r2, #0x72
	lsls r2, r2, #6
	adds r2, r2, r5
	ldr r1, _0801BC54 @ =0x03001800
	adds r1, #0x3c
	ldrb r1, [r1]
	adds r1, #2
	lsls r1, r1, #0xa
	ldr r4, _0801BC58 @ =0xFFFFC004
	adds r3, r4, #0
	movs r4, #0
	orrs r1, r3
	strh r1, [r2]
	strb r4, [r2, #0x1c]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r5
	ldrh r1, [r0, #2]
	strh r1, [r2, #2]
	ldrh r0, [r0, #4]
	adds r0, #8
	strh r0, [r2, #4]
	movs r0, #5
	strb r0, [r2, #0xa]
	movs r0, #1
	strb r0, [r2, #0xb]
	movs r0, #0xf0
	lsls r0, r0, #4
	strh r0, [r2, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801BC50: .4byte 0x03002C30
_0801BC54: .4byte 0x03001800
_0801BC58: .4byte 0xFFFFC004
	.syntax divided
