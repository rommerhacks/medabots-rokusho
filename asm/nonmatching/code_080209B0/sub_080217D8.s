	.syntax unified

	thumb_func_start sub_080217D8
sub_080217D8: @ 0x080217D8
	push {lr}
	ldr r1, _080217F4 @ =0x03002C30
	ldr r2, _080217F8 @ =0x00000867
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x10
	bne _08021800
	movs r0, #0x3e
	bl play_sound_effect
	ldr r1, _080217FC @ =0x03001800
	adds r1, #0xaa
	b _08021852
	.align 2, 0
_080217F4: .4byte 0x03002C30
_080217F8: .4byte 0x00000867
_080217FC: .4byte 0x03001800
_08021800:
	cmp r0, #7
	bhi _08021830
	ldr r0, _08021824 @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _08021828 @ =0x00000888
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _0802182C @ =0x000008C8
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #8
	b _0802184C
	.align 2, 0
_08021824: .4byte 0x00000848
_08021828: .4byte 0x00000888
_0802182C: .4byte 0x000008C8
_08021830:
	ldr r0, _0802185C @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #8
	strb r0, [r1]
	ldr r0, _08021860 @ =0x00000888
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #8
	strb r0, [r1]
	ldr r0, _08021864 @ =0x000008C8
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #8
_0802184C:
	strb r0, [r1]
	ldr r0, _08021868 @ =0x00000867
	adds r1, r2, r0
_08021852:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802185C: .4byte 0x00000848
_08021860: .4byte 0x00000888
_08021864: .4byte 0x000008C8
_08021868: .4byte 0x00000867
	.syntax divided
