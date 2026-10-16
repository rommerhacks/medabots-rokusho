	.syntax unified

	thumb_func_start sub_08039BFC
sub_08039BFC: @ 0x08039BFC
	push {lr}
	bl load_battle_sequence_commands
	ldr r2, _08039C5C @ =0x03002C30
	ldr r3, _08039C60 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0xe4
	strb r1, [r0]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0xed
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08039C64
	adds r0, r2, #0
	adds r0, #0xec
	strb r1, [r0]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0xe5
	strb r0, [r1]
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0xc2
	strh r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	b _08039C94
	.align 2, 0
_08039C5C: .4byte 0x03002C30
_08039C60: .4byte 0x03001800
_08039C64:
	adds r1, r2, #0
	adds r1, #0xec
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r0, r0, r1
	movs r1, #0x1f
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0xe5
	strb r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0xc2
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
_08039C94:
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0xc4
	strh r1, [r0]
	ldr r0, _08039CB0 @ =0x03002C30
	adds r0, #0xe9
	movs r1, #9
	strb r1, [r0]
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_08039CB0: .4byte 0x03002C30
	.syntax divided
