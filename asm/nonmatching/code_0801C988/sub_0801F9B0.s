	.syntax unified

	thumb_func_start sub_0801F9B0
sub_0801F9B0: @ 0x0801F9B0
	push {lr}
	movs r0, #0xa
	movs r1, #0
	bl medal_update_exp_progress
	movs r0, #0xb
	movs r1, #1
	bl medal_update_exp_progress
	cmp r0, #0
	beq _0801F9DE
	movs r0, #0x2a
	bl play_sound_effect
	ldr r0, _0801F9E4 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x5a
	strh r1, [r0]
	ldr r1, _0801F9E8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801F9DE:
	pop {r0}
	bx r0
	.align 2, 0
_0801F9E4: .4byte 0x03000440
_0801F9E8: .4byte 0x03001800
	.syntax divided
