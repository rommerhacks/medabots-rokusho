	.syntax unified

	thumb_func_start sub_08024C44
sub_08024C44: @ 0x08024C44
	push {lr}
	ldr r1, _08024C6C @ =0x03002C30
	ldr r0, _08024C70 @ =0x00000848
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0x40
	bne _08024C7C
	movs r0, #0x3c
	bl play_sound_effect
	ldr r0, _08024C74 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	ldr r1, _08024C78 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08024C88
	.align 2, 0
_08024C6C: .4byte 0x03002C30
_08024C70: .4byte 0x00000848
_08024C74: .4byte 0x03000440
_08024C78: .4byte 0x03001800
_08024C7C:
	subs r0, #8
	strb r0, [r2]
	ldr r0, _08024C90 @ =0x00000849
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #8
_08024C88:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08024C90: .4byte 0x00000849
	.syntax divided
