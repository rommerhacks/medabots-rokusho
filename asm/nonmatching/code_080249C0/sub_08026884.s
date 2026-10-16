	.syntax unified

	thumb_func_start sub_08026884
	.global sub_08026884
sub_08026884: @ 0x08026884
	push {lr}
	ldr r1, _080268A4 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080268A8 @ =0x083AE1C0
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080268A4: .4byte 0x03001800
_080268A8: .4byte 0x083AE1C0
	.syntax divided
