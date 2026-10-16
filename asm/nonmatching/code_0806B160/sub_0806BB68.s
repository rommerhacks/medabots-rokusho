	.syntax unified

	thumb_func_start sub_0806BB68
sub_0806BB68: @ 0x0806BB68
	push {lr}
	sub sp, #4
	bl execute_scene_step
	cmp r0, #0
	beq _0806BB90
	movs r0, #0
	str r0, [sp]
	ldr r1, _0806BB98 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806BB9C @ =0x03002C30
	str r0, [r1, #4]
	ldr r0, _0806BBA0 @ =0x85000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0806BBA4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806BB90:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0806BB98: .4byte 0x040000D4
_0806BB9C: .4byte 0x03002C30
_0806BBA0: .4byte 0x85000800
_0806BBA4: .4byte 0x0300137C
	.syntax divided
