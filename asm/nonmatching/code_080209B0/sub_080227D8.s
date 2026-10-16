	.syntax unified

	thumb_func_start sub_080227D8
	.global sub_080227D8
sub_080227D8: @ 0x080227D8
	push {lr}
	ldr r1, _080227F8 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080227FC @ =0x083ADBAC
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080227F8: .4byte 0x03001800
_080227FC: .4byte 0x083ADBAC
	.syntax divided
