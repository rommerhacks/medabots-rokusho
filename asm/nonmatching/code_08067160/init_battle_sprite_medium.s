	.syntax unified

	thumb_func_start init_battle_sprite_medium
init_battle_sprite_medium: @ 0x08069C88
	push {lr}
	sub sp, #4
	ldr r1, _08069CCC @ =0x0000C404
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #3
	str r0, [sp]
	movs r0, #1
	movs r3, #1
	bl init_battle_sprite_entry_08048818
	ldr r3, _08069CD0 @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0x42
	movs r2, #0
	movs r0, #0x28
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x5a
	strh r2, [r0]
	ldr r1, _08069CD4 @ =0x040000D4
	ldr r0, _08069CD8 @ =0x0807C260
	str r0, [r1]
	ldr r0, _08069CDC @ =0x05000220
	str r0, [r1, #4]
	ldr r0, _08069CE0 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08069CCC: .4byte 0x0000C404
_08069CD0: .4byte 0x03002C30
_08069CD4: .4byte 0x040000D4
_08069CD8: .4byte 0x0807C260
_08069CDC: .4byte 0x05000220
_08069CE0: .4byte 0x84000008
	.syntax divided
