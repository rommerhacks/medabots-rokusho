	.syntax unified

	thumb_func_start load_song_channels
load_song_channels: @ 0x08074914
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	mov sl, r1
	bl sub_080750CC
	adds r5, r0, #0
	movs r1, #0xd1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, [sp]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl sound_channel_finish_and_callback
	adds r0, r5, #0
	adds r0, #0x74
	bl sound_channel_finish_and_callback
	adds r0, r5, #0
	adds r0, #0xe8
	bl sound_channel_finish_and_callback
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	bl sound_channel_finish_and_callback
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r5, r2
	bl sound_channel_finish_and_callback
	ldr r1, _08074A04 @ =0x00000414
	adds r0, r5, r1
	bl sound_channel_finish_and_callback
	movs r2, #0xae
	lsls r2, r2, #3
	adds r0, r5, r2
	bl sound_channel_finish_and_callback
	movs r0, #0
	mov sb, r0
	movs r7, #0x80
	lsls r7, r7, #4
	mov r6, r8
_08074982:
	mov r1, r8
	ldrh r0, [r1]
	ands r0, r7
	cmp r0, #0
	beq _080749AE
	movs r0, #0x74
	mov r4, sb
	muls r4, r0, r4
	adds r4, r5, r4
	ldr r1, [r6, #4]
	adds r0, r4, #0
	bl init_sound_channel
	mov r2, r8
	ldrb r0, [r2, #2]
	adds r1, r4, #0
	adds r1, #0x6d
	strb r0, [r1]
	adds r4, #0x70
	mov r0, sl
	strb r0, [r4]
	adds r6, #4
_080749AE:
	lsrs r7, r7, #1
	movs r1, #1
	add sb, r1
	cmp r7, #0
	bne _08074982
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080749EA
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0x85
	lsls r2, r2, #3
	adds r1, r5, r2
	ldr r1, [r1]
	bl init_sound_channel
	mov r0, r8
	ldrb r1, [r0, #2]
	ldr r2, _08074A08 @ =0x000005DD
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r2, sl
	strb r2, [r0]
_080749EA:
	ldr r1, _08074A0C @ =0x0000072F
	adds r0, r5, r1
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074A04: .4byte 0x00000414
_08074A08: .4byte 0x000005DD
_08074A0C: .4byte 0x0000072F
	.syntax divided
