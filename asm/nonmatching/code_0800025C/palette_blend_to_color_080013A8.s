	.syntax unified

	thumb_func_start palette_blend_to_color_080013A8
	.global palette_blend_to_color_080013A8
palette_blend_to_color_080013A8: @ 0x080013A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r1, #0x20
	bls _080013BC
	movs r1, #0x20
_080013BC:
	movs r0, #0x20
	subs r4, r0, r1
	movs r5, #0
	movs r0, #0x1f
	mov r8, r0
	adds r0, r2, #0
	mov r3, r8
	ands r0, r3
	adds r3, r0, #0
	muls r3, r1, r3
	mov sl, r3
	movs r7, #0xf8
	lsls r7, r7, #2
	movs r6, #0xf8
	lsls r6, r6, #7
	adds r0, r2, #0
	ands r0, r7
	adds r3, r0, #0
	muls r3, r1, r3
	mov sb, r3
	adds r0, r2, #0
	ands r0, r6
	adds r2, r0, #0
	muls r2, r1, r2
	mov ip, r2
_080013EE:
	lsls r0, r5, #1
	ldr r1, _08001440 @ =0x0202FC00
	adds r3, r0, r1
	ldr r2, _08001444 @ =0x0202F800
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, r8
	ands r0, r2
	adds r1, r0, #0
	muls r1, r4, r1
	add r1, sl
	lsrs r1, r1, #5
	adds r0, r7, #0
	ands r0, r2
	muls r0, r4, r0
	add r0, sb
	lsrs r0, r0, #5
	ands r0, r7
	orrs r1, r0
	adds r0, r6, #0
	ands r0, r2
	muls r0, r4, r0
	add r0, ip
	lsrs r0, r0, #5
	ands r0, r6
	orrs r1, r0
	strh r1, [r3]
	adds r5, #1
	ldr r3, _08001448 @ =0x000001FF
	cmp r5, r3
	bls _080013EE
	ldr r0, _0800144C @ =dma_obj_palette_to_hardware
	ldr r1, _08001450 @ =0x03000B98
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001440: .4byte 0x0202FC00
_08001444: .4byte 0x0202F800
_08001448: .4byte 0x000001FF
_0800144C: .4byte dma_obj_palette_to_hardware
_08001450: .4byte 0x03000B98
	.syntax divided
