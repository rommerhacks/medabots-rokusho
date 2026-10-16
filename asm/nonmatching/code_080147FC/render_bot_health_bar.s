	.syntax unified

	thumb_func_start render_bot_health_bar
	.global render_bot_health_bar
render_bot_health_bar: @ 0x08015C40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	movs r7, #0
	cmp r4, #2
	bhi _08015D0C
	ldr r0, _08015CFC @ =0x03000590
	lsls r4, r4, #8
	adds r4, r4, r0
	adds r4, #0xc1
	ldrb r2, [r4]
	movs r0, #0x40
	movs r1, #0x50
	bl fixed_point_multiply_divide
	adds r6, r0, #0
	ldr r0, _08015D00 @ =0x0000FFFF
	mov r8, r0
	ands r0, r6
	mov r8, r0
	lsrs r6, r6, #0x10
	ldrb r0, [r4]
	cmp r0, #0
	beq _08015C82
	cmp r6, #0
	bne _08015C82
	mov r0, r8
	cmp r0, #0
	bne _08015C82
	movs r0, #1
	mov r8, r0
_08015C82:
	movs r5, #0
	cmp r5, r6
	bhs _08015CA8
_08015C88:
	adds r4, r7, #1
	ldr r0, _08015D04 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08015D08 @ =0x0000D208
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	adds r7, r4, #0
	adds r5, #1
	cmp r5, r6
	blo _08015C88
_08015CA8:
	mov r0, r8
	cmp r0, #0
	beq _08015CD0
	adds r4, r7, #1
	ldr r0, _08015D04 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0xd2
	lsls r0, r0, #8
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	adds r7, r4, #0
_08015CD0:
	adds r5, r7, #0
	cmp r5, #7
	bhi _08015DB4
_08015CD6:
	adds r4, r7, #1
	ldr r0, _08015D04 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0xd2
	lsls r0, r0, #8
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	adds r7, r4, #0
	adds r5, #1
	cmp r5, #7
	bls _08015CD6
	b _08015DB4
	.align 2, 0
_08015CFC: .4byte 0x03000590
_08015D00: .4byte 0x0000FFFF
_08015D04: .4byte 0x0400000A
_08015D08: .4byte 0x0000D208
_08015D0C:
	ldr r0, _08015DC0 @ =0x03000590
	lsls r4, r4, #8
	adds r4, r4, r0
	adds r4, #0xc1
	ldrb r2, [r4]
	movs r0, #0x40
	movs r1, #0x50
	bl fixed_point_multiply_divide
	adds r6, r0, #0
	ldr r0, _08015DC4 @ =0x0000FFFF
	mov r8, r0
	ands r0, r6
	mov r8, r0
	lsrs r6, r6, #0x10
	ldrb r0, [r4]
	cmp r0, #0
	beq _08015D3E
	cmp r6, #0
	bne _08015D3E
	mov r0, r8
	cmp r0, #0
	bne _08015D3E
	movs r0, #1
	mov r8, r0
_08015D3E:
	movs r5, #0
	cmp r5, r6
	bhs _08015D64
_08015D44:
	adds r2, r7, #0
	adds r2, #0x15
	ldr r0, _08015DC8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08015DCC @ =0x0000D208
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	adds r7, #1
	adds r5, #1
	cmp r5, r6
	blo _08015D44
_08015D64:
	mov r0, r8
	cmp r0, #0
	beq _08015D8C
	adds r2, r7, #0
	adds r2, #0x15
	ldr r0, _08015DC8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0xd2
	lsls r0, r0, #8
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	adds r7, #1
_08015D8C:
	adds r5, r7, #0
	cmp r5, #7
	bhi _08015DB4
_08015D92:
	adds r2, r7, #0
	adds r2, #0x15
	ldr r0, _08015DC8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0xd2
	lsls r0, r0, #8
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	adds r7, #1
	adds r5, #1
	cmp r5, #7
	bls _08015D92
_08015DB4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015DC0: .4byte 0x03000590
_08015DC4: .4byte 0x0000FFFF
_08015DC8: .4byte 0x0400000A
_08015DCC: .4byte 0x0000D208
	.syntax divided
