	.syntax unified

	thumb_func_start check_sprite_overlap_and_adjust
	.global check_sprite_overlap_and_adjust
check_sprite_overlap_and_adjust: @ 0x080356CC
	push {r4, r5, lr}
	adds r2, r1, #0
	ldr r3, _080356FC @ =0x03002C30
	lsls r0, r0, #6
	adds r5, r0, r3
	movs r0, #4
	ldrsh r1, [r5, r0]
	cmp r1, #0x9f
	bhi _080356EE
	adds r1, #8
	lsls r0, r2, #6
	adds r4, r0, r3
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r0, #0x20
	cmp r1, r0
	bgt _08035700
_080356EE:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_sprite_table_mask
	b _08035724
	.align 2, 0
_080356FC: .4byte 0x03002C30
_08035700:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl set_sprite_hidden_flags
	ldrb r1, [r4, #4]
	subs r1, #8
	ldrb r0, [r5, #4]
	subs r0, r1, r0
	lsls r0, r0, #1
	movs r2, #0x40
	subs r0, r2, r0
	strb r0, [r4, #8]
	ldrb r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #1
	subs r2, r2, r1
	strb r2, [r4, #9]
_08035724:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
