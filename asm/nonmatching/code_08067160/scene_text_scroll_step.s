	.syntax unified

	thumb_func_start scene_text_scroll_step
scene_text_scroll_step: @ 0x08067740
	push {r4, lr}
	sub sp, #0xc
	mov r0, sp
	ldr r1, _080677A0 @ =0x080AFE9C
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	bl update_scene_animation_frame
	ldr r4, _080677A4 @ =0x03006F74
	ldr r2, [r4]
	ldrh r0, [r2, #0x3a]
	adds r0, #1
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd
	ble _080677AC
	ldrb r0, [r2, #5]
	movs r3, #0x3a
	ldrsh r1, [r2, r3]
	subs r1, #0xe
	bl copy_bg_tile_column
	cmp r0, #0
	beq _080677CA
	ldr r1, [r4]
	adds r2, r1, #0
	adds r2, #0xac
	ldrb r0, [r1, #5]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0
	strh r0, [r1, #0x3a]
	ldr r1, _080677A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r2]
	ldr r0, [r0]
	bl sub_08067160
	ldr r1, [r4]
	adds r1, #0x7d
	strb r0, [r1]
	b _080677CA
	.align 2, 0
_080677A0: .4byte 0x080AFE9C
_080677A4: .4byte 0x03006F74
_080677A8: .4byte 0x0300137C
_080677AC:
	ldr r0, _080677D4 @ =0x04000008
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	movs r4, #0x3a
	ldrsh r1, [r2, r4]
	lsls r0, r0, #0xb
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, _080677D8 @ =0x06000080
	adds r0, r0, r1
	ldr r1, _080677DC @ =0x0600D8C0
	ldrh r1, [r1]
	strh r1, [r0]
_080677CA:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080677D4: .4byte 0x04000008
_080677D8: .4byte 0x06000080
_080677DC: .4byte 0x0600D8C0
	.syntax divided
