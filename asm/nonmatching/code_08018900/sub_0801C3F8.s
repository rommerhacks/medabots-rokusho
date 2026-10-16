	.syntax unified

	thumb_func_start sub_0801C3F8
sub_0801C3F8: @ 0x0801C3F8
	push {lr}
	ldr r0, _0801C408 @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl animate_battle_sprites
	pop {r0}
	bx r0
	.align 2, 0
_0801C408: .4byte 0x03001800
	.syntax divided
