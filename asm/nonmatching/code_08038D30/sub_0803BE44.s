	.syntax unified

	thumb_func_start sub_0803BE44
sub_0803BE44: @ 0x0803BE44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0803BEC8 @ =0x083AFAAC
	ldr r0, _0803BECC @ =0x03001800
	mov ip, r0
	adds r0, #0x38
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov sb, r0
	mov r7, sb
	ldr r1, _0803BED0 @ =0x03002C30
	ldr r2, _0803BED4 @ =0x03000440
	ldr r3, _0803BED8 @ =0x0000012F
	adds r6, r2, r3
	ldrb r0, [r6]
	lsls r0, r0, #6
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	mov r8, r1
	mov sl, r2
	cmp r0, #0
	bne _0803BF44
	movs r4, #0xaa
	lsls r4, r4, #1
	add r4, ip
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	ldrh r0, [r4]
	adds r0, r0, r1
	ldr r7, _0803BEDC @ =0x000001FF
	ands r0, r7
	strh r0, [r4]
	ldrb r0, [r6]
	lsls r0, r0, #6
	add r0, r8
	adds r2, r0, #0
	adds r2, #0x2b
	ldrh r1, [r0, #0x30]
	ldrb r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #0x30]
	ldrb r0, [r6]
	lsls r0, r0, #6
	mov r1, r8
	adds r2, r0, r1
	ldrh r0, [r2, #0x30]
	cmp r0, #0x78
	bhi _0803BEB4
	b _0803C034
_0803BEB4:
	movs r5, #0xc4
	lsls r5, r5, #1
	cmp r0, r5
	bhi _0803BEE0
	movs r2, #0
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	subs r3, #0x78
	b _0803BEF4
	.align 2, 0
_0803BEC8: .4byte gUnk_083AFAAC
_0803BECC: .4byte 0x03001800
_0803BED0: .4byte 0x03002C30
_0803BED4: .4byte 0x03000440
_0803BED8: .4byte 0x0000012F
_0803BEDC: .4byte 0x000001FF
_0803BEE0:
	ldrh r1, [r2, #0x30]
	ldr r3, _0803BF20 @ =0xFFFFFE78
	adds r0, r1, r3
	adds r3, r2, #0
	adds r3, #0x2b
	ldrb r3, [r3]
	cmp r0, r3
	bge _0803BF2C
	adds r0, r3, r5
	subs r3, r0, r1
_0803BEF4:
	ldrh r1, [r4]
	subs r1, r1, r3
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, ip
	ldrh r0, [r2]
	subs r0, r0, r3
	ands r1, r7
	strh r1, [r4]
	ands r0, r7
	strh r0, [r2]
	ldr r1, _0803BF24 @ =0x0300057C
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _0803BF28 @ =0x03001C04
	mov r0, sb
	lsrs r3, r0
	ldrh r2, [r1]
	adds r0, r3, r2
	strh r0, [r1]
	b _0803C034
	.align 2, 0
_0803BF20: .4byte 0xFFFFFE78
_0803BF24: .4byte 0x0300057C
_0803BF28: .4byte 0x03001C04
_0803BF2C:
	ldr r0, _0803BF40 @ =0x0000018F
	cmp r1, r0
	bhi _0803BF34
	b _0803C034
_0803BF34:
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	b _0803C034
	.align 2, 0
_0803BF40: .4byte 0x0000018F
_0803BF44:
	movs r4, #0xac
	lsls r4, r4, #1
	add r4, ip
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	ldrh r0, [r4]
	subs r0, r0, r1
	ldr r5, _0803BFBC @ =0x000001FF
	ands r0, r5
	strh r0, [r4]
	ldrb r1, [r6]
	lsls r1, r1, #6
	add r1, r8
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r2, [r0]
	ldrh r0, [r1, #0x30]
	subs r0, r0, r2
	strh r0, [r1, #0x30]
	ldrb r0, [r6]
	lsls r0, r0, #6
	mov r3, r8
	adds r1, r0, r3
	ldrh r2, [r1, #0x30]
	ands r2, r5
	ldrh r0, [r1, #0x30]
	subs r0, #0x78
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x78
	bls _0803C034
	adds r0, r2, #0
	subs r0, #0x78
	cmp r0, #0xef
	bls _0803BFC8
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0x78
	subs r3, r0, r1
	ldrh r1, [r4]
	adds r1, r1, r3
	movs r2, #0xaa
	lsls r2, r2, #1
	add r2, ip
	ldrh r0, [r2]
	adds r0, r0, r3
	ands r0, r5
	strh r0, [r2]
	ands r1, r5
	strh r1, [r4]
	ldr r1, _0803BFC0 @ =0x0300057C
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	ldr r1, _0803BFC4 @ =0x03001C04
	mov r2, sb
	lsrs r3, r2
	b _0803C002
	.align 2, 0
_0803BFBC: .4byte 0x000001FF
_0803BFC0: .4byte 0x0300057C
_0803BFC4: .4byte 0x03001C04
_0803BFC8:
	ldr r0, _0803C00C @ =0x00000167
	cmp r2, r0
	bhi _0803C01C
	adds r0, #1
	subs r0, r0, r2
	adds r1, #0x2b
	ldrb r1, [r1]
	cmp r0, r1
	bhs _0803C01C
	ldr r3, _0803C010 @ =0xFFFFFE98
	adds r0, r1, r3
	adds r3, r0, r2
	ldrh r1, [r4]
	adds r1, r1, r3
	movs r2, #0xaa
	lsls r2, r2, #1
	add r2, ip
	ldrh r0, [r2]
	adds r0, r0, r3
	ands r0, r5
	strh r0, [r2]
	ands r1, r5
	strh r1, [r4]
	ldr r1, _0803C014 @ =0x0300057C
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	ldr r1, _0803C018 @ =0x03001C04
	lsrs r3, r7
_0803C002:
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	b _0803C034
	.align 2, 0
_0803C00C: .4byte 0x00000167
_0803C010: .4byte 0xFFFFFE98
_0803C014: .4byte 0x0300057C
_0803C018: .4byte 0x03001C04
_0803C01C:
	movs r0, #0xb0
	lsls r0, r0, #1
	cmp r2, r0
	bhi _0803C034
	subs r0, #0x31
	add r0, sl
	ldrb r0, [r0]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
_0803C034:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
