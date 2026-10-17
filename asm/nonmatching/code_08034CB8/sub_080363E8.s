	.syntax unified

	thumb_func_start sub_080363E8
sub_080363E8: @ 0x080363E8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	adds r0, r2, #0
	adds r1, r3, #0
	ldr r4, [sp, #0x24]
	adds r2, r4, #0
	bl scale_to_bar_fill
	adds r5, r0, #0
	ldr r7, _08036498 @ =0x0000FFFF
	ands r7, r5
	lsrs r5, r5, #0x10
	cmp r4, #0
	beq _08036418
	cmp r5, #0
	bne _08036418
	cmp r7, #0
	bne _08036418
	movs r7, #1
_08036418:
	movs r6, #0
	movs r4, #0
	cmp r4, r5
	bhs _08036440
_08036420:
	mov r0, sb
	adds r2, r0, r6
	ldr r0, _0803649C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080364A0 @ =0x0000A328
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	mov r3, r8
	bl fill_tilemap_rect_08042698
	adds r6, #1
	adds r4, #1
	cmp r4, r5
	blo _08036420
_08036440:
	cmp r7, #0
	beq _08036464
	mov r1, sb
	adds r2, r1, r6
	ldr r0, _0803649C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _080364A4 @ =0x0000A320
	adds r0, r7, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	mov r3, r8
	bl fill_tilemap_rect_08042698
	adds r6, #1
_08036464:
	adds r4, r6, #0
	cmp r4, #7
	bhi _0803648A
_0803646A:
	mov r0, sb
	adds r2, r0, r6
	ldr r0, _0803649C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080364A4 @ =0x0000A320
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	mov r3, r8
	bl fill_tilemap_rect_08042698
	adds r6, #1
	adds r4, #1
	cmp r4, #7
	bls _0803646A
_0803648A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036498: .4byte 0x0000FFFF
_0803649C: .4byte 0x0400000A
_080364A0: .4byte 0x0000A328
_080364A4: .4byte 0x0000A320
	.syntax divided
