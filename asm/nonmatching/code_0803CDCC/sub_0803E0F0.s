	.syntax unified

	thumb_func_start sub_0803E0F0
sub_0803E0F0: @ 0x0803E0F0
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r0, _0803E110 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0x78
	bne _0803E118
	ldr r1, _0803E114 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0803E11C
	.align 2, 0
_0803E110: .4byte 0x03000440
_0803E114: .4byte 0x0300137C
_0803E118:
	adds r0, #1
	strh r0, [r1]
_0803E11C:
	pop {r0}
	bx r0
	.syntax divided
