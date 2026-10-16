	.syntax unified

	thumb_func_start init_cursor_state
	.global init_cursor_state
init_cursor_state: @ 0x08047C00
	push {lr}
	bl sub_08047E4C
	ldr r1, _08047C1C @ =0x03005000
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r0, _08047C20 @ =0x030064A0
	strb r2, [r0]
	strb r2, [r0, #1]
	pop {r0}
	bx r0
	.align 2, 0
_08047C1C: .4byte 0x03005000
_08047C20: .4byte 0x030064A0
	.syntax divided
