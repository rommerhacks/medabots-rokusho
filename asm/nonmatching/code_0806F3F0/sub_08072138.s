	.syntax unified

	thumb_func_start sub_08072138
sub_08072138: @ 0x08072138
	push {r4, r5, lr}
	sub sp, #0x34
	ldr r1, _080721DC @ =0x080AFFA8
	add r0, sp, #0x20
	movs r2, #0xd
	bl memcpy_optimized
	ldr r3, _080721E0 @ =0x03002C30
	adds r0, r3, #0
	adds r0, #0x84
	movs r5, #0
	movs r2, #0
	movs r1, #0xc8
	strh r1, [r0]
	adds r0, #0x40
	strh r1, [r0]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r1, [r0]
	adds r4, #0x40
	adds r0, r3, r4
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x30]
	ldr r1, _080721E4 @ =0x040000D4
	add r0, sp, #0x30
	str r0, [r1]
	ldr r0, _080721E8 @ =0x03002414
	ldr r0, [r0]
	ldr r3, _080721EC @ =0x00000B84
	adds r0, r0, r3
	str r0, [r1, #4]
	ldr r0, _080721F0 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x2a
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	movs r0, #0x42
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r2, [sp, #0x1c]
	movs r0, #0
	movs r1, #0x2a
	movs r2, #0x2a
	movs r3, #0x2a
	bl setup_scene_with_bg_and_sprites
	ldr r4, _080721F4 @ =0x03001800
	ldrb r1, [r4, #0x12]
	mov r0, sp
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #1
	beq _080721F8
	cmp r0, #1
	bgt _0807220C
	cmp r0, #0
	bne _0807220C
	adds r0, r1, #1
	mov r2, sp
	adds r2, r2, r0
	adds r2, #0x20
	ldrb r0, [r4, #0x11]
	adds r1, r0, #1
	strb r1, [r4, #0x11]
	ldrb r1, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	bhs _0807220C
	b _08072204
	.align 2, 0
_080721DC: .4byte 0x080AFFA8
_080721E0: .4byte 0x03002C30
_080721E4: .4byte 0x040000D4
_080721E8: .4byte 0x03002414
_080721EC: .4byte 0x00000B84
_080721F0: .4byte 0x85000100
_080721F4: .4byte 0x03001800
_080721F8:
	adds r0, r1, #1
	add r0, sp
	adds r0, #0x20
	ldrb r0, [r0]
	bl play_sound_effect
_08072204:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x11]
_0807220C:
	movs r0, #0
	movs r1, #0x2d
	movs r2, #0
	bl advance_text_display
	cmp r0, #0
	bne _0807221E
	movs r0, #0
	b _08072226
_0807221E:
	ldr r1, _08072230 @ =0x03001800
	movs r0, #0
	strb r0, [r1, #0x10]
	movs r0, #1
_08072226:
	add sp, #0x34
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08072230: .4byte 0x03001800
	.syntax divided
