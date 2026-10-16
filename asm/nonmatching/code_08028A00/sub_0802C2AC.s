	.syntax unified

	thumb_func_start sub_0802C2AC
	.global sub_0802C2AC
sub_0802C2AC: @ 0x0802C2AC
	push {lr}
	ldr r1, _0802C2CC @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _0802C2D0 @ =0x083AE7D4
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0802C2CC: .4byte 0x03001800
_0802C2D0: .4byte 0x083AE7D4
	.syntax divided
