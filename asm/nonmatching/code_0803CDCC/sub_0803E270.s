	.syntax unified

	thumb_func_start sub_0803E270
sub_0803E270: @ 0x0803E270
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r1, _0803E29C @ =0x03000440
	adds r2, r1, #0
	adds r2, #0x86
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #4
	bne _0803E2A4
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0803E2A0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0803E2A8
	.align 2, 0
_0803E29C: .4byte 0x03000440
_0803E2A0: .4byte 0x0300137C
_0803E2A4:
	adds r0, #1
	strb r0, [r1]
_0803E2A8:
	pop {r0}
	bx r0
	.syntax divided
