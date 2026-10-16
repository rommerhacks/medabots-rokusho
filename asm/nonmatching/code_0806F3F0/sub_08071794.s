	.syntax unified

	thumb_func_start sub_08071794
sub_08071794: @ 0x08071794
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _080717D4 @ =0x080AFF94
	mov r0, sp
	movs r2, #8
	bl memcpy_optimized
	ldr r1, _080717D8 @ =0x03002C30
	lsls r0, r4, #6
	adds r2, r0, r1
	adds r3, r2, #0
	adds r3, #0x21
	ldrb r0, [r3]
	cmp r0, #7
	bhi _080717DC
	ldrh r1, [r2, #0x1a]
	add r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _080717E2
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _080717E2
	.align 2, 0
_080717D4: .4byte 0x080AFF94
_080717D8: .4byte 0x03002C30
_080717DC:
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
_080717E2:
	ldr r0, _0807181C @ =0x03002C30
	lsls r1, r4, #6
	adds r2, r1, r0
	adds r0, r2, #0
	adds r0, #0x21
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #4
	bne _08071808
	adds r1, r2, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _08071808
	adds r1, r0, #0
	movs r0, #1
	movs r2, #0
	bl sub_08071C40
_08071808:
	ldr r0, _0807181C @ =0x03002C30
	adds r2, r4, r0
	movs r1, #2
	ldrsh r0, [r2, r1]
	cmp r0, #0xc9
	beq _08071820
	cmp r0, #0xcf
	ble _08071830
	movs r0, #0xff
	b _08071832
	.align 2, 0
_0807181C: .4byte 0x03002C30
_08071820:
	ldrh r0, [r2]
	ldr r1, _0807183C @ =0x0000F7FF
	ands r1, r0
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r3, #0
	orrs r1, r0
	strh r1, [r2]
_08071830:
	movs r0, #1
_08071832:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807183C: .4byte 0x0000F7FF
	.syntax divided
