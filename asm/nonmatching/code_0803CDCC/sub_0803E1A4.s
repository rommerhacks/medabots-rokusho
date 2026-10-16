	.syntax unified

	thumb_func_start sub_0803E1A4
sub_0803E1A4: @ 0x0803E1A4
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r0, _0803E1C8 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x86
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803E1D0
	ldr r0, _0803E1CC @ =0x083CF3B0
	ldr r0, [r0, #0x10]
	b _0803E1D4
	.align 2, 0
_0803E1C8: .4byte 0x03000440
_0803E1CC: .4byte 0x083CF3B0
_0803E1D0:
	ldr r0, _0803E1F4 @ =0x083CF3B0
	ldr r0, [r0, #0x14]
_0803E1D4:
	bl run_message
	cmp r0, #0
	beq _0803E1EE
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _0803E1F8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E1EE:
	pop {r0}
	bx r0
	.align 2, 0
_0803E1F4: .4byte 0x083CF3B0
_0803E1F8: .4byte 0x0300137C
	.syntax divided
