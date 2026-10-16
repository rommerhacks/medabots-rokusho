	.syntax unified

	thumb_func_start sub_0801FA68
sub_0801FA68: @ 0x0801FA68
	push {r4, r5, lr}
	sub sp, #8
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	ldr r5, _0801FAC0 @ =0x03001800
	ldr r2, _0801FAC4 @ =0x0000015F
	adds r1, r5, r2
	movs r4, #0
	strb r0, [r1]
	bl battle_advance_action_text
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0801FAC8 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	str r4, [sp]
	ldr r1, _0801FACC @ =0x05000120
	ldr r4, _0801FAD0 @ =0x01000008
	mov r0, sp
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801FAD4 @ =0x11111111
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r1, _0801FAD8 @ =0x06004120
	adds r2, r4, #0
	bl CpuFastSet
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FAC0: .4byte 0x03001800
_0801FAC4: .4byte 0x0000015F
_0801FAC8: .4byte 0x03000440
_0801FACC: .4byte 0x05000120
_0801FAD0: .4byte 0x01000008
_0801FAD4: .4byte 0x11111111
_0801FAD8: .4byte 0x06004120
	.syntax divided
