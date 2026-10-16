	.syntax unified

	thumb_func_start sub_0802EBE8
sub_0802EBE8: @ 0x0802EBE8
	push {r4, r5, r6, r7, lr}
	bl sub_0803836C
	ldr r4, _0802EC44 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	ldr r6, _0802EC48 @ =0x03000590
	adds r7, r4, #0
	adds r5, r7, #0
	adds r5, #0xd2
	adds r4, r1, #0
	movs r1, #1
_0802EC0E:
	ldrb r0, [r4]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r2, r0, r6
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EC2E
	adds r0, r2, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EC2E
	adds r0, r3, r5
	strb r1, [r0]
_0802EC2E:
	adds r3, #1
	cmp r3, #2
	bls _0802EC0E
	adds r1, r7, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EC44: .4byte 0x03001800
_0802EC48: .4byte 0x03000590
	.syntax divided
