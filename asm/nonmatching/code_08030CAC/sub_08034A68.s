	.syntax unified

	thumb_func_start sub_08034A68
sub_08034A68: @ 0x08034A68
	push {lr}
	ldr r3, _08034A98 @ =0x03001800
	ldr r2, _08034A9C @ =0x03000590
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r3, #0
	adds r1, #0x88
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x59
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xec
	strh r1, [r0]
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
_08034A98: .4byte 0x03001800
_08034A9C: .4byte 0x03000590
	.syntax divided
