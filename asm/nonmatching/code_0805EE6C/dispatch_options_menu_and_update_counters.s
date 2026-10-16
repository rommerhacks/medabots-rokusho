	.syntax unified

	thumb_func_start dispatch_options_menu_and_update_counters
dispatch_options_menu_and_update_counters: @ 0x0805EF9C
	push {lr}
	ldr r1, _0805EFCC @ =0x08483C6C
	ldr r0, _0805EFD0 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0805EFD4 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805EFC8
	ldr r0, _0805EFD8 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0805EFC8:
	pop {r0}
	bx r0
	.align 2, 0
_0805EFCC: .4byte 0x08483C6C
_0805EFD0: .4byte 0x0300137C
_0805EFD4: .4byte 0x03001780
_0805EFD8: .4byte 0x03001C04
	.syntax divided
