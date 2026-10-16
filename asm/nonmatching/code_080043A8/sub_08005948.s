	.syntax unified

	thumb_func_start sub_08005948
	.global sub_08005948
sub_08005948: @ 0x08005948
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, _08005984 @ =0x030017A0
	ldr r0, _08005988 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x51
	ldrb r4, [r5]
	lsls r4, r4, #3
	adds r4, r4, r1
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	ldrb r2, [r4, #4]
	ldrb r3, [r4, #5]
	ldrb r4, [r4, #6]
	str r4, [sp]
	bl validate_medapart_stats
	cmp r0, #0
	beq _0800597A
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, #0xa
	movs r1, #8
	bl battle_sprite_set_palette_index
_0800597A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08005984: .4byte 0x030017A0
_08005988: .4byte 0x03000440
	.syntax divided
