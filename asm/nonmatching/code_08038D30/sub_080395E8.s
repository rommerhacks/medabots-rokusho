	.syntax unified

	thumb_func_start sub_080395E8
sub_080395E8: @ 0x080395E8
	push {r4, lr}
	bl load_battle_sequence_commands
	ldr r2, _08039620 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08039658
	ldr r3, _08039624 @ =0x03002C30
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
	beq _08039628
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r2, r1
	b _0803962C
	.align 2, 0
_08039620: .4byte 0x03001800
_08039624: .4byte 0x03002C30
_08039628:
	adds r0, r2, #0
	adds r0, #0xa7
_0803962C:
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #1
	movs r4, #0x81
	lsls r4, r4, #1
	adds r1, r2, r4
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x6c
	strb r1, [r0]
	ldr r0, _08039654 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x70
	b _080396AC
	.align 2, 0
_08039654: .4byte 0x03001800
_08039658:
	ldr r3, _08039680 @ =0x03002C30
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
	beq _08039684
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	adds r0, #4
	lsls r0, r0, #1
	subs r4, #0x60
	b _08039692
	.align 2, 0
_08039680: .4byte 0x03002C30
_08039684:
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	adds r0, #4
	lsls r0, r0, #1
	movs r4, #0x81
	lsls r4, r4, #1
_08039692:
	adds r1, r2, r4
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xac
	strb r1, [r0]
	ldr r0, _080396C0 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xb0
_080396AC:
	movs r2, #0
	strh r1, [r0]
	subs r0, #3
	strb r2, [r0]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080396C0: .4byte 0x03001800
_080396C4:
	.byte 0x02, 0x48, 0x2A, 0x30, 0x01, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00
	.byte 0x30, 0x2C, 0x00, 0x03
	.syntax divided
