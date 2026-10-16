	.syntax unified

	thumb_func_start sub_08036D64
	.global sub_08036D64
sub_08036D64: @ 0x08036D64
	adds r2, r0, #0
	adds r0, r1, #0
	subs r0, #0xd
	cmp r0, #1
	bhi _08036D88
	ldr r1, _08036D84 @ =0x03000590
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r0, #1
_08036D7A:
	ands r0, r1
	cmp r0, #0
	bne _08036DDA
	b _08036DE4
	.align 2, 0
_08036D84: .4byte 0x03000590
_08036D88:
	adds r0, r1, #0
	subs r0, #0xf
	cmp r0, #1
	bhi _08036DA4
	ldr r1, _08036DA0 @ =0x03000590
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r0, #8
	b _08036D7A
	.align 2, 0
_08036DA0: .4byte 0x03000590
_08036DA4:
	adds r0, r1, #0
	subs r0, #0x11
	cmp r0, #1
	bhi _08036DC0
	ldr r1, _08036DBC @ =0x03000590
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r0, #2
	b _08036D7A
	.align 2, 0
_08036DBC: .4byte 0x03000590
_08036DC0:
	adds r0, r1, #0
	subs r0, #0x13
	cmp r0, #1
	bhi _08036DE4
	ldr r1, _08036DE0 @ =0x03000590
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0xcf
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08036DE4
_08036DDA:
	movs r0, #1
	b _08036DE6
	.align 2, 0
_08036DE0: .4byte 0x03000590
_08036DE4:
	movs r0, #0
_08036DE6:
	bx lr
	.syntax divided
