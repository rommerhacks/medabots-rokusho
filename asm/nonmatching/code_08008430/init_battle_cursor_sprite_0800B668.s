	.syntax unified

	thumb_func_start init_battle_cursor_sprite_0800B668
init_battle_cursor_sprite_0800B668: @ 0x0800B668
	push {r4, lr}
	ldr r3, _0800B6D8 @ =0x03002C30
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0
	ldr r0, _0800B6DC @ =0x0000D204
	strh r0, [r1]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #0xa8
	strh r0, [r1]
	ldr r0, _0800B6E0 @ =0x03000440
	adds r0, #0x4a
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #0x70
	adds r4, #2
	adds r1, r3, r4
	strh r0, [r1]
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _0800B6E4 @ =0x00000307
	strh r0, [r1]
	adds r4, #6
	adds r1, r3, r4
	movs r0, #0xe
	strb r0, [r1]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r3, r1
	strb r2, [r0]
	adds r4, #0x20
	adds r0, r3, r4
	strb r2, [r0]
	adds r1, #0xb
	adds r0, r3, r1
	strb r2, [r0]
	subs r4, #0x1e
	adds r1, r3, r4
	movs r0, #0xc1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B6D8: .4byte 0x03002C30
_0800B6DC: .4byte 0x0000D204
_0800B6E0: .4byte 0x03000440
_0800B6E4: .4byte 0x00000307
	.syntax divided
