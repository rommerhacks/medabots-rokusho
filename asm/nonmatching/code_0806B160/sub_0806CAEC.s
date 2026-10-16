	.syntax unified

	thumb_func_start sub_0806CAEC
sub_0806CAEC: @ 0x0806CAEC
	ldr r2, _0806CB10 @ =0x03002C30
	movs r1, #0x9c
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CBB0
	ldr r3, _0806CB14 @ =0x000004E1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806CB54
	cmp r0, #1
	bgt _0806CB18
	cmp r0, #0
	beq _0806CB1E
	b _0806CBC8
	.align 2, 0
_0806CB10: .4byte 0x03002C30
_0806CB14: .4byte 0x000004E1
_0806CB18:
	cmp r0, #2
	beq _0806CB78
	b _0806CBC8
_0806CB1E:
	ldr r1, _0806CB48 @ =0x000004DA
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	movs r1, #0x1b
	cmp r0, #0
	beq _0806CB30
	movs r1, #0x1a
_0806CB30:
	ldr r3, _0806CB4C @ =0x00000446
	adds r0, r2, r3
	strh r1, [r0]
	ldr r0, _0806CB50 @ =0x00000486
	adds r1, r2, r0
	movs r0, #0x1c
	strh r0, [r1]
	subs r3, #0x40
	adds r1, r2, r3
	movs r0, #0x1f
	b _0806CBC6
	.align 2, 0
_0806CB48: .4byte 0x000004DA
_0806CB4C: .4byte 0x00000446
_0806CB50: .4byte 0x00000486
_0806CB54:
	ldr r0, _0806CB6C @ =0x00000446
	adds r1, r2, r0
	movs r0, #0x1a
	strh r0, [r1]
	ldr r3, _0806CB70 @ =0x00000486
	adds r1, r2, r3
	movs r0, #0x1c
	strh r0, [r1]
	ldr r0, _0806CB74 @ =0x00000406
	adds r1, r2, r0
	b _0806CBC4
	.align 2, 0
_0806CB6C: .4byte 0x00000446
_0806CB70: .4byte 0x00000486
_0806CB74: .4byte 0x00000406
_0806CB78:
	ldr r3, _0806CBA0 @ =0x00000446
	adds r1, r2, r3
	movs r0, #0x1a
	strh r0, [r1]
	ldr r1, _0806CBA4 @ =0x000004DA
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	movs r1, #0x1d
	cmp r0, #0
	beq _0806CB92
	movs r1, #0x1c
_0806CB92:
	ldr r3, _0806CBA8 @ =0x00000486
	adds r0, r2, r3
	strh r1, [r0]
	ldr r0, _0806CBAC @ =0x00000406
	adds r1, r2, r0
	movs r0, #0x20
	b _0806CBC6
	.align 2, 0
_0806CBA0: .4byte 0x00000446
_0806CBA4: .4byte 0x000004DA
_0806CBA8: .4byte 0x00000486
_0806CBAC: .4byte 0x00000406
_0806CBB0:
	ldr r3, _0806CBCC @ =0x00000446
	adds r1, r2, r3
	movs r0, #0x1a
	strh r0, [r1]
	ldr r0, _0806CBD0 @ =0x00000486
	adds r1, r2, r0
	movs r0, #0x1c
	strh r0, [r1]
	subs r3, #0x40
	adds r1, r2, r3
_0806CBC4:
	movs r0, #0x1e
_0806CBC6:
	strh r0, [r1]
_0806CBC8:
	bx lr
	.align 2, 0
_0806CBCC: .4byte 0x00000446
_0806CBD0: .4byte 0x00000486
	.syntax divided
