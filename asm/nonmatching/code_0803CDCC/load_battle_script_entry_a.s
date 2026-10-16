	.syntax unified

	thumb_func_start load_battle_script_entry_a
load_battle_script_entry_a: @ 0x0803E870
	push {lr}
	ldr r1, _0803E88C @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x38
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r2, _0803E890 @ =0x083C3B04
	adds r0, r0, r2
	adds r1, #0x39
	movs r2, #8
	bl memcpy_bytes_0803F63C
	pop {r0}
	bx r0
	.align 2, 0
_0803E88C: .4byte 0x03001800
_0803E890: .4byte 0x083C3B04
	.syntax divided
