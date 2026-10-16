	.syntax unified

	thumb_func_start apply_battle_blend_effect_a
	.global apply_battle_blend_effect_a
apply_battle_blend_effect_a: @ 0x08043DF8
	push {lr}
	ldr r3, _08043E28 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043E38
	ldr r2, _08043E2C @ =0x04000052
	adds r0, r3, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r0, #1
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08043E30 @ =0x04000054
	movs r0, #0
	strh r0, [r1]
	subs r1, #4
	ldr r2, _08043E34 @ =0x00001844
	adds r0, r2, #0
	strh r0, [r1]
	b _08043E42
	.align 2, 0
_08043E28: .4byte 0x03001800
_08043E2C: .4byte 0x04000052
_08043E30: .4byte 0x04000054
_08043E34: .4byte 0x00001844
_08043E38:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl set_blend_effect_mode
_08043E42:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
