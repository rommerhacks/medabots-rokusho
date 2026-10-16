	.syntax unified

	thumb_func_start sub_0801EC3C
sub_0801EC3C: @ 0x0801EC3C
	push {r4, lr}
	ldr r4, _0801EC7C @ =0x03000590
	ldr r2, _0801EC80 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r2, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r3, r0, r4
	adds r0, r3, #0
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x30
	bne _0801EC84
	adds r1, r2, #0
	adds r1, #0xec
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0801ECAE
	subs r1, #0x42
	movs r0, #0x20
	b _0801ECB6
	.align 2, 0
_0801EC7C: .4byte 0x03000590
_0801EC80: .4byte 0x03001800
_0801EC84:
	adds r0, r1, r4
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801EC9C
	adds r0, r3, #0
	adds r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801ECAE
_0801EC9C:
	adds r0, r2, #0
	adds r0, #0xca
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801ECAE
	adds r1, r2, #0
	adds r1, #0xaa
	movs r0, #0x20
	b _0801ECB6
_0801ECAE:
	adds r1, r2, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801ECB6:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
