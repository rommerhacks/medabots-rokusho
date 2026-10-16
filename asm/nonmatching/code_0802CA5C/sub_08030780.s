	.syntax unified

	thumb_func_start sub_08030780
sub_08030780: @ 0x08030780
	push {r4, lr}
	ldr r2, _080307A0 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	bne _080307AC
	ldr r0, _080307A4 @ =0x03002C30
	ldr r1, _080307A8 @ =0x00000858
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, #0x40
	b _080307B6
	.align 2, 0
_080307A0: .4byte 0x03001800
_080307A4: .4byte 0x03002C30
_080307A8: .4byte 0x00000858
_080307AC:
	ldr r0, _080307E8 @ =0x03002C30
	ldr r1, _080307EC @ =0x00000858
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #0x40
_080307B6:
	ldr r4, _080307F0 @ =0x000003FF
	adds r2, r4, #0
	ands r1, r2
	strh r1, [r0]
	ldr r0, _080307F4 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x89
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	bne _080307D8
	ldr r0, _080307F8 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080307FC
_080307D8:
	adds r1, r2, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _080307FC
	subs r0, #1
	strh r0, [r1]
	b _08030806
	.align 2, 0
_080307E8: .4byte 0x03002C30
_080307EC: .4byte 0x00000858
_080307F0: .4byte 0x000003FF
_080307F4: .4byte 0x03000440
_080307F8: .4byte 0x03001798
_080307FC:
	adds r1, r3, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08030806:
	pop {r4}
	pop {r0}
	bx r0
_0803080C:
	.byte 0x02, 0x48, 0xB5, 0x30
	.byte 0x01, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.syntax divided
