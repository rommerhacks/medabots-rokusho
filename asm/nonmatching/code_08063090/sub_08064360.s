	.syntax unified

	thumb_func_start sub_08064360
sub_08064360: @ 0x08064360
	push {r4, lr}
	bl fade_update_tilemap_copy
	ldr r4, _080643A4 @ =0x03006F74
	ldr r0, [r4]
	movs r1, #0x3a
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0806439C
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl text_window_init
	ldr r1, _080643A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r4]
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #5
	cmp r0, #0
	beq _08064396
	movs r1, #0xe
_08064396:
	adds r0, r1, #0
	bl play_sound_effect
_0806439C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080643A4: .4byte 0x03006F74
_080643A8: .4byte 0x0300137C
	.syntax divided
