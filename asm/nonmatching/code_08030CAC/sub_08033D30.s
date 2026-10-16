	.syntax unified

	thumb_func_start sub_08033D30
sub_08033D30: @ 0x08033D30
	push {r4, r5, r6, r7, lr}
	ldr r4, _08033EFC @ =0x03001800
	adds r6, r4, #0
	adds r6, #0xec
	movs r0, #0
	strh r0, [r6]
	ldr r3, _08033F00 @ =0x03000590
	adds r5, r4, #0
	adds r5, #0xa7
	ldrb r0, [r5]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r0, #0x87
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r3
	adds r1, #0x4e
	adds r0, r4, #0
	adds r0, #0xea
	ldrh r2, [r0]
	ldrb r1, [r1]
	adds r2, r2, r1
	strh r2, [r6]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	adds r0, r0, r3
	adds r0, #0xd0
	ldrb r0, [r0]
	adds r2, r2, r0
	strh r2, [r6]
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov r5, ip
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r0, #0x4a
	ldrb r0, [r0]
	adds r5, r3, #0
	cmp r0, #0
	beq _08033D96
	cmp r0, #1
	bne _08033DA0
_08033D96:
	adds r0, r1, r5
	adds r0, #0xd3
	ldrb r0, [r0]
	adds r0, r2, r0
	strh r0, [r6]
_08033DA0:
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r5
	adds r1, #0x4a
	ldrb r1, [r1]
	cmp r1, #2
	beq _08033DC4
	cmp r1, #3
	bne _08033DD4
_08033DC4:
	adds r2, r4, #0
	adds r2, #0xec
	adds r1, r0, r5
	adds r1, #0xd4
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
_08033DD4:
	adds r3, r4, #0
	adds r3, #0xa7
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r4, #0
	adds r2, #0x87
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #1
	bne _08033E06
	adds r0, r4, #0
	adds r0, #0xec
	adds r1, r1, r5
	adds r1, #0xa2
	ldrb r1, [r1]
	lsrs r1, r1, #1
	ldrh r6, [r0]
	adds r1, r1, r6
	strh r1, [r0]
_08033E06:
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldrb r0, [r2]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r5
	adds r0, r1, #0
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #4
	beq _08033E24
	cmp r0, #5
	bne _08033E32
_08033E24:
	adds r2, r4, #0
	adds r2, #0xec
	adds r1, #0x4e
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
_08033E32:
	adds r6, r5, #0
	adds r7, r4, #0
	adds r7, #0x87
	ldrb r0, [r7]
	lsls r3, r0, #8
	adds r0, r3, r6
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08033E68
	adds r2, r4, #0
	adds r2, #0xec
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, r0, r6
	adds r0, #0x4e
	ldrh r1, [r2]
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r2]
_08033E68:
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r7]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x34
	bne _08033EA6
	adds r0, r4, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, r0, r4
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0x33
	bne _08033EA6
	adds r2, r4, #0
	adds r2, #0xec
	adds r1, #0x2d
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
_08033EA6:
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08035B9C
	adds r7, r4, #0
	adds r7, #0xec
	ldr r6, _08033F00 @ =0x03000590
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xd1
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_08035754
	adds r0, r4, #0
	adds r0, #0xde
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033EF0
	adds r0, r4, #0
	adds r0, #0xdf
	ldrb r0, [r0]
	cmp r0, #0x1b
	bne _08033EF0
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xd8
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl sub_08035754
_08033EF0:
	bl sub_08034F08
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033EFC: .4byte 0x03001800
_08033F00: .4byte 0x03000590
	.syntax divided
