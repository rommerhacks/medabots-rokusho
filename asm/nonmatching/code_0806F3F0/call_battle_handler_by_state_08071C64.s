	.syntax unified

	thumb_func_start call_battle_handler_by_state_08071C64
call_battle_handler_by_state_08071C64: @ 0x08071C64
	push {lr}
	ldr r1, _08071C7C @ =0x08486138
	ldr r0, _08071C80 @ =0x03001800
	ldrb r0, [r0, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	.align 2, 0
_08071C7C: .4byte 0x08486138
_08071C80: .4byte 0x03001800
_08071C84:
	.byte 0x02, 0x49, 0x08, 0x7C, 0x01, 0x30, 0x08, 0x74, 0x01, 0x20, 0x70, 0x47
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
