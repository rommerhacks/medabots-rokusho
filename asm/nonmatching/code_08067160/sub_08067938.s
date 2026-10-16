	.syntax unified

	thumb_func_start sub_08067938
sub_08067938: @ 0x08067938
	push {r4, lr}
	bl update_scene_animation_frame
	ldr r0, _08067964 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #0x3a]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _0806796C
	ldr r1, _08067968 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	strh r3, [r2, #0x3e]
	movs r0, #0xc0
	bl sound_stop_all_with_fade_guard
	b _08067986
	.align 2, 0
_08067964: .4byte 0x03006F74
_08067968: .4byte 0x0300137C
_0806796C:
	ldr r0, _0806798C @ =0x04000008
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	movs r4, #0x3a
	ldrsh r1, [r2, r4]
	lsls r0, r0, #0xb
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, _08067990 @ =0x06000080
	adds r0, r0, r1
	strh r3, [r0]
_08067986:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806798C: .4byte 0x04000008
_08067990: .4byte 0x06000080
	.syntax divided
