	.syntax unified

	thumb_func_start sub_0803E434
sub_0803E434: @ 0x0803E434
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r0, _0803E458 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x86
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803E460
	ldr r0, _0803E45C @ =0x083CF3B0
	ldr r0, [r0, #0x18]
	b _0803E464
	.align 2, 0
_0803E458: .4byte 0x03000440
_0803E45C: .4byte 0x083CF3B0
_0803E460:
	ldr r0, _0803E484 @ =0x083CF3B0
	ldr r0, [r0, #0x1c]
_0803E464:
	bl run_message
	cmp r0, #0
	beq _0803E47E
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _0803E488 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E47E:
	pop {r0}
	bx r0
	.align 2, 0
_0803E484: .4byte 0x083CF3B0
_0803E488: .4byte 0x0300137C
	.syntax divided
