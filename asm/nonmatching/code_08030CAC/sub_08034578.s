	.syntax unified

	thumb_func_start sub_08034578
sub_08034578: @ 0x08034578
	push {lr}
	bl dispatch_battle_action_step
	ldr r0, _08034590 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803458C
	bl sub_08034F08
_0803458C:
	pop {r0}
	bx r0
	.align 2, 0
_08034590: .4byte 0x03001800
	.syntax divided
