	.syntax unified

	thumb_func_start sub_0801B004
	.global sub_0801B004
sub_0801B004: @ 0x0801B004
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	ldr r0, _0801B0CC @ =0x084E3058
	ldr r1, _0801B0D0 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	movs r5, #0
	ldr r0, _0801B0D4 @ =0x03002C30
	mov sb, r0
	movs r2, #0
	mov r8, r2
	ldr r4, _0801B0D8 @ =0x00000842
	add r4, sb
	ldr r6, _0801B0DC @ =0x00000861
	add r6, sb
	movs r7, #0x84
	lsls r7, r7, #4
	add r7, sb
_0801B034:
	adds r0, r5, #0
	adds r0, #0x21
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r0, _0801B0E0 @ =0x03001800
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	lsls r0, r0, #0xa
	ldr r2, _0801B0E4 @ =0x00004204
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7]
	mov r0, r8
	strb r0, [r4, #0x1a]
	movs r0, #6
	strb r0, [r4, #8]
	movs r0, #0x81
	strb r0, [r4, #9]
	movs r0, #0xa1
	lsls r0, r0, #4
	strh r0, [r4, #4]
	lsls r0, r5, #5
	strb r0, [r4, #0x1e]
	mov r0, sl
	lsls r2, r0, #8
	movs r0, #0xba
	lsls r0, r0, #5
	adds r2, r2, r0
	add r2, sb
	ldrh r0, [r2, #4]
	strb r0, [r4, #0x1f]
	mov r0, r8
	strb r0, [r6, #7]
	lsls r0, r5, #2
	strb r0, [r6, #6]
	mov r0, r8
	strb r0, [r6, #5]
	ldrb r1, [r4, #0x1e]
	movs r0, #2
	ldrsh r3, [r2, r0]
	ldrb r0, [r4, #0x1f]
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r2, #0
	str r2, [sp, #8]
	add r0, sp, #0xc
	movs r2, #0x10
	bl compute_polar_to_screen_position
	ldr r0, [sp, #0xc]
	strh r0, [r4]
	asrs r0, r0, #0x10
	strh r0, [r4, #2]
	movs r0, #4
	strb r0, [r4, #6]
	strb r0, [r4, #7]
	adds r4, #0x40
	adds r6, #0x40
	adds r7, #0x40
	adds r5, #1
	cmp r5, #7
	bls _0801B034
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B0CC: .4byte 0x084E3058
_0801B0D0: .4byte 0x050002C0
_0801B0D4: .4byte 0x03002C30
_0801B0D8: .4byte 0x00000842
_0801B0DC: .4byte 0x00000861
_0801B0E0: .4byte 0x03001800
_0801B0E4: .4byte 0x00004204
	.syntax divided
