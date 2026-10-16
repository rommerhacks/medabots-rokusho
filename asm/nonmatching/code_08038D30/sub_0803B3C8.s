	.syntax unified

	thumb_func_start sub_0803B3C8
sub_0803B3C8: @ 0x0803B3C8
	push {r4, r5, lr}
	bl load_battle_sequence_commands
	ldr r4, _0803B418 @ =0x083AF88C
	ldr r1, _0803B41C @ =0x03001800
	movs r0, #0x81
	lsls r0, r0, #1
	adds r5, r1, r0
	movs r2, #0
	ldrsh r0, [r5, r2]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #5
	ldr r2, _0803B420 @ =0x06010000
	adds r1, r1, r2
	bl lz_decompress_dispatch
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, _0803B424 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	bl battle_advance_sequence_counter
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B418: .4byte 0x083AF88C
_0803B41C: .4byte 0x03001800
_0803B420: .4byte 0x06010000
_0803B424: .4byte 0x050003C0
	.syntax divided
