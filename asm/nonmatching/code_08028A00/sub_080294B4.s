	.syntax unified

	thumb_func_start sub_080294B4
	.global sub_080294B4
sub_080294B4: @ 0x080294B4
	push {lr}
	ldr r1, _080294D4 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080294D8 @ =0x083AE540
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080294D4: .4byte 0x03001800
_080294D8: .4byte 0x083AE540
	.syntax divided
