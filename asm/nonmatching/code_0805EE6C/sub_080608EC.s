	.syntax unified

	thumb_func_start sub_080608EC
sub_080608EC: @ 0x080608EC
	push {r4, r5, lr}
	bl update_battle_sprite_animation
	bl update_animation_timer
	bl sub_0805B7A0
	cmp r0, #0
	bne _08060978
	ldr r0, _08060924 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08060982
	ldr r0, _08060928 @ =0x03002B8C
	ldr r0, [r0]
	cmp r0, #0xa
	bne _08060930
	movs r0, #5
	bl play_sound_effect
	ldr r0, _0806092C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x48
	movs r1, #1
	strb r1, [r0]
	b _0806095E
	.align 2, 0
_08060924: .4byte 0x0300058C
_08060928: .4byte 0x03002B8C
_0806092C: .4byte 0x03006F74
_08060930:
	movs r5, #1
	adds r4, r5, #0
	ands r4, r1
	cmp r4, #0
	beq _08060950
	movs r0, #4
	bl play_sound_effect
	ldr r0, _0806094C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x48
	strb r5, [r0]
	b _0806095E
	.align 2, 0
_0806094C: .4byte 0x03006F74
_08060950:
	movs r0, #5
	bl play_sound_effect
	ldr r0, _08060970 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x48
	strb r4, [r0]
_0806095E:
	ldr r0, _08060970 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08060974 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08060980
	.align 2, 0
_08060970: .4byte 0x03006F74
_08060974: .4byte 0x0300137C
_08060978:
	bl sub_0803FB0C
	ldr r1, _08060988 @ =0x0300137C
	movs r0, #4
_08060980:
	str r0, [r1]
_08060982:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08060988: .4byte 0x0300137C
	.syntax divided
