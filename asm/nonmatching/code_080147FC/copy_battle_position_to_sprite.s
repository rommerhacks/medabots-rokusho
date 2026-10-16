	.syntax unified

	thumb_func_start copy_battle_position_to_sprite
copy_battle_position_to_sprite: @ 0x08014F44
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r0, _08014F84 @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x5a
	ldrb r2, [r1]
	cmp r4, r2
	bhs _08014F7E
	adds r5, r0, #0
	adds r6, r1, #0
_08014F58:
	adds r0, r5, #0
	adds r0, #0x41
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #3
	ldr r1, _08014F88 @ =0x030017A0
	adds r0, r0, r1
	lsls r1, r4, #8
	ldr r2, _08014F8C @ =0x030005D0
	adds r1, r1, r2
	movs r2, #8
	bl memcpy_bytes_0803F63C
	adds r4, #1
	ldrb r0, [r6]
	cmp r4, r0
	blo _08014F58
_08014F7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014F84: .4byte 0x03001800
_08014F88: .4byte 0x030017A0
_08014F8C: .4byte 0x030005D0
	.syntax divided
