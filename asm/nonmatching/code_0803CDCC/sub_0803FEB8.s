	.syntax unified

	thumb_func_start sub_0803FEB8
sub_0803FEB8: @ 0x0803FEB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r2, _0803FF54 @ =0x03000440
	ldrb r1, [r2, #0x14]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _0803FEF4
	ldrb r0, [r2, #0x14]
	adds r1, r0, #0
	adds r1, #8
	asrs r1, r1, #3
	subs r1, #1
	lsls r1, r1, #0x18
	ldr r0, _0803FF58 @ =0x02020000
	lsrs r1, r1, #0x12
	ldrb r3, [r2, #0x17]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r3
	lsls r2, r2, #7
	ldr r3, _0803FF5C @ =0x06000280
	adds r2, r2, r3
	adds r1, r1, r2
	movs r2, #0x10
	bl CpuFastSet
_0803FEF4:
	ldr r4, _0803FF54 @ =0x03000440
	movs r5, #0
	strb r5, [r4, #0x14]
	ldrb r0, [r4, #1]
	cmp r0, #2
	bne _0803FF02
	b _08040026
_0803FF02:
	ldrh r0, [r4, #0xc]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	ldrb r7, [r0, #1]
	ldrb r0, [r0, #2]
	bl sub_08044B34
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #0xc]
	ldr r1, [r4, #8]
	adds r0, r0, r1
	ldrb r0, [r0, #3]
	mov r8, r0
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bne _0803FFD4
	ldrb r0, [r4, #0xf]
	movs r3, #3
	cmp r0, #0
	bne _0803FF2E
	movs r3, #0x13
_0803FF2E:
	cmp r0, r7
	bne _0803FF88
	ldrb r0, [r4, #0x10]
	cmp r0, r6
	bne _0803FF88
	cmp r6, #0xff
	bne _0803FF64
	ldr r0, _0803FF60 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #8
	movs r1, #8
	adds r2, r3, #0
	movs r3, #5
	bl vram_fill_tilemap_rect
	b _0803FF72
	.align 2, 0
_0803FF54: .4byte 0x03000440
_0803FF58: .4byte 0x02020000
_0803FF5C: .4byte 0x06000280
_0803FF60: .4byte 0x04000008
_0803FF64:
	str r7, [sp]
	adds r0, r6, #0
	mov r1, r8
	adds r2, r3, #0
	movs r3, #5
	bl load_bg0_tilemap
_0803FF72:
	ldr r1, _0803FF84 @ =0x03000440
	strb r7, [r1, #0xf]
	strb r6, [r1, #0x10]
	mov r0, r8
	strb r0, [r1, #0x11]
	ldrh r0, [r1, #0xc]
	adds r0, #4
	strh r0, [r1, #0xc]
	b _0804002C
	.align 2, 0
_0803FF84: .4byte 0x03000440
_0803FF88:
	ldr r5, _0803FFB0 @ =0x03000440
	ldrb r4, [r5, #1]
	cmp r4, #0
	bne _0803FFB4
	ldrb r0, [r5, #0x10]
	ldrb r1, [r5, #0x11]
	ldrb r2, [r5, #0xf]
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	adds r2, r3, #0
	movs r3, #5
	bl message_portrait_anim_step
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0804002C
	b _0803FFCA
	.align 2, 0
_0803FFB0: .4byte 0x03000440
_0803FFB4:
	ldr r0, _0803FFD0 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #8
	movs r1, #8
	adds r2, r3, #0
	movs r3, #5
	bl vram_fill_tilemap_rect
_0803FFCA:
	strb r4, [r5, #0xe]
	strb r4, [r5, #0x12]
	b _0804002C
	.align 2, 0
_0803FFD0: .4byte 0x04000008
_0803FFD4:
	movs r3, #3
	cmp r7, #0
	bne _0803FFDC
	movs r3, #0x13
_0803FFDC:
	cmp r6, #0xff
	beq _0804001E
	ldrb r5, [r4, #1]
	cmp r5, #0
	beq _08040002
	str r7, [sp]
	adds r0, r6, #0
	mov r1, r8
	adds r2, r3, #0
	movs r3, #5
	bl load_bg0_tilemap
	movs r0, #1
	strb r0, [r4, #0x12]
	strb r7, [r4, #0xf]
	strb r6, [r4, #0x10]
	mov r0, r8
	strb r0, [r4, #0x11]
	b _08040026
_08040002:
	str r7, [sp]
	str r5, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	adds r2, r3, #0
	movs r3, #5
	bl message_portrait_anim_step
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0804002C
	strb r5, [r4, #0xe]
	strb r0, [r4, #0x12]
_0804001E:
	strb r7, [r4, #0xf]
	strb r6, [r4, #0x10]
	mov r3, r8
	strb r3, [r4, #0x11]
_08040026:
	ldrh r0, [r4, #0xc]
	adds r0, #4
	strh r0, [r4, #0xc]
_0804002C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
