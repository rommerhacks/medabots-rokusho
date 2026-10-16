	.syntax unified

	thumb_func_start sub_080297EC
sub_080297EC: @ 0x080297EC
	push {r4, r5, r6, r7, lr}
	movs r4, #0
	ldr r5, _08029824 @ =0x03001800
	adds r7, r5, #0
	adds r7, #0x60
_080297F6:
	adds r6, r5, #0
	adds r6, #0xd2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802980C
	ldrb r0, [r7]
	adds r0, r0, r4
	movs r1, #1
	bl sub_08038394
_0802980C:
	adds r4, #1
	cmp r4, #2
	bls _080297F6
	adds r1, r6, #0
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029824: .4byte 0x03001800
_08029828:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x53, 0x20
	.byte 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
