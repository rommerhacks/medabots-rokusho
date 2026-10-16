	.syntax unified

	thumb_func_start sub_0804070C
sub_0804070C: @ 0x0804070C
	push {lr}
	ldr r2, _08040764 @ =0x03000440
	ldrb r0, [r2, #0x1a]
	adds r1, r0, #0
	cmp r1, #0
	bne _08040770
	ldrb r1, [r2, #0x14]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _0804074A
	ldrb r0, [r2, #0x14]
	adds r1, r0, #0
	adds r1, #8
	asrs r1, r1, #3
	subs r1, #1
	lsls r1, r1, #0x18
	ldr r0, _08040768 @ =0x02020000
	lsrs r1, r1, #0x12
	ldrb r3, [r2, #0x17]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r3
	lsls r2, r2, #7
	ldr r3, _0804076C @ =0x06000280
	adds r2, r2, r3
	adds r1, r1, r2
	movs r2, #0x10
	bl CpuFastSet
_0804074A:
	ldr r2, _08040764 @ =0x03000440
	ldrh r3, [r2, #0xc]
	ldrh r0, [r2, #0xc]
	ldr r1, [r2, #8]
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	strb r0, [r2, #0x1a]
	ldrb r0, [r2, #0x1a]
	cmp r0, #0xff
	bne _0804079C
	adds r0, r3, #2
	b _0804079A
	.align 2, 0
_08040764: .4byte 0x03000440
_08040768: .4byte 0x02020000
_0804076C: .4byte 0x06000280
_08040770:
	cmp r1, #0xff
	beq _08040796
	subs r0, #1
	strb r0, [r2, #0x1a]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040796
	adds r0, r2, #0
	adds r0, #0x89
	ldrb r3, [r0]
	cmp r3, #0
	bne _0804079C
	ldr r0, _080407A0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804079C
	strb r3, [r2, #0x1a]
_08040796:
	ldrh r0, [r2, #0xc]
	adds r0, #2
_0804079A:
	strh r0, [r2, #0xc]
_0804079C:
	pop {r0}
	bx r0
	.align 2, 0
_080407A0: .4byte 0x03001798
	.syntax divided
