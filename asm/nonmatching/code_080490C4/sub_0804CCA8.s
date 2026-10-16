	.syntax unified

	thumb_func_start sub_0804CCA8
sub_0804CCA8: @ 0x0804CCA8
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804CCE8 @ =0x030057E0
	ldr r0, _0804CCEC @ =0x00000C94
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _0804CCC0
	subs r0, #1
	strb r0, [r2]
_0804CCC0:
	ldr r3, _0804CCF0 @ =0x00000C38
	adds r0, r1, r3
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r2, _0804CCF4 @ =0x00000C95
	adds r1, r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	bl decompress_battle_tile_graphics
	ldr r0, _0804CCF8 @ =0x03006F40
	ldrb r0, [r0, #1]
	cmp r0, #3
	beq _0804CD04
	cmp r0, #3
	bgt _0804CCFC
	cmp r0, #1
	beq _0804CD04
	b _0804CD0A
	.align 2, 0
_0804CCE8: .4byte 0x030057E0
_0804CCEC: .4byte 0x00000C94
_0804CCF0: .4byte 0x00000C38
_0804CCF4: .4byte 0x00000C95
_0804CCF8: .4byte 0x03006F40
_0804CCFC:
	cmp r0, #6
	bgt _0804CD0A
	cmp r0, #5
	blt _0804CD0A
_0804CD04:
	bl dma_load_obj_palettes_08048664
	b _0804CD0E
_0804CD0A:
	bl dma_load_battle_palettes
_0804CD0E:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
