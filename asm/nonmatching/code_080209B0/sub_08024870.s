	.syntax unified

	thumb_func_start sub_08024870
sub_08024870: @ 0x08024870
	push {lr}
	movs r0, #0x21
	movs r1, #4
	bl update_sprite_animations_tick_080370AC
	cmp r0, #0
	beq _08024888
	ldr r1, _0802488C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08024888:
	pop {r0}
	bx r0
	.align 2, 0
_0802488C: .4byte 0x03001800
	.syntax divided
