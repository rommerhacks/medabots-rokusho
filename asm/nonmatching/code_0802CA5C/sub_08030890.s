	.syntax unified

	thumb_func_start sub_08030890
sub_08030890: @ 0x08030890
	push {r4, lr}
	ldr r0, _080308A8 @ =0x03000440
	ldr r1, _080308AC @ =0x00000139
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #1
	beq _080308D0
	cmp r0, #1
	bgt _080308B0
	cmp r0, #0
	beq _080308B6
	b _080308FE
	.align 2, 0
_080308A8: .4byte 0x03000440
_080308AC: .4byte 0x00000139
_080308B0:
	cmp r0, #2
	beq _080308E8
	b _080308FE
_080308B6:
	ldr r0, _080308CC @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl reset_bot_status_and_init_palette_transfers
	bl copy_battle_entity_positions
	ldrb r0, [r4]
	adds r0, #1
	b _080308FC
	.align 2, 0
_080308CC: .4byte 0x03001800
_080308D0:
	ldr r0, _080308E0 @ =0x084C8AC4
	ldr r1, _080308E4 @ =0x06014E00
	bl lz_decompress_dispatch
	ldrb r0, [r4]
	adds r0, #1
	b _080308FC
	.align 2, 0
_080308E0: .4byte 0x084C8AC4
_080308E4: .4byte 0x06014E00
_080308E8:
	ldr r0, _08030904 @ =0x084E2FF8
	ldr r1, _08030908 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0803090C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_080308FC:
	strb r0, [r4]
_080308FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030904: .4byte 0x084E2FF8
_08030908: .4byte 0x050002C0
_0803090C: .4byte 0x0300137C
	.syntax divided
