	.syntax unified

	thumb_func_start sub_0806086C
sub_0806086C: @ 0x0806086C
	push {lr}
	ldr r0, _08060888 @ =0x03006F74
	ldr r2, [r0]
	ldrb r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _08060890
	ldr r1, _0806088C @ =0x04000054
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	strh r0, [r1]
	b _080608A4
	.align 2, 0
_08060888: .4byte 0x03006F74
_0806088C: .4byte 0x04000054
_08060890:
	strh r1, [r2, #2]
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _080608B0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080608A4:
	bl update_battle_sprite_animation
	bl update_animation_timer
	pop {r0}
	bx r0
	.align 2, 0
_080608B0: .4byte 0x0300137C
	.syntax divided
