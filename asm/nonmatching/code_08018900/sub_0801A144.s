	.syntax unified

	thumb_func_start sub_0801A144
	.global sub_0801A144
sub_0801A144: @ 0x0801A144
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	movs r6, #0
	ldr r0, _0801A188 @ =0x03002C30
	mov r8, r0
	lsls r1, r1, #2
	movs r3, #0
	mov ip, r3
	adds r0, r1, #0
	adds r0, #0x5d
	lsls r0, r0, #6
	mov sb, r0
	movs r5, #0
	adds r1, #0xa
	ldr r7, _0801A18C @ =0x0000C224
	mov sl, r7
	lsls r1, r1, #6
	adds r0, r1, #4
	mov r3, r8
	adds r2, r0, r3
	adds r4, r1, r3
_0801A178:
	ldr r7, [sp]
	adds r1, r7, r6
	ldrb r0, [r1]
	cmp r0, #0xfe
	bne _0801A190
	movs r0, #0xff
	strb r0, [r2, #0x1d]
	b _0801A214
	.align 2, 0
_0801A188: .4byte 0x03002C30
_0801A18C: .4byte 0x0000C224
_0801A190:
	mov r0, sl
	strh r0, [r4]
	mov r3, ip
	strb r3, [r2, #0x18]
	mov r3, sb
	add r3, r8
	ldrh r0, [r3, #4]
	adds r0, #4
	strh r0, [r2]
	movs r0, #0x90
	strb r0, [r2, #7]
	ldrb r0, [r1]
	movs r7, #0x80
	lsls r7, r7, #4
	adds r1, r7, #0
	adds r0, r0, r1
	strh r0, [r2, #2]
	lsls r0, r6, #2
	strb r0, [r2, #0x1c]
	mov r0, ip
	strb r0, [r2, #0x1d]
	movs r0, #0x40
	strb r0, [r2, #5]
	strb r0, [r2, #4]
	ldr r1, [sp]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r2, #6]
	ldrb r0, [r1, #6]
	cmp r0, #2
	beq _0801A1E6
	cmp r0, #2
	bgt _0801A1D8
	cmp r0, #1
	beq _0801A1E2
	b _0801A208
_0801A1D8:
	cmp r0, #3
	beq _0801A1F0
	cmp r0, #4
	beq _0801A1FC
	b _0801A208
_0801A1E2:
	ldrh r0, [r3, #2]
	b _0801A204
_0801A1E6:
	ldr r7, _0801A1EC @ =0x0000FFFC
	b _0801A1FE
	.align 2, 0
_0801A1EC: .4byte 0x0000FFFC
_0801A1F0:
	ldr r1, _0801A1F8 @ =0x0000FFF8
	adds r0, r1, #0
	b _0801A200
	.align 2, 0
_0801A1F8: .4byte 0x0000FFF8
_0801A1FC:
	ldr r7, _0801A224 @ =0x0000FFF4
_0801A1FE:
	adds r0, r7, #0
_0801A200:
	ldrh r3, [r3, #2]
	adds r0, r0, r3
_0801A204:
	adds r0, r0, r5
	strh r0, [r4, #2]
_0801A208:
	adds r5, #8
	adds r2, #0x40
	adds r4, #0x40
	adds r6, #1
	cmp r6, #2
	bls _0801A178
_0801A214:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A224: .4byte 0x0000FFF4
	.syntax divided
