	.syntax unified

	thumb_func_start load_wave_pattern
load_wave_pattern: @ 0x080738D0
	push {lr}
	sub sp, #4
	lsls r0, r0, #4
	ldr r1, _08073900 @ =0x080B06AC
	adds r0, r0, r1
	ldr r1, _08073904 @ =0x04000090
	ldr r2, _08073908 @ =0x04000004
	bl CpuSet
	mov r1, sp
	ldr r2, _0807390C @ =0x04000070
	ldrh r0, [r2]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	movs r1, #0x80
	cmp r0, #0x80
	bne _080738F6
	movs r1, #0xc0
_080738F6:
	strh r1, [r2]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08073900: .4byte 0x080B06AC
_08073904: .4byte 0x04000090
_08073908: .4byte 0x04000004
_0807390C: .4byte 0x04000070
	.syntax divided
