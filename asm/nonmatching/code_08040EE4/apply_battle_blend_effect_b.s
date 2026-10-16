	.syntax unified

	thumb_func_start apply_battle_blend_effect_b
	.global apply_battle_blend_effect_b
apply_battle_blend_effect_b: @ 0x08043F9C
	push {lr}
	ldr r3, _08043FCC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x77
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043FDC
	ldr r2, _08043FD0 @ =0x04000052
	adds r0, r3, #0
	adds r0, #0x78
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r0, #1
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08043FD4 @ =0x04000054
	movs r0, #0
	strh r0, [r1]
	subs r1, #4
	ldr r2, _08043FD8 @ =0x00001844
	adds r0, r2, #0
	strh r0, [r1]
	b _08043FE6
	.align 2, 0
_08043FCC: .4byte 0x03001800
_08043FD0: .4byte 0x04000052
_08043FD4: .4byte 0x04000054
_08043FD8: .4byte 0x00001844
_08043FDC:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl set_blend_effect_mode
_08043FE6:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
