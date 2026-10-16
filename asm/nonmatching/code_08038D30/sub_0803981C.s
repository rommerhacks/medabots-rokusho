	.syntax unified

	thumb_func_start sub_0803981C
sub_0803981C: @ 0x0803981C
	push {lr}
	bl load_battle_sequence_commands
	ldr r2, _0803984C @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08039854
	cmp r0, #1
	beq _0803986C
	ldr r1, _08039850 @ =0x0000015F
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803989A
	adds r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803989A
	b _08039896
	.align 2, 0
_0803984C: .4byte 0x03001800
_08039850: .4byte 0x0000015F
_08039854:
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08039884
	ldr r1, _08039868 @ =0x0000015F
	b _08039888
	.align 2, 0
_08039868: .4byte 0x0000015F
_0803986C:
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08039884
	ldr r1, _08039880 @ =0x0000015F
	b _08039888
	.align 2, 0
_08039880: .4byte 0x0000015F
_08039884:
	movs r1, #0xb0
	lsls r1, r1, #1
_08039888:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803989A
	bl battle_advance_sequence_counter
	b _0803989A
_08039896:
	bl battle_advance_sequence_counter
_0803989A:
	ldr r0, _080398A8 @ =0x03002C30
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080398A8: .4byte 0x03002C30
	.syntax divided
