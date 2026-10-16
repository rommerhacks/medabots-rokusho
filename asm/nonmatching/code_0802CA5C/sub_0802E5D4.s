	.syntax unified

	thumb_func_start sub_0802E5D4
sub_0802E5D4: @ 0x0802E5D4
	push {r4, r5, r6, lr}
	movs r3, #0
	movs r2, #0
	ldr r5, _0802E5FC @ =0x03001800
	adds r4, r5, #0
	adds r4, #0xd2
	ldr r0, _0802E600 @ =0x03002C30
	movs r6, #0xa0
	lsls r6, r6, #2
	adds r1, r0, r6
_0802E5E8:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E60E
	ldrb r0, [r1, #8]
	cmp r0, #0x40
	bne _0802E604
	movs r3, #1
	b _0802E60E
	.align 2, 0
_0802E5FC: .4byte 0x03001800
_0802E600: .4byte 0x03002C30
_0802E604:
	adds r0, #4
	strb r0, [r1, #8]
	ldrb r0, [r1, #9]
	adds r0, #4
	strb r0, [r1, #9]
_0802E60E:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #2
	bls _0802E5E8
	cmp r3, #0
	beq _0802E62C
	ldr r0, _0802E634 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802E62C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E634: .4byte 0x03000440
	.syntax divided
