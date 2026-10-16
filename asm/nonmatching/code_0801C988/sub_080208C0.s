	.syntax unified

	thumb_func_start sub_080208C0
	.global sub_080208C0
sub_080208C0: @ 0x080208C0
	push {lr}
	ldr r1, _080208E0 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080208E4 @ =0x083AD8D8
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080208E0: .4byte 0x03001800
_080208E4: .4byte 0x083AD8D8
	.syntax divided
