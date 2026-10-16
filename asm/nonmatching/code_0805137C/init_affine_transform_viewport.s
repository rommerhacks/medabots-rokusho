	.syntax unified

	thumb_func_start init_affine_transform_viewport
init_affine_transform_viewport: @ 0x08053F70
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r3, _08053FB4 @ =0x03005350
	movs r2, #0xf0
	str r2, [r3]
	movs r2, #0xa0
	str r2, [r3, #4]
	adds r0, #0x78
	str r0, [r3, #8]
	adds r1, #0x50
	str r1, [r3, #0xc]
	ldr r4, _08053FB8 @ =0xC2F10000
	ldr r5, _08053FBC @ =0x42F10000
	ldr r6, _08053FC0 @ =0xC2A10000
	ldr r0, _08053FC4 @ =0x42A10000
	mov r8, r0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl affine_set_destination_and_compute_transform
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl affine_set_source_and_compute_transform
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053FB4: .4byte 0x03005350
_08053FB8: .4byte 0xC2F10000
_08053FBC: .4byte 0x42F10000
_08053FC0: .4byte 0xC2A10000
_08053FC4: .4byte 0x42A10000
	.syntax divided
