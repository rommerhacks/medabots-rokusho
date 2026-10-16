	.syntax unified

	thumb_func_start iterate_bots_setup_battle_sprites
	.global iterate_bots_setup_battle_sprites
iterate_bots_setup_battle_sprites: @ 0x0801A0D0
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r1, _0801A10C @ =0x03000590
	ldr r0, _0801A110 @ =0x03002C30
	ldr r2, _0801A114 @ =0x00001742
	adds r4, r0, r2
	adds r6, r1, #0
	adds r6, #0x40
_0801A0E0:
	ldrb r0, [r6]
	cmp r0, #0
	beq _0801A0F6
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #2
	ldrsh r2, [r4, r0]
	subs r2, #4
	adds r0, r5, #0
	bl setup_bot_battle_sprites_08015A00
_0801A0F6:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r4, r4, r2
	adds r6, r6, r2
	adds r5, #1
	cmp r5, #5
	bls _0801A0E0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801A10C: .4byte 0x03000590
_0801A110: .4byte 0x03002C30
_0801A114: .4byte 0x00001742
_0801A118:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x0D, 0x1C, 0x00, 0x2A
	.byte 0x01, 0xD0, 0x0B, 0x20, 0x00, 0xE0, 0x0A, 0x20, 0x20, 0x70, 0x28, 0x1C, 0x0A, 0x21, 0x62, 0xF0
	.byte 0x13, 0xFE, 0x60, 0x70, 0x28, 0x1C, 0x0A, 0x21, 0x62, 0xF0, 0x4A, 0xFE, 0xA0, 0x70, 0x30, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47
	.syntax divided
