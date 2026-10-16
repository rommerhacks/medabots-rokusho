	.syntax unified

	thumb_func_start sub_0806904C
sub_0806904C: @ 0x0806904C
	push {lr}
	bl update_sprite_animations_tick_0806AF40
	bl update_sprite_animations_0806B334
	bl sub_0806A4C0
	cmp r0, #0
	beq _0806906A
	ldr r1, _08069070 @ =0x03006F88
	movs r0, #0
	str r0, [r1]
	ldr r1, _08069074 @ =0x0300137C
	movs r0, #9
	str r0, [r1]
_0806906A:
	pop {r0}
	bx r0
	.align 2, 0
_08069070: .4byte 0x03006F88
_08069074: .4byte 0x0300137C
	.syntax divided
