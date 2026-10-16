	.syntax unified

	thumb_func_start load_sprite_tree_recursive
load_sprite_tree_recursive: @ 0x08045E6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	movs r0, #0
	str r0, [sp, #0x14]
	lsls r2, r2, #2
	ldr r1, [sp, #0xc]
	adds r0, r2, r1
	ldr r5, [r0]
	movs r0, #0
	mov sb, r0
	movs r1, #0
	str r1, [sp, #0x18]
	movs r6, #0
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _08045F44
	movs r7, #0
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	str r2, [sp, #0x1c]
	cmp r0, #0
	beq _08045F48
	mov r4, sl
	ldr r2, [sp, #0x10]
_08045EB6:
	ldr r3, [r2]
	lsls r0, r3, #0x1a
	lsrs r0, r0, #0x1a
	cmp r4, r0
	bne _08045F34
	lsrs r2, r3, #6
	lsls r1, r3, #0x10
	lsrs r1, r1, #0x1f
	ldr r0, [sp, #0x48]
	ands r0, r1
	adds r2, r2, r0
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x18
	mov sb, r2
	ldr r0, _08045EE4 @ =0x03000440
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045EE8
	movs r1, #0
	str r1, [sp, #0x18]
	b _08045EEE
	.align 2, 0
_08045EE4: .4byte 0x03000440
_08045EE8:
	lsls r0, r3, #0x11
	lsrs r0, r0, #0x1f
	str r0, [sp, #0x18]
_08045EEE:
	movs r6, #1
	cmp r7, #0
	bne _08045F48
	ldr r0, [r5]
	mov r2, sb
	lsls r4, r2, #2
	adds r0, r4, r0
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _08045F48
	movs r6, #0x20
	ldrb r1, [r5, #0x11]
	add r1, r8
	lsls r1, r1, #5
	ldr r2, _08045F2C @ =0x05000200
	adds r1, r1, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r5]
	adds r0, r4, r0
	ldr r0, [r0, #4]
	ldrb r1, [r5, #0x11]
	add r1, r8
	lsls r1, r1, #5
	ldr r2, _08045F30 @ =0x02030400
	adds r1, r1, r2
	movs r2, #0x10
	bl CpuSet
	b _08045F48
	.align 2, 0
_08045F2C: .4byte 0x05000200
_08045F30: .4byte 0x02030400
_08045F34:
	adds r2, #4
	adds r7, #1
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08045EB6
	b _08045F48
_08045F44:
	movs r6, #1
	str r2, [sp, #0x1c]
_08045F48:
	cmp r6, #0
	beq _08045FD0
	ldr r1, [r5]
	mov r2, sb
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08045FD0
	ldr r4, _08045FB0 @ =0x02030800
	adds r1, r4, #0
	bl dma3_copy_or_decompress
	adds r6, r0, #0
	cmp r6, #0
	beq _08045F7C
	ldr r0, [sp, #0x44]
	ldrh r1, [r0]
	lsls r1, r1, #5
	ldr r2, _08045FB4 @ =0x06010000
	adds r1, r1, r2
	lsls r2, r6, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuSet
_08045F7C:
	mov r1, sl
	lsls r0, r1, #4
	ldr r2, [sp, #0x40]
	adds r4, r2, r0
	ldr r0, [sp, #0x44]
	ldrh r3, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, r8
	bl init_oam_sprite_entry
	ldr r1, [sp, #0x44]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r2, [sp, #0x44]
	strh r0, [r2]
	ldr r0, _08045FB8 @ =0x03000440
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045FBC
	ldrb r1, [r4, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	b _08045FC8
	.align 2, 0
_08045FB0: .4byte 0x02030800
_08045FB4: .4byte 0x06010000
_08045FB8: .4byte 0x03000440
_08045FBC:
	ldrb r1, [r4, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	ldr r1, [sp, #0x18]
	orrs r0, r1
_08045FC8:
	strb r0, [r4, #1]
	ldr r2, [sp, #0x14]
	adds r2, r2, r6
	str r2, [sp, #0x14]
_08045FD0:
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	adds r4, r0, r1
	ldr r1, [r4]
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _08045FFC
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	str r0, [sp]
	ldr r1, [sp, #0x44]
	str r1, [sp, #4]
	ldr r0, [sp, #0x48]
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	mov r3, r8
	bl load_sprite_tree_recursive
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
_08045FFC:
	ldr r1, [r4]
	ldrb r0, [r1, #0xf]
	cmp r0, #0
	beq _08046022
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	str r0, [sp]
	ldr r1, [sp, #0x44]
	str r1, [sp, #4]
	ldr r0, [sp, #0x48]
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	mov r3, r8
	bl load_sprite_tree_recursive
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
_08046022:
	ldr r0, [sp, #0x14]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
