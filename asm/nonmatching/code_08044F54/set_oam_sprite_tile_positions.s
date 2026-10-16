	.syntax unified

	thumb_func_start set_oam_sprite_tile_positions
set_oam_sprite_tile_positions: @ 0x0804538C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	adds r4, r3, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r7, [r0]
	ldrb r0, [r7, #1]
	lsrs r5, r0, #6
	ldrb r0, [r7, #3]
	lsrs r6, r0, #6
	lsls r0, r5, #0xe
	lsls r1, r6, #0x1e
	bl sub_08044E64
	lsrs r5, r0, #0x10
	ldr r1, _080453D0 @ =0x0000FFFF
	adds r6, r0, #0
	ands r6, r1
	mov r0, sb
	strh r4, [r0, #8]
	movs r0, #0
	b _0804543A
	.align 2, 0
_080453D0: .4byte 0x0000FFFF
_080453D4:
	movs r3, #0
	adds r0, #1
	str r0, [sp]
	mov r2, sb
	ldrb r2, [r2, #0xb]
	cmp r3, r2
	bhs _0804541A
	ldr r0, _08045454 @ =0x000001FF
	mov ip, r0
	adds r4, r6, #0
_080453E8:
	mov r1, sl
	strb r1, [r7]
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	mov r0, ip
	ands r1, r0
	ldrh r2, [r7, #2]
	ldr r0, _08045458 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #2]
	mov r1, r8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r7, #8
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r2, sb
	ldrb r2, [r2, #0xb]
	cmp r3, r2
	blo _080453E8
_0804541A:
	mov r1, sb
	ldrb r0, [r1, #0xb]
	muls r0, r6, r0
	mov r2, r8
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sl
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r2, [sp]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
_0804543A:
	mov r1, sb
	ldrb r1, [r1, #0xa]
	cmp r0, r1
	blo _080453D4
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045454: .4byte 0x000001FF
_08045458: .4byte 0xFFFFFE00
	.syntax divided
