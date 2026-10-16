	.syntax unified

	thumb_func_start clear_battle_sprite_entry
	.global clear_battle_sprite_entry
clear_battle_sprite_entry: @ 0x0804883C
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r4, #6
	ldr r1, _0804885C @ =0x03002C30
	adds r0, r0, r1
	movs r1, #0x40
	bl sub_080496C8
	adds r0, r4, #0
	bl clear_entity_state
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804885C: .4byte 0x03002C30
	.syntax divided
