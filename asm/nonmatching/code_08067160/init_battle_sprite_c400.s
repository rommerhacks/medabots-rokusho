	.syntax unified

	thumb_func_start init_battle_sprite_c400
init_battle_sprite_c400: @ 0x08069CE4
	push {lr}
	sub sp, #4
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x82
	lsls r2, r2, #1
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r3, #0xc
	bl init_battle_sprite_entry_08048818
	ldr r1, _08069D2C @ =0x03002C30
	movs r2, #0
	movs r0, #0x78
	strh r0, [r1, #2]
	ldr r0, _08069D30 @ =0x0000FFF0
	strh r0, [r1, #4]
	strh r2, [r1, #0x1a]
	ldr r0, _08069D34 @ =0x040000D4
	ldr r2, _08069D38 @ =0x0807C280
	str r2, [r0]
	ldr r1, _08069D3C @ =0x05000380
	str r1, [r0, #4]
	ldr r3, _08069D40 @ =0x84000008
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	adds r2, #0x60
	str r2, [r0]
	ldr r1, _08069D44 @ =0x05000360
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08069D2C: .4byte 0x03002C30
_08069D30: .4byte 0x0000FFF0
_08069D34: .4byte 0x040000D4
_08069D38: .4byte 0x0807C280
_08069D3C: .4byte 0x05000380
_08069D40: .4byte 0x84000008
_08069D44: .4byte 0x05000360
	.syntax divided
