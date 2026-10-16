	.syntax unified

	thumb_func_start sub_08013FA8
sub_08013FA8: @ 0x08013FA8
	push {r4, r5, lr}
	sub sp, #0xc
	bl sub_080182D0
	bl animate_bg_window_blink
	bl setup_scene_bg_from_game_state
	bl setup_battle_bot_display
	ldr r0, _0801402C @ =0x03001780
	ldrb r4, [r0]
	bl sub_0801827C
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #8
	adds r1, r4, #0
	bl sub_08041C14
	bl sub_080182AC
	bl update_blend_effect
	cmp r0, #0
	beq _08014022
	ldr r0, _08014030 @ =0x03000440
	adds r0, #0x96
	movs r4, #0
	strb r4, [r0]
	ldr r0, _08014034 @ =0x03000430
	str r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldr r0, _08014038 @ =0x03002414
	ldr r1, [r0]
	ldr r0, _0801403C @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _08014040 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, _08014044 @ =0x05000200
	ldr r5, _08014048 @ =0x01000080
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #8]
	add r0, sp, #8
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r5, #0
	bl CpuFastSet
	ldr r1, _0801404C @ =0x0300137C
	movs r0, #0x3c
	str r0, [r1]
_08014022:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801402C: .4byte 0x03001780
_08014030: .4byte 0x03000440
_08014034: .4byte 0x03000430
_08014038: .4byte 0x03002414
_0801403C: .4byte 0x00000B84
_08014040: .4byte 0x01000100
_08014044: .4byte 0x05000200
_08014048: .4byte 0x01000080
_0801404C: .4byte 0x0300137C
	.syntax divided
