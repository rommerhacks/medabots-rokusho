	.syntax unified

	thumb_func_start sub_08020B4C
sub_08020B4C: @ 0x08020B4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r5, _08020C14 @ =0x030018C8
	adds r0, r5, #0
	subs r0, #0x40
	ldrb r1, [r0]
	adds r0, #3
	ldrb r2, [r0]
	adds r0, r5, #0
	bl battle_check_action_counter
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r7, #2
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _08020C28
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	ldr r0, _08020C18 @ =0x03001864
	ldrb r1, [r0]
	ldr r3, _08020C1C @ =0x03001865
	ldrb r2, [r3]
	ldr r4, _08020C20 @ =0x03001866
	ldrb r3, [r4]
	ldr r6, _08020C24 @ =0x03001867
	ldrb r0, [r6]
	str r0, [sp]
	movs r0, #0x8c
	adds r0, r0, r5
	mov r8, r0
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp, #4]
	movs r6, #0x8e
	adds r6, r6, r5
	mov sl, r6
	movs r4, #0
	ldrsh r0, [r6, r4]
	str r0, [sp, #8]
	movs r6, #0x8c
	rsbs r6, r6, #0
	adds r6, r6, r5
	mov sb, r6
	ldrb r0, [r6]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r6, #4
	str r6, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	str r7, [sp, #0x18]
	str r4, [sp, #0x1c]
	adds r5, #0x4c
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #0
	bl init_scene_with_bg_and_palette
	ldr r7, _08020C18 @ =0x03001864
	ldrb r1, [r7]
	ldr r0, _08020C1C @ =0x03001865
	ldrb r2, [r0]
	ldr r3, _08020C20 @ =0x03001866
	ldrb r3, [r3]
	mov ip, r3
	ldr r7, _08020C24 @ =0x03001867
	ldrb r0, [r7]
	str r0, [sp]
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	str r0, [sp, #4]
	mov r3, sl
	movs r7, #0
	ldrsh r0, [r3, r7]
	str r0, [sp, #8]
	mov r3, sb
	ldrb r0, [r3]
	adds r0, #2
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #0
	mov r3, ip
	bl init_scene_with_bg_and_palette
	b _08020CBE
	.align 2, 0
_08020C14: .4byte 0x030018C8
_08020C18: .4byte 0x03001864
_08020C1C: .4byte 0x03001865
_08020C20: .4byte 0x03001866
_08020C24: .4byte 0x03001867
_08020C28:
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	ldr r4, _08020CD8 @ =0x03001864
	ldrb r1, [r4]
	ldr r6, _08020CDC @ =0x03001865
	ldrb r2, [r6]
	ldr r0, _08020CE0 @ =0x03001866
	ldrb r3, [r0]
	ldr r4, _08020CE4 @ =0x03001867
	ldrb r0, [r4]
	str r0, [sp]
	movs r6, #0x90
	adds r6, r6, r5
	mov r8, r6
	movs r4, #0
	ldrsh r0, [r6, r4]
	str r0, [sp, #4]
	movs r6, #0x92
	adds r6, r6, r5
	mov sl, r6
	movs r4, #0
	ldrsh r0, [r6, r4]
	str r0, [sp, #8]
	movs r6, #0x8c
	rsbs r6, r6, #0
	adds r6, r6, r5
	mov sb, r6
	ldrb r0, [r6]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r6, #8
	str r6, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	str r7, [sp, #0x18]
	str r4, [sp, #0x1c]
	adds r5, #0x4d
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
	ldr r7, _08020CD8 @ =0x03001864
	ldrb r1, [r7]
	ldr r0, _08020CDC @ =0x03001865
	ldrb r2, [r0]
	ldr r3, _08020CE0 @ =0x03001866
	ldrb r3, [r3]
	mov ip, r3
	ldr r7, _08020CE4 @ =0x03001867
	ldrb r0, [r7]
	str r0, [sp]
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	str r0, [sp, #4]
	mov r3, sl
	movs r7, #0
	ldrsh r0, [r3, r7]
	str r0, [sp, #8]
	mov r3, sb
	ldrb r0, [r3]
	adds r0, #2
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #1
	mov r3, ip
	bl init_scene_with_bg_and_palette
_08020CBE:
	ldr r1, _08020CE8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020CD8: .4byte 0x03001864
_08020CDC: .4byte 0x03001865
_08020CE0: .4byte 0x03001866
_08020CE4: .4byte 0x03001867
_08020CE8: .4byte 0x03001800
_08020CEC:
	.byte 0x02, 0x48, 0xAA, 0x30
	.byte 0x02, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.syntax divided
