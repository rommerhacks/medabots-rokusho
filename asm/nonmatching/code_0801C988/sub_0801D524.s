	.syntax unified

	thumb_func_start sub_0801D524
sub_0801D524: @ 0x0801D524
	push {lr}
	movs r0, #9
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0801D53A
	ldr r1, _0801D540 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801D53A:
	pop {r0}
	bx r0
	.align 2, 0
_0801D540: .4byte 0x03001800
	.syntax divided
