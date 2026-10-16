	.syntax unified

	thumb_func_start sub_0801CD50
sub_0801CD50: @ 0x0801CD50
	push {r4, lr}
	ldr r0, _0801CD9C @ =0x084CDBD8
	ldr r1, _0801CDA0 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801CDA4 @ =0x0850E378
	ldr r1, _0801CDA8 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0801CDAC @ =0x03002C30
	ldr r4, _0801CDB0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r2, [r0]
	lsls r2, r2, #2
	adds r0, #0x49
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
_0801CD9C: .4byte 0x084CDBD8
_0801CDA0: .4byte 0x06014800
_0801CDA4: .4byte 0x0850E378
_0801CDA8: .4byte 0x050002E0
_0801CDAC: .4byte 0x03002C30
_0801CDB0: .4byte 0x03001800
	.syntax divided
