	.syntax unified

	thumb_func_start sub_080023D8
sub_080023D8: @ 0x080023D8
	ldr r3, _08002428 @ =0x03005170
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _08002424
	ldrb r0, [r3, #6]
	cmp r0, #0
	beq _08002424
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r3, #0x18]
	ldr r1, [r3, #0x28]
	ldr r0, [r3, #0x24]
	str r0, [r3, #0x28]
	str r1, [r3, #0x24]
	ldrb r0, [r3, #4]
	cmp r0, #0
	beq _08002408
	ldr r1, [r3, #0x20]
	ldr r0, [r3, #0x1c]
	str r0, [r3, #0x20]
	str r1, [r3, #0x1c]
	movs r0, #0
	strb r0, [r3, #4]
	str r0, [r3, #0x14]
_08002408:
	ldr r2, _0800242C @ =0x04000128
	ldr r0, [r2]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1f
	strb r0, [r3, #7]
	ldr r0, _08002430 @ =0x0000FEFE
	strh r0, [r2, #2]
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08002434 @ =0x0400010E
	movs r0, #0xc0
	strh r0, [r1]
_08002424:
	bx lr
	.align 2, 0
_08002428: .4byte 0x03005170
_0800242C: .4byte 0x04000128
_08002430: .4byte 0x0000FEFE
_08002434: .4byte 0x0400010E
	.syntax divided
