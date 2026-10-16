	.syntax unified

	thumb_func_start sub_08020FB8
sub_08020FB8: @ 0x08020FB8
	push {lr}
	ldr r0, _08020FE8 @ =0x084CCE48
	ldr r1, _08020FEC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08020FF0 @ =0x0850E358
	ldr r1, _08020FF4 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08020FF8 @ =0x083B5F80
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r1, _08020FFC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08020FE8: .4byte 0x084CCE48
_08020FEC: .4byte 0x06014800
_08020FF0: .4byte 0x0850E358
_08020FF4: .4byte 0x050002E0
_08020FF8: .4byte 0x083B5F80
_08020FFC: .4byte 0x03001800
	.syntax divided
