	.syntax unified

	thumb_func_start sub_0807458C
sub_0807458C: @ 0x0807458C
	push {lr}
	ldr r0, _080745AC @ =0x03007014
	ldr r1, [r0]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _080745A6
	adds r0, r1, #0
	adds r0, #0xe8
	bl update_wave_channel
_080745A6:
	pop {r0}
	bx r0
	.align 2, 0
_080745AC: .4byte 0x03007014
	.syntax divided
