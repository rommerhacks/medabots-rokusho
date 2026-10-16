	.syntax unified

	thumb_func_start sub_080396D4
sub_080396D4: @ 0x080396D4
	push {r4, lr}
	bl load_battle_sequence_commands
	ldr r2, _0803970C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08039744
	ldr r3, _08039710 @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xab
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf6
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08039714
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r2, r1
	b _08039718
	.align 2, 0
_0803970C: .4byte 0x03001800
_08039710: .4byte 0x03002C30
_08039714:
	adds r0, r2, #0
	adds r0, #0xa7
_08039718:
	ldrb r0, [r0]
	adds r0, #4
	lsls r0, r0, #1
	movs r4, #0x81
	lsls r4, r4, #1
	adds r1, r2, r4
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xac
	strb r1, [r0]
	ldr r0, _08039740 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xb0
	b _08039798
	.align 2, 0
_08039740: .4byte 0x03001800
_08039744:
	ldr r3, _0803976C @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0x6b
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf6
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08039770
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #1
	subs r4, #0x60
	b _0803977E
	.align 2, 0
_0803976C: .4byte 0x03002C30
_08039770:
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #1
	movs r4, #0x81
	lsls r4, r4, #1
_0803977E:
	adds r1, r2, r4
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x6c
	strb r1, [r0]
	ldr r0, _080397AC @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x70
_08039798:
	movs r2, #0
	strh r1, [r0]
	subs r0, #3
	strb r2, [r0]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080397AC: .4byte 0x03001800
	.syntax divided
