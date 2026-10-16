	.syntax unified

	thumb_func_start sub_0804C81C
sub_0804C81C: @ 0x0804C81C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl read_map_script_byte
	ldr r1, _0804C8C8 @ =0x030057E0
	ldr r2, _0804C8CC @ =0x00000C94
	adds r1, r1, r2
	strb r0, [r1]
	movs r6, #0
	ldr r0, _0804C8D0 @ =0x030055A0
	mov sl, r0
	ldr r5, _0804C8D4 @ =0x03002C30
	mov sb, r6
	mov r8, r1
	movs r7, #8
_0804C840:
	lsls r0, r6, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl sub_0804DBA4
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _0804C8AA
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #2
	add r0, sl
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804C8AA
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r5
	mov r2, r8
	ldrb r1, [r2]
	adds r0, #0x26
	strb r1, [r0]
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x27
	mov r1, sb
	strb r1, [r0]
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x28
	strb r7, [r0]
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x29
	strb r7, [r0]
_0804C8AA:
	adds r6, #1
	cmp r6, #3
	ble _0804C840
	ldr r0, _0804C8C8 @ =0x030057E0
	ldr r2, _0804C8D8 @ =0x00000C89
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C8C8: .4byte 0x030057E0
_0804C8CC: .4byte 0x00000C94
_0804C8D0: .4byte 0x030055A0
_0804C8D4: .4byte 0x03002C30
_0804C8D8: .4byte 0x00000C89

	.syntax divided
