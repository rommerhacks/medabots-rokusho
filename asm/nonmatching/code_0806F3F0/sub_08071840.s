	.syntax unified

	thumb_func_start sub_08071840
sub_08071840: @ 0x08071840
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _08071880 @ =0x080AFF94
	mov r0, sp
	movs r2, #8
	bl memcpy_optimized
	ldr r1, _08071884 @ =0x03002C30
	lsls r0, r4, #6
	adds r2, r0, r1
	adds r3, r2, #0
	adds r3, #0x21
	ldrb r0, [r3]
	cmp r0, #7
	bhi _08071888
	ldrh r1, [r2, #0x1a]
	add r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0807188E
	ldrh r0, [r2, #2]
	subs r0, #1
	strh r0, [r2, #2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _0807188E
	.align 2, 0
_08071880: .4byte 0x080AFF94
_08071884: .4byte 0x03002C30
_08071888:
	ldrh r0, [r2, #2]
	subs r0, #1
	strh r0, [r2, #2]
_0807188E:
	ldr r0, _080718C8 @ =0x03002C30
	lsls r1, r4, #6
	adds r2, r1, r0
	adds r0, r2, #0
	adds r0, #0x21
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #4
	bne _080718B4
	adds r1, r2, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _080718B4
	adds r1, r0, #0
	movs r0, #2
	movs r2, #0
	bl sub_08071C40
_080718B4:
	ldr r0, _080718C8 @ =0x03002C30
	adds r2, r4, r0
	movs r1, #2
	ldrsh r0, [r2, r1]
	cmp r0, #0x1f
	beq _080718CC
	cmp r0, #0x18
	bgt _080718DC
	movs r0, #0xff
	b _080718DE
	.align 2, 0
_080718C8: .4byte 0x03002C30
_080718CC:
	ldrh r0, [r2]
	ldr r1, _080718E8 @ =0x0000F7FF
	ands r1, r0
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r3, #0
	orrs r1, r0
	strh r1, [r2]
_080718DC:
	movs r0, #1
_080718DE:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080718E8: .4byte 0x0000F7FF
	.syntax divided
