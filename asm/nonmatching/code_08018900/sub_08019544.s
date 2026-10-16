	.syntax unified

	thumb_func_start sub_08019544
	.global sub_08019544
sub_08019544: @ 0x08019544
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r2, _08019594 @ =0x03002C30
	lsls r4, r5, #2
	adds r0, r4, #0
	adds r0, #0x5b
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801959C
	adds r1, r4, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r2
	ldr r2, _08019598 @ =0x03000590
	lsls r0, r5, #8
	adds r0, r0, r2
	adds r0, #0xbb
	ldrb r2, [r0]
	movs r0, #0x20
	subs r0, r0, r2
	asrs r0, r0, #1
	adds r0, #1
	adds r1, #0x24
	strb r0, [r1]
	adds r4, #0x5a
	adds r0, r5, #0
	bl sub_08015924
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl update_battle_sprite_orbiting_positions
	b _080195B6
	.align 2, 0
_08019594: .4byte 0x03002C30
_08019598: .4byte 0x03000590
_0801959C:
	adds r0, r4, #0
	adds r0, #0x5a
	ldr r2, _080195BC @ =0x03000590
	lsls r1, r5, #8
	adds r1, r1, r2
	adds r1, #0xbb
	ldrb r2, [r1]
	movs r1, #0x20
	subs r1, r1, r2
	asrs r1, r1, #1
	adds r1, #1
	bl battle_sprite_set_palette_index
_080195B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080195BC: .4byte 0x03000590
	.syntax divided
