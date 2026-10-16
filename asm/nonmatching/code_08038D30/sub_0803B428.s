	.syntax unified

	thumb_func_start sub_0803B428
sub_0803B428: @ 0x0803B428
	push {r4, r5, lr}
	bl load_battle_sequence_commands
	ldr r3, _0803B4EC @ =0x03002C30
	ldr r0, _0803B4F0 @ =0x03001800
	mov ip, r0
	movs r5, #0x81
	lsls r5, r5, #1
	add r5, ip
	movs r2, #0
	ldrsh r1, [r5, r2]
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r2, [r1]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	movs r4, #0
	orrs r0, r2
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x85
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	strb r1, [r0, #8]
	movs r2, #0
	ldrsh r0, [r5, r2]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x86
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	strb r1, [r0, #9]
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	strh r4, [r0, #0x18]
	movs r2, #0
	ldrsh r0, [r5, r2]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x84
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x26
	strb r1, [r0]
	movs r4, #0
	ldrsh r0, [r5, r4]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x83
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x2d
	strb r1, [r0]
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x82
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x23
	strb r1, [r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x29
	movs r1, #0x34
	strb r1, [r0]
	ldr r1, _0803B4F4 @ =0x083B5F80
	movs r4, #0
	ldrsh r0, [r5, r4]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r5]
	bl init_battle_sprite_entry_08040B90
	bl battle_advance_sequence_counter
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B4EC: .4byte 0x03002C30
_0803B4F0: .4byte 0x03001800
_0803B4F4: .4byte 0x083B5F80
	.syntax divided
