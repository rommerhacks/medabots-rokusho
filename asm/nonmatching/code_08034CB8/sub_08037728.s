	.syntax unified

	thumb_func_start sub_08037728
	.global sub_08037728
sub_08037728: @ 0x08037728
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r2, _08037754 @ =0x03000590
	lsls r4, r6, #1
	adds r1, r4, r6
	lsls r1, r1, #3
	lsls r3, r3, #8
	adds r1, r1, r3
	adds r1, r1, r2
	adds r1, #0x59
	ldrb r5, [r1]
	cmp r5, #0
	bne _0803775C
	ldr r1, _08037758 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xd6
	adds r2, r4, r2
	movs r3, #0
	strh r5, [r2]
	b _0803776E
	.align 2, 0
_08037754: .4byte 0x03000590
_08037758: .4byte 0x03001800
_0803775C:
	ldrb r3, [r1]
	cmp r3, r7
	bls _0803777C
	ldr r1, _08037778 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xd6
	adds r2, r4, r2
	movs r3, #0
	strh r7, [r2]
_0803776E:
	adds r1, #0xd2
	adds r1, r6, r1
	strb r3, [r1]
	b _0803778E
	.align 2, 0
_08037778: .4byte 0x03001800
_0803777C:
	ldr r1, _08037794 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xd6
	adds r2, r4, r2
	strh r3, [r2]
	adds r1, #0xd2
	adds r1, r6, r1
	movs r2, #1
	strb r2, [r1]
_0803778E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08037794: .4byte 0x03001800
	.syntax divided
