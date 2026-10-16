	.syntax unified

	thumb_func_start handle_battle_sprite_scroll_input
handle_battle_sprite_scroll_input: @ 0x08041A28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08041B10 @ =0x0300058C
	mov r8, r0
	ldrb r1, [r0]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _08041A62
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08041B14 @ =0x03000440
	adds r3, r2, #0
	adds r3, #0x2a
	ldrb r0, [r3]
	movs r1, #1
	eors r0, r1
	strb r0, [r3]
	ldr r0, _08041B18 @ =0x03002C30
	adds r2, #0x2b
	ldrb r1, [r2]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r3]
	lsls r0, r0, #4
	adds r0, #0x48
	strh r0, [r1, #4]
_08041A62:
	ldr r4, _08041B14 @ =0x03000440
	adds r6, r4, #0
	adds r6, #0x2b
	ldrb r0, [r6]
	adds r5, r4, #0
	adds r5, #0x84
	ldrb r1, [r5]
	adds r7, r4, #0
	adds r7, #0x2c
	ldrb r2, [r7]
	lsls r2, r2, #0x13
	movs r3, #0xa0
	lsls r3, r3, #0xd
	adds r2, r2, r3
	lsrs r2, r2, #0x10
	bl sub_08041C14
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08041AD4
	movs r0, #5
	bl play_sound_effect
	movs r1, #0x2a
	adds r1, r1, r4
	mov ip, r1
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08041B18 @ =0x03002C30
	ldrb r1, [r6]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, #0x14
	movs r3, #0
	strh r0, [r1, #2]
	ldrb r1, [r6]
	lsls r1, r1, #6
	adds r1, r1, r2
	mov r2, ip
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, #0x48
	strh r0, [r1, #4]
	strb r3, [r5]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08041AD4:
	mov r3, r8
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08041B04
	movs r0, #4
	bl play_sound_effect
	ldr r0, _08041B18 @ =0x03002C30
	ldrb r1, [r6]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, #0x14
	movs r2, #0
	strh r0, [r1, #2]
	strb r2, [r5]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08041B04:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041B10: .4byte 0x0300058C
_08041B14: .4byte 0x03000440
_08041B18: .4byte 0x03002C30
	.syntax divided
