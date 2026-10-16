	.syntax unified

	thumb_func_start sub_0802F13C
sub_0802F13C: @ 0x0802F13C
	push {r4, lr}
	movs r0, #0x21
	bl sub_080353CC
	ldr r3, _0802F168 @ =0x03002C30
	ldr r1, _0802F16C @ =0x00000867
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0x20
	bne _0802F17C
	ldr r0, _0802F170 @ =0x00000858
	adds r1, r3, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0802F174 @ =0x03000440
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	ldr r1, _0802F178 @ =0x03001800
	adds r1, #0xaa
	b _0802F1FE
	.align 2, 0
_0802F168: .4byte 0x03002C30
_0802F16C: .4byte 0x00000867
_0802F170: .4byte 0x00000858
_0802F174: .4byte 0x03000440
_0802F178: .4byte 0x03001800
_0802F17C:
	ldr r2, _0802F198 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _0802F1A0
	ldr r1, _0802F19C @ =0x00000858
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r1, #0x20
	b _0802F1A8
	.align 2, 0
_0802F198: .4byte 0x03001800
_0802F19C: .4byte 0x00000858
_0802F1A0:
	ldr r1, _0802F1DC @ =0x00000858
	adds r0, r3, r1
	ldrh r1, [r0]
	subs r1, #0x20
_0802F1A8:
	ldr r3, _0802F1E0 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0]
	ldr r2, _0802F1E4 @ =0x03002C30
	ldr r1, _0802F1E8 @ =0x00000867
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _0802F1FA
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _0802F1F0
	ldr r3, _0802F1EC @ =0x00000842
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	b _0802F1F8
	.align 2, 0
_0802F1DC: .4byte 0x00000858
_0802F1E0: .4byte 0x000003FF
_0802F1E4: .4byte 0x03002C30
_0802F1E8: .4byte 0x00000867
_0802F1EC: .4byte 0x00000842
_0802F1F0:
	ldr r0, _0802F20C @ =0x00000842
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
_0802F1F8:
	strh r0, [r1]
_0802F1FA:
	ldr r3, _0802F210 @ =0x00000867
	adds r1, r2, r3
_0802F1FE:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F20C: .4byte 0x00000842
_0802F210: .4byte 0x00000867
	.syntax divided
