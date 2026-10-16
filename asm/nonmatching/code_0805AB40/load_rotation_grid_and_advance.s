	.syntax unified

	thumb_func_start load_rotation_grid_and_advance
load_rotation_grid_and_advance: @ 0x0805C8D4
	push {lr}
	sub sp, #0x54
	ldr r1, _0805C904 @ =0x080AF755
	mov r0, sp
	movs r2, #0x53
	bl memcpy_optimized
	mov r0, sp
	bl run_message
	cmp r0, #0
	beq _0805C8FE
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r1, _0805C908 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805C8FE:
	add sp, #0x54
	pop {r0}
	bx r0
	.align 2, 0
_0805C904: .4byte 0x080AF755
_0805C908: .4byte 0x0300137C
	.syntax divided
