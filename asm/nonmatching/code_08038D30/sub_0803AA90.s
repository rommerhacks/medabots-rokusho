	.syntax unified

	thumb_func_start sub_0803AA90
sub_0803AA90: @ 0x0803AA90
	push {r4, lr}
	bl load_battle_sequence_commands
	ldr r3, _0803AAF8 @ =0x03001800
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0803AAC2
	ldr r0, _0803AAFC @ =0x03002C30
	movs r4, #0x81
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r2, r4, #0
	eors r0, r2
	strh r0, [r1]
_0803AAC2:
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0803AAEC
	ldr r0, _0803AAFC @ =0x03002C30
	movs r4, #0x81
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r2, r3, #0
	eors r0, r2
	strh r0, [r1]
_0803AAEC:
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803AAF8: .4byte 0x03001800
_0803AAFC: .4byte 0x03002C30
	.syntax divided
