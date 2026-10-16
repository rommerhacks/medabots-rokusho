	.syntax unified

	thumb_func_start clear_stack_buffer_64
clear_stack_buffer_64: @ 0x08067180
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0
	str r0, [sp, #0x40]
	add r0, sp, #0x40
	ldr r2, _080671D8 @ =0x01000010
	mov r1, sp
	bl CpuFastSet
	cmp r5, #0xd
	bgt _080671CA
	ldr r0, _080671DC @ =0x0600DD3E
	ldrh r7, [r0]
	movs r4, #0
	cmp r4, r6
	bge _080671CA
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0xd
	bl sub_0807CBBC
	adds r2, r0, #0
	lsls r0, r2, #1
	mov r3, sp
	adds r1, r0, r3
_080671BA:
	subs r0, r2, r4
	cmp r0, #0
	blt _080671C2
	strh r7, [r1]
_080671C2:
	subs r1, #2
	adds r4, #1
	cmp r4, r6
	blt _080671BA
_080671CA:
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0
	bne _080671E4
	mov r0, sp
	ldr r1, _080671E0 @ =0x0600D8C0
	b _080671E8
	.align 2, 0
_080671D8: .4byte 0x01000010
_080671DC: .4byte 0x0600DD3E
_080671E0: .4byte 0x0600D8C0
_080671E4:
	mov r0, sp
	ldr r1, _0806720C @ =0x0600D940
_080671E8:
	ldrh r1, [r1]
	strh r1, [r0]
	ldr r0, _08067210 @ =0x04000008
	ldrh r1, [r0]
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, _08067214 @ =0x06000400
	adds r1, r1, r0
	mov r0, sp
	movs r2, #0x10
	bl CpuFastSet
	add sp, #0x44
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806720C: .4byte 0x0600D940
_08067210: .4byte 0x04000008
_08067214: .4byte 0x06000400
	.syntax divided
