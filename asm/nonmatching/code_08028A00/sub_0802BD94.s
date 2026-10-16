	.syntax unified

	thumb_func_start sub_0802BD94
sub_0802BD94: @ 0x0802BD94
	push {r4, r5, lr}
	ldr r1, _0802BE14 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r3, #0
	movs r5, #0
	ldr r0, _0802BE18 @ =0x0000C604
	strh r0, [r2]
	ldr r2, _0802BE1C @ =0x0000085C
	adds r0, r1, r2
	strb r3, [r0]
	ldr r0, _0802BE20 @ =0x00000842
	adds r2, r1, r0
	movs r0, #0x78
	strh r0, [r2]
	ldr r0, _0802BE24 @ =0x00000844
	adds r2, r1, r0
	movs r4, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _0802BE28 @ =0x0000084A
	adds r2, r1, r0
	movs r0, #6
	strb r0, [r2]
	ldr r0, _0802BE2C @ =0x0000084B
	adds r2, r1, r0
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _0802BE30 @ =0x00000846
	adds r2, r1, r0
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2]
	ldr r2, _0802BE34 @ =0x00000848
	adds r0, r1, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r4, [r0]
	adds r2, #0xf
	adds r0, r1, r2
	strh r5, [r0]
	adds r2, #0x15
	adds r0, r1, r2
	strb r3, [r0]
	ldr r0, _0802BE38 @ =0x0000086E
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0802BE3C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	strh r5, [r1]
	adds r0, #0x84
	strb r3, [r0]
	ldr r1, _0802BE40 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BE14: .4byte 0x03002C30
_0802BE18: .4byte 0x0000C604
_0802BE1C: .4byte 0x0000085C
_0802BE20: .4byte 0x00000842
_0802BE24: .4byte 0x00000844
_0802BE28: .4byte 0x0000084A
_0802BE2C: .4byte 0x0000084B
_0802BE30: .4byte 0x00000846
_0802BE34: .4byte 0x00000848
_0802BE38: .4byte 0x0000086E
_0802BE3C: .4byte 0x03000440
_0802BE40: .4byte 0x03001800
	.syntax divided
