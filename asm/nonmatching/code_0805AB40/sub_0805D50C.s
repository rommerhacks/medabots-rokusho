	.syntax unified

	thumb_func_start sub_0805D50C
sub_0805D50C: @ 0x0805D50C
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _0805D540 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _0805D548
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _0805D544 @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0805D56A
	.align 2, 0
_0805D540: .4byte 0x03000440
_0805D544: .4byte 0x0000FFFF
_0805D548:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0805D574 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _0805D578 @ =0x01006000
	mov r0, sp
	bl CpuFastSet
	movs r0, #4
	bl dispatch_by_index_0476e8
_0805D56A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D574: .4byte 0x0000FDFF
_0805D578: .4byte 0x01006000
	.syntax divided
