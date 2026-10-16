	.syntax unified

	thumb_func_start sub_08021300
sub_08021300: @ 0x08021300
	push {r4, lr}
	ldr r1, _0802133C @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0
	beq _08021348
	adds r0, r2, #0
	adds r0, #0x2b
	adds r1, #0x52
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08021348
	ldr r0, _08021340 @ =0x03002C30
	ldr r1, _08021344 @ =0x00000867
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08021366
	.align 2, 0
_0802133C: .4byte 0x03001800
_08021340: .4byte 0x03002C30
_08021344: .4byte 0x00000867
_08021348:
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #2
	bne _0802135A
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x14
	b _08021366
_0802135A:
	movs r0, #0x3e
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0xe
_08021366:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
