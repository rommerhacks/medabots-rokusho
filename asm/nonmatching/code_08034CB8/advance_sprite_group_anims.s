	.syntax unified

	thumb_func_start advance_sprite_group_anims
	.global advance_sprite_group_anims
advance_sprite_group_anims: @ 0x08036B1C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r5, #0
	movs r4, #0
	b _08036B2A
_08036B28:
	adds r4, #1
_08036B2A:
	cmp r4, #4
	bhi _08036B46
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _08036B46
	adds r0, r6, r4
	movs r1, #1
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _08036B28
	movs r5, #1
	b _08036B28
_08036B46:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
