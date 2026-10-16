	.syntax unified

	thumb_func_start sub_0800D710
sub_0800D710: @ 0x0800D710
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x28
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x24]
	ldr r1, _0800D7A4 @ =0x040000D4
	add r0, sp, #0x24
	str r0, [r1]
	ldr r0, _0800D7A8 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800D7AC @ =0x00000B84
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _0800D7B0 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0800D7B4 @ =0x03000440
	mov sb, r0
	mov r6, sb
	adds r6, #0x39
	ldrb r3, [r6]
	str r3, [sp]
	movs r0, #0x38
	str r0, [sp, #4]
	movs r0, #0x68
	str r0, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	movs r5, #4
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r7, #1
	str r7, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	movs r0, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl init_scene_with_bg_and_palette
	ldrb r3, [r6]
	str r3, [sp]
	movs r0, #0xb8
	str r0, [sp, #4]
	movs r0, #0x30
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #8
	mov r8, r2
	str r2, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	str r7, [sp, #0x1c]
	movs r0, #0x28
	str r0, [sp, #0x20]
	movs r0, #1
	adds r1, r3, #0
	adds r2, r3, #0
	bl init_scene_with_bg_and_palette
	ldr r0, _0800D7B8 @ =0x03001780
	ldr r6, [r0]
	ands r6, r5
	cmp r6, #0
	beq _0800D7BC
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800D7E4
	.align 2, 0
_0800D7A4: .4byte 0x040000D4
_0800D7A8: .4byte 0x03002414
_0800D7AC: .4byte 0x00000B84
_0800D7B0: .4byte 0x85000100
_0800D7B4: .4byte 0x03000440
_0800D7B8: .4byte 0x03001780
_0800D7BC:
	ldr r0, _0800D870 @ =0x083ACB50
	ldr r0, [r0]
	mov r4, sb
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	mov r0, r8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800D7E4:
	ldr r7, _0800D874 @ =0x03001798
	ldrb r1, [r7]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D802
	ldr r0, _0800D878 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0800D802:
	ldrb r1, [r7]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D81E
	ldr r0, _0800D878 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
_0800D81E:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r4, _0800D87C @ =0x030004DE
	adds r1, r4, #0
	subs r1, #0x6a
	adds r0, r4, #0
	subs r0, #0x69
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	movs r0, #3
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r6, #1
	str r6, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x20
	movs r2, #8
	movs r3, #2
	bl render_text_sprites_08040DB8
	ldrb r1, [r7]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800D894
	adds r1, r4, #0
	subs r1, #0x65
	ldrb r0, [r1]
	cmp r0, #0x79
	bne _0800D880
	strb r5, [r1]
	b _0800D884
	.align 2, 0
_0800D870: .4byte 0x083ACB50
_0800D874: .4byte 0x03001798
_0800D878: .4byte 0x03000440
_0800D87C: .4byte 0x030004DE
_0800D880:
	adds r0, #1
	strb r0, [r1]
_0800D884:
	ldr r1, _0800D890 @ =0x03000440
	adds r1, #0x33
	ldrb r0, [r1]
	subs r0, #1
	b _0800D8FC
	.align 2, 0
_0800D890: .4byte 0x03000440
_0800D894:
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0800D8C0
	adds r1, r4, #0
	subs r1, #0x65
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D8AE
	movs r0, #0x79
	b _0800D8B0
_0800D8AE:
	subs r0, #1
_0800D8B0:
	strb r0, [r1]
	ldr r1, _0800D8BC @ =0x03000440
	adds r1, #0x33
	ldrb r0, [r1]
	subs r0, #1
	b _0800D8FC
	.align 2, 0
_0800D8BC: .4byte 0x03000440
_0800D8C0:
	ldr r0, _0800D8E0 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D8EC
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800D8E4 @ =0x03000430
	str r5, [r0]
	ldr r0, _0800D8E8 @ =0x0300137C
	str r6, [r0]
	b _0800D8FE
	.align 2, 0
_0800D8E0: .4byte 0x0300058C
_0800D8E4: .4byte 0x03000430
_0800D8E8: .4byte 0x0300137C
_0800D8EC:
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0800D8FE
	adds r1, r4, #0
	subs r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
_0800D8FC:
	strb r0, [r1]
_0800D8FE:
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
