	.syntax unified

	thumb_func_start load_sprite_animation_by_type
	.global load_sprite_animation_by_type
load_sprite_animation_by_type: @ 0x08046A60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov sb, r1
	adds r7, r2, #0
	adds r5, r3, #0
	ldr r3, [sp, #0x38]
	ldr r6, [sp, #0x48]
	movs r0, #0
	mov r8, r0
	movs r0, #2
	ands r0, r6
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	mov sl, r0
	cmp r5, #1
	beq _08046AB0
	cmp r5, #1
	bgt _08046A92
	cmp r5, #0
	beq _08046A9C
	b _08046AE8
_08046A92:
	cmp r5, #2
	beq _08046AC4
	cmp r5, #3
	beq _08046AD8
	b _08046AE8
_08046A9C:
	lsls r1, r7, #4
	ldr r0, _08046AAC @ =0x0807ED00
	adds r1, r1, r0
	mov r8, r1
	movs r1, #0xa0
	lsls r1, r1, #1
	b _08046AE4
	.align 2, 0
_08046AAC: .4byte 0x0807ED00
_08046AB0:
	lsls r1, r7, #4
	ldr r0, _08046AC0 @ =0x0807F4A0
	adds r1, r1, r0
	mov r8, r1
	movs r1, #0xd0
	lsls r1, r1, #1
	b _08046AE4
	.align 2, 0
_08046AC0: .4byte 0x0807F4A0
_08046AC4:
	lsls r1, r7, #4
	ldr r0, _08046AD4 @ =0x0807FC40
	adds r1, r1, r0
	mov r8, r1
	movs r1, #0xf0
	lsls r1, r1, #1
	b _08046AE4
	.align 2, 0
_08046AD4: .4byte 0x0807FC40
_08046AD8:
	lsls r1, r7, #5
	ldr r0, _08046B10 @ =0x080803E0
	adds r1, r1, r0
	mov r8, r1
	movs r1, #0x88
	lsls r1, r1, #2
_08046AE4:
	add r0, sp, #0x10
	strh r1, [r0]
_08046AE8:
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	bne _08046B18
	ldr r0, _08046B14 @ =0x03005308
	ldr r1, [r0]
	mov r2, sl
	lsls r0, r2, #1
	add r0, sl
	lsls r0, r0, #4
	adds r0, r0, r1
	ldr r1, [r0, #0x2c]
	movs r2, #1
	orrs r1, r2
	subs r2, #0xa
	ands r1, r2
	str r1, [r0, #0x2c]
	mov r4, sl
	str r4, [r0, #0x28]
	b _08046CB6
	.align 2, 0
_08046B10: .4byte 0x080803E0
_08046B14: .4byte 0x03005308
_08046B18:
	ldr r0, _08046B80 @ =0x03005308
	ldr r1, [r0]
	mov r0, sl
	lsls r2, r0, #1
	adds r0, r2, r0
	lsls r0, r0, #4
	adds r0, r0, r1
	ldr r1, [r0, #0x2c]
	movs r0, #2
	adds r4, r1, #0
	ands r4, r0
	str r2, [sp, #0x14]
	cmp r4, #0
	bne _08046B36
	b _08046C68
_08046B36:
	ands r6, r0
	cmp r6, #0
	beq _08046B4A
	add r0, sp, #0x10
	ldrh r0, [r0]
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r0, r1
	add r1, sp, #0x10
	strh r0, [r1]
_08046B4A:
	mov r2, sb
	ldr r0, [r2, #4]
	mov r4, r8
	ldr r2, [r4]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	ldr r3, [sp, #0x44]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r4, sb
	ldr r1, [r4, #8]
	str r1, [sp]
	add r1, sp, #0x10
	str r1, [sp, #4]
	mov r4, sl
	str r4, [sp, #8]
	mov r1, r8
	bl load_sprite_tree_recursive
	cmp r4, #0
	beq _08046C3A
	cmp r5, #1
	beq _08046B84
	cmp r5, #2
	beq _08046BE4
	b _08046C3A
	.align 2, 0
_08046B80: .4byte 0x03005308
_08046B84:
	ldr r1, _08046BDC @ =0x0807F4A0
	lsls r7, r7, #4
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	beq _08046C3A
	movs r0, #0
	mov r8, r0
_08046B96:
	adds r5, r7, #0
	mov r1, r8
	adds r4, r1, r5
	ldr r2, _08046BDC @ =0x0807F4A0
	adds r6, r4, r2
	ldrb r0, [r6, #1]
	lsrs r0, r0, #7
	cmp r0, #0
	bne _08046BC6
	mov r1, sb
	ldr r0, [r1, #4]
	ldr r1, [r1, #8]
	ldr r3, _08046BE0 @ =0x0807FC40
	adds r2, r5, r3
	adds r3, r4, r3
	ldrb r3, [r3]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1a
	ldrb r4, [r6]
	lsls r4, r4, #0x1a
	lsrs r4, r4, #0x1a
	str r4, [sp]
	bl load_sprite_tiles_by_table
_08046BC6:
	movs r2, #4
	add r8, r2
	mov r4, r8
	adds r0, r4, r5
	ldr r1, _08046BDC @ =0x0807F4A0
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bne _08046B96
	b _08046C3A
	.align 2, 0
_08046BDC: .4byte 0x0807F4A0
_08046BE0: .4byte 0x0807FC40
_08046BE4:
	ldr r1, _08046C5C @ =0x0807FC40
	lsls r7, r7, #4
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	beq _08046C3A
	movs r2, #0
	mov r8, r2
_08046BF6:
	adds r5, r7, #0
	mov r0, r8
	adds r4, r0, r5
	ldr r1, _08046C5C @ =0x0807FC40
	adds r6, r4, r1
	ldrb r0, [r6, #1]
	lsrs r0, r0, #7
	cmp r0, #0
	bne _08046C26
	mov r2, sb
	ldr r0, [r2, #4]
	ldr r1, [r2, #8]
	ldr r3, _08046C60 @ =0x0807F4A0
	adds r2, r5, r3
	adds r3, r4, r3
	ldrb r3, [r3]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1a
	ldrb r4, [r6]
	lsls r4, r4, #0x1a
	lsrs r4, r4, #0x1a
	str r4, [sp]
	bl load_sprite_tiles_by_table
_08046C26:
	movs r4, #4
	add r8, r4
	mov r1, r8
	adds r0, r1, r5
	ldr r2, _08046C5C @ =0x0807FC40
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bne _08046BF6
_08046C3A:
	ldr r0, _08046C64 @ =0x03005308
	ldr r0, [r0]
	ldr r2, [sp, #0x14]
	add r2, sl
	lsls r2, r2, #4
	adds r2, r2, r0
	ldr r0, [r2, #0x2c]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [r2, #0x2c]
	b _08046CB6
	.align 2, 0
_08046C5C: .4byte 0x0807FC40
_08046C60: .4byte 0x0807F4A0
_08046C64: .4byte 0x03005308
_08046C68:
	movs r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08046CB6
	mov r0, r8
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	mov r0, sb
	ldr r1, [r0, #4]
	lsrs r0, r2, #0x18
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r3, r3, r0
	lsrs r0, r2, #0x18
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0xd]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [sp, #0x3c]
	subs r1, r1, r0
	lsrs r2, r2, #0x1a
	lsls r3, r3, #8
	lsls r0, r1, #8
	str r0, [sp]
	ldr r0, [sp, #0x40]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r4, sl
	str r4, [sp, #0xc]
	mov r0, sb
	mov r1, r8
	bl render_sprite_node_recursive
_08046CB6:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
