	.syntax unified

	thumb_func_start sub_0802480C
sub_0802480C: @ 0x0802480C
	push {r4, lr}
	ldr r0, _08024858 @ =0x084CDBD8
	ldr r1, _0802485C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08024860 @ =0x0850E378
	ldr r1, _08024864 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08024868 @ =0x03002C30
	ldr r4, _0802486C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r2, [r0]
	lsls r2, r2, #2
	adds r0, #0x48
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
_08024858: .4byte 0x084CDBD8
_0802485C: .4byte 0x06014800
_08024860: .4byte 0x0850E378
_08024864: .4byte 0x050002E0
_08024868: .4byte 0x03002C30
_0802486C: .4byte 0x03001800
	.syntax divided
