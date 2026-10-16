	.syntax unified

	thumb_func_start sub_0804B90C
sub_0804B90C: @ 0x0804B90C
	push {r4, r5, r6, r7, lr}
	bl read_map_script_byte
	ldr r7, _0804B94C @ =0x030057E0
	ldr r2, _0804B950 @ =0x00000C94
	adds r1, r7, r2
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r0, #1
	bgt _0804B922
	movs r0, #1
_0804B922:
	cmp r0, #0xf
	ble _0804B928
	movs r0, #0x10
_0804B928:
	ldr r4, _0804B954 @ =0x00007FFF
	ldr r5, _0804B958 @ =0x42000000
	ldr r6, _0804B95C @ =0x00000000
	bl int_to_softfloat
	adds r3, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl setup_palette_fade_to_color
	ldr r0, _0804B960 @ =0x00000C89
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B94C: .4byte 0x030057E0
_0804B950: .4byte 0x00000C94
_0804B954: .4byte 0x00007FFF
_0804B958: .4byte 0x42000000
_0804B95C: .4byte 0x00000000
_0804B960: .4byte 0x00000C89
	.syntax divided
