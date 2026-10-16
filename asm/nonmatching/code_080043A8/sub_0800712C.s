	.syntax unified

	thumb_func_start sub_0800712C
	.global sub_0800712C
sub_0800712C: @ 0x0800712C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _0800714C @ =0x03000440
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #1
	bge _08007140
	b _08007250
_08007140:
	cmp r0, #2
	ble _08007150
	cmp r0, #3
	beq _080071D2
	b _08007250
	.align 2, 0
_0800714C: .4byte 0x03000440
_08007150:
	movs r5, #0
	movs r0, #0
	mov r8, r0
	ldr r3, _080071A4 @ =0x083AC43B
	movs r7, #0xf
	movs r6, #4
	ldr r0, _080071A8 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0x41
_08007162:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080071B8
	ldr r0, _080071AC @ =0x03002C30
	lsls r2, r6, #6
	adds r2, r2, r0
	ldr r0, _080071B0 @ =0x0000C004
	strh r0, [r2]
	ldrb r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r2, #2]
	ldrb r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r2, #4]
	ldr r1, _080071B4 @ =0x00000401
	adds r0, r5, r1
	strh r0, [r2, #6]
	strb r7, [r2, #0xa]
	mov r0, r8
	strb r0, [r2, #0x1c]
	movs r0, #0xc0
	strb r0, [r2, #0xb]
	b _080071C6
	.align 2, 0
_080071A4: .4byte 0x083AC43B
_080071A8: .4byte 0x03001800
_080071AC: .4byte 0x03002C30
_080071B0: .4byte 0x0000C004
_080071B4: .4byte 0x00000401
_080071B8:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	str r3, [sp]
	bl clear_sprite_table_mask
	ldr r3, [sp]
_080071C6:
	adds r6, #1
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	bls _08007162
	b _08007250
_080071D2:
	movs r5, #0
	movs r1, #0
	mov r8, r1
	ldr r3, _08007224 @ =0x083AC43B
	movs r7, #0xf
	movs r6, #4
	ldr r0, _08007228 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0x41
_080071E4:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08007238
	ldr r0, _0800722C @ =0x03002C30
	lsls r2, r6, #6
	adds r2, r2, r0
	ldr r0, _08007230 @ =0x0000C004
	strh r0, [r2]
	ldrb r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r2, #2]
	ldrb r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r2, #4]
	ldr r1, _08007234 @ =0x00000404
	adds r0, r5, r1
	strh r0, [r2, #6]
	strb r7, [r2, #0xa]
	mov r0, r8
	strb r0, [r2, #0x1c]
	movs r0, #0xc0
	strb r0, [r2, #0xb]
	b _08007246
	.align 2, 0
_08007224: .4byte 0x083AC43B
_08007228: .4byte 0x03001800
_0800722C: .4byte 0x03002C30
_08007230: .4byte 0x0000C004
_08007234: .4byte 0x00000404
_08007238:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	str r3, [sp]
	bl clear_sprite_table_mask
	ldr r3, [sp]
_08007246:
	adds r6, #1
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	bls _080071E4
_08007250:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
