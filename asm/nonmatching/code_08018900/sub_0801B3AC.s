	.syntax unified

	thumb_func_start sub_0801B3AC
sub_0801B3AC: @ 0x0801B3AC
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r3, _0801B4B0 @ =0x03001800
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r5, r3, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801B49A
	ldr r2, _0801B4B4 @ =0x03000590
	adds r4, r3, #0
	adds r4, #0xa7
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r6, #0x87
	adds r6, r6, r3
	mov ip, r6
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r2
	movs r6, #0x8e
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, #0x48
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r6, ip
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r2
	ldr r6, _0801B4B8 @ =0x0000011D
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, #0x49
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r6, ip
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r2
	ldr r6, _0801B4BC @ =0x00000121
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, #0x4d
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r6, ip
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r2
	movs r6, #0x91
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, #0x4e
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r6, ip
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r2
	ldr r6, _0801B4C0 @ =0x00000123
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, #0x4f
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r6, ip
	ldrb r0, [r6]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r2
	movs r6, #0x94
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, #0x54
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	mov r4, ip
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r2
	adds r6, #0xb
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r1, #0x5f
	strb r0, [r1]
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
_0801B49A:
	movs r0, #0
	str r0, [sp]
	ldr r2, _0801B4C4 @ =0x05000009
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801B4B0: .4byte 0x03001800
_0801B4B4: .4byte 0x03000590
_0801B4B8: .4byte 0x0000011D
_0801B4BC: .4byte 0x00000121
_0801B4C0: .4byte 0x00000123
_0801B4C4: .4byte 0x05000009
	.syntax divided
