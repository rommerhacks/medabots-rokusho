	.syntax unified

	thumb_func_start sub_0804B8B4
sub_0804B8B4: @ 0x0804B8B4
	push {r4, r5, r6, r7, lr}
	bl read_map_script_byte
	ldr r7, _0804B8F4 @ =0x030057E0
	ldr r2, _0804B8F8 @ =0x00000C94
	adds r1, r7, r2
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r0, #1
	bgt _0804B8CA
	movs r0, #1
_0804B8CA:
	cmp r0, #0xf
	ble _0804B8D0
	movs r0, #0x10
_0804B8D0:
	ldr r4, _0804B8FC @ =0x00007FFF
	ldr r5, _0804B900 @ =0x00000000
	ldr r6, _0804B904 @ =0x42000000
	bl int_to_softfloat
	adds r3, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl setup_palette_fade_to_color_with_obj
	ldr r0, _0804B908 @ =0x00000C89
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B8F4: .4byte 0x030057E0
_0804B8F8: .4byte 0x00000C94
_0804B8FC: .4byte 0x00007FFF
_0804B900: .4byte 0x00000000
_0804B904: .4byte 0x42000000
_0804B908: .4byte 0x00000C89
	.syntax divided
