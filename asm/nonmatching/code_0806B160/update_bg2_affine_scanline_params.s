	.syntax unified

	thumb_func_start update_bg2_affine_scanline_params
update_bg2_affine_scanline_params: @ 0x0806D310
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0806D3E0 @ =0x030003F0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r5, #0
	ldr r0, _0806D3E4 @ =0x03000030
	mov r8, r0
	ldr r2, _0806D3E8 @ =0x03000170
	mov sb, r2
	ldr r0, _0806D3EC @ =0x030002B0
	mov sl, r0
	mov ip, r1
	movs r7, #0xf0
	lsls r7, r7, #7
	mov r6, r8
	mov r4, sl
	mov r3, sb
_0806D33C:
	mov r0, ip
	ldrh r2, [r0]
	subs r2, r7, r2
	ldrh r1, [r6]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r0, r2, r0
	strh r0, [r3]
	asrs r0, r0, #0x10
	strh r0, [r4]
	adds r6, #2
	adds r4, #2
	adds r3, #2
	adds r5, #1
	cmp r5, #0x1f
	ble _0806D33C
	cmp r5, #0x7f
	bgt _0806D37C
	ldr r2, _0806D3E8 @ =0x03000170
	movs r3, #0
	ldr r1, _0806D3EC @ =0x030002B0
	lsls r0, r5, #1
	adds r1, r0, r1
	adds r0, r0, r2
_0806D36E:
	strh r3, [r0]
	strh r3, [r1]
	adds r1, #2
	adds r0, #2
	adds r5, #1
	cmp r5, #0x7f
	ble _0806D36E
_0806D37C:
	cmp r5, #0x9f
	bgt _0806D3B8
	ldr r2, _0806D3E0 @ =0x030003F0
	mov ip, r2
	movs r7, #0xf0
	lsls r7, r7, #7
	ldr r0, _0806D3E4 @ =0x03000030
	lsls r1, r5, #1
	adds r6, r1, r0
	ldr r2, _0806D3E8 @ =0x03000170
	ldr r0, _0806D3EC @ =0x030002B0
	adds r4, r1, r0
	adds r3, r1, r2
_0806D396:
	mov r0, ip
	ldrh r2, [r0]
	adds r2, r2, r7
	ldrh r1, [r6]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r0, r2, r0
	strh r0, [r3]
	asrs r0, r0, #0x10
	strh r0, [r4]
	adds r6, #2
	adds r4, #2
	adds r3, #2
	adds r5, #1
	cmp r5, #0x9f
	ble _0806D396
_0806D3B8:
	ldr r1, _0806D3F0 @ =0x04000020
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #8
	mov r2, sb
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #2
	mov r2, sl
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D3E0: .4byte 0x030003F0
_0806D3E4: .4byte 0x03000030
_0806D3E8: .4byte 0x03000170
_0806D3EC: .4byte 0x030002B0
_0806D3F0: .4byte 0x04000020
	.syntax divided
