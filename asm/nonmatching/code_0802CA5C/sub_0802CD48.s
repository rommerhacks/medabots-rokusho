	.syntax unified

	thumb_func_start sub_0802CD48
sub_0802CD48: @ 0x0802CD48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r0, #0
	mov sb, r0
	movs r3, #0
	movs r4, #0
	ldr r1, _0802CDFC @ =0x03001800
	mov r8, r1
_0802CD5E:
	mov r0, r8
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CDD0
	adds r3, #1
	adds r5, r4, #0
	adds r5, #0x21
	ldr r6, _0802CE00 @ =0x03002C30
	mov r7, r8
	adds r7, #0x60
	ldrb r0, [r7]
	adds r0, r0, r4
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r6
	ldrh r2, [r0, #4]
	subs r1, r2, #4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r5, #0
	str r3, [sp]
	bl sprite_move_toward_target
	ldr r3, [sp]
	cmp r0, #0
	beq _0802CDD0
	lsls r1, r5, #6
	adds r1, r1, r6
	ldrb r0, [r7]
	adds r0, r0, r4
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r6
	ldrh r0, [r0, #2]
	strh r0, [r1, #0x30]
	ldrb r0, [r7]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, r0, r6
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r1, #0x32]
	adds r1, #0x24
	movs r0, #6
	strb r0, [r1]
	movs r0, #1
	add sb, r0
_0802CDD0:
	adds r4, #1
	cmp r4, #2
	bls _0802CD5E
	cmp sb, r3
	bne _0802CDEC
	ldr r0, _0802CE04 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _0802CDFC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802CDEC:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CDFC: .4byte 0x03001800
_0802CE00: .4byte 0x03002C30
_0802CE04: .4byte 0x03000440
	.syntax divided
