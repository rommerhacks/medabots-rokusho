	.syntax unified

	thumb_func_start update_battle_medapart_icons
update_battle_medapart_icons: @ 0x0805AD84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	add r7, sp, #0x10
	mov r1, sp
	adds r0, r1, #0
	str r0, [r7, #0x10]
	sub sp, #8
	mov r2, sp
	adds r2, #0x10
	str r2, [r7, #8]
	sub sp, #8
	mov r3, sp
	adds r3, #0x10
	str r3, [r7, #0xc]
	movs r2, #0
	movs r4, #0x81
	lsls r4, r4, #0x12
	ldr r3, _0805AECC @ =0x03006F74
_0805ADB0:
	lsls r1, r2, #0x18
	asrs r1, r1, #0x18
	ldr r0, [r7, #8]
	adds r2, r0, r1
	ldr r0, [r3]
	ldrb r0, [r0, #0x11]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r2]
	ldr r0, [r7, #0xc]
	adds r2, r0, r1
	ldr r0, [r3]
	ldrb r0, [r0, #0x11]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	strb r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #5
	blt _0805ADB0
	movs r2, #0
	cmp r2, #5
	bge _0805AE1C
_0805ADEA:
	lsls r4, r2, #0x18
	asrs r4, r4, #0x18
	lsls r0, r4, #0x1c
	lsrs r0, r0, #0x18
	movs r1, #0x10
	bl clear_sprite_table_mask
	lsls r5, r4, #1
	adds r1, r5, #3
	movs r0, #0x18
	movs r2, #3
	bl sub_0805B3E4
	adds r5, #4
	movs r0, #0x18
	adds r1, r5, #0
	movs r2, #3
	bl sub_0805B3E4
	adds r4, #1
	lsls r4, r4, #0x18
	lsrs r2, r4, #0x18
	asrs r4, r4, #0x18
	cmp r4, #5
	blt _0805ADEA
_0805AE1C:
	ldr r0, _0805AED0 @ =0x0600F0EE
	ldrh r0, [r0]
	str r0, [r7]
	ldr r0, _0805AED4 @ =0x0600F12E
	ldrh r0, [r0]
	str r0, [r7, #4]
	movs r2, #0
	cmp r2, #5
	blt _0805AE30
	b _0805AF3C
_0805AE30:
	ldr r1, _0805AED8 @ =0x0600F02E
	mov sb, r1
_0805AE34:
	lsls r0, r2, #0x18
	asrs r2, r0, #0x18
	str r2, [r7, #0x14]
	ldr r3, [r7, #0xc]
	adds r6, r3, r2
	ldrb r3, [r6]
	mov sl, r0
	cmp r3, #0
	beq _0805AEE8
	ldr r1, _0805AEDC @ =0x08484444
	ldr r4, [r7, #8]
	adds r4, r4, r2
	mov r8, r4
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0805AEE0 @ =0x030004DE
	movs r2, #0x11
	bl memcpy_bytes_0803F63C
	ldr r0, [r7, #0x14]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r5, r0, #1
	adds r4, r5, #3
	movs r0, #7
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	ldr r0, _0805AEE0 @ =0x030004DE
	movs r2, #0xc
	adds r3, r4, #0
	bl render_text_sprites_08040DB8
	ldrb r0, [r6]
	movs r1, #0x18
	adds r2, r4, #0
	bl percent_rescale
	lsls r4, r4, #6
	add r4, sb
	ldr r1, [r7]
	strh r1, [r4]
	adds r5, #4
	lsls r5, r5, #6
	add r5, sb
	ldr r2, [r7, #4]
	strh r2, [r5]
	ldr r0, [r7, #0x14]
	adds r0, #0x55
	lsls r0, r0, #6
	ldr r3, _0805AEE4 @ =0x03002C30
	adds r5, r0, r3
	ldrh r1, [r5]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r5]
	mov r1, r8
	ldrb r0, [r1]
	bl sub_0805B4B0
	movs r1, #0x22
	cmp r0, #0
	beq _0805AEC8
	movs r1, #0x21
_0805AEC8:
	strh r1, [r5, #6]
	b _0805AF2C
	.align 2, 0
_0805AECC: .4byte 0x03006F74
_0805AED0: .4byte 0x0600F0EE
_0805AED4: .4byte 0x0600F12E
_0805AED8: .4byte 0x0600F02E
_0805AEDC: .4byte 0x08484444
_0805AEE0: .4byte 0x030004DE
_0805AEE4: .4byte 0x03002C30
_0805AEE8:
	ldr r2, [r7, #0x14]
	lsls r1, r2, #1
	adds r0, r1, #3
	lsls r0, r0, #6
	mov r4, sb
	adds r2, r0, r4
	strh r3, [r2]
	ldr r4, _0805AF54 @ =0x0600F030
	adds r2, r0, r4
	strh r3, [r2]
	adds r4, #2
	adds r2, r0, r4
	strh r3, [r2]
	adds r1, #4
	lsls r1, r1, #6
	mov r0, sb
	adds r2, r1, r0
	strh r3, [r2]
	subs r4, #2
	adds r2, r1, r4
	strh r3, [r2]
	ldr r0, _0805AF58 @ =0x0600F032
	adds r2, r1, r0
	strh r3, [r2]
	ldr r2, [r7, #0x14]
	adds r2, #0x55
	lsls r2, r2, #6
	ldr r1, _0805AF5C @ =0x03002C30
	adds r2, r2, r1
	ldrh r0, [r2]
	ldr r3, _0805AF60 @ =0x0000BFFF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2]
_0805AF2C:
	movs r0, #0x80
	lsls r0, r0, #0x11
	add r0, sl
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bge _0805AF3C
	b _0805AE34
_0805AF3C:
	bl item_menu_draw_page_numbers
	ldr r4, [r7, #0x10]
	mov sp, r4
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805AF54: .4byte 0x0600F030
_0805AF58: .4byte 0x0600F032
_0805AF5C: .4byte 0x03002C30
_0805AF60: .4byte 0x0000BFFF
	.syntax divided
