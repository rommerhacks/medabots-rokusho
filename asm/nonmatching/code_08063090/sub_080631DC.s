	.syntax unified

	thumb_func_start sub_080631DC
sub_080631DC: @ 0x080631DC
	push {r4, lr}
	ldr r0, _0806326C @ =0x08485BD8
	ldr r0, [r0, #0x4c]
	bl run_message
	bl update_animated_tilemap
	ldr r4, _08063270 @ =0x03006F74
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
	ldr r2, [r4]
	ldrh r0, [r2, #0x3c]
	subs r0, #1
	strh r0, [r2, #0x3c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08063264
	ldr r0, _08063274 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08063278 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #1
	bl reduce_medapart_stat
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	ldrb r1, [r1]
	movs r2, #1
	bl medapart_add_quantity
	ldr r0, _0806327C @ =0x05000200
	ldr r1, _08063280 @ =0x0202F800
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	movs r0, #0x4b
	bl play_sound_effect
_08063264:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806326C: .4byte 0x08485BD8
_08063270: .4byte 0x03006F74
_08063274: .4byte 0x03000440
_08063278: .4byte 0x0300137C
_0806327C: .4byte 0x05000200
_08063280: .4byte 0x0202F800
	.syntax divided
