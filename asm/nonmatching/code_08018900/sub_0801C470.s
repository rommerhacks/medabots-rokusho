	.syntax unified

	thumb_func_start sub_0801C470
sub_0801C470: @ 0x0801C470
	push {r4, r5, lr}
	ldr r4, _0801C4A0 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl animate_battle_sprites
	ldrb r0, [r5]
	bl sub_0801AE70
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl sub_0801AC98
	adds r1, r4, #0
	adds r1, #0x9c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C4A0: .4byte 0x03001800
	.syntax divided
