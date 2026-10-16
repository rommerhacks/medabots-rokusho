	.syntax unified

	thumb_func_start clear_ewram_buffer_02023000_b
	.global clear_ewram_buffer_02023000_b
clear_ewram_buffer_02023000_b: @ 0x08033184
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r1, _080331E0 @ =0x02023000
	ldr r2, _080331E4 @ =0x01000080
	mov r0, sp
	bl CpuFastSet
	movs r4, #0
	ldr r0, _080331E8 @ =0x03000590
	mov ip, r0
	movs r5, #0
_080331A0:
	lsls r0, r4, #3
	ldr r1, _080331E0 @ =0x02023000
	adds r3, r0, r1
	strh r4, [r3, #4]
	lsls r0, r6, #8
	adds r0, r5, r0
	add r0, ip
	adds r2, r0, #0
	adds r2, #0x59
	ldrb r1, [r2]
	cmp r1, #0
	beq _080331C6
	adds r0, #0x4c
	ldrb r7, [r0]
	cmp r1, r7
	beq _080331C6
	ldrb r0, [r0]
	subs r0, r0, r1
	strh r0, [r3]
_080331C6:
	adds r5, #0x18
	adds r4, #1
	cmp r4, #3
	bls _080331A0
	movs r0, #4
	bl sub_0804242C
	ldr r1, _080331E0 @ =0x02023000
	ldrh r0, [r1]
	cmp r0, #0
	bne _080331EC
	movs r0, #0
	b _080331F0
	.align 2, 0
_080331E0: .4byte 0x02023000
_080331E4: .4byte 0x01000080
_080331E8: .4byte 0x03000590
_080331EC:
	ldrh r0, [r1, #4]
	adds r0, #1
_080331F0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
