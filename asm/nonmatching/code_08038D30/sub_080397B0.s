	.syntax unified

	thumb_func_start sub_080397B0
sub_080397B0: @ 0x080397B0
	push {lr}
	bl load_battle_sequence_commands
	ldr r3, _080397E8 @ =0x03002C30
	ldr r2, _080397EC @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0xeb
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080397F0
	adds r0, r3, #0
	adds r0, #0xec
	strb r1, [r0]
	movs r1, #0xaa
	lsls r1, r1, #1
	b _080397FC
	.align 2, 0
_080397E8: .4byte 0x03002C30
_080397EC: .4byte 0x03001800
_080397F0:
	adds r1, r3, #0
	adds r1, #0xec
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
_080397FC:
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xf0
	strh r1, [r0]
	ldr r0, _08039818 @ =0x03002C30
	adds r0, #0xe9
	movs r1, #8
	strb r1, [r0]
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_08039818: .4byte 0x03002C30
	.syntax divided
