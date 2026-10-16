	.syntax unified

	thumb_func_start sub_08027CB0
sub_08027CB0: @ 0x08027CB0
	push {r4, r5, lr}
	ldr r4, _08027CF4 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _08027CF8 @ =0x03002C30
	ldr r0, _08027CFC @ =0x00000858
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #0x40
	ldr r5, _08027D00 @ =0x000003FF
	adds r1, r5, #0
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08027D04 @ =0x00000888
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	bne _08027D0C
	movs r0, #0x30
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0x3c
	strb r0, [r1]
	ldr r1, _08027D08 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08027D18
	.align 2, 0
_08027CF4: .4byte 0x03000440
_08027CF8: .4byte 0x03002C30
_08027CFC: .4byte 0x00000858
_08027D00: .4byte 0x000003FF
_08027D04: .4byte 0x00000888
_08027D08: .4byte 0x03001800
_08027D0C:
	subs r0, #8
	strb r0, [r1]
	ldr r5, _08027D20 @ =0x00000889
	adds r1, r3, r5
	ldrb r0, [r1]
	subs r0, #8
_08027D18:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08027D20: .4byte 0x00000889
	.syntax divided
