	.syntax unified

	thumb_func_start sub_0800EB60
sub_0800EB60: @ 0x0800EB60
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	ldr r0, _0800EB80 @ =0x03000440
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800EB94
	cmp r0, #1
	bgt _0800EB84
	cmp r0, #0
	beq _0800EB8A
	b _0800EBAE
	.align 2, 0
_0800EB80: .4byte 0x03000440
_0800EB84:
	cmp r0, #2
	beq _0800EBA8
	b _0800EBAE
_0800EB8A:
	ldr r1, _0800EB90 @ =0x0300137C
	movs r0, #0xa
	b _0800EBAC
	.align 2, 0
_0800EB90: .4byte 0x0300137C
_0800EB94:
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	ldr r1, _0800EBA4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0800EBAC
	.align 2, 0
_0800EBA4: .4byte 0x0300137C
_0800EBA8:
	ldr r1, _0800EBB4 @ =0x0300137C
	movs r0, #4
_0800EBAC:
	str r0, [r1]
_0800EBAE:
	pop {r0}
	bx r0
	.align 2, 0
_0800EBB4: .4byte 0x0300137C
_0800EBB8:
	.byte 0x07, 0x4A, 0x08, 0x49, 0x08, 0x1C, 0x3E, 0x30
	.byte 0x00, 0x78, 0x00, 0x04, 0x3D, 0x31, 0x09, 0x78, 0x40, 0x18, 0x10, 0x60, 0x04, 0x49, 0x08, 0x68
	.byte 0x01, 0x30, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00, 0x68, 0x2B, 0x00, 0x03, 0x40, 0x04, 0x00, 0x03
	.byte 0x7C, 0x13, 0x00, 0x03
	.syntax divided
