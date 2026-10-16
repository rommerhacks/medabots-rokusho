	.syntax unified

	thumb_func_start sub_08027F5C
	.global sub_08027F5C
sub_08027F5C: @ 0x08027F5C
	push {lr}
	ldr r1, _08027F7C @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08027F80 @ =0x083AE440
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08027F7C: .4byte 0x03001800
_08027F80: .4byte 0x083AE440
	.syntax divided
