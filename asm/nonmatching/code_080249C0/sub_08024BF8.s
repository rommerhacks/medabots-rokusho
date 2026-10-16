	.syntax unified

	thumb_func_start sub_08024BF8
sub_08024BF8: @ 0x08024BF8
	push {r4, lr}
	movs r0, #0x21
	movs r1, #1
	bl set_sprite_hidden_flags
	ldr r1, _08024C34 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r1, r0
	ldrh r2, [r3]
	movs r4, #0x88
	lsls r4, r4, #2
	adds r0, r4, #0
	orrs r0, r2
	strh r0, [r3]
	ldr r2, _08024C38 @ =0x00000848
	adds r0, r1, r2
	movs r2, #0x80
	strb r2, [r0]
	ldr r4, _08024C3C @ =0x00000849
	adds r1, r1, r4
	strb r2, [r1]
	ldr r1, _08024C40 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024C34: .4byte 0x03002C30
_08024C38: .4byte 0x00000848
_08024C3C: .4byte 0x00000849
_08024C40: .4byte 0x03001800
	.syntax divided
