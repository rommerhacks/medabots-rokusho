	.syntax unified

	thumb_func_start setup_scene_from_game_state
	.global setup_scene_from_game_state
setup_scene_from_game_state: @ 0x08018180
	push {r4, r5, r6, lr}
	sub sp, #0x24
	ldr r1, _080181F8 @ =0x02026000
	ldr r0, _080181FC @ =0x020260D0
	str r0, [r1, #8]
	ldr r5, _08018200 @ =0x03002414
	ldr r0, [r5]
	ldr r6, _08018204 @ =0x00000B84
	adds r0, r0, r6
	ldr r2, _08018208 @ =0x03000440
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
	movs r4, #0x28
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r4, #0xe1
	lsls r4, r4, #1
	str r4, [sp, #0x10]
	movs r4, #8
	str r4, [sp, #0x14]
	movs r4, #1
	str r4, [sp, #0x18]
	movs r4, #0
	str r4, [sp, #0x1c]
	bl setup_scene_bg_layers_and_sprites
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r1, [r5]
	adds r1, r1, r6
	ldr r2, _0801820C @ =0x01000100
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, [r5]
	ldr r1, _08018210 @ =0x00001094
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r2, _08018214 @ =0x00001095
	adds r0, r0, r2
	strb r4, [r0]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080181F8: .4byte 0x02026000
_080181FC: .4byte 0x020260D0
_08018200: .4byte 0x03002414
_08018204: .4byte 0x00000B84
_08018208: .4byte 0x03000440
_0801820C: .4byte 0x01000100
_08018210: .4byte 0x00001094
_08018214: .4byte 0x00001095
	.syntax divided
