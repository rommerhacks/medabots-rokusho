	.syntax unified

	thumb_func_start sub_08039AC8
sub_08039AC8: @ 0x08039AC8
	push {r4, r5, lr}
	bl load_battle_sequence_commands
	ldr r2, _08039B58 @ =0x03002C30
	ldr r0, _08039B5C @ =0x03001800
	mov ip, r0
	movs r4, #0x81
	lsls r4, r4, #1
	add r4, ip
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	movs r1, #0x82
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	movs r3, #0
	strh r1, [r0, #0x30]
	movs r5, #0
	ldrsh r0, [r4, r5]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	adds r0, #0x2c
	strb r3, [r0]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	movs r1, #0x84
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x2d
	strb r1, [r0]
	movs r3, #0
	ldrsh r0, [r4, r3]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	movs r1, #0x85
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x2e
	strb r1, [r0]
	movs r5, #0
	ldrsh r0, [r4, r5]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	adds r0, #0x29
	movs r1, #0x18
	strb r1, [r0]
	mov r0, ip
	adds r0, #0xf6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08039B64
	ldr r0, _08039B60 @ =0x00000161
	add r0, ip
	ldrb r0, [r0]
	mov r1, ip
	adds r1, #0x64
	bl get_bot_part_effective_values
	b _08039B72
	.align 2, 0
_08039B58: .4byte 0x03002C30
_08039B5C: .4byte 0x03001800
_08039B60: .4byte 0x00000161
_08039B64:
	mov r0, ip
	adds r0, #0x87
	ldrb r0, [r0]
	mov r1, ip
	adds r1, #0x64
	bl get_bot_part_effective_values
_08039B72:
	ldr r1, _08039B84 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x67
	ldrb r0, [r0]
	adds r3, r1, #0
	cmp r0, #0x77
	bls _08039B88
	movs r4, #3
	b _08039BBC
	.align 2, 0
_08039B84: .4byte 0x03001800
_08039B88:
	adds r0, r3, #0
	adds r0, #0xf6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08039BA8
	ldr r0, _08039BA0 @ =0x03000590
	ldr r2, _08039BA4 @ =0x00000161
	adds r1, r3, r2
	b _08039BAE
	.align 2, 0
_08039BA0: .4byte 0x03000590
_08039BA4: .4byte 0x00000161
_08039BA8:
	ldr r0, _08039BF0 @ =0x03000590
	adds r1, r3, #0
	adds r1, #0x87
_08039BAE:
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r1, #0x91
	ldrb r0, [r1]
	adds r4, r0, #0
	subs r4, #0x64
_08039BBC:
	ldr r1, _08039BF4 @ =0x083AF888
	movs r5, #0x83
	lsls r5, r5, #1
	adds r0, r3, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, _08039BF8 @ =0x03002C30
	subs r5, #4
	adds r0, r3, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	adds r1, r1, r4
	ldrb r1, [r1]
	adds r0, #0x2b
	strb r1, [r0]
	bl battle_advance_sequence_counter
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08039BF0: .4byte 0x03000590
_08039BF4: .4byte 0x083AF888
_08039BF8: .4byte 0x03002C30
	.syntax divided
