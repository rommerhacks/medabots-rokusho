	.syntax unified

	thumb_func_start sub_08021370
sub_08021370: @ 0x08021370
	push {r4, lr}
	ldr r1, _08021394 @ =0x03002C30
	ldr r2, _08021398 @ =0x00000867
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x10
	bne _080213AE
	ldr r4, _0802139C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #2
	bne _080213A0
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x14
	b _080213D2
	.align 2, 0
_08021394: .4byte 0x03002C30
_08021398: .4byte 0x00000867
_0802139C: .4byte 0x03001800
_080213A0:
	movs r0, #0x3e
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0xe
	b _080213D2
_080213AE:
	cmp r0, #7
	bhi _080213C0
	ldr r0, _080213BC @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #8
	b _080213C8
	.align 2, 0
_080213BC: .4byte 0x00000848
_080213C0:
	ldr r0, _080213DC @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #8
_080213C8:
	strb r0, [r1]
	ldr r0, _080213E0 @ =0x00000867
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
_080213D2:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080213DC: .4byte 0x00000848
_080213E0: .4byte 0x00000867
	.syntax divided
