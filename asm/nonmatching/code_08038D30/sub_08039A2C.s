	.syntax unified

	thumb_func_start sub_08039A2C
sub_08039A2C: @ 0x08039A2C
	push {r4, lr}
	bl load_battle_sequence_commands
	ldr r2, _08039AC0 @ =0x03002C30
	ldr r0, _08039AC4 @ =0x03001800
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
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	movs r1, #0x83
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x2b
	strb r1, [r0]
	movs r1, #0
	ldrsh r0, [r4, r1]
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
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	movs r1, #0x85
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x2e
	strb r1, [r0]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, #5
	lsls r0, r0, #6
	adds r0, r0, r2
	adds r0, #0x29
	movs r1, #0x18
	strb r1, [r0]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039AC0: .4byte 0x03002C30
_08039AC4: .4byte 0x03001800
	.syntax divided
