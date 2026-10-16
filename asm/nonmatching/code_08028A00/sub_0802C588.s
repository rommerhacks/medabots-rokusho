	.syntax unified

	thumb_func_start sub_0802C588
sub_0802C588: @ 0x0802C588
	push {r4, r5, r6, r7, lr}
	ldr r5, _0802C624 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r5, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r4, #0
	adds r7, r5, #0
	adds r7, #0xec
_0802C5A2:
	adds r6, r5, #0
	adds r6, #0xd2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C5C8
	adds r0, r5, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r4
	lsls r0, r0, #8
	ldr r1, _0802C628 @ =0x03000648
	adds r0, r0, r1
	adds r0, #1
	movs r2, #0
	ldrsh r1, [r7, r2]
	movs r2, #0x78
	bl sub_08035740
_0802C5C8:
	adds r4, #1
	cmp r4, #2
	bls _0802C5A2
	adds r5, r6, #0
	subs r5, #0xd2
	adds r0, r6, #0
	subs r0, #0x4b
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r6, #0
	subs r1, #0x72
	strb r0, [r1]
	movs r4, #0
	adds r7, r6, #0
	adds r7, #0x1a
_0802C5E8:
	lsls r0, r4, #1
	adds r6, r5, #0
	adds r6, #0xd6
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802C60E
	adds r0, r5, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r4
	lsls r0, r0, #8
	ldr r1, _0802C628 @ =0x03000648
	adds r0, r0, r1
	adds r0, #1
	movs r2, #0
	ldrsh r1, [r7, r2]
	bl sub_0803572C
_0802C60E:
	adds r4, #1
	cmp r4, #2
	bls _0802C5E8
	adds r1, r6, #0
	subs r1, #0x2c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C624: .4byte 0x03001800
_0802C628: .4byte 0x03000648
_0802C62C:
	.byte 0x04, 0x49, 0x0A, 0x1C
	.byte 0xA6, 0x32, 0x5C, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
