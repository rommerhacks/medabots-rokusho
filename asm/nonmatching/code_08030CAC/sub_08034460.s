	.syntax unified

	thumb_func_start sub_08034460
sub_08034460: @ 0x08034460
	push {lr}
	bl sub_08022CA8
	ldr r0, _08034478 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034474
	bl sub_08034F08
_08034474:
	pop {r0}
	bx r0
	.align 2, 0
_08034478: .4byte 0x03001800
	.syntax divided
