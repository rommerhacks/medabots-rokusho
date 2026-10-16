	.syntax unified

	thumb_func_start sub_080644C4
sub_080644C4: @ 0x080644C4
	push {r4, lr}
	sub sp, #0x34
	mov r1, sp
	ldr r0, _0806452C @ =0x080AFAA0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, _08064530 @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _080644FA
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x30]
	add r0, sp, #0x30
	ldr r1, _08064534 @ =0x03002414
	ldr r1, [r1]
	ldr r2, _08064538 @ =0x00000B84
	adds r1, r1, r2
	ldr r2, _0806453C @ =0x01000100
	bl CpuFastSet
_080644FA:
	ldr r0, _08064540 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _08064544 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08064522
	ldr r0, _08064548 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_08064522:
	add sp, #0x34
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806452C: .4byte 0x080AFAA0
_08064530: .4byte 0x03000430
_08064534: .4byte 0x03002414
_08064538: .4byte 0x00000B84
_0806453C: .4byte 0x01000100
_08064540: .4byte 0x0300137C
_08064544: .4byte 0x03001780
_08064548: .4byte 0x03001C04
	.syntax divided
