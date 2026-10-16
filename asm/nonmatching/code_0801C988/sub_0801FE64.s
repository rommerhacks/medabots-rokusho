	.syntax unified

	thumb_func_start sub_0801FE64
sub_0801FE64: @ 0x0801FE64
	push {r4, lr}
	ldr r0, _0801FEB0 @ =0x084CDBD8
	ldr r1, _0801FEB4 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801FEB8 @ =0x0850E378
	ldr r1, _0801FEBC @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0801FEC0 @ =0x03002C30
	ldr r4, _0801FEC4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	movs r2, #2
	ldrsh r1, [r0, r2]
	ldrh r2, [r0, #4]
	subs r2, #4
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r0, #0x21
	movs r3, #8
	bl setup_battle_cursor_sprite_08036FF8
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FEB0: .4byte 0x084CDBD8
_0801FEB4: .4byte 0x06014800
_0801FEB8: .4byte 0x0850E378
_0801FEBC: .4byte 0x050002E0
_0801FEC0: .4byte 0x03002C30
_0801FEC4: .4byte 0x03001800
	.syntax divided
