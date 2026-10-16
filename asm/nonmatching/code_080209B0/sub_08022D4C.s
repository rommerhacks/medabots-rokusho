	.syntax unified

	thumb_func_start sub_08022D4C
sub_08022D4C: @ 0x08022D4C
	push {r4, r5, r6, lr}
	ldr r0, _08022DE4 @ =0x084D5B08
	ldr r1, _08022DE8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08022DEC @ =0x0850E738
	ldr r1, _08022DF0 @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r2, _08022DF4 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r2, r0
	ldrh r1, [r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r6, _08022DF8 @ =0x00000848
	adds r0, r2, r6
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08022DFC @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	ldr r4, _08022E00 @ =0x0000084A
	adds r0, r2, r4
	movs r5, #6
	strb r5, [r0]
	ldr r4, _08022E04 @ =0x03001800
	adds r3, r4, #0
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	movs r6, #0x87
	lsls r6, r6, #4
	adds r0, r2, r6
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08022E08 @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r6, #0xc
	adds r2, r2, r6
	strb r5, [r2]
	ldr r0, _08022E0C @ =0x083B5F80
	adds r0, #0xf8
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08022E10 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08022DE4: .4byte 0x084D5B08
_08022DE8: .4byte 0x06014800
_08022DEC: .4byte 0x0850E738
_08022DF0: .4byte 0x050002C0
_08022DF4: .4byte 0x03002C30
_08022DF8: .4byte 0x00000848
_08022DFC: .4byte 0x00000849
_08022E00: .4byte 0x0000084A
_08022E04: .4byte 0x03001800
_08022E08: .4byte 0x00000872
_08022E0C: .4byte 0x083B5F80
_08022E10: .4byte 0x03000440
	.syntax divided
