	.syntax unified

	thumb_func_start sub_080191E4
sub_080191E4: @ 0x080191E4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r2, _0801921C @ =0x03001800
	adds r2, #0x38
	ldr r1, _08019220 @ =0x03000590
	lsls r0, r5, #8
	adds r0, r0, r1
	adds r0, #0x91
	ldrb r0, [r0]
	subs r0, #0x64
	movs r1, #0xb
	muls r0, r1, r0
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r1, _08019224 @ =0x083C4C10
	adds r0, r0, r1
	ldr r4, _08019228 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #1
	bl memcpy_bytes_08041D04
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_08019184
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801921C: .4byte 0x03001800
_08019220: .4byte 0x03000590
_08019224: .4byte 0x083C4C10
_08019228: .4byte 0x0300052E
	.syntax divided
