	.syntax unified

	thumb_func_start copy_sprite_tiles_to_vram
copy_sprite_tiles_to_vram: @ 0x08044FB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r6, r1, #0
	adds r0, r2, #0
	adds r1, r3, #0
	ldr r4, [sp, #0x38]
	bl sub_08044E64
	mov r2, sp
	lsrs r1, r0, #0x10
	strh r1, [r2]
	mov r1, sp
	strh r0, [r1, #2]
	mov r0, sp
	ldrh r0, [r0]
	lsrs r0, r0, #3
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #2]
	lsrs r0, r0, #3
	strh r0, [r1, #2]
	movs r1, #2
	subs r1, r1, r4
	movs r0, #0x40
	bl Div
	mov r2, sp
	mov r1, sp
	ldrh r1, [r1, #2]
	muls r0, r1, r0
	strh r0, [r2, #2]
	movs r1, #0
	ldr r0, [sp, #0x30]
	cmp r1, r0
	bge _08045074
	mov sl, sp
_08045006:
	str r6, [sp, #4]
	movs r0, #0
	adds r1, #1
	str r1, [sp, #8]
	ldr r1, [sp, #0x34]
	cmp r0, r1
	bge _0804505C
	mov r7, sp
_08045016:
	mov r8, r6
	movs r5, #0
	adds r3, r0, #1
	ldrh r2, [r7]
	cmp r5, r2
	bge _0804504E
	mov r4, sp
_08045024:
	ldrh r2, [r4, #2]
	lsrs r2, r2, #2
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r6, #0
	mov r1, sb
	str r3, [sp, #0xc]
	bl CpuSet
	ldrh r1, [r4, #2]
	ldr r2, [sp, #0x34]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r6, r6, r0
	add sb, r1
	adds r5, #1
	ldr r3, [sp, #0xc]
	ldrh r0, [r4]
	cmp r5, r0
	blt _08045024
_0804504E:
	ldrh r0, [r7, #2]
	mov r1, r8
	adds r6, r1, r0
	adds r0, r3, #0
	ldr r2, [sp, #0x34]
	cmp r0, r2
	blt _08045016
_0804505C:
	mov r0, sl
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	muls r0, r1, r0
	ldr r1, [sp, #0x34]
	muls r0, r1, r0
	ldr r2, [sp, #4]
	adds r6, r2, r0
	ldr r1, [sp, #8]
	ldr r0, [sp, #0x30]
	cmp r1, r0
	blt _08045006
_08045074:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
