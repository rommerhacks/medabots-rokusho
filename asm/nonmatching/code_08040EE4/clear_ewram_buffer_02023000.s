	.syntax unified

	thumb_func_start clear_ewram_buffer_02023000
clear_ewram_buffer_02023000: @ 0x0804206C
	push {r4, lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r4, _080420B4 @ =0x02023000
	ldr r2, _080420B8 @ =0x01000080
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	movs r2, #0
	ldr r1, _080420BC @ =0x03000BE0
_08042084:
	ldrb r0, [r1, #5]
	strh r0, [r4]
	adds r1, #0x40
	adds r4, #8
	adds r2, #1
	cmp r2, #0x1d
	bls _08042084
	movs r0, #0x1e
	bl sub_0804242C
	ldr r0, _080420B4 @ =0x02023000
	ldrh r0, [r0]
	ldr r1, _080420C0 @ =0x02023018
	ldrh r2, [r1]
	subs r0, r0, r2
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, r0, r2
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080420B4: .4byte 0x02023000
_080420B8: .4byte 0x01000080
_080420BC: .4byte 0x03000BE0
_080420C0: .4byte 0x02023018
	.syntax divided
