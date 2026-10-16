	.syntax unified

	thumb_func_start sub_080633E4
sub_080633E4: @ 0x080633E4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x30
	ldr r5, _080634B8 @ =0x0202F880
	ldr r4, _080634BC @ =0x0202F800
	movs r6, #3
_080633F4:
	adds r0, r4, #0
	add r1, sp, #0x10
	movs r2, #8
	bl CpuFastSet
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	add r0, sp, #0x10
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	adds r5, #0x20
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _080633F4
	ldr r1, _080634C0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r4, _080634C4 @ =0x03006F74
	ldr r0, [r4]
	movs r1, #0
	mov sb, r1
	movs r1, #1
	mov r8, r1
	mov r1, r8
	strh r1, [r0, #0x3c]
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0
	bl sub_08062A74
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #1
	bl sub_08062A74
	ldr r4, _080634C8 @ =0x030004DE
	movs r6, #0x10
	str r6, [sp]
	movs r5, #0xd
	str r5, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xa
	bl render_text_string_to_sprites
	adds r4, #0x14
	str r6, [sp]
	str r5, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0xe
	movs r3, #0xa
	bl render_text_string_to_sprites
	movs r0, #0x2a
	bl play_sound_effect
	bl update_animated_tilemap
	add sp, #0x30
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080634B8: .4byte 0x0202F880
_080634BC: .4byte 0x0202F800
_080634C0: .4byte 0x0300137C
_080634C4: .4byte 0x03006F74
_080634C8: .4byte 0x030004DE
	.syntax divided
