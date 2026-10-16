	.syntax unified

	thumb_func_start sub_080388A4
sub_080388A4: @ 0x080388A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0803894C @ =0x083B5F80
	mov r8, r0
	movs r0, #0xda
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ldr r1, _08038950 @ =0x03000440
	ldr r2, _08038954 @ =0x0000012F
	adds r4, r1, r2
	ldrb r1, [r4]
	bl process_sprite_anim_commands
	ldr r6, _08038958 @ =0x03001800
	adds r0, r6, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r3, #1
	mov sb, r3
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	bne _0803896C
	ldr r5, _0803895C @ =0x03002C30
	ldrb r2, [r4]
	lsls r2, r2, #6
	adds r2, r2, r5
	ldrh r0, [r2, #2]
	adds r0, #4
	ldr r7, _08038960 @ =0x000001FF
	adds r1, r7, #0
	ands r0, r1
	movs r1, #0
	mov sl, r1
	strh r0, [r2, #2]
	ldrb r2, [r4]
	lsls r0, r2, #6
	adds r3, r0, r5
	ldr r7, _08038964 @ =0x03001860
	ldrb r0, [r7]
	subs r0, #0x21
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r5
	movs r7, #2
	ldrsh r1, [r3, r7]
	movs r7, #2
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bgt _08038918
	b _08038A70
_08038918:
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0xd6
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803892C
	b _08038A70
_0803892C:
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _08038938
	b _08038A70
_08038938:
	movs r0, #0x54
	bl play_sound_effect
	ldrb r0, [r4]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	ldr r1, _08038968 @ =0x0000C404
	b _080389D4
	.align 2, 0
_0803894C: .4byte 0x083B5F80
_08038950: .4byte 0x03000440
_08038954: .4byte 0x0000012F
_08038958: .4byte 0x03001800
_0803895C: .4byte 0x03002C30
_08038960: .4byte 0x000001FF
_08038964: .4byte 0x03001860
_08038968: .4byte 0x0000C404
_0803896C:
	ldr r5, _08038A94 @ =0x03002C30
	ldrb r2, [r4]
	lsls r2, r2, #6
	adds r2, r2, r5
	ldrh r0, [r2, #2]
	subs r0, #4
	ldr r3, _08038A98 @ =0x000001FF
	adds r1, r3, #0
	ands r0, r1
	movs r7, #0
	mov sl, r7
	strh r0, [r2, #2]
	ldrb r2, [r4]
	lsls r0, r2, #6
	adds r3, r0, r5
	ldr r1, _08038A9C @ =0x03001860
	ldrb r0, [r1]
	subs r0, #0x21
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r5
	movs r7, #2
	ldrsh r1, [r3, r7]
	movs r7, #2
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bge _08038A70
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0xd6
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08038A70
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _08038A70
	movs r0, #0x54
	bl play_sound_effect
	ldrb r0, [r4]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	ldr r1, _08038AA0 @ =0x0000D404
_080389D4:
	strh r1, [r0]
	ldrb r0, [r4]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	mov r1, sl
	strb r1, [r0, #0x1c]
	ldrb r2, [r4]
	adds r1, r2, #3
	lsls r1, r1, #6
	adds r1, r1, r5
	ldr r3, _08038A9C @ =0x03001860
	ldrb r0, [r3]
	subs r0, #0x21
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldrb r2, [r4]
	adds r1, r2, #3
	lsls r1, r1, #6
	adds r1, r1, r5
	ldrb r0, [r3]
	subs r0, #0x21
	adds r0, r0, r2
	lsls r0, r0, #8
	adds r2, r7, #0
	adds r0, r0, r2
	adds r0, r0, r5
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r1, #4]
	ldrb r0, [r4]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	movs r1, #6
	strb r1, [r0, #0xa]
	ldrb r0, [r4]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	movs r1, #0xf1
	strb r1, [r0, #0xb]
	ldrb r0, [r4]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x29
	movs r1, #2
	strb r1, [r0]
	ldrb r0, [r4]
	adds r0, #3
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x28
	mov r3, sl
	strb r3, [r0]
	movs r0, #0xdc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ldrb r1, [r4]
	adds r1, #3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x28
	mov r7, sb
	strb r7, [r0]
_08038A70:
	ldr r1, _08038A94 @ =0x03002C30
	ldr r0, _08038AA4 @ =0x03000440
	ldr r2, _08038AA8 @ =0x0000012F
	adds r0, r0, r2
	ldrb r2, [r0]
	lsls r0, r2, #6
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #0x28
	bls _08038AAC
	adds r0, r2, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	b _08038AB0
	.align 2, 0
_08038A94: .4byte 0x03002C30
_08038A98: .4byte 0x000001FF
_08038A9C: .4byte 0x03001860
_08038AA0: .4byte 0x0000D404
_08038AA4: .4byte 0x03000440
_08038AA8: .4byte 0x0000012F
_08038AAC:
	adds r0, #1
	strb r0, [r1]
_08038AB0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
