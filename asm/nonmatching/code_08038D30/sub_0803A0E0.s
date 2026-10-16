	.syntax unified

	thumb_func_start sub_0803A0E0
sub_0803A0E0: @ 0x0803A0E0
	push {r4, r5, lr}
	bl load_battle_sequence_commands
	ldr r4, _0803A120 @ =0x083AF88C
	ldr r0, _0803A124 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r5, r0, r1
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, _0803A128 @ =0x06010000
	bl lz_decompress_dispatch
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, _0803A12C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	bl battle_advance_sequence_counter
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803A120: .4byte 0x083AF88C
_0803A124: .4byte 0x03001800
_0803A128: .4byte 0x06010000
_0803A12C: .4byte 0x050003C0
	.syntax divided
