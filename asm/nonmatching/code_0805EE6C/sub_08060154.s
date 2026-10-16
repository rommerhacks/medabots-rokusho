	.syntax unified

	thumb_func_start sub_08060154
sub_08060154: @ 0x08060154
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08060198 @ =0x01006000
	mov r0, sp
	bl CpuFastSet
	bl reset_bg_scroll
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	adds r1, #0x50
	ldr r2, _0806019C @ =0x000002FF
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, _080601A0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08060198: .4byte 0x01006000
_0806019C: .4byte 0x000002FF
_080601A0: .4byte 0x0300137C
	.syntax divided
