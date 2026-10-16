	.syntax unified

	thumb_func_start sub_0806CD48
sub_0806CD48: @ 0x0806CD48
	ldr r2, _0806CD70 @ =0x03002C30
	ldr r1, _0806CD74 @ =0x0000081A
	adds r0, r2, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _0806CDD8
	ldr r3, _0806CD78 @ =0x000007A1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CD80
	ldr r0, _0806CD7C @ =0x00000806
	adds r1, r2, r0
	movs r0, #8
	strh r0, [r1]
	adds r3, #0x23
	adds r1, r2, r3
	movs r0, #0x12
	b _0806CDDE
	.align 2, 0
_0806CD70: .4byte 0x03002C30
_0806CD74: .4byte 0x0000081A
_0806CD78: .4byte 0x000007A1
_0806CD7C: .4byte 0x00000806
_0806CD80:
	cmp r1, #3
	bgt _0806CD90
	ldr r0, _0806CD8C @ =0x00000806
	adds r1, r2, r0
	movs r0, #8
	b _0806CDDE
	.align 2, 0
_0806CD8C: .4byte 0x00000806
_0806CD90:
	ldr r3, _0806CDA4 @ =0x00000821
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806CDB8
	cmp r0, #1
	bgt _0806CDA8
	cmp r0, #0
	beq _0806CDAE
	b _0806CDE0
	.align 2, 0
_0806CDA4: .4byte 0x00000821
_0806CDA8:
	cmp r0, #2
	beq _0806CDC2
	b _0806CDE0
_0806CDAE:
	movs r3, #0xb
	cmp r1, #7
	bgt _0806CDCA
	movs r3, #0xa
	b _0806CDCA
_0806CDB8:
	movs r3, #8
	cmp r1, #0xe
	bgt _0806CDCA
	movs r3, #9
	b _0806CDCA
_0806CDC2:
	movs r3, #0xd
	cmp r1, #7
	bgt _0806CDCA
	movs r3, #0xc
_0806CDCA:
	ldr r1, _0806CDD4 @ =0x00000806
	adds r0, r2, r1
	strh r3, [r0]
	b _0806CDE0
	.align 2, 0
_0806CDD4: .4byte 0x00000806
_0806CDD8:
	ldr r3, _0806CDE4 @ =0x00000806
	adds r1, r2, r3
	movs r0, #7
_0806CDDE:
	strh r0, [r1]
_0806CDE0:
	bx lr
	.align 2, 0
_0806CDE4: .4byte 0x00000806
	.syntax divided
