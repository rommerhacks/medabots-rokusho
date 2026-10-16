	.syntax unified

	thumb_func_start sub_08026924
sub_08026924: @ 0x08026924
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _08026954 @ =0x084D1824
	ldr r1, _08026958 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0802695C @ =0x0850E018
	ldr r1, _08026960 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08026964 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08026968
	movs r1, #0xac
	lsls r1, r1, #1
	b _0802696C
	.align 2, 0
_08026954: .4byte 0x084D1824
_08026958: .4byte 0x06010000
_0802695C: .4byte 0x0850E018
_08026960: .4byte 0x050003C0
_08026964: .4byte 0x03001800
_08026968:
	movs r1, #0xaa
	lsls r1, r1, #1
_0802696C:
	adds r0, r2, r1
	ldrh r5, [r0]
	adds r1, #2
	adds r0, r2, r1
	ldrh r6, [r0]
	ldr r4, _08026A1C @ =0x030004DE
	ldr r7, _08026A20 @ =0x03001800
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	lsls r5, r5, #0x10
	mov r8, r5
	mov r0, r8
	asrs r0, r0, #0x10
	mov r8, r0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	str r6, [sp]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	mov r3, r8
	bl setup_battle_sprite_oam_entries
	adds r5, r4, #0
	adds r5, #0x14
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #1
	bl set_display_digit_type
	str r6, [sp]
	adds r0, r5, #0
	movs r1, #0xe
	movs r2, #1
	mov r3, r8
	bl setup_battle_sprite_oam_entries
	adds r5, #0x14
	adds r0, r7, #0
	adds r0, #0xda
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #1
	bl set_display_digit_type
	str r6, [sp]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #2
	mov r3, r8
	bl setup_battle_sprite_oam_entries
	adds r4, #0x3c
	adds r0, r7, #0
	adds r0, #0xdc
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	str r6, [sp]
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	mov r3, r8
	bl setup_battle_sprite_oam_entries
	movs r0, #0x5b
	bl play_sound_effect
	adds r1, r7, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026A1C: .4byte 0x030004DE
_08026A20: .4byte 0x03001800
	.syntax divided
