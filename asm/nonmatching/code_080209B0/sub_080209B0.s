	.syntax unified

	thumb_func_start sub_080209B0
	.global sub_080209B0
sub_080209B0: @ 0x080209B0
	push {lr}
	ldr r1, _080209D0 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080209D4 @ =0x083AD93C
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080209D0: .4byte 0x03001800
_080209D4: .4byte 0x083AD93C
	.syntax divided
