	.syntax unified

	thumb_func_start sub_0800994C
	.global sub_0800994C
sub_0800994C: @ 0x0800994C
	push {r4, lr}
	ldr r0, _08009974 @ =0x03001780
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08009980
	ldr r2, _08009978 @ =0x03002C30
	adds r4, r2, #0
	adds r4, #0x40
	ldrh r3, [r4]
	ldr r1, _0800997C @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r3
	strh r0, [r4]
	adds r2, #0x80
	ldrh r0, [r2]
	ands r1, r0
	b _08009998
	.align 2, 0
_08009974: .4byte 0x03001780
_08009978: .4byte 0x03002C30
_0800997C: .4byte 0x0000BFFF
_08009980:
	ldr r2, _080099A0 @ =0x03002C30
	adds r3, r2, #0
	adds r3, #0x40
	ldrh r0, [r3]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r3]
	adds r2, #0x80
	ldrh r0, [r2]
	orrs r1, r0
_08009998:
	strh r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080099A0: .4byte 0x03002C30
	.syntax divided
