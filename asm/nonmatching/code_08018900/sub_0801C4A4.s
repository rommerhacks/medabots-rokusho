	.syntax unified

	thumb_func_start sub_0801C4A4
sub_0801C4A4: @ 0x0801C4A4
	push {r4, r5, lr}
	ldr r5, _0801C4DC @ =0x03001800
	adds r4, r5, #0
	adds r4, #0x87
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r0, [r4]
	bl sub_0801AE70
	adds r4, #1
	ldrb r0, [r4]
	bl render_bot_name_sprites
	ldrb r0, [r4]
	bl sub_0801AD10
	adds r1, r5, #0
	adds r1, #0x9e
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C4DC: .4byte 0x03001800
	.syntax divided
