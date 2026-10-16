	.syntax unified

	thumb_func_start calc_battle_stat_ratio
	.global calc_battle_stat_ratio
calc_battle_stat_ratio: @ 0x08037280
	push {r4, r5, lr}
	ldr r4, _080372CC @ =0x03001800
	adds r2, r4, #0
	adds r2, #0xe8
	ldrh r3, [r2]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x12
	adds r5, r4, #0
	adds r5, #0xec
	strh r3, [r5]
	ldr r4, _080372D0 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r4
	adds r0, r2, #0
	adds r0, #0x4e
	ldrb r0, [r0]
	adds r3, r3, r0
	strh r3, [r5]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r2, #0x54
	ldrb r1, [r2]
	bl sub_0807CBBC
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080372C4
	movs r0, #1
	strh r0, [r5]
_080372C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080372CC: .4byte 0x03001800
_080372D0: .4byte 0x03000590
	.syntax divided
