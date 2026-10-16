	.syntax unified

	thumb_func_start sub_08061678
sub_08061678: @ 0x08061678
	push {lr}
	ldr r0, _080616A8 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #2]
	ldr r3, _080616AC @ =0x0000FFFF
	adds r1, r0, r3
	strh r1, [r2, #2]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r1, _080616B0 @ =0x03002C30
	movs r0, #0x82
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0x3f
	bhi _080616B8
	adds r0, #4
	strb r0, [r2]
	ldr r0, _080616B4 @ =0x00000209
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	b _080616BE
	.align 2, 0
_080616A8: .4byte 0x03006F74
_080616AC: .4byte 0x0000FFFF
_080616B0: .4byte 0x03002C30
_080616B4: .4byte 0x00000209
_080616B8:
	ldr r0, _080616D4 @ =0x00000209
	adds r1, r1, r0
	movs r0, #0x40
_080616BE:
	strb r0, [r1]
	cmp r3, #0
	beq _080616DC
	ldr r2, _080616D8 @ =0x04000052
	lsls r1, r3, #8
	movs r0, #0x10
	subs r0, r0, r3
	orrs r1, r0
	strh r1, [r2]
	b _080616EC
	.align 2, 0
_080616D4: .4byte 0x00000209
_080616D8: .4byte 0x04000052
_080616DC:
	ldr r1, _080616F0 @ =0x04000052
	movs r0, #0x10
	strh r0, [r1]
	bl sub_0803FB0C
	ldr r1, _080616F4 @ =0x0300137C
	movs r0, #4
	str r0, [r1]
_080616EC:
	pop {r0}
	bx r0
	.align 2, 0
_080616F0: .4byte 0x04000052
_080616F4: .4byte 0x0300137C
	.syntax divided
