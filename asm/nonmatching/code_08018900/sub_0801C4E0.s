	.syntax unified

	thumb_func_start sub_0801C4E0
sub_0801C4E0: @ 0x0801C4E0
	push {r4, lr}
	ldr r4, _0801C4F8 @ =0x03001800
	adds r4, #0x87
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r0, [r4]
	bl sub_0801AE70
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C4F8: .4byte 0x03001800
	.syntax divided
