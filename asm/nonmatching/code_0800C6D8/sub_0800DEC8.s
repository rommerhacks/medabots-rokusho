	.syntax unified

	thumb_func_start sub_0800DEC8
sub_0800DEC8: @ 0x0800DEC8
	push {lr}
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r0, _0800DF04 @ =0x084E2E38
	ldr r1, _0800DF08 @ =0x050003E0
	movs r2, #8
	bl CpuFastSet
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800DF0C @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	ldr r1, _0800DF10 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800DF04: .4byte 0x084E2E38
_0800DF08: .4byte 0x050003E0
_0800DF0C: .4byte 0x03001780
_0800DF10: .4byte 0x0300137C
	.syntax divided
