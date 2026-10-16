	.syntax unified

	thumb_func_start sub_0801CC24
sub_0801CC24: @ 0x0801CC24
	push {lr}
	movs r0, #0x21
	movs r1, #0x3c
	movs r2, #0x84
	bl sprite_move_toward_target
	cmp r0, #0
	beq _0801CC4C
	movs r0, #0x41
	bl play_sound_effect
	ldr r0, _0801CC50 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0801CC54 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801CC4C:
	pop {r0}
	bx r0
	.align 2, 0
_0801CC50: .4byte 0x03000440
_0801CC54: .4byte 0x03001800
	.syntax divided
