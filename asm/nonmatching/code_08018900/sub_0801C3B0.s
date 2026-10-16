	.syntax unified

	thumb_func_start sub_0801C3B0
sub_0801C3B0: @ 0x0801C3B0
	push {r4, r5, lr}
	ldr r4, _0801C3E4 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl animate_battle_sprites
	ldrb r0, [r5]
	bl render_bot_name_sprites
	ldrb r0, [r5]
	bl sub_0801AD10
	adds r0, r4, #0
	adds r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801C3E8
	adds r1, r4, #0
	adds r1, #0x9e
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	adds r0, #1
	b _0801C3EE
	.align 2, 0
_0801C3E4: .4byte 0x03001800
_0801C3E8:
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #5
_0801C3EE:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
