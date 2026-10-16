	.syntax unified

	thumb_func_start dispatch_battle_menu_and_update_counters
dispatch_battle_menu_and_update_counters: @ 0x08066690
	push {lr}
	sub sp, #0x34
	ldr r1, _080666CC @ =0x080AFB48
	mov r0, sp
	movs r2, #0x34
	bl memcpy_optimized
	ldr r0, _080666D0 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _080666D4 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080666C6
	ldr r0, _080666D8 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_080666C6:
	add sp, #0x34
	pop {r0}
	bx r0
	.align 2, 0
_080666CC: .4byte 0x080AFB48
_080666D0: .4byte 0x0300137C
_080666D4: .4byte 0x03001780
_080666D8: .4byte 0x03001C04
	.syntax divided
