	.syntax unified

	thumb_func_start sub_0803B5DC
sub_0803B5DC: @ 0x0803B5DC
	push {r4, lr}
	bl load_battle_sequence_commands
	ldr r0, _0803B640 @ =0x084C4F00
	ldr r1, _0803B644 @ =0x06006400
	bl lz_decompress_dispatch
	ldr r0, _0803B648 @ =0x084882F4
	ldr r1, _0803B64C @ =0x06006520
	bl lz_decompress_dispatch
	ldr r0, _0803B650 @ =0x084C3648
	ldr r1, _0803B654 @ =0x06006600
	bl lz_decompress_dispatch
	ldr r0, _0803B658 @ =0x084C65C8
	ldr r1, _0803B65C @ =0x06006800
	bl lz_decompress_dispatch
	ldr r0, _0803B660 @ =0x08488B24
	ldr r1, _0803B664 @ =0x05000140
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803B668 @ =0x084E3098
	ldr r1, _0803B66C @ =0x05000100
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803B670 @ =0x084C6A58
	ldr r1, _0803B674 @ =0x05000160
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803B678 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0803B684
	ldr r1, _0803B67C @ =0x03002C30
	ldr r2, _0803B680 @ =0x0000026D
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, r1, #0
	b _0803B68E
	.align 2, 0
_0803B640: .4byte 0x084C4F00
_0803B644: .4byte 0x06006400
_0803B648: .4byte 0x084882F4
_0803B64C: .4byte 0x06006520
_0803B650: .4byte 0x084C3648
_0803B654: .4byte 0x06006600
_0803B658: .4byte 0x084C65C8
_0803B65C: .4byte 0x06006800
_0803B660: .4byte 0x08488B24
_0803B664: .4byte 0x05000140
_0803B668: .4byte 0x084E3098
_0803B66C: .4byte 0x05000100
_0803B670: .4byte 0x084C6A58
_0803B674: .4byte 0x05000160
_0803B678: .4byte 0x03001800
_0803B67C: .4byte 0x03002C30
_0803B680: .4byte 0x0000026D
_0803B684:
	ldr r2, _0803B6C8 @ =0x03002C30
	ldr r3, _0803B6CC @ =0x0000026D
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
_0803B68E:
	ldr r4, _0803B6D0 @ =0x0000026E
	adds r1, r2, r4
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0803B6D4 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	subs r4, #3
	adds r0, r2, r4
	strb r1, [r0]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	subs r4, #2
	adds r1, r2, r4
	movs r0, #0x38
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B6C8: .4byte 0x03002C30
_0803B6CC: .4byte 0x0000026D
_0803B6D0: .4byte 0x0000026E
_0803B6D4: .4byte 0x03001800
	.syntax divided
