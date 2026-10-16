	.syntax unified

	thumb_func_start sub_0801D40C
	.global sub_0801D40C
sub_0801D40C: @ 0x0801D40C
	push {lr}
	ldr r1, _0801D42C @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _0801D430 @ =0x083AD550
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0801D42C: .4byte 0x03001800
_0801D430: .4byte 0x083AD550
	.syntax divided
