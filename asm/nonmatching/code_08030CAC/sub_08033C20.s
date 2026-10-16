	.syntax unified

	thumb_func_start sub_08033C20
sub_08033C20: @ 0x08033C20
	push {r4, r5, r6, lr}
	ldr r1, _08033CC8 @ =0x03000590
	ldr r2, _08033CCC @ =0x03001800
	adds r4, r2, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r5, r1, #0
	adds r6, r2, #0
	cmp r0, #0x2e
	bne _08033C4A
	adds r2, r3, #0
	adds r2, #0xbc
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
_08033C4A:
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r2, r0, r5
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2f
	bne _08033C64
	adds r2, #0xbc
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_08033C64:
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0xc9
	ldrb r1, [r1]
	cmp r1, #0xf
	beq _08033C78
	cmp r1, #0x10
	bne _08033C84
_08033C78:
	adds r2, r0, #0
	adds r2, #0xbc
	ldrb r1, [r2]
	movs r0, #0xc
	orrs r0, r1
	strb r0, [r2]
_08033C84:
	adds r2, r6, #0
	adds r2, #0x88
	ldrb r0, [r2]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r3, r0, #0
	adds r3, #0xbc
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08033CA2
	movs r0, #4
	orrs r0, r1
	strb r0, [r3]
_08033CA2:
	ldrb r0, [r2]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0xbc
	ldrb r3, [r1]
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _08033CBC
	movs r0, #8
	orrs r0, r3
	strb r0, [r1]
_08033CBC:
	bl sub_08034F08
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033CC8: .4byte 0x03000590
_08033CCC: .4byte 0x03001800
	.syntax divided
