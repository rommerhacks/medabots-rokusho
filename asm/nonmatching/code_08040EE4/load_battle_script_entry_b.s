	.syntax unified

	thumb_func_start load_battle_script_entry_b
	.global load_battle_script_entry_b
load_battle_script_entry_b: @ 0x08043E54
	push {lr}
	ldr r1, _08043E70 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x38
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r2, _08043E74 @ =0x083C3B5C
	adds r0, r0, r2
	adds r1, #0x74
	movs r2, #8
	bl memcpy_bytes_0803F63C
	pop {r0}
	bx r0
	.align 2, 0
_08043E70: .4byte 0x03001800
_08043E74: .4byte 0x083C3B5C
	.syntax divided
