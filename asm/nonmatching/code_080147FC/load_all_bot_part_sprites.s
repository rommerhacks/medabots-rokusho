	.syntax unified

	thumb_func_start load_all_bot_part_sprites
	.global load_all_bot_part_sprites
load_all_bot_part_sprites: @ 0x080158F8
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _08015920 @ =0x03000590
	adds r5, r0, #0
	adds r5, #0x40
_08015902:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801590E
	adds r0, r4, #0
	bl load_bot_part_sprite
_0801590E:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _08015902
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08015920: .4byte 0x03000590
	.syntax divided
