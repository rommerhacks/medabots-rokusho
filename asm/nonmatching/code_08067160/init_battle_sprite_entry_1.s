	.syntax unified

	thumb_func_start init_battle_sprite_entry_1
init_battle_sprite_entry_1: @ 0x08069D48
	push {lr}
	sub sp, #4
	ldr r1, _08069D94 @ =0x0000C808
	ldr r2, _08069D98 @ =0x0000010B
	movs r0, #3
	str r0, [sp]
	movs r0, #1
	movs r3, #3
	bl init_battle_sprite_entry_08048818
	ldr r1, _08069D9C @ =0x03002C30
	adds r2, r1, #0
	adds r2, #0x44
	movs r3, #0
	movs r0, #0x40
	strh r0, [r2]
	adds r1, #0x5a
	strh r3, [r1]
	ldr r1, _08069DA0 @ =0x040000D4
	ldr r0, _08069DA4 @ =0x0807C2C0
	str r0, [r1]
	ldr r0, _08069DA8 @ =0x05000260
	str r0, [r1, #4]
	ldr r0, _08069DAC @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0x84
	movs r2, #0xc4
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	strh r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08069D94: .4byte 0x0000C808
_08069D98: .4byte 0x0000010B
_08069D9C: .4byte 0x03002C30
_08069DA0: .4byte 0x040000D4
_08069DA4: .4byte 0x0807C2C0
_08069DA8: .4byte 0x05000260
_08069DAC: .4byte 0x84000008
	.syntax divided
