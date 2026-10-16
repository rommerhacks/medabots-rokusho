	.syntax unified

	thumb_func_start sub_0802DCDC
sub_0802DCDC: @ 0x0802DCDC
	push {lr}
	ldr r0, _0802DD34 @ =0x084E046C
	ldr r1, _0802DD38 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802DD3C @ =0x0850EEB8
	ldr r1, _0802DD40 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0802DD44 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r3, r0
	movs r2, #0
	ldr r0, _0802DD48 @ =0x0000C404
	strh r0, [r1]
	ldr r1, _0802DD4C @ =0x0000085C
	adds r0, r3, r1
	strb r2, [r0]
	ldr r0, _0802DD50 @ =0x00000844
	adds r1, r3, r0
	movs r0, #0xe0
	strh r0, [r1]
	ldr r0, _0802DD54 @ =0x0000084A
	adds r1, r3, r0
	movs r0, #7
	strb r0, [r1]
	ldr r0, _0802DD58 @ =0x0000084B
	adds r1, r3, r0
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _0802DD5C @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802DD64
	ldr r0, _0802DD60 @ =0x00000842
	adds r1, r3, r0
	movs r0, #0xb8
	b _0802DD6A
	.align 2, 0
_0802DD34: .4byte 0x084E046C
_0802DD38: .4byte 0x06014800
_0802DD3C: .4byte 0x0850EEB8
_0802DD40: .4byte 0x050002E0
_0802DD44: .4byte 0x03002C30
_0802DD48: .4byte 0x0000C404
_0802DD4C: .4byte 0x0000085C
_0802DD50: .4byte 0x00000844
_0802DD54: .4byte 0x0000084A
_0802DD58: .4byte 0x0000084B
_0802DD5C: .4byte 0x03001800
_0802DD60: .4byte 0x00000842
_0802DD64:
	ldr r0, _0802DD8C @ =0x00000842
	adds r1, r3, r0
	movs r0, #0x40
_0802DD6A:
	strh r0, [r1]
	ldr r0, _0802DD90 @ =0x083B5F80
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r1, _0802DD94 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802DD8C: .4byte 0x00000842
_0802DD90: .4byte 0x083B5F80
_0802DD94: .4byte 0x03001800
	.syntax divided
