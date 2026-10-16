	.syntax unified

	thumb_func_start sub_0806CE58
sub_0806CE58: @ 0x0806CE58
	push {r4, lr}
	sub sp, #0x20
	ldr r0, _0806CEC0 @ =0x03002C30
	adds r1, r0, #0
	adds r1, #0x20
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #1
	beq _0806CE6C
	b _0806CF6C
_0806CE6C:
	ldrh r1, [r4, #0x1a]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0806CF32
	movs r0, #0x20
	ands r1, r0
	cmp r1, #0
	beq _0806CEE8
	ldr r0, _0806CEC4 @ =0x040000D4
	ldr r1, _0806CEC8 @ =0x05000380
	str r1, [r0]
	mov r1, sp
	str r1, [r0, #4]
	ldr r1, _0806CECC @ =0x80000010
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	adds r1, #2
	str r1, [r0]
	ldr r1, _0806CED0 @ =0x05000384
	str r1, [r0, #4]
	ldr r1, _0806CED4 @ =0x8000000B
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	add r1, sp, #8
	str r1, [r0]
	ldr r1, _0806CED8 @ =0x05000382
	str r1, [r0, #4]
	ldr r2, _0806CEDC @ =0x80000001
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	add r1, sp, #0x10
	str r1, [r0]
	ldr r1, _0806CEE0 @ =0x0500038A
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	add r1, sp, #0x18
	str r1, [r0]
	ldr r1, _0806CEE4 @ =0x05000392
	b _0806CF2C
	.align 2, 0
_0806CEC0: .4byte 0x03002C30
_0806CEC4: .4byte 0x040000D4
_0806CEC8: .4byte 0x05000380
_0806CECC: .4byte 0x80000010
_0806CED0: .4byte 0x05000384
_0806CED4: .4byte 0x8000000B
_0806CED8: .4byte 0x05000382
_0806CEDC: .4byte 0x80000001
_0806CEE0: .4byte 0x0500038A
_0806CEE4: .4byte 0x05000392
_0806CEE8:
	ldr r0, _0806CF74 @ =0x040000D4
	ldr r1, _0806CF78 @ =0x05000380
	str r1, [r0]
	mov r2, sp
	str r2, [r0, #4]
	ldr r1, _0806CF7C @ =0x80000010
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	add r1, sp, #4
	str r1, [r0]
	ldr r1, _0806CF80 @ =0x05000382
	str r1, [r0, #4]
	ldr r1, _0806CF84 @ =0x8000000B
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	adds r1, #2
	str r1, [r0]
	ldr r1, _0806CF88 @ =0x05000388
	str r1, [r0, #4]
	ldr r2, _0806CF8C @ =0x80000001
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	adds r1, #0xa
	str r1, [r0]
	ldr r1, _0806CF90 @ =0x05000390
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	adds r1, #0x12
	str r1, [r0]
	ldr r1, _0806CF94 @ =0x05000398
_0806CF2C:
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
_0806CF32:
	adds r3, r4, #0
	ldrh r2, [r3, #0x1a]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0806CF58
	ldr r1, _0806CF98 @ =0x08485E84
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x1a
	movs r1, #0x80
	subs r1, r1, r0
	ldr r2, _0806CF9C @ =0x00000784
	adds r0, r3, r2
	strh r1, [r0]
_0806CF58:
	ldrh r1, [r3, #0x1a]
	movs r0, #8
	ands r0, r1
	movs r1, #0xf
	cmp r0, #0
	beq _0806CF66
	movs r1, #0xe
_0806CF66:
	ldr r2, _0806CFA0 @ =0x00000806
	adds r0, r4, r2
	strh r1, [r0]
_0806CF6C:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806CF74: .4byte 0x040000D4
_0806CF78: .4byte 0x05000380
_0806CF7C: .4byte 0x80000010
_0806CF80: .4byte 0x05000382
_0806CF84: .4byte 0x8000000B
_0806CF88: .4byte 0x05000388
_0806CF8C: .4byte 0x80000001
_0806CF90: .4byte 0x05000390
_0806CF94: .4byte 0x05000398
_0806CF98: .4byte 0x08485E84
_0806CF9C: .4byte 0x00000784
_0806CFA0: .4byte 0x00000806
	.syntax divided
