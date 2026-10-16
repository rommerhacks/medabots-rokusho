	.syntax unified

	thumb_func_start sub_0803E234
sub_0803E234: @ 0x0803E234
	push {r4, lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r4, _0803E268 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl sub_0803E79C
	cmp r0, #0
	beq _0803E262
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0803E26C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E262:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E268: .4byte 0x03000440
_0803E26C: .4byte 0x0300137C
	.syntax divided
