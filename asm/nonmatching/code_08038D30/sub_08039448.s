	.syntax unified

	thumb_func_start sub_08039448
sub_08039448: @ 0x08039448
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	bl load_battle_sequence_commands
	bl battle_advance_sequence_counter
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080394B6
	ldr r0, _080394A4 @ =0x083CDFE4
	mov r8, r0
	ldr r5, _080394A8 @ =0x03001800
	movs r2, #0x81
	lsls r2, r2, #1
	adds r7, r5, r2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r5, r0
	mov r4, sp
_0803947A:
	adds r0, r5, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r7, r2]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _080394AC
	bl battle_advance_sequence_counter
	movs r0, #1
	strb r0, [r4]
	b _080394B0
	.align 2, 0
_080394A4: .4byte 0x083CDFE4
_080394A8: .4byte 0x03001800
_080394AC:
	bl battle_advance_sequence_counter
_080394B0:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803947A
_080394B6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
