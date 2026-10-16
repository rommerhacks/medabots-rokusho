	.syntax unified

	thumb_func_start sub_0804B80C
sub_0804B80C: @ 0x0804B80C
	push {r4, r5, r6, lr}
	bl read_map_script_byte
	ldr r6, _0804B84C @ =0x030057E0
	ldr r2, _0804B850 @ =0x00000C94
	adds r1, r6, r2
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r0, #1
	bgt _0804B822
	movs r0, #1
_0804B822:
	cmp r0, #0xf
	ble _0804B828
	movs r0, #0x10
_0804B828:
	ldr r4, _0804B854 @ =0x00000000
	ldr r5, _0804B858 @ =0x42000000
	bl int_to_softfloat
	adds r3, r0, #0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl setup_palette_fade_to_color_with_obj
	ldr r0, _0804B85C @ =0x00000C89
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804B84C: .4byte 0x030057E0
_0804B850: .4byte 0x00000C94
_0804B854: .4byte 0x00000000
_0804B858: .4byte 0x42000000
_0804B85C: .4byte 0x00000C89
	.syntax divided
