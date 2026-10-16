	.syntax unified

	thumb_func_start sub_0800E43C
sub_0800E43C: @ 0x0800E43C
	push {r4, lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	bl toggle_sprite_hflip_by_frame
	ldr r4, _0800E468 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800E45A
	cmp r0, #4
	bne _0800E46C
_0800E45A:
	bl copy_obj_palette_to_buffer
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	b _0800E476
	.align 2, 0
_0800E468: .4byte 0x03000440
_0800E46C:
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
_0800E476:
	ldr r1, _0800E484 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800E484: .4byte 0x0300137C
	.syntax divided
