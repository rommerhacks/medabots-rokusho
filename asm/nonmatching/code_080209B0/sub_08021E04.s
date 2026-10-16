	.syntax unified

	thumb_func_start sub_08021E04
	.global sub_08021E04
sub_08021E04: @ 0x08021E04
	push {lr}
	ldr r1, _08021E24 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08021E28 @ =0x083ADAEC
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08021E24: .4byte 0x03001800
_08021E28: .4byte 0x083ADAEC
	.syntax divided
