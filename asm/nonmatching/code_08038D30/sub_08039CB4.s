	.syntax unified

	thumb_func_start sub_08039CB4
sub_08039CB4: @ 0x08039CB4
	push {lr}
	ldr r1, _08039CE0 @ =0x03000590
	ldr r3, _08039CE4 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08039CE8
	adds r1, r3, #0
	adds r1, #0xfd
	movs r0, #1
	strb r0, [r1]
	b _08039CEE
	.align 2, 0
_08039CE0: .4byte 0x03000590
_08039CE4: .4byte 0x03001800
_08039CE8:
	adds r0, r3, #0
	adds r0, #0xfd
	strb r2, [r0]
_08039CEE:
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
