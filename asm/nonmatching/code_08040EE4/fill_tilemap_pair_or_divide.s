	.syntax unified

	thumb_func_start fill_tilemap_pair_or_divide
	.global fill_tilemap_pair_or_divide
fill_tilemap_pair_or_divide: @ 0x080426F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r3
	ldr r3, [sp, #0x38]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	str r7, [sp, #0xc]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sb, r2
	mov r0, sb
	str r0, [sp, #0x10]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	mov r1, sl
	str r1, [sp, #0x14]
	cmp r6, #0xff
	bne _08042746
	mov r0, r8
	str r0, [sp]
	mov r4, sl
	adds r4, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #4]
	movs r0, #1
	movs r1, #2
	adds r2, r7, #0
	mov r3, sb
	bl fill_tilemap_rect_08042698
	adds r2, r7, #1
	mov r1, r8
	str r1, [sp]
	str r4, [sp, #4]
	b _080427E6
_08042746:
	add r4, sp, #8
	movs r5, #0x64
	adds r0, r6, #0
	movs r1, #0x64
	bl sub_0807CD58
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	muls r4, r5, r4
	subs r4, r6, r4
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	add r5, sp, #8
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CD58
	strb r0, [r5, #1]
	add r2, sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	strb r4, [r2, #2]
	adds r0, r2, #0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080427AC
	mov r0, r8
	str r0, [sp]
	mov r0, sl
	adds r0, #0x14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	adds r2, r7, #0
	mov r3, sb
	bl fill_tilemap_rect_08042698
	adds r2, r7, #1
	mov r1, r8
	str r1, [sp]
	mov r0, sl
	adds r0, #0x16
	b _080427E0
_080427AC:
	add r0, sp, #8
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq _080427F2
	mov r0, r8
	str r0, [sp]
	add r0, sp, #8
	ldrb r0, [r0, #1]
	lsls r0, r0, #1
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	adds r2, r7, #0
	mov r3, sb
	bl fill_tilemap_rect_08042698
	adds r2, r7, #1
	mov r1, r8
	str r1, [sp]
	add r0, sp, #8
	ldrb r0, [r0, #2]
	lsls r0, r0, #1
	add r0, sl
_080427E0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
_080427E6:
	movs r0, #1
	movs r1, #2
	mov r3, sb
	bl fill_tilemap_rect_08042698
	b _08042826
_080427F2:
	mov r1, r8
	str r1, [sp]
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl vram_fill_tilemap_rect
	ldr r2, [sp, #0xc]
	adds r2, #1
	mov r0, r8
	str r0, [sp]
	add r0, sp, #8
	ldrb r0, [r0, #2]
	lsls r0, r0, #1
	ldr r1, [sp, #0x14]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	ldr r3, [sp, #0x10]
	bl fill_tilemap_rect_08042698
_08042826:
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
