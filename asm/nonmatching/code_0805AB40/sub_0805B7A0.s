	.syntax unified

	thumb_func_start sub_0805B7A0
	.global sub_0805B7A0
sub_0805B7A0: @ 0x0805B7A0
	push {r4, r5, r6, lr}
	ldr r6, _0805B7D8 @ =0x03006F74
	ldr r3, [r6]
	ldrb r5, [r3, #0x17]
	lsls r2, r5, #2
	ldr r0, _0805B7DC @ =0x030057E0
	ldr r1, _0805B7E0 @ =0x00000C32
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrb r0, [r3, #0x18]
	ldr r4, _0805B7E4 @ =0x080AF5FC
	cmp r0, #0
	beq _0805B7C4
	ldr r4, _0805B7E8 @ =0x080AF674
_0805B7C4:
	ldr r0, _0805B7EC @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0805B7F0
	adds r0, r4, r2
	ldrb r0, [r0]
	b _0805B818
	.align 2, 0
_0805B7D8: .4byte 0x03006F74
_0805B7DC: .4byte 0x030057E0
_0805B7E0: .4byte 0x00000C32
_0805B7E4: .4byte 0x080AF5FC
_0805B7E8: .4byte 0x080AF674
_0805B7EC: .4byte 0x0300058C
_0805B7F0:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805B7FE
	adds r0, r2, r4
	ldrb r0, [r0, #1]
	b _0805B818
_0805B7FE:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0805B80C
	adds r0, r2, r4
	ldrb r0, [r0, #2]
	b _0805B818
_0805B80C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805B830
	adds r0, r2, r4
	ldrb r0, [r0, #3]
_0805B818:
	strb r0, [r3, #0x17]
	ldr r0, [r6]
	movs r1, #6
	ldrb r0, [r0, #0x17]
	cmp r5, r0
	beq _0805B826
	movs r1, #2
_0805B826:
	adds r0, r1, #0
	bl play_sound_effect
	movs r0, #1
	b _0805B832
_0805B830:
	movs r0, #0
_0805B832:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
