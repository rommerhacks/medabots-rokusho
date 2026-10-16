	.syntax unified

	thumb_func_start sub_0803DC8C
sub_0803DC8C: @ 0x0803DC8C
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_08043CA8
	movs r4, #0
	str r4, [sp]
	ldr r1, _0803DCD4 @ =0x05000200
	ldr r5, _0803DCD8 @ =0x01000080
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r5, #0
	bl CpuFastSet
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	movs r0, #3
	bl sub_08044CDC
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803DCD4: .4byte 0x05000200
_0803DCD8: .4byte 0x01000080
	.syntax divided
