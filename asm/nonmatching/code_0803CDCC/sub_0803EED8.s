	.syntax unified

	thumb_func_start sub_0803EED8
	.global sub_0803EED8
sub_0803EED8: @ 0x0803EED8
	ldr r0, _0803EF04 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803EF1C
	ldr r0, _0803EF08 @ =0x03005010
	ldr r0, [r0, #0x1c]
	ldr r1, _0803EF0C @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	beq _0803EF1C
	ldr r1, _0803EF10 @ =0x0300178C
	movs r0, #0
	str r0, [r1]
	ldr r1, _0803EF14 @ =0x03002B8C
	movs r0, #0xa
	str r0, [r1]
	ldr r1, _0803EF18 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
	movs r0, #1
	b _0803EF1E
	.align 2, 0
_0803EF04: .4byte 0x03000440
_0803EF08: .4byte 0x03005010
_0803EF0C: .4byte 0x00FFFF00
_0803EF10: .4byte 0x0300178C
_0803EF14: .4byte 0x03002B8C
_0803EF18: .4byte 0x0300137C
_0803EF1C:
	movs r0, #0
_0803EF1E:
	bx lr
	.syntax divided
