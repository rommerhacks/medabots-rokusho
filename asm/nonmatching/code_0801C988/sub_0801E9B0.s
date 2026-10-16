	.syntax unified

	thumb_func_start sub_0801E9B0
sub_0801E9B0: @ 0x0801E9B0
	push {r4, lr}
	ldr r4, _0801E9D8 @ =0x0300052E
	adds r0, r4, #0
	movs r1, #0xa
	bl advance_sprite_group_anims
	cmp r0, #0
	beq _0801E9D2
	adds r1, r4, #0
	subs r1, #0x68
	movs r0, #0x3c
	strh r0, [r1]
	ldr r1, _0801E9DC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801E9D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E9D8: .4byte 0x0300052E
_0801E9DC: .4byte 0x03001800
	.syntax divided
