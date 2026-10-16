	.syntax unified

	thumb_func_start sub_0801CDB4
sub_0801CDB4: @ 0x0801CDB4
	push {lr}
	movs r0, #0x21
	movs r1, #4
	bl update_sprite_animations_tick_080370AC
	cmp r0, #0
	beq _0801CDCC
	ldr r1, _0801CDD0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801CDCC:
	pop {r0}
	bx r0
	.align 2, 0
_0801CDD0: .4byte 0x03001800
	.syntax divided
