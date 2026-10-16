	.syntax unified

	thumb_func_start sub_08022010
sub_08022010: @ 0x08022010
	push {r4, r5, r6, lr}
	ldr r2, _08022090 @ =0x03000590
	ldr r5, _08022094 @ =0x03001800
	adds r3, r5, #0
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xc9
	movs r1, #0
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xca
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xcb
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xcc
	strb r1, [r0]
	ldr r4, _08022098 @ =0x03002C30
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x47
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r6, _0802209C @ =0x00008220
	adds r1, r6, #0
	orrs r1, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x47
	lsls r0, r0, #6
	adds r0, r0, r4
	movs r2, #0x40
	strb r2, [r0, #9]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x47
	lsls r0, r0, #6
	adds r0, r0, r4
	strb r2, [r0, #8]
	movs r0, #0x37
	bl play_sound_effect
	adds r5, #0xaa
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08022090: .4byte 0x03000590
_08022094: .4byte 0x03001800
_08022098: .4byte 0x03002C30
_0802209C: .4byte 0x00008220
	.syntax divided
