	.syntax unified

	thumb_func_start init_battle_sprite_entry_08048818
	.global init_battle_sprite_entry_08048818
init_battle_sprite_entry_08048818: @ 0x08048818
	push {r4, r5, lr}
	ldr r5, [sp, #0xc]
	lsls r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08048838 @ =0x03002C30
	lsrs r0, r0, #0x12
	adds r0, r0, r4
	strh r1, [r0]
	strh r1, [r0, #0x32]
	strh r2, [r0, #6]
	strb r3, [r0, #0xa]
	strb r5, [r0, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08048838: .4byte 0x03002C30
	.syntax divided
