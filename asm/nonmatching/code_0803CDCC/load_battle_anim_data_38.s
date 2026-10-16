	.syntax unified

	thumb_func_start load_battle_anim_data_38
load_battle_anim_data_38: @ 0x0803E7F0
	push {r4, lr}
	sub sp, #0x10
	ldr r1, _0803E830 @ =0x083BE9E8
	ldr r0, _0803E834 @ =0x03001800
	adds r0, #0x38
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _0803E838 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x1e
	movs r2, #1
	movs r3, #3
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E830: .4byte 0x083BE9E8
_0803E834: .4byte 0x03001800
_0803E838: .4byte 0x030004DE
	.syntax divided
