	.syntax unified

	thumb_func_start sub_08053798
sub_08053798: @ 0x08053798
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	ldr r4, _080537F8 @ =0x03005350
	movs r0, #0xf0
	str r0, [r4]
	movs r0, #0xa0
	str r0, [r4, #4]
	movs r0, #0
	mov sl, r0
	movs r0, #0x78
	str r0, [r4, #8]
	movs r0, #0x50
	str r0, [r4, #0xc]
	ldr r5, _080537FC @ =0xC2F10000
	ldr r6, _08053800 @ =0x42F10000
	ldr r1, _08053804 @ =0xC2A10000
	mov r8, r1
	ldr r0, _08053808 @ =0x42A10000
	mov sb, r0
	adds r0, r5, #0
	adds r1, r6, #0
	mov r2, r8
	mov r3, sb
	bl affine_set_destination_and_compute_transform
	adds r0, r5, #0
	adds r1, r6, #0
	mov r2, r8
	mov r3, sb
	bl affine_set_source_and_compute_transform
	adds r0, r4, #0
	adds r0, #0xb4
	mov r1, sl
	str r1, [r0]
	adds r4, #0xb8
	str r1, [r4]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080537F8: .4byte 0x03005350
_080537FC: .4byte 0xC2F10000
_08053800: .4byte 0x42F10000
_08053804: .4byte 0xC2A10000
_08053808: .4byte 0x42A10000
	.syntax divided
