	.syntax unified

	thumb_func_start setup_scene_bg_from_game_state
	.global setup_scene_bg_from_game_state
setup_scene_bg_from_game_state: @ 0x08018218
	push {r4, lr}
	sub sp, #0x20
	ldr r0, _0801826C @ =0x03002414
	ldr r0, [r0]
	ldr r1, _08018270 @ =0x00000B84
	adds r0, r0, r1
	ldr r1, _08018274 @ =0x02026000
	ldr r2, _08018278 @ =0x03000440
	mov ip, r2
	adds r2, #0x98
	ldrb r2, [r2]
	mov r3, ip
	adds r3, #0x99
	ldrb r3, [r3]
	mov r4, ip
	adds r4, #0x9a
	ldrb r4, [r4]
	str r4, [sp]
	mov r4, ip
	adds r4, #0x9b
	ldrb r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x44
	str r4, [sp, #8]
	movs r4, #0x2a
	str r4, [sp, #0xc]
	movs r4, #0xe1
	lsls r4, r4, #1
	str r4, [sp, #0x10]
	movs r4, #8
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	movs r4, #0
	str r4, [sp, #0x1c]
	bl setup_scene_bg_layers_and_sprites
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801826C: .4byte 0x03002414
_08018270: .4byte 0x00000B84
_08018274: .4byte 0x02026000
_08018278: .4byte 0x03000440
	.syntax divided
