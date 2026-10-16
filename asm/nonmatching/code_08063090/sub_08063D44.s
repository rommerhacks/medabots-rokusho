	.syntax unified

	thumb_func_start sub_08063D44
sub_08063D44: @ 0x08063D44
	push {r4, lr}
	ldr r4, _08063D80 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _08063D78
	ldr r0, _08063D84 @ =0x05000200
	ldr r1, _08063D88 @ =0x0202F800
	movs r2, #0x40
	bl CpuFastSet
	ldr r1, _08063D8C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r1, [r4]
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1, #0x3c]
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl text_window_init
_08063D78:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08063D80: .4byte 0x03006F74
_08063D84: .4byte 0x05000200
_08063D88: .4byte 0x0202F800
_08063D8C: .4byte 0x0300137C
	.syntax divided
