	.syntax unified

	thumb_func_start sub_080632FC
sub_080632FC: @ 0x080632FC
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r6, _08063364 @ =0x03006F74
	ldr r2, [r6]
	ldrh r0, [r2, #0x3c]
	adds r1, r0, #1
	strh r1, [r2, #0x3c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x10
	subs r5, r1, r0
	cmp r5, #0
	beq _0806336C
	ldr r1, _08063368 @ =0x04000050
	movs r3, #0xe5
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	subs r0, r0, r5
	lsls r0, r0, #8
	orrs r0, r5
	strh r0, [r1]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	ldrb r1, [r1]
	movs r2, #1
	bl load_medapart_sprite_animation
	cmp r5, #1
	bne _080633C8
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	b _080633C8
	.align 2, 0
_08063364: .4byte 0x03006F74
_08063368: .4byte 0x04000050
_0806336C:
	adds r1, r2, #0
	adds r1, #0x31
	ldrb r5, [r1]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, #0x32
	strb r5, [r0]
	ldr r0, [r6]
	adds r1, r0, #0
	adds r1, #0x33
	ldrb r5, [r1]
	adds r0, #0x34
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, #0x34
	strb r5, [r0]
	movs r0, #0
	bl init_scene_rendering_context
	movs r0, #1
	bl init_scene_rendering_context
	ldr r0, [r6]
	strh r4, [r0, #0x3c]
	ldr r1, _080633D4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	mov r1, sp
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080633D8 @ =0x03002414
	ldr r1, [r0]
	ldr r3, _080633DC @ =0x00000B84
	adds r1, r1, r3
	ldr r2, _080633E0 @ =0x01000200
	mov r0, sp
	bl CpuSet
_080633C8:
	bl update_animated_tilemap
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080633D4: .4byte 0x0300137C
_080633D8: .4byte 0x03002414
_080633DC: .4byte 0x00000B84
_080633E0: .4byte 0x01000200
	.syntax divided
