	.syntax unified

	thumb_func_start bg_layer_init_check
bg_layer_init_check: @ 0x08068A30
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _08068AFC @ =0x00001111
	mov r1, sp
	strh r0, [r1]
	ldr r3, _08068B00 @ =0x03000000
	ldr r0, [r3]
	cmp r0, #0
	bne _08068A58
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r0]
_08068A58:
	ldr r0, _08068B04 @ =0x03000005
	mov r8, r0
	ldrb r1, [r0]
	ldr r6, [r3]
	adds r0, r6, #0
	bl sub_0807CC88
	adds r7, r6, #0
	cmp r0, #0
	bne _08068AEC
	ldr r4, _08068B08 @ =0x040000D4
	mov r1, sp
	str r1, [r4]
	ldr r0, _08068B0C @ =0x03000008
	mov sb, r0
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r1, _08068B10 @ =0x0600C000
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r5, _08068B14 @ =0x80000001
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, sp
	str r0, [r4]
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r1, _08068B18 @ =0x0600C004
	adds r0, r0, r1
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, sp
	str r0, [r4]
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r1, _08068B1C @ =0x0600C008
	adds r0, r0, r1
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, sp
	str r0, [r4]
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r1, _08068B20 @ =0x0600C00C
	adds r0, r0, r1
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
_08068AEC:
	mov r4, r8
	ldrb r0, [r4]
	lsls r0, r0, #4
	cmp r6, r0
	beq _08068B24
	movs r0, #0
	b _08068B26
	.align 2, 0
_08068AFC: .4byte 0x00001111
_08068B00: .4byte 0x03000000
_08068B04: .4byte 0x03000005
_08068B08: .4byte 0x040000D4
_08068B0C: .4byte 0x03000008
_08068B10: .4byte 0x0600C000
_08068B14: .4byte 0x80000001
_08068B18: .4byte 0x0600C004
_08068B1C: .4byte 0x0600C008
_08068B20: .4byte 0x0600C00C
_08068B24:
	movs r0, #1
_08068B26:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
