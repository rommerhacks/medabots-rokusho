	.syntax unified

	thumb_func_start sub_08050868
sub_08050868: @ 0x08050868
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r5, _0805087C @ =0x03006D20
	ldrb r0, [r5]
	cmp r0, #0
	beq _08050880
	cmp r0, #1
	beq _080508AC
	b _080508C2
	.align 2, 0
_0805087C: .4byte 0x03006D20
_08050880:
	ldrb r4, [r5, #0xa]
	ldr r1, _080508A8 @ =0x03002C30
	lsls r0, r4, #6
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r1, [r0]
	adds r0, r4, #0
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_080493D4
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080508C2
	.align 2, 0
_080508A8: .4byte 0x03002C30
_080508AC:
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _080508C0
	ldrb r0, [r5, #0xa]
	bl advance_sprite_animation_frame
	ldrb r0, [r5, #2]
	subs r0, #1
	strb r0, [r5, #2]
	b _080508C2
_080508C0:
	movs r6, #1
_080508C2:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
