	.syntax unified

	thumb_func_start sub_0801C388
sub_0801C388: @ 0x0801C388
	push {r4, r5, lr}
	ldr r4, _0801C3AC @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl animate_battle_sprites
	ldrb r0, [r5]
	bl sub_0801AC98
	adds r4, #0x9c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C3AC: .4byte 0x03001800
	.syntax divided
