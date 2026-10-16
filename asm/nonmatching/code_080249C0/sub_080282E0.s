	.syntax unified

	thumb_func_start sub_080282E0
sub_080282E0: @ 0x080282E0
	push {r4, lr}
	ldr r0, _08028300 @ =0x03002C30
	ldr r1, _08028304 @ =0x00000867
	adds r4, r0, r1
	ldrb r1, [r4]
	adds r2, r0, #0
	cmp r1, #0x10
	bne _0802830C
	movs r0, #0x28
	bl play_sound_effect
	movs r0, #0
	strb r0, [r4]
	ldr r1, _08028308 @ =0x03001800
	adds r1, #0xaa
	b _0802833A
	.align 2, 0
_08028300: .4byte 0x03002C30
_08028304: .4byte 0x00000867
_08028308: .4byte 0x03001800
_0802830C:
	ldr r0, _08028324 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802832C
	ldr r0, _08028328 @ =0x00000842
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
	b _08028334
	.align 2, 0
_08028324: .4byte 0x03001800
_08028328: .4byte 0x00000842
_0802832C:
	ldr r0, _08028348 @ =0x00000842
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
_08028334:
	strh r0, [r1]
	ldr r0, _0802834C @ =0x00000867
	adds r1, r2, r0
_0802833A:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028348: .4byte 0x00000842
_0802834C: .4byte 0x00000867
	.syntax divided
