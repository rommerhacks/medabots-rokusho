	.syntax unified

	thumb_func_start sub_080366DC
	.global sub_080366DC
sub_080366DC: @ 0x080366DC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r3, r1, #0
	ldr r2, _08036704 @ =0x03002C30
	lsls r0, r7, #6
	adds r4, r0, r2
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	mov ip, r2
	cmp r0, #0
	beq _08036700
	adds r1, r4, #0
	adds r1, #0x23
	ldrb r0, [r1]
	cmp r0, #0x10
	bne _08036708
_08036700:
	movs r0, #1
	b _08036774
	.align 2, 0
_08036704: .4byte 0x03002C30
_08036708:
	cmp r3, #1
	beq _08036724
	cmp r3, #1
	blo _0803671A
	cmp r3, #2
	beq _0803672C
	cmp r3, #3
	beq _08036734
	b _08036748
_0803671A:
	ldr r0, _08036720 @ =0x083AF380
	b _08036736
	.align 2, 0
_08036720: .4byte 0x083AF380
_08036724:
	ldr r0, _08036728 @ =0x083AF3C0
	b _08036736
	.align 2, 0
_08036728: .4byte 0x083AF3C0
_0803672C:
	ldr r0, _08036730 @ =0x083AF400
	b _08036736
	.align 2, 0
_08036730: .4byte 0x083AF400
_08036734:
	ldr r0, _0803677C @ =0x083AF440
_08036736:
	ldrb r1, [r1]
	lsls r2, r1, #1
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r6, [r1]
	adds r2, #1
	lsls r2, r2, #1
	adds r2, r2, r0
	ldrh r5, [r2]
_08036748:
	lsls r2, r7, #6
	add r2, ip
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	ldr r3, _08036780 @ =0x000001FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2, #2]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r2, #4]
	adds r2, #0x23
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r0, #0
_08036774:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803677C: .4byte 0x083AF440
_08036780: .4byte 0x000001FF
	.syntax divided
