	.syntax unified

	thumb_func_start scene_complete_dma_and_restore_state
scene_complete_dma_and_restore_state: @ 0x0806DFF8
	push {lr}
	sub sp, #4
	bl execute_scene_step
	cmp r0, #0
	beq _0806E038
	movs r0, #0
	str r0, [sp]
	ldr r1, _0806E040 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806E044 @ =0x03002C30
	str r0, [r1, #4]
	ldr r0, _0806E048 @ =0x85000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806E04C @ =0x000080FF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0806E050 @ =0x0300178C
	ldr r1, _0806E054 @ =0x03001800
	ldrh r0, [r1]
	str r0, [r2]
	ldr r2, _0806E058 @ =0x03002B8C
	ldrh r0, [r1, #2]
	str r0, [r2]
	ldr r2, _0806E05C @ =0x0300137C
	ldrh r0, [r1, #4]
	str r0, [r2]
_0806E038:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0806E040: .4byte 0x040000D4
_0806E044: .4byte 0x03002C30
_0806E048: .4byte 0x85000800
_0806E04C: .4byte 0x000080FF
_0806E050: .4byte 0x0300178C
_0806E054: .4byte 0x03001800
_0806E058: .4byte 0x03002B8C
_0806E05C: .4byte 0x0300137C
	.syntax divided
