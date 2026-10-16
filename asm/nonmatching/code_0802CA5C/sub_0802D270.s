	.syntax unified

	thumb_func_start sub_0802D270
sub_0802D270: @ 0x0802D270
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r5, #0
	ldr r7, _0802D3C0 @ =0x030018D2
_0802D280:
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r6, r5, #1
	cmp r0, #0
	beq _0802D29E
	movs r4, #0
	lsls r0, r5, #2
	adds r5, r0, #0
	adds r5, #0x30
_0802D292:
	adds r0, r4, r5
	bl update_sprite_animation_position
	adds r4, #1
	cmp r4, #3
	bls _0802D292
_0802D29E:
	adds r5, r6, #0
	cmp r5, #2
	bls _0802D280
	ldr r0, _0802D3C4 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #0x10
	bne _0802D3AC
	movs r5, #0
	ldr r0, _0802D3C8 @ =0x03001800
	mov sl, r0
	ldr r7, _0802D3CC @ =0x03003530
	mov r6, sl
	adds r6, #0x60
	ldr r1, _0802D3D0 @ =0xFFFFF700
	adds r1, r1, r7
	mov sb, r1
	str r7, [sp]
	movs r2, #0x80
	lsls r2, r2, #8
	mov r8, r2
_0802D2CA:
	ldr r3, _0802D3C0 @ =0x030018D2
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D38E
	lsls r4, r5, #8
	ldrb r1, [r6]
	adds r1, r1, r5
	lsls r1, r1, #8
	movs r2, #0xd8
	lsls r2, r2, #4
	adds r0, r7, r2
	adds r1, r1, r0
	ldr r0, [sp]
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r7, #0
	adds r0, #0x40
	adds r0, r4, r0
	ldrb r1, [r6]
	adds r1, r1, r5
	lsls r1, r1, #8
	movs r3, #0xdc
	lsls r3, r3, #4
	adds r2, r7, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r7, #0
	adds r0, #0x80
	adds r0, r4, r0
	ldrb r1, [r6]
	adds r1, r1, r5
	lsls r1, r1, #8
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r2, r7, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r0, r7, #0
	adds r0, #0xc0
	adds r4, r4, r0
	ldrb r1, [r6]
	adds r1, r1, r5
	lsls r1, r1, #8
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r0, r7, r2
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r3, #0xb4
	lsls r3, r3, #5
	adds r0, r0, r3
	add r0, sb
	ldrh r1, [r0]
	mov r2, r8
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r3, #0x40
	adds r0, r0, r3
	add r0, sb
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	add r0, sb
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	add r0, sb
	ldrh r1, [r0]
	mov r3, r8
	orrs r1, r3
	strh r1, [r0]
_0802D38E:
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp]
	adds r5, #1
	cmp r5, #2
	bls _0802D2CA
	movs r0, #0x21
	movs r1, #0x1b
	bl clear_battle_sprite_slot
	ldr r1, _0802D3C0 @ =0x030018D2
	subs r1, #0x28
	ldrb r0, [r1]
_0802D3AC:
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D3C0: .4byte 0x030018D2
_0802D3C4: .4byte 0x03000440
_0802D3C8: .4byte 0x03001800
_0802D3CC: .4byte 0x03003530
_0802D3D0: .4byte 0xFFFFF700
	.syntax divided
