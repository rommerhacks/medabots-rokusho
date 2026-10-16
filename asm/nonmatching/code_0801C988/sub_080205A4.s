	.syntax unified

	thumb_func_start sub_080205A4
sub_080205A4: @ 0x080205A4
	push {r4, lr}
	ldr r0, _080205F0 @ =0x084CDBD8
	ldr r1, _080205F4 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080205F8 @ =0x0850E378
	ldr r1, _080205FC @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08020600 @ =0x03002C30
	ldr r4, _08020604 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r2, [r0]
	lsls r2, r2, #2
	adds r0, #0x20
	ldrb r0, [r0]
	adds r0, #0x5a
	adds r2, r2, r0
	lsls r2, r2, #6
	adds r2, r2, r1
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r0, #4
	ldrsh r2, [r2, r0]
	movs r0, #0x21
	movs r3, #4
	bl setup_battle_cursor_sprite_08036FF8
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080205F0: .4byte 0x084CDBD8
_080205F4: .4byte 0x06014800
_080205F8: .4byte 0x0850E378
_080205FC: .4byte 0x050002E0
_08020600: .4byte 0x03002C30
_08020604: .4byte 0x03001800
	.syntax divided
