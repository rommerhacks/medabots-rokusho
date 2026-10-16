	.syntax unified

	thumb_func_start update_fade_in_blend_effect
update_fade_in_blend_effect: @ 0x080634CC
	push {r4, lr}
	ldr r0, _08063508 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #0x3c]
	adds r1, r0, #1
	strh r1, [r2, #0x3c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x10
	bgt _08063514
	ldr r0, _0806350C @ =0x00007FFF
	movs r1, #0x20
	movs r2, #0xff
	bl blend_obj_palettes_to_color_0803F998
	ldr r1, _08063510 @ =0x04000050
	movs r2, #0xe5
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	subs r0, r0, r4
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	b _08063544
	.align 2, 0
_08063508: .4byte 0x03006F74
_0806350C: .4byte 0x00007FFF
_08063510: .4byte 0x04000050
_08063514:
	ldr r1, _08063574 @ =0x04000050
	movs r3, #0xe1
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	subs r0, r0, r4
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	movs r1, #0
	movs r0, #0
	strh r0, [r2, #0x3c]
	ldr r0, _08063578 @ =0x03000440
	adds r0, #0x84
	strb r1, [r0]
	ldr r1, _0806357C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08063544:
	ldr r4, _08063580 @ =0x03006F74
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	ldrb r1, [r1]
	movs r2, #1
	bl load_medapart_sprite_animation
	bl update_animated_tilemap
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08063574: .4byte 0x04000050
_08063578: .4byte 0x03000440
_0806357C: .4byte 0x0300137C
_08063580: .4byte 0x03006F74
	.syntax divided
