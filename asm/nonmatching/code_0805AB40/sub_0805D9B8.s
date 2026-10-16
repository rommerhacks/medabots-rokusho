	.syntax unified

	thumb_func_start sub_0805D9B8
sub_0805D9B8: @ 0x0805D9B8
	push {lr}
	ldr r0, _0805D9DC @ =0x08485BD8
	ldr r0, [r0, #0x48]
	bl run_message
	cmp r0, #0
	beq _0805D9D8
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r1, _0805D9E0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805D9D8:
	pop {r0}
	bx r0
	.align 2, 0
_0805D9DC: .4byte 0x08485BD8
_0805D9E0: .4byte 0x0300137C
	.syntax divided
