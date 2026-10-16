	.syntax unified

	thumb_func_start sub_08029840
	.global sub_08029840
sub_08029840: @ 0x08029840
	push {lr}
	ldr r1, _08029860 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08029864 @ =0x083AE580
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08029860: .4byte 0x03001800
_08029864: .4byte 0x083AE580
	.syntax divided
