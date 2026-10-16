	.syntax unified

	thumb_func_start clear_oam
	.global clear_oam
clear_oam: @ 0x08000540
	push {r4, lr}
	sub sp, #8
	movs r0, #0xa0
	str r0, [sp]
	movs r1, #0xe0
	lsls r1, r1, #0x13
	ldr r2, _08000580 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	add r3, sp, #4
	ldr r1, _08000584 @ =0x03001380
	movs r2, #0xa0
	movs r4, #0xfe
	lsls r4, r4, #2
	adds r0, r1, r4
_08000560:
	strh r2, [r0]
	subs r0, #8
	cmp r0, r1
	bge _08000560
	movs r0, #0
	str r0, [sp, #4]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08000588 @ =0x01006000
	adds r0, r3, #0
	bl CpuFastSet
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08000580: .4byte 0x01000100
_08000584: .4byte 0x03001380
_08000588: .4byte 0x01006000
	.syntax divided
