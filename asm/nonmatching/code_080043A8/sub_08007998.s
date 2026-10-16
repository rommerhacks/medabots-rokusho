	.syntax unified

	thumb_func_start sub_08007998
sub_08007998: @ 0x08007998
	push {lr}
	bl sub_080093F8
	bl sub_0800994C
	ldr r0, _080079C4 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x18
	bl sub_08041C14
	bl update_blend_effect
	cmp r0, #0
	beq _080079BE
	ldr r1, _080079C8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080079BE:
	pop {r0}
	bx r0
	.align 2, 0
_080079C4: .4byte 0x03001780
_080079C8: .4byte 0x0300137C
	.syntax divided
