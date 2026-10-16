	.syntax unified

	thumb_func_start sub_080630DC
sub_080630DC: @ 0x080630DC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r0, _08063140 @ =0x08485BD8
	ldr r0, [r0, #0x3c]
	bl run_message
	ldr r2, _08063144 @ =0x03005010
	ldr r6, _08063148 @ =0x03006F74
	ldr r0, [r6]
	mov ip, r0
	adds r0, #0x31
	ldrb r1, [r0]
	mov r0, ip
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r1, r0
	strh r1, [r2, #6]
	ldrh r3, [r2, #0xa]
	ldrh r2, [r2, #0xe]
	adds r5, r2, #0
	movs r4, #0xc0
	lsls r4, r4, #8
	adds r1, r3, #0
	ands r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bne _080631B4
	ands r2, r4
	cmp r2, r1
	bne _080631B4
	ldr r0, _0806314C @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063150
	movs r1, #0x7f
	adds r0, r3, #0
	ands r0, r1
	mov r1, ip
	adds r1, #0x32
	strb r0, [r1]
	ldr r2, [r6]
	lsrs r0, r3, #8
	b _08063160
	.align 2, 0
_08063140: .4byte 0x08485BD8
_08063144: .4byte 0x03005010
_08063148: .4byte 0x03006F74
_0806314C: .4byte 0x03000B90
_08063150:
	movs r1, #0x7f
	adds r0, r5, #0
	ands r0, r1
	mov r1, ip
	adds r1, #0x32
	strb r0, [r1]
	ldr r2, [r6]
	lsrs r0, r5, #8
_08063160:
	movs r1, #3
	ands r0, r1
	adds r2, #0x34
	strb r0, [r2]
	movs r0, #1
	bl init_scene_rendering_context
	ldr r0, _080631D0 @ =0x03006F74
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #1
	bl sub_08062A74
	ldr r0, _080631D4 @ =0x030004F2
	movs r1, #0x10
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #0x10
	movs r2, #0xe
	movs r3, #0xa
	bl render_text_string_to_sprites
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl text_window_init
	ldr r1, _080631D8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080631B4:
	ldr r0, _080631D0 @ =0x03006F74
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080631D0: .4byte 0x03006F74
_080631D4: .4byte 0x030004F2
_080631D8: .4byte 0x0300137C
	.syntax divided
