	.syntax unified

	thumb_func_start sub_080368C4
	.global sub_080368C4
sub_080368C4: @ 0x080368C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	movs r0, #0
	mov ip, r0
	movs r7, #0
	mov r8, r7
	ldr r4, _0803696C @ =0x083AF480
	lsls r0, r2, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	mov sb, r0
	movs r6, #0
	ldr r5, [sp, #4]
	ldr r3, _08036970 @ =0x03002C30
	lsls r2, r2, #2
	adds r2, r2, r4
	lsls r1, r1, #6
	adds r0, r3, #0
	adds r0, #0x23
	adds r4, r1, r0
	adds r3, r1, r3
_08036908:
	ldrb r0, [r5]
	cmp r0, #0xfe
	beq _080369B2
	ldr r0, _08036974 @ =0xFFFFC624
	strh r0, [r3]
	mov r1, r8
	strb r1, [r3, #0x1c]
	ldr r7, [sp]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r2]
	adds r0, r0, r1
	ldr r7, _08036978 @ =0x000001FF
	adds r1, r7, #0
	ands r0, r1
	strh r0, [r3, #2]
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r7, sb
	ldrh r7, [r7]
	adds r0, r0, r7
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #4]
	movs r0, #0x80
	strb r0, [r3, #0xb]
	ldrb r0, [r5]
	movs r7, #0xb4
	lsls r7, r7, #6
	adds r1, r7, #0
	adds r0, r0, r1
	strh r0, [r3, #6]
	mov r0, r8
	strb r0, [r4]
	movs r0, #0x40
	strb r0, [r3, #9]
	strb r0, [r3, #8]
	movs r0, #0xe
	strb r0, [r3, #0xa]
	ldr r1, [sp, #4]
	ldrb r0, [r1, #6]
	cmp r0, #3
	beq _0803698C
	cmp r0, #3
	bgt _0803697C
	cmp r0, #2
	beq _08036982
	b _080369A0
	.align 2, 0
_0803696C: .4byte gUnk_083AF480
_08036970: .4byte 0x03002C30
_08036974: .4byte 0xFFFFC624
_08036978: .4byte 0x000001FF
_0803697C:
	cmp r0, #4
	beq _08036994
	b _080369A0
_08036982:
	ldr r7, _08036988 @ =0x0000FFFC
	b _08036996
	.align 2, 0
_08036988: .4byte 0x0000FFFC
_0803698C:
	ldr r7, _08036990 @ =0x0000FFF8
	b _08036996
	.align 2, 0
_08036990: .4byte 0x0000FFF8
_08036994:
	ldr r7, _080369C4 @ =0x0000FFF4
_08036996:
	adds r0, r7, #0
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	adds r0, r0, r6
	strh r0, [r3, #2]
_080369A0:
	adds r6, #8
	adds r5, #1
	adds r4, #0x40
	adds r3, #0x40
	movs r7, #1
	add ip, r7
	mov r0, ip
	cmp r0, #4
	bls _08036908
_080369B2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080369C4: .4byte 0x0000FFF4
	.syntax divided
