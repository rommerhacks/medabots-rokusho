	.syntax unified

	thumb_func_start init_enemy_bot_loadouts
init_enemy_bot_loadouts: @ 0x0801520C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r6, #0
	ldr r0, _08015280 @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x5b
	ldrb r2, [r1]
	cmp r6, r2
	bhs _08015274
	ldr r3, _08015284 @ =0x0300052E
	mov r8, r1
	adds r5, r0, #4
	ldr r0, _08015288 @ =0x03000590
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r7, r0, r2
_08015236:
	movs r0, #3
	strb r0, [r4]
	ldrb r0, [r5]
	movs r1, #0
	adds r2, r3, #0
	str r3, [sp]
	bl load_part_data
	ldr r3, [sp]
	ldrb r0, [r3, #3]
	strb r0, [r4, #1]
	ldrb r0, [r7, #1]
	strb r0, [r4, #2]
	ldrb r0, [r5]
	strb r0, [r4, #3]
	ldrb r0, [r5, #1]
	strb r0, [r4, #4]
	ldrb r0, [r5, #2]
	strb r0, [r4, #5]
	ldrb r0, [r5, #3]
	strb r0, [r4, #6]
	adds r5, #0xc
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r7, r7, r0
	adds r6, #1
	mov r0, r8
	ldrb r0, [r0]
	cmp r6, r0
	blo _08015236
_08015274:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015280: .4byte 0x03001800
_08015284: .4byte 0x0300052E
_08015288: .4byte 0x03000590
	.syntax divided
