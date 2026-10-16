	.syntax unified

	thumb_func_start render_battle_medal_names
render_battle_medal_names: @ 0x08064AF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x10]
	ldr r0, _08064C18 @ =0x03006F74
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r0, [r1]
	movs r2, #4
	str r2, [sp, #0x14]
	cmp r0, #3
	bhi _08064B1C
	ldrb r1, [r1]
	str r1, [sp, #0x14]
_08064B1C:
	movs r4, #0
	ldr r0, [sp, #0x14]
	cmp r4, r0
	bge _08064C06
_08064B24:
	lsls r7, r4, #2
	ldr r1, [sp, #0x10]
	adds r6, r4, r1
	lsls r2, r4, #1
	mov r8, r2
	adds r0, r4, #1
	mov sl, r0
	adds r0, r7, r4
	ldr r5, _08064C1C @ =0x0000BFFF
	lsls r0, r0, #7
	movs r3, #0xa
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _08064C20 @ =0x03002C30
	adds r2, r0, r1
_08064B44:
	ldrh r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	strh r0, [r2]
	adds r2, #0x40
	subs r3, #1
	cmp r3, #0
	bge _08064B44
	movs r3, #0
	ldr r5, _08064C18 @ =0x03006F74
	ldr r2, _08064C24 @ =0x03000BE0
	mov sb, r2
	movs r0, #0xa
	add r0, sb
	mov ip, r0
_08064B62:
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x58
	adds r1, r1, r3
	adds r0, #0xb0
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r3, r0
	add r0, ip
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0x58
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _08064B8E
	adds r3, #1
	cmp r3, #0xa
	ble _08064B62
_08064B8E:
	adds r1, r7, r4
	lsls r1, r1, #0x19
	movs r0, #0xc0
	lsls r0, r0, #0x14
	adds r1, r1, r0
	lsrs r1, r1, #0x18
	mov r4, r8
	adds r4, #3
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	movs r2, #6
	adds r3, r4, #0
	bl render_text_sprites_08040DB8
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0xb0
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	add r0, sb
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r0, #1
	ldrh r1, [r1, #0x36]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	movs r2, #0xc0
	lsls r2, r2, #0x17
	orrs r2, r1
	lsrs r2, r2, #0x10
	ldr r0, _08064C28 @ =0x0400000A
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	lsls r4, r4, #6
	ldr r1, _08064C2C @ =0x06000006
	adds r4, r4, r1
	adds r0, r0, r4
	strh r2, [r0]
	adds r0, #2
	adds r1, r2, #1
	strh r1, [r0]
	adds r0, #0x3e
	adds r1, r2, #2
	strh r1, [r0]
	adds r2, #3
	strh r2, [r0, #2]
	mov r4, sl
	ldr r2, [sp, #0x14]
	cmp r4, r2
	blt _08064B24
_08064C06:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08064C18: .4byte 0x03006F74
_08064C1C: .4byte 0x0000BFFF
_08064C20: .4byte 0x03002C30
_08064C24: .4byte 0x03000BE0
_08064C28: .4byte 0x0400000A
_08064C2C: .4byte 0x06000006
_08064C30:
	.byte 0x01, 0x49, 0x01, 0x20, 0x08, 0x60, 0x70, 0x47, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
