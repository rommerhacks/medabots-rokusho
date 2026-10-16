	.syntax unified

	thumb_func_start sub_080399EC
sub_080399EC: @ 0x080399EC
	push {lr}
	bl load_battle_sequence_commands
	ldr r2, _08039A0C @ =0x03002C30
	ldrh r1, [r2, #0x30]
	ldr r0, _08039A10 @ =0x03001800
	movs r3, #0x81
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	beq _08039A14
	adds r0, r1, #1
	strh r0, [r2, #0x30]
	b _08039A1C
	.align 2, 0
_08039A0C: .4byte 0x03002C30
_08039A10: .4byte 0x03001800
_08039A14:
	movs r0, #0
	strh r0, [r2, #0x30]
	bl battle_advance_sequence_counter
_08039A1C:
	ldr r0, _08039A28 @ =0x03002C30
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08039A28: .4byte 0x03002C30
	.syntax divided
