	.syntax unified

	thumb_func_start sub_08024998
	.global sub_08024998
sub_08024998: @ 0x08024998
	push {lr}
	ldr r1, _080249B8 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080249BC @ =0x083ADEE4
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080249B8: .4byte 0x03001800
_080249BC: .4byte 0x083ADEE4
	.syntax divided
