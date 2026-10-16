	.syntax unified

	thumb_func_start update_battle_sprite_scroll
update_battle_sprite_scroll: @ 0x0800B814
	push {r4, lr}
	ldr r4, _0800B84C @ =0x03002C30
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r1, [r0]
	subs r1, #8
	strb r1, [r0]
	ldr r0, _0800B850 @ =0x000001C9
	adds r2, r4, r0
	ldrb r0, [r2]
	subs r0, #8
	strb r0, [r2]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _0800B846
	movs r0, #7
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r0, _0800B854 @ =0x000001E9
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800B846:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B84C: .4byte 0x03002C30
_0800B850: .4byte 0x000001C9
_0800B854: .4byte 0x000001E9
	.syntax divided
