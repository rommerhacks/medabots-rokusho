	.syntax unified

	thumb_func_start execute_scene_step
	.global execute_scene_step
execute_scene_step: @ 0x0806874C
	push {lr}
	ldr r1, _08068770 @ =0x08485C7C
	ldr r0, _08068774 @ =0x03000004
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	cmp r0, #0
	bne _0806877C
	ldr r1, _08068778 @ =0x03000000
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
	b _08068784
	.align 2, 0
_08068770: .4byte 0x08485C7C
_08068774: .4byte 0x03000004
_08068778: .4byte 0x03000000
_0806877C:
	ldr r1, _08068788 @ =0x03000000
	movs r0, #0
	str r0, [r1]
	movs r0, #1
_08068784:
	pop {r1}
	bx r1
	.align 2, 0
_08068788: .4byte 0x03000000
_0806878C:
	.byte 0x01, 0x20, 0x70, 0x47
	.syntax divided
