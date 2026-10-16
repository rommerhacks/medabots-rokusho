	.syntax unified

	thumb_func_start sub_08039FE4
sub_08039FE4: @ 0x08039FE4
	push {r4, lr}
	bl load_battle_sequence_commands
	movs r0, #0x1e
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r3, _0803A054 @ =0x03002C30
	ldr r2, _0803A058 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r4, _0803A05C @ =0x000007AB
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r4, #0x27
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r4, #0x20
	adds r0, r3, r4
	strb r1, [r0]
	ldr r0, _0803A060 @ =0x000007A9
	adds r1, r3, r0
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803A068
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r4, #0x22
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r2, _0803A064 @ =0x000007A5
	adds r0, r3, r2
	strb r1, [r0]
	b _0803A090
	.align 2, 0
_0803A054: .4byte 0x03002C30
_0803A058: .4byte 0x03001800
_0803A05C: .4byte 0x000007AB
_0803A060: .4byte 0x000007A9
_0803A064: .4byte 0x000007A5
_0803A068:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	movs r0, #0xf0
	subs r0, r0, r1
	ldr r4, _0803A0AC @ =0x00000782
	adds r1, r3, r4
	strh r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r0, r0, r1
	movs r1, #0x1f
	ands r0, r1
	ldr r2, _0803A0B0 @ =0x000007A5
	adds r1, r3, r2
	strb r0, [r1]
_0803A090:
	ldr r0, _0803A0B4 @ =0x03002C30
	ldr r4, _0803A0AC @ =0x00000782
	adds r1, r0, r4
	ldrh r1, [r1]
	movs r2, #0xf6
	lsls r2, r2, #3
	adds r0, r0, r2
	strh r1, [r0]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A0AC: .4byte 0x00000782
_0803A0B0: .4byte 0x000007A5
_0803A0B4: .4byte 0x03002C30
	.syntax divided
