	.syntax unified

	thumb_func_start sub_080394C4
sub_080394C4: @ 0x080394C4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	bl load_battle_sequence_commands
	bl battle_advance_sequence_counter
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08039536
	ldr r7, _08039524 @ =0x083CDFE4
	ldr r4, _08039528 @ =0x03001800
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r4, r0
	mov r5, sp
_080394EA:
	adds r0, r4, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r4, #0
	adds r0, #0xfd
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r3, #0x81
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r1, r0
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _0803952C
	bl battle_advance_sequence_counter
	movs r0, #1
	strb r0, [r5]
	b _08039530
	.align 2, 0
_08039524: .4byte 0x083CDFE4
_08039528: .4byte 0x03001800
_0803952C:
	bl battle_advance_sequence_counter
_08039530:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080394EA
_08039536:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
