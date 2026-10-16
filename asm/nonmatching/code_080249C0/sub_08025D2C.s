	.syntax unified

	thumb_func_start sub_08025D2C
sub_08025D2C: @ 0x08025D2C
	push {lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	cmp r0, #0
	beq _08025D42
	ldr r1, _08025D48 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08025D42:
	pop {r0}
	bx r0
	.align 2, 0
_08025D48: .4byte 0x03001800
	.syntax divided
