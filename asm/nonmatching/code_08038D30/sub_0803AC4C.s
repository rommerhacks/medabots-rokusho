	.syntax unified

	thumb_func_start sub_0803AC4C
sub_0803AC4C: @ 0x0803AC4C
	push {lr}
	bl load_battle_sequence_commands
	ldr r1, _0803AC80 @ =0x03001800
	movs r2, #0x81
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0803AC88
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #5
	movs r2, #0xa0
	lsls r2, r2, #0x13
	adds r0, r1, r2
	ldr r2, _0803AC84 @ =0x0202FA00
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	b _0803ACA2
	.align 2, 0
_0803AC80: .4byte 0x03001800
_0803AC84: .4byte 0x0202FA00
_0803AC88:
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #5
	ldr r2, _0803ACAC @ =0x05000200
	adds r0, r1, r2
	ldr r2, _0803ACB0 @ =0x0202F800
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
_0803ACA2:
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_0803ACAC: .4byte 0x05000200
_0803ACB0: .4byte 0x0202F800
	.syntax divided
