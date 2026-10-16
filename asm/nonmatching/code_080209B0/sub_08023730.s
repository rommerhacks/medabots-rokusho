	.syntax unified

	thumb_func_start sub_08023730
	.global sub_08023730
sub_08023730: @ 0x08023730
	push {lr}
	ldr r1, _08023750 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08023754 @ =0x083ADD20
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08023750: .4byte 0x03001800
_08023754: .4byte 0x083ADD20
	.syntax divided
