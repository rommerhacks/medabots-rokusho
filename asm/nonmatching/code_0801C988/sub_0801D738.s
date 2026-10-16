	.syntax unified

	thumb_func_start sub_0801D738
sub_0801D738: @ 0x0801D738
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	ldr r7, _0801D858 @ =0x03001800
	movs r0, #0xde
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #8
	ldr r5, _0801D85C @ =0x030042B0
	adds r0, r0, r5
	ldr r2, _0801D860 @ =0xFFFFF1C0
	adds r1, r5, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	mov r4, r8
	ldrb r0, [r4]
	subs r0, #1
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x40
	adds r0, r0, r1
	ldr r6, _0801D864 @ =0xFFFFF200
	adds r1, r5, r6
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldrb r0, [r4]
	subs r0, #1
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x80
	adds r0, r0, r1
	ldr r2, _0801D868 @ =0xFFFFF240
	adds r1, r5, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldrb r0, [r4]
	subs r0, #1
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0xc0
	adds r0, r0, r1
	ldr r4, _0801D86C @ =0xFFFFF280
	adds r1, r5, r4
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	movs r0, #0x21
	movs r1, #4
	bl clear_sprite_table_mask
	mov r6, r8
	ldrb r0, [r6]
	subs r0, #1
	adds r4, r7, #0
	adds r4, #0x64
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	adds r1, r7, #0
	adds r1, #0x65
	ldrb r1, [r1]
	adds r2, r7, #0
	adds r2, #0x66
	ldrb r2, [r2]
	adds r3, r7, #0
	adds r3, #0x67
	ldrb r3, [r3]
	ldrb r4, [r6]
	subs r4, #1
	str r4, [sp]
	ldrb r4, [r6]
	lsls r4, r4, #2
	adds r4, #0x56
	str r4, [sp, #4]
	ldr r4, _0801D870 @ =0xFFFFE980
	adds r5, r5, r4
	ldrb r4, [r6]
	lsls r4, r4, #8
	movs r6, #0xb2
	lsls r6, r6, #5
	adds r4, r4, r6
	adds r4, r4, r5
	movs r6, #2
	ldrsh r4, [r4, r6]
	str r4, [sp, #8]
	mov r6, r8
	ldrb r4, [r6]
	lsls r4, r4, #8
	movs r6, #0xb2
	lsls r6, r6, #5
	adds r4, r4, r6
	adds r4, r4, r5
	movs r5, #4
	ldrsh r4, [r4, r5]
	subs r4, #4
	str r4, [sp, #0xc]
	adds r4, r7, #0
	adds r4, #0xf8
	ldrb r5, [r4]
	movs r6, #1
	movs r4, #1
	ands r4, r5
	eors r4, r6
	str r4, [sp, #0x10]
	adds r4, r7, #0
	adds r4, #0x3c
	ldrb r4, [r4]
	adds r4, #2
	str r4, [sp, #0x14]
	mov r6, r8
	ldrb r4, [r6]
	lsls r4, r4, #2
	adds r4, #0x56
	str r4, [sp, #0x18]
	bl setup_battle_sprite_group
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, #0x56
	movs r1, #8
	bl battle_sprite_set_palette_index
	ldr r0, _0801D874 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D858: .4byte 0x03001800
_0801D85C: .4byte 0x030042B0
_0801D860: .4byte 0xFFFFF1C0
_0801D864: .4byte 0xFFFFF200
_0801D868: .4byte 0xFFFFF240
_0801D86C: .4byte 0xFFFFF280
_0801D870: .4byte 0xFFFFE980
_0801D874: .4byte 0x03000440
	.syntax divided
