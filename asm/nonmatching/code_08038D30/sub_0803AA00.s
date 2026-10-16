	.syntax unified

	thumb_func_start sub_0803AA00
sub_0803AA00: @ 0x0803AA00
	push {lr}
	bl load_battle_sequence_commands
	ldr r0, _0803AA34 @ =0x03001800
	mov ip, r0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803AA3C
	ldr r2, _0803AA38 @ =0x03002C30
	movs r0, #0x81
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	adds r0, r0, r2
	movs r1, #0x82
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	adds r0, #0x25
	strb r1, [r0]
	b _0803AA62
	.align 2, 0
_0803AA34: .4byte 0x03001800
_0803AA38: .4byte 0x03002C30
_0803AA3C:
	ldr r3, _0803AA88 @ =0x03002C30
	movs r0, #0x81
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x82
	lsls r1, r1, #1
	add r1, ip
	ldrb r2, [r1]
	movs r1, #0x20
	subs r1, r1, r2
	movs r2, #0x1f
	ands r1, r2
	adds r0, #0x25
	strb r1, [r0]
	adds r2, r3, #0
_0803AA62:
	ldr r1, _0803AA8C @ =0x03001800
	movs r3, #0x81
	lsls r3, r3, #1
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	adds r0, r0, r2
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r0, #0x24
	strb r1, [r0]
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_0803AA88: .4byte 0x03002C30
_0803AA8C: .4byte 0x03001800
	.syntax divided
