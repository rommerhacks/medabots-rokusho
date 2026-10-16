	.syntax unified

	thumb_func_start sub_0803E1FC
sub_0803E1FC: @ 0x0803E1FC
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r1, _0803E228 @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _0803E22C @ =0x083CF3B0
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	beq _0803E224
	ldr r1, _0803E230 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E224:
	pop {r0}
	bx r0
	.align 2, 0
_0803E228: .4byte 0x03000440
_0803E22C: .4byte 0x083CF3B0
_0803E230: .4byte 0x0300137C
	.syntax divided
