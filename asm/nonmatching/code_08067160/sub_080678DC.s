	.syntax unified

	thumb_func_start sub_080678DC
sub_080678DC: @ 0x080678DC
	push {r4, lr}
	bl update_scene_animation_frame
	ldr r4, _08067914 @ =0x03006F74
	ldr r2, [r4]
	ldrh r0, [r2, #0x3a]
	adds r1, r0, #1
	strh r1, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl bg_tilemap_scroll_up_row
	cmp r0, #0
	beq _08067928
	ldr r1, [r4]
	movs r2, #0
	strh r2, [r1, #0x3a]
	ldrb r0, [r1, #5]
	adds r0, #1
	strb r0, [r1, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0806791C
	ldr r1, _08067918 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08067926
	.align 2, 0
_08067914: .4byte 0x03006F74
_08067918: .4byte 0x0300137C
_0806791C:
	ldr r0, _08067930 @ =0x03004C30
	strh r2, [r0, #2]
	ldr r1, _08067934 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #2
_08067926:
	str r0, [r1]
_08067928:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08067930: .4byte 0x03004C30
_08067934: .4byte 0x0300137C
	.syntax divided
