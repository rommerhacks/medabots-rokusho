	.syntax unified

	thumb_func_start sub_0803E680
sub_0803E680: @ 0x0803E680
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0803E748 @ =0x03005010
	mov r8, r0
	ldr r0, _0803E74C @ =0x03002B70
	ldr r3, _0803E750 @ =0x03001800
	adds r4, r3, #0
	adds r4, #0x51
	adds r0, #4
	ldrb r1, [r4]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r5, _0803E754 @ =0x000001AF
	adds r5, r5, r3
	mov ip, r5
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r7, r1, #0
	ands r0, r7
	ldr r5, _0803E758 @ =0xFFFF8000
	adds r1, r5, #0
	adds r0, r0, r1
	adds r2, r2, r0
	mov r0, r8
	strh r2, [r0, #6]
	ldr r0, _0803E75C @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x86
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803E6DE
	mov r1, ip
	ldrb r0, [r1]
	movs r1, #1
	eors r0, r1
	mov r2, ip
	strb r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0803E6DE:
	ldr r0, _0803E760 @ =0x03000B90
	ldrb r0, [r0]
	movs r6, #1
	eors r0, r6
	lsls r0, r0, #2
	mov r1, r8
	adds r1, #0xa
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0803E73C
	adds r0, r1, #0
	ands r0, r7
	lsls r0, r0, #0x10
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r4, r3, r2
	ldrb r2, [r4]
	lsrs r0, r0, #0x18
	cmp r0, r2
	beq _0803E73C
	eors r2, r6
	strb r2, [r4]
	adds r2, r3, #0
	adds r2, #0x52
	movs r4, #0xc5
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrb r3, [r2]
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _0803E73C
	movs r0, #0
	strh r0, [r5]
	ldr r1, _0803E764 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E73C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E748: .4byte 0x03005010
_0803E74C: .4byte 0x03002B70
_0803E750: .4byte 0x03001800
_0803E754: .4byte 0x000001AF
_0803E758: .4byte 0xFFFF8000
_0803E75C: .4byte 0x03000440
_0803E760: .4byte 0x03000B90
_0803E764: .4byte 0x0300137C
_0803E768:
	.byte 0x01, 0x49, 0x06, 0x20, 0x08, 0x60, 0x70, 0x47
	.byte 0x7C, 0x13, 0x00, 0x03, 0x01, 0x49, 0x05, 0x20, 0x08, 0x60, 0x70, 0x47, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
