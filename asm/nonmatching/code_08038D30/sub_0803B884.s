	.syntax unified

	thumb_func_start sub_0803B884
sub_0803B884: @ 0x0803B884
	push {r4, r5, lr}
	movs r2, #0
	ldr r0, _0803B8BC @ =0x03002C30
	ldr r5, _0803B8C0 @ =0x03001988
	movs r4, #0
	ldr r3, _0803B8C4 @ =0x000002A3
	adds r1, r0, r3
	movs r3, #0x3a
_0803B894:
	adds r0, r2, r5
	ldrb r0, [r0]
	strb r0, [r1, #5]
	strb r4, [r1]
	strb r3, [r1, #6]
	adds r0, r2, #0
	adds r0, #0x56
	strb r0, [r1, #3]
	adds r1, #0x40
	adds r2, #1
	cmp r2, #1
	bls _0803B894
	movs r0, #0x10
	bl play_sound_effect
	bl battle_advance_sequence_counter
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B8BC: .4byte 0x03002C30
_0803B8C0: .4byte 0x03001988
_0803B8C4: .4byte 0x000002A3
	.syntax divided
