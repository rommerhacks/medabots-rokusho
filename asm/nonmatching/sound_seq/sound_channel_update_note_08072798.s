	.syntax unified

	thumb_func_start sound_channel_update_note_08072798
sound_channel_update_note_08072798: @ 0x08072798
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r0, #0x65
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x66
	movs r2, #0
	movs r6, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x63
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807286E
	cmp r0, #1
	bgt _080727C2
	cmp r0, #0
	beq _080727CA
	b _08072940
_080727C2:
	cmp r0, #2
	bne _080727C8
	b _080728D2
_080727C8:
	b _08072940
_080727CA:
	adds r3, r4, #0
	adds r3, #0x6e
	ldrb r0, [r3]
	lsls r0, r0, #8
	ldr r2, [r4, #0x14]
	ldrb r1, [r2]
	adds r0, r0, r1
	adds r0, #1
	str r0, [r4, #0x28]
	adds r2, #1
	str r2, [r4, #0x14]
	strb r6, [r3]
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #5
	bls _080727EE
	b _08072940
_080727EE:
	lsls r0, r0, #2
	ldr r1, _080727F8 @ =_080727FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080727F8: .4byte _080727FC
_080727FC: @ jump table
	.4byte _08072814 @ case 0
	.4byte _08072814 @ case 1
	.4byte _08072814 @ case 2
	.4byte _080728F4 @ case 3
	.4byte _08072866 @ case 4
	.4byte _08072866 @ case 5
_08072814:
	adds r0, r4, #0
	adds r0, #0x6a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r5, r0
	adds r1, r0, #0
	subs r1, #0x24
	cmp r1, #0
	bge _0807282C
	movs r1, #0
	b _08072832
_0807282C:
	cmp r1, #0x47
	ble _08072832
	movs r1, #0x47
_08072832:
	adds r2, r4, #0
	adds r2, #0x48
	strh r1, [r2]
	adds r1, r4, #0
	adds r1, #0x6c
	movs r0, #0xff
	strb r0, [r1]
	ldrh r0, [r2]
	bl sub_08073140
	adds r1, r4, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #0x53
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl sub_0807255C
	adds r0, r4, #0
	bl sound_env_key_on
	b _08072940
_08072866:
	adds r0, r4, #0
	adds r0, #0x48
	strh r5, [r0]
	b _08072934
_0807286E:
	ldr r0, [r4, #0x2c]
	str r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x6c
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	blt _08072940
	cmp r0, #2
	bgt _080728A8
	adds r0, r4, #0
	adds r0, #0x48
	strh r6, [r0]
	lsls r2, r5, #8
	ldr r1, [r4, #0x14]
	ldrb r0, [r1]
	orrs r0, r2
	adds r2, r4, #0
	adds r2, #0x46
	strh r0, [r2]
	adds r1, #1
	str r1, [r4, #0x14]
	adds r2, #0xa
	ldrb r0, [r2]
	movs r1, #0x53
	b _0807293C
_080728A8:
	cmp r0, #5
	bgt _08072940
	cmp r0, #4
	blt _08072940
	lsls r1, r5, #8
	ldr r2, [r4, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	adds r1, r4, #0
	adds r1, #0x48
	strh r0, [r1]
	adds r2, #1
	str r2, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x46
	strh r6, [r0]
	adds r2, r4, #0
	adds r2, #0x50
	ldrb r0, [r2]
	movs r1, #0x50
	b _0807293C
_080728D2:
	adds r3, r4, #0
	adds r3, #0x6e
	ldrb r0, [r3]
	lsls r0, r0, #8
	ldr r2, [r4, #0x14]
	ldrb r1, [r2]
	adds r0, r0, r1
	adds r0, #1
	str r0, [r4, #0x28]
	adds r2, #1
	str r2, [r4, #0x14]
	strb r6, [r3]
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #3
	bne _080728FE
_080728F4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sound_set_channel_note
	b _08072940
_080728FE:
	cmp r0, #3
	blt _08072940
	cmp r0, #5
	bgt _08072940
	ldr r0, _08072920 @ =0x03007014
	ldr r0, [r0]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2, #2]
	subs r1, r5, r0
	cmp r1, #0
	bge _08072924
	movs r1, #0
	b _0807292E
	.align 2, 0
_08072920: .4byte 0x03007014
_08072924:
	ldrh r0, [r2]
	subs r0, #1
	cmp r0, r1
	bge _0807292E
	adds r1, r0, #0
_0807292E:
	adds r0, r4, #0
	adds r0, #0x48
	strh r1, [r0]
_08072934:
	adds r2, r4, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #0x50
_0807293C:
	orrs r0, r1
	strb r0, [r2]
_08072940:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
