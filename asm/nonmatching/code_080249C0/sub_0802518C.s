	.syntax unified

	thumb_func_start sub_0802518C
	.global sub_0802518C
sub_0802518C: @ 0x0802518C
	push {lr}
	ldr r1, _080251AC @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080251B0 @ =0x083ADFA4
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080251AC: .4byte 0x03001800
_080251B0: .4byte 0x083ADFA4
	.syntax divided
