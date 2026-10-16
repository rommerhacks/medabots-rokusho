	.syntax unified

	thumb_func_start sub_08024D18
sub_08024D18: @ 0x08024D18
	push {r4, r5, r6, lr}
	ldr r6, _08024D74 @ =0x03000590
	ldr r4, _08024D78 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xc9
	movs r1, #0x2b
	strb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r6
	adds r1, #0xcb
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xec
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r6
	adds r1, #0xcc
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #1
	beq _08024D7C
	cmp r0, #2
	beq _08024D88
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xca
	movs r1, #1
	b _08024D92
	.align 2, 0
_08024D74: .4byte 0x03000590
_08024D78: .4byte 0x03001800
_08024D7C:
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xca
	movs r1, #2
	b _08024D92
_08024D88:
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xca
	movs r1, #3
_08024D92:
	strb r1, [r0]
	ldr r1, _08024DA4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08024DA4: .4byte 0x03001800
	.syntax divided
