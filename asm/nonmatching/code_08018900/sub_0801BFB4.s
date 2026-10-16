	.syntax unified

	thumb_func_start sub_0801BFB4
	.global sub_0801BFB4
sub_0801BFB4: @ 0x0801BFB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _0801BFF8 @ =0x03000440
	lsls r1, r1, #3
	adds r1, r1, r0
	adds r2, r1, #0
	adds r2, #0x66
	ldrb r0, [r2]
	cmp r0, #0xff
	beq _0801C08A
	mov r8, r1
	str r2, [sp]
	movs r0, #0x64
	add r0, r8
	mov sb, r0
	mov r6, r8
	adds r5, r6, #0
	adds r5, #0x65
	movs r1, #0x67
	adds r1, r1, r6
	mov sl, r1
_0801BFE8:
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	beq _0801BFFC
	subs r0, #1
	strb r0, [r3]
	b _0801C08A
	.align 2, 0
_0801BFF8: .4byte 0x03000440
_0801BFFC:
	mov r4, r8
	adds r4, #0x65
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrb r1, [r0]
	cmp r1, #0xfe
	beq _0801C02A
	cmp r1, #0xfe
	bgt _0801C016
	cmp r1, #0xfd
	beq _0801C01C
	b _0801C03A
_0801C016:
	cmp r1, #0xff
	beq _0801C032
	b _0801C03A
_0801C01C:
	ldrh r0, [r0, #2]
	bl play_sound_effect
	ldrb r0, [r4]
	adds r0, #2
	strb r0, [r4]
	b _0801C084
_0801C02A:
	ldrh r0, [r0, #2]
	lsls r0, r0, #1
	strb r0, [r4]
	b _0801C084
_0801C032:
	movs r0, #0xff
	ldr r1, [sp]
	strb r0, [r1]
	b _0801C08A
_0801C03A:
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strb r1, [r0]
	adds r0, #4
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x6a
	ldrh r2, [r1]
	ldrb r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r1, [r1, #2]
	lsls r1, r1, #5
	muls r1, r2, r1
	movs r3, #0x80
	lsls r3, r3, #0x12
	adds r1, r1, r3
	adds r0, r0, r1
	mov r3, sl
	ldrb r1, [r3]
	lsls r1, r1, #5
	ldr r3, _0801C09C @ =0x06010000
	adds r1, r1, r3
	lsls r2, r2, #3
	movs r3, #0x80
	lsls r3, r3, #0x13
	orrs r2, r3
	bl CpuSet
	ldrb r0, [r5]
	adds r0, #2
	strb r0, [r5]
_0801C084:
	movs r0, #1
	cmp r0, #0
	bne _0801BFE8
_0801C08A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C09C: .4byte 0x06010000
_0801C0A0:
	.byte 0x04, 0x49, 0x00, 0x02, 0x40, 0x18, 0x04, 0x4A, 0xE0, 0x30, 0x01, 0x78, 0x89, 0x18, 0x09, 0x78
	.byte 0x01, 0x70, 0x70, 0x47, 0x90, 0x05, 0x00, 0x03, 0xF9, 0xD3, 0x3A, 0x08
	.syntax divided
