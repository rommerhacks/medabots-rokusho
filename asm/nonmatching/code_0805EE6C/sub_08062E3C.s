	.syntax unified

	thumb_func_start sub_08062E3C
sub_08062E3C: @ 0x08062E3C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x14
	bl sub_08074B68
	cmp r0, #0x18
	beq _08062E54
	movs r0, #0x18
	bl play_song
_08062E54:
	movs r0, #0
	mov sb, r0
	str r0, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08063010 @ =0x01006000
	add r0, sp, #0x10
	bl CpuFastSet
	bl sub_080415BC
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r1, #0x80
	lsls r1, r1, #0x13
	mov r8, r1
	movs r0, #0x60
	strh r0, [r1]
	adds r1, #0x50
	ldr r2, _08063014 @ =0x000002FF
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x4a
	ldr r2, _08063018 @ =0x00001E05
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, _0806301C @ =0x0400000C
	ldr r2, _08063020 @ =0x00001B06
	adds r0, r2, #0
	strh r0, [r4]
	ldr r5, _08063024 @ =0x0400000E
	ldr r2, _08063028 @ =0x00003C07
	adds r0, r2, #0
	strh r0, [r5]
	ldr r0, _0806302C @ =0x0879DDCC
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _08063030 @ =0x0879DF44
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _08063034 @ =0x0879E1DC
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r1, _08063038 @ =0x00001D06
	adds r0, r1, #0
	strh r0, [r4]
	ldr r0, _0806303C @ =0x0879C89C
	ldr r6, _08063040 @ =0x02030000
	adds r1, r6, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r5, _08063044 @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r6, #0
	adds r1, r5, #0
	bl CpuSet
	ldr r0, _08063048 @ =0x08784CB0
	adds r5, r4, r5
	adds r1, r5, #0
	bl lz_decompress_dispatch
	ldr r5, _0806304C @ =0x03006F74
	ldr r0, [r5]
	lsrs r4, r4, #5
	subs r4, #1
	strh r4, [r0, #0x36]
	ldr r0, _08063050 @ =0x0879C69C
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	bl CpuFastSet
	ldr r4, _08063054 @ =0x0850DD78
	ldr r1, _08063058 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0806305C @ =0x0202F9A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08063060 @ =0x08784DA4
	ldr r1, _08063064 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _08063068 @ =0x084C6A98
	ldr r1, _0806306C @ =0x06011E00
	bl lz_decompress_dispatch
	ldr r1, [r5]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r1, #0x3a]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0
	bl sub_08062A74
	ldr r0, _08063070 @ =0x030004DE
	movs r1, #0x10
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #0
	movs r2, #0
	movs r3, #0xa
	bl render_text_string_to_sprites
	movs r0, #0
	bl init_scene_rendering_context
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	bl update_animated_tilemap
	ldr r0, [r5]
	adds r0, #0x50
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0x10
	movs r2, #0
	bl init_blend_effect
	ldr r1, _08063074 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r2]
	ldr r0, _08063078 @ =0x0000085C
	adds r2, r1, r0
	movs r0, #2
	strb r0, [r2]
	ldr r0, _0806307C @ =0x00000842
	adds r2, r1, r0
	movs r0, #0x28
	strh r0, [r2]
	ldr r0, _08063080 @ =0x00000844
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _08063084 @ =0x0000084A
	adds r2, r1, r0
	movs r0, #8
	strb r0, [r2]
	ldr r2, _08063088 @ =0x00000846
	adds r1, r1, r2
	movs r0, #0x2a
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	ldr r1, _0806308C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08063010: .4byte 0x01006000
_08063014: .4byte 0x000002FF
_08063018: .4byte 0x00001E05
_0806301C: .4byte 0x0400000C
_08063020: .4byte 0x00001B06
_08063024: .4byte 0x0400000E
_08063028: .4byte 0x00003C07
_0806302C: .4byte 0x0879DDCC
_08063030: .4byte 0x0879DF44
_08063034: .4byte 0x0879E1DC
_08063038: .4byte 0x00001D06
_0806303C: .4byte 0x0879C89C
_08063040: .4byte 0x02030000
_08063044: .4byte 0x06004000
_08063048: .4byte 0x08784CB0
_0806304C: .4byte 0x03006F74
_08063050: .4byte 0x0879C69C
_08063054: .4byte 0x0850DD78
_08063058: .4byte 0x050003A0
_0806305C: .4byte 0x0202F9A0
_08063060: .4byte 0x08784DA4
_08063064: .4byte 0x06010000
_08063068: .4byte 0x084C6A98
_0806306C: .4byte 0x06011E00
_08063070: .4byte 0x030004DE
_08063074: .4byte 0x03002C30
_08063078: .4byte 0x0000085C
_0806307C: .4byte 0x00000842
_08063080: .4byte 0x00000844
_08063084: .4byte 0x0000084A
_08063088: .4byte 0x00000846
_0806308C: .4byte 0x0300137C
	.syntax divided
