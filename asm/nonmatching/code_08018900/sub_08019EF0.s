	.syntax unified

	thumb_func_start sub_08019EF0
	.global sub_08019EF0
sub_08019EF0: @ 0x08019EF0
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r7, #0
	ldr r0, _08019F38 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _08019F08
	ldr r0, _08019F3C @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	bne _08019F44
_08019F08:
	movs r4, #0
	ldr r0, _08019F40 @ =0x03000590
	adds r5, r0, #0
	adds r5, #0x40
_08019F10:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08019F2A
	adds r0, r4, #0
	movs r1, #0
	bl sub_08019FBC
	adds r6, r6, r0
	adds r0, r4, #0
	movs r1, #0
	bl sub_0801A030
	adds r7, r7, r0
_08019F2A:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _08019F10
	b _08019FA2
	.align 2, 0
_08019F38: .4byte 0x03000440
_08019F3C: .4byte 0x03000B90
_08019F40: .4byte 0x03000590
_08019F44:
	movs r4, #3
	ldr r0, _08019FB0 @ =0x03000590
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r5, r0, r1
_08019F4E:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08019F68
	adds r0, r4, #0
	movs r1, #0
	bl sub_08019FBC
	adds r6, r6, r0
	adds r0, r4, #0
	movs r1, #0
	bl sub_0801A030
	adds r7, r7, r0
_08019F68:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _08019F4E
	movs r4, #0
	ldr r0, _08019FB0 @ =0x03000590
	adds r5, r0, #0
	adds r5, #0x40
_08019F7C:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08019F96
	adds r0, r4, #0
	movs r1, #0
	bl sub_08019FBC
	adds r6, r6, r0
	adds r0, r4, #0
	movs r1, #0
	bl sub_0801A030
	adds r7, r7, r0
_08019F96:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, #1
	cmp r4, #2
	bls _08019F7C
_08019FA2:
	cmp r6, #0
	bne _08019FAA
	cmp r7, #0
	beq _08019FB4
_08019FAA:
	movs r0, #1
	b _08019FB6
	.align 2, 0
_08019FB0: .4byte 0x03000590
_08019FB4:
	movs r0, #0
_08019FB6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
