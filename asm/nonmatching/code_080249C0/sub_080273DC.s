	.syntax unified

	thumb_func_start sub_080273DC
sub_080273DC: @ 0x080273DC
	push {r4, r5, r6, r7, lr}
	ldr r4, _08027424 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl sub_080378A8
	adds r7, r4, #0
	adds r7, #0x84
	ldrb r0, [r7]
	cmp r0, #8
	bhi _08027430
	ldr r6, _08027428 @ =0x00007FFF
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _0802742C @ =0x0000FFFF
	adds r0, r6, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r7]
	lsls r0, r0, #2
	subs r4, r4, r0
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	b _0802743A
	.align 2, 0
_08027424: .4byte 0x03000440
_08027428: .4byte 0x00007FFF
_0802742C: .4byte 0x0000FFFF
_08027430:
	ldr r1, _08027440 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802743A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027440: .4byte 0x03001800
	.syntax divided
