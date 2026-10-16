	.syntax unified

	thumb_func_start sub_0805C85C
sub_0805C85C: @ 0x0805C85C
	push {r4, lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _0805C8BC @ =0x01006000
	mov r0, sp
	bl CpuFastSet
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_080415BC
	movs r4, #0x80
	lsls r4, r4, #0x13
	movs r0, #0x60
	strh r0, [r4]
	ldr r0, _0805C8C0 @ =0x084E2E38
	ldr r1, _0805C8C4 @ =0x0202F9E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805C8C8 @ =0x084C6A98
	ldr r1, _0805C8CC @ =0x06017400
	bl lz_decompress_dispatch
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _0805C8D0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C8BC: .4byte 0x01006000
_0805C8C0: .4byte 0x084E2E38
_0805C8C4: .4byte 0x0202F9E0
_0805C8C8: .4byte 0x084C6A98
_0805C8CC: .4byte 0x06017400
_0805C8D0: .4byte 0x0300137C
	.syntax divided
