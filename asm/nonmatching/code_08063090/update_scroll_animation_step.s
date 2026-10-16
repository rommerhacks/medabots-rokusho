	.syntax unified

	thumb_func_start update_scroll_animation_step
update_scroll_animation_step: @ 0x08064768
	push {r4, lr}
	sub sp, #4
	ldr r2, _080647D0 @ =0x0300057C
	ldr r0, _080647D4 @ =0x03006F74
	ldr r3, [r0]
	movs r1, #0x3a
	ldrsh r0, [r3, r1]
	lsls r0, r0, #4
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, _080647D8 @ =0x000001FF
	ands r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3, #0x3a]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	subs r4, #0xb8
	adds r1, r4, #0
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #0x3a]
	adds r0, #1
	strh r0, [r3, #0x3a]
	ldr r0, _080647DC @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080647C6
	adds r0, r3, #0
	adds r0, #0x50
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl init_blend_effect
	ldr r1, _080647E0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080647C6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080647D0: .4byte 0x0300057C
_080647D4: .4byte 0x03006F74
_080647D8: .4byte 0x000001FF
_080647DC: .4byte 0x03001798
_080647E0: .4byte 0x0300137C
	.syntax divided
