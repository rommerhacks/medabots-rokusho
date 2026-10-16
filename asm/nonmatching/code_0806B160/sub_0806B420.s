	.syntax unified

	thumb_func_start sub_0806B420
sub_0806B420: @ 0x0806B420
	push {r1, r3, r5, lr}
	lsrs r6, r0, #0x20
	push {r1, r2, r4, r5, r6, lr}
	lsrs r6, r0, #0x20
	push {r4, r6, lr}
	lsrs r6, r0, #0x20
_0806B42C:
	adds r2, r4, r6
	adds r0, r2, #0
	adds r0, #0x20
	movs r1, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r3, [r0]
	movs r0, #0x33
	strh r0, [r2, #0x30]
	ldr r0, _0806B450 @ =0x08485D5C
	ldrh r0, [r0, #8]
	strh r0, [r2, #6]
	b _0806B576
	.align 2, 0
_0806B450: .4byte 0x08485D5C
_0806B454:
	adds r3, r4, r6
	adds r1, r3, #0
	adds r1, #0x20
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #3
	strb r0, [r1]
	lsrs r0, r5, #1
	adds r1, #1
	strb r0, [r1]
	movs r0, #0x33
	strh r0, [r3, #0x30]
	ldr r0, _0806B474 @ =0x08485D5C
	ldrh r0, [r0, #0x18]
	b _0806B574
	.align 2, 0
_0806B474: .4byte 0x08485D5C
_0806B478:
	adds r3, r4, r6
	adds r1, r3, #0
	adds r1, #0x20
	movs r0, #3
	strb r0, [r1]
	adds r1, #1
	movs r0, #7
	strb r0, [r1]
	lsrs r0, r5, #1
	adds r1, #1
	strb r0, [r1]
	movs r0, #0x33
	strh r0, [r3, #0x30]
	ldr r0, _0806B498 @ =0x08485D5C
	ldrh r0, [r0, #0x38]
	b _0806B574
	.align 2, 0
_0806B498: .4byte 0x08485D5C
_0806B49C:
	adds r2, r4, r6
	adds r1, r2, #0
	adds r1, #0x20
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xb
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x22
	strb r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #0x30]
	ldr r0, _0806B4C0 @ =0x08485D5C
	adds r0, #0x58
	b _0806B4E2
	.align 2, 0
_0806B4C0: .4byte 0x08485D5C
_0806B4C4:
	adds r2, r4, r6
	adds r1, r2, #0
	adds r1, #0x20
	movs r0, #5
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xf
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x22
	strb r5, [r0]
	ldr r0, _0806B4E8 @ =0x00000107
	strh r0, [r2, #0x30]
	ldr r0, _0806B4EC @ =0x08485D5C
	adds r0, #0x78
_0806B4E2:
	ldrh r0, [r0]
	strh r0, [r2, #6]
	b _0806B576
	.align 2, 0
_0806B4E8: .4byte 0x00000107
_0806B4EC: .4byte 0x08485D5C
_0806B4F0:
	adds r3, r4, r6
	adds r1, r3, #0
	adds r1, #0x20
	movs r2, #0
	movs r0, #6
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x21
	strb r2, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r0, _0806B50C @ =0x0000010B
	b _0806B572
	.align 2, 0
_0806B50C: .4byte 0x0000010B
_0806B510:
	adds r3, r4, r6
	adds r1, r3, #0
	adds r1, #0x20
	movs r2, #0
	movs r0, #7
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x21
	strb r2, [r0]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	b _0806B572
_0806B52A:
	adds r0, r4, r6
	mov ip, r0
	mov r1, ip
	adds r1, #0x20
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x21
	strb r2, [r0]
	adds r0, #2
	strb r3, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	mov r1, ip
	strh r0, [r1, #0x30]
	strh r0, [r1, #6]
	b _0806B576
_0806B550:
	adds r3, r4, r6
	adds r1, r3, #0
	adds r1, #0x20
	movs r2, #0
	movs r0, #0xa
	strb r0, [r1]
	lsls r0, r5, #2
	adds r0, #0x14
	adds r1, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x27
	strb r2, [r0]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, #0x6f
_0806B572:
	strh r0, [r3, #0x30]
_0806B574:
	strh r0, [r3, #6]
_0806B576:
	adds r1, r4, r6
	movs r0, #0
	strh r0, [r1, #0x1a]
_0806B57C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
