	.syntax unified

	thumb_func_start process_sprite_anim_commands
	.global process_sprite_anim_commands
process_sprite_anim_commands: @ 0x08040BD8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	ldr r0, _08040C08 @ =0x03002C30
	lsrs r1, r1, #0x12
	adds r0, r1, r0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08040CCA
	movs r7, #1
	adds r5, r1, #0
_08040BF0:
	ldr r0, _08040C08 @ =0x03002C30
	adds r1, r5, r0
	mov ip, r1
	mov r2, ip
	adds r2, #0x20
	ldrb r3, [r2]
	adds r4, r0, #0
	cmp r3, #0
	beq _08040C0C
	subs r0, r3, #1
	strb r0, [r2]
	b _08040CCA
	.align 2, 0
_08040C08: .4byte 0x03002C30
_08040C0C:
	mov r3, ip
	adds r3, #0x21
	ldrb r0, [r3]
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0xfb
	cmp r0, #4
	bhi _08040CAE
	lsls r0, r0, #2
	ldr r1, _08040C28 @ =_08040C2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040C28: .4byte _08040C2C
_08040C2C: @ jump table
	.4byte _08040C40 @ case 0
	.4byte _08040C64 @ case 1
	.4byte _08040C7C @ case 2
	.4byte _08040C92 @ case 3
	.4byte _08040CA4 @ case 4
_08040C40:
	ldrh r1, [r4]
	ldr r0, _08040C60 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r4]
	adds r1, r5, r4
	adds r3, r1, #0
	adds r3, #0x21
	ldrb r0, [r3]
	adds r0, r0, r6
	ldrb r0, [r0, #1]
	adds r1, #0x20
	strb r0, [r1]
	ldrb r0, [r3]
	adds r0, #3
	strb r0, [r3]
	b _08040CCA
	.align 2, 0
_08040C60: .4byte 0x0000BFFF
_08040C64:
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r5, r4
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
	b _08040CC6
_08040C7C:
	adds r4, r5, r4
	adds r4, #0x21
	ldrb r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0, #1]
	bl play_sound_effect
	ldrb r0, [r4]
	adds r0, #3
	strb r0, [r4]
	b _08040CC6
_08040C92:
	adds r2, r5, r4
	adds r2, #0x21
	ldrb r0, [r2]
	adds r0, r0, r6
	ldrb r1, [r0, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	strb r0, [r2]
	b _08040CC6
_08040CA4:
	adds r0, r5, r4
	adds r0, #0x22
	movs r1, #0xff
	strb r1, [r0]
	b _08040CCA
_08040CAE:
	strb r1, [r2]
	ldrb r0, [r3]
	adds r0, r0, r6
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	ldrb r0, [r0, #2]
	adds r0, r0, r1
	mov r1, ip
	strh r0, [r1, #6]
	ldrb r0, [r3]
	adds r0, #3
	strb r0, [r3]
_08040CC6:
	cmp r7, #0
	bne _08040BF0
_08040CCA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
