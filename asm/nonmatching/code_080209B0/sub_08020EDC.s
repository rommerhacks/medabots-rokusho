	.syntax unified

	thumb_func_start sub_08020EDC
sub_08020EDC: @ 0x08020EDC
	push {r4, lr}
	movs r0, #0x21
	bl sub_080353CC
	ldr r3, _08020F0C @ =0x03002C30
	ldr r1, _08020F10 @ =0x00000867
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0x20
	bne _08020F20
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r3, r0
	ldrh r1, [r2]
	ldr r0, _08020F14 @ =0x0000FDFF
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r2, _08020F18 @ =0x00000858
	adds r0, r3, r2
	strh r1, [r0]
	ldr r1, _08020F1C @ =0x03001800
	adds r1, #0xaa
	b _08020FA2
	.align 2, 0
_08020F0C: .4byte 0x03002C30
_08020F10: .4byte 0x00000867
_08020F14: .4byte 0x0000FDFF
_08020F18: .4byte 0x00000858
_08020F1C: .4byte 0x03001800
_08020F20:
	ldr r2, _08020F3C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _08020F44
	ldr r1, _08020F40 @ =0x00000858
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r1, #0x20
	b _08020F4C
	.align 2, 0
_08020F3C: .4byte 0x03001800
_08020F40: .4byte 0x00000858
_08020F44:
	ldr r1, _08020F80 @ =0x00000858
	adds r0, r3, r1
	ldrh r1, [r0]
	subs r1, #0x20
_08020F4C:
	ldr r3, _08020F84 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0]
	ldr r2, _08020F88 @ =0x03002C30
	ldr r1, _08020F8C @ =0x00000867
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08020F9E
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08020F94
	ldr r3, _08020F90 @ =0x00000842
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	b _08020F9C
	.align 2, 0
_08020F80: .4byte 0x00000858
_08020F84: .4byte 0x000003FF
_08020F88: .4byte 0x03002C30
_08020F8C: .4byte 0x00000867
_08020F90: .4byte 0x00000842
_08020F94:
	ldr r0, _08020FB0 @ =0x00000842
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
_08020F9C:
	strh r0, [r1]
_08020F9E:
	ldr r3, _08020FB4 @ =0x00000867
	adds r1, r2, r3
_08020FA2:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020FB0: .4byte 0x00000842
_08020FB4: .4byte 0x00000867
	.syntax divided
