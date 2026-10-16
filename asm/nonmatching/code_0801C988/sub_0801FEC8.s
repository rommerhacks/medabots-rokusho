	.syntax unified

	thumb_func_start sub_0801FEC8
sub_0801FEC8: @ 0x0801FEC8
	push {lr}
	movs r0, #0x21
	movs r1, #8
	bl update_sprite_animations_tick_080370AC
	cmp r0, #0
	beq _0801FEE0
	ldr r1, _0801FEE4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801FEE0:
	pop {r0}
	bx r0
	.align 2, 0
_0801FEE4: .4byte 0x03001800
	.syntax divided
