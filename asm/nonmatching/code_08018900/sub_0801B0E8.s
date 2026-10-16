	.syntax unified

	thumb_func_start sub_0801B0E8
	.global sub_0801B0E8
sub_0801B0E8: @ 0x0801B0E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r1, #0
	str r1, [sp, #0x14]
	ldr r2, _0801B130 @ =0x03002C30
	mov sb, r2
	movs r3, #0x84
	lsls r3, r3, #4
	str r3, [sp, #0x1c]
	ldr r6, _0801B134 @ =0x00000861
	add r6, sb
	add r3, sb
	mov r8, r3
	ldr r4, _0801B138 @ =0x00000842
	add r4, sb
	movs r5, #0x86
	lsls r5, r5, #4
	add r5, sb
	mov sl, r5
	movs r7, #0x21
	str r7, [sp, #0x20]
_0801B120:
	mov r0, r8
	ldrh r1, [r0]
	cmp r1, #0
	bne _0801B13C
	ldr r1, [sp, #0x18]
	adds r1, #1
	str r1, [sp, #0x18]
	b _0801B22E
	.align 2, 0
_0801B130: .4byte 0x03002C30
_0801B134: .4byte 0x00000861
_0801B138: .4byte 0x00000842
_0801B13C:
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r0, r1
	mov r3, r8
	strh r0, [r3]
	ldrb r0, [r6, #7]
	adds r0, #1
	strb r0, [r6, #7]
	ldrb r0, [r4, #0x1e]
	subs r0, #8
	strb r0, [r4, #0x1e]
	ldrb r1, [r6, #7]
	movs r0, #7
	ands r0, r1
	movs r5, #0x21
	add r5, r8
	mov ip, r5
	cmp r0, #0
	bne _0801B16A
	ldrb r0, [r4, #0x1f]
	subs r0, #1
	strb r0, [r4, #0x1f]
_0801B16A:
	mov r7, sl
	ldrb r1, [r7]
	ldrb r2, [r6, #5]
	adds r2, #0x10
	ldr r0, [sp, #0x10]
	lsls r5, r0, #2
	adds r0, r5, #0
	adds r0, #0x5d
	lsls r0, r0, #6
	add r0, sb
	movs r7, #2
	ldrsh r3, [r0, r7]
	mov r7, ip
	ldrb r0, [r7]
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	bl compute_polar_to_screen_position
	ldr r0, [sp, #0xc]
	strh r0, [r4]
	asrs r0, r0, #0x10
	strh r0, [r4, #2]
	mov r1, sl
	ldrb r0, [r1]
	adds r2, r5, #0
	cmp r0, #0x80
	bls _0801B1AE
	adds r0, r2, #0
	adds r0, #0x59
	b _0801B1B0
_0801B1AE:
	movs r0, #0x81
_0801B1B0:
	strb r0, [r4, #9]
	ldrb r0, [r4, #0x1f]
	adds r1, r2, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	add r1, sb
	movs r3, #4
	ldrsh r1, [r1, r3]
	subs r1, #8
	ldr r3, _0801B25C @ =0x03002C30
	cmp r0, r1
	ble _0801B1D8
	ldrb r0, [r4, #6]
	cmp r0, #0x40
	beq _0801B1D8
	adds r0, #4
	strb r0, [r4, #6]
	ldrb r0, [r4, #7]
	adds r0, #4
	strb r0, [r4, #7]
_0801B1D8:
	ldrb r0, [r4, #0x1f]
	adds r1, r2, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	add r1, sb
	movs r5, #4
	ldrsh r1, [r1, r5]
	subs r1, #0xc
	cmp r0, r1
	bge _0801B1FC
	ldrb r0, [r4, #6]
	cmp r0, #4
	beq _0801B1FC
	subs r0, #4
	strb r0, [r4, #6]
	ldrb r0, [r4, #7]
	subs r0, #4
	strb r0, [r4, #7]
_0801B1FC:
	ldr r7, [sp, #0x1c]
	adds r1, r7, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0xc0
	bne _0801B22E
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x5d
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r0, #0x10
	cmp r1, r0
	bge _0801B22E
	ldr r3, [sp, #0x20]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
_0801B22E:
	ldr r5, [sp, #0x1c]
	adds r5, #0x40
	str r5, [sp, #0x1c]
	adds r6, #0x40
	movs r7, #0x40
	add r8, r7
	adds r4, #0x40
	movs r0, #0x40
	add sl, r0
	ldr r1, [sp, #0x20]
	adds r1, #1
	str r1, [sp, #0x20]
	ldr r2, [sp, #0x14]
	adds r2, #1
	str r2, [sp, #0x14]
	cmp r2, #7
	bhi _0801B252
	b _0801B120
_0801B252:
	ldr r3, [sp, #0x18]
	cmp r3, #8
	beq _0801B260
	movs r0, #0
	b _0801B262
	.align 2, 0
_0801B25C: .4byte 0x03002C30
_0801B260:
	movs r0, #1
_0801B262:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
