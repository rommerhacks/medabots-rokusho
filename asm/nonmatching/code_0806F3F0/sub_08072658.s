	.syntax unified

	thumb_func_start sub_08072658
sub_08072658: @ 0x08072658
	adds r3, r0, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807269E
	adds r1, r3, #0
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _0807268A
	ldr r0, [r3, #0x38]
	ldr r1, [r3, #0x34]
	adds r0, r0, r1
	str r0, [r3, #0x38]
	adds r2, r3, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x5a
	ldrb r0, [r1]
	cmp r0, #0
	beq _08072690
_0807268A:
	subs r0, #1
	strb r0, [r1]
	b _0807269E
_08072690:
	adds r0, r3, #0
	adds r0, #0x57
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r3, #0x34]
	rsbs r0, r0, #0
	str r0, [r3, #0x34]
_0807269E:
	bx lr
	.syntax divided
