	.syntax unified

	thumb_func_start sub_08021038
sub_08021038: @ 0x08021038
	push {r4, r5, r6, lr}
	ldr r0, _08021050 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0802109C
	cmp r0, #1
	bgt _08021054
	cmp r0, #0
	beq _0802105E
	b _08021142
	.align 2, 0
_08021050: .4byte 0x03001800
_08021054:
	cmp r0, #2
	beq _080210E0
	cmp r0, #3
	beq _08021124
	b _08021142
_0802105E:
	ldr r0, _08021080 @ =0x084C907C
	ldr r1, _08021084 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08021088 @ =0x0850E058
	ldr r1, _0802108C @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08021090 @ =0x03002C30
	ldr r1, _08021094 @ =0x00000844
	adds r0, r0, r1
	movs r1, #0x3c
	strh r1, [r0]
	ldr r0, _08021098 @ =0x083B5F80
	ldr r0, [r0, #0x64]
	b _080210BC
	.align 2, 0
_08021080: .4byte 0x084C907C
_08021084: .4byte 0x06014800
_08021088: .4byte 0x0850E058
_0802108C: .4byte 0x050002E0
_08021090: .4byte 0x03002C30
_08021094: .4byte 0x00000844
_08021098: .4byte 0x083B5F80
_0802109C:
	ldr r0, _080210C4 @ =0x084C9288
	ldr r1, _080210C8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080210CC @ =0x0850E078
	ldr r1, _080210D0 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080210D4 @ =0x03002C30
	ldr r2, _080210D8 @ =0x00000844
	adds r0, r0, r2
	movs r1, #0x3c
	strh r1, [r0]
	ldr r0, _080210DC @ =0x083B5F80
	ldr r0, [r0, #0x68]
_080210BC:
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	b _08021142
	.align 2, 0
_080210C4: .4byte 0x084C9288
_080210C8: .4byte 0x06014800
_080210CC: .4byte 0x0850E078
_080210D0: .4byte 0x050002E0
_080210D4: .4byte 0x03002C30
_080210D8: .4byte 0x00000844
_080210DC: .4byte 0x083B5F80
_080210E0:
	ldr r0, _08021108 @ =0x084C9624
	ldr r1, _0802110C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08021110 @ =0x0850E098
	ldr r1, _08021114 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08021118 @ =0x03002C30
	ldr r0, _0802111C @ =0x00000844
	adds r2, r1, r0
	movs r0, #0x3c
	strh r0, [r2]
	ldr r2, _08021120 @ =0x00000846
	adds r1, r1, r2
	movs r0, #0xd0
	lsls r0, r0, #4
	strh r0, [r1]
	b _08021142
	.align 2, 0
_08021108: .4byte 0x084C9624
_0802110C: .4byte 0x06014800
_08021110: .4byte 0x0850E098
_08021114: .4byte 0x050002E0
_08021118: .4byte 0x03002C30
_0802111C: .4byte 0x00000844
_08021120: .4byte 0x00000846
_08021124:
	ldr r0, _080211A0 @ =0x084D513C
	ldr r1, _080211A4 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080211A8 @ =0x0850E678
	ldr r1, _080211AC @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080211B0 @ =0x083B5F80
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
_08021142:
	ldr r3, _080211B4 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r3, r0
	ldrh r1, [r4]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r2, #0
	movs r5, #0
	adds r2, r0, #0
	orrs r2, r1
	strh r2, [r4]
	ldr r0, _080211B8 @ =0x00000849
	adds r1, r3, r0
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _080211BC @ =0x00000848
	adds r1, r3, r0
	movs r0, #8
	strb r0, [r1]
	ldr r6, _080211C0 @ =0x03001800
	adds r0, r6, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802118E
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r2, r0
	strh r2, [r4]
	ldr r2, _080211C4 @ =0x00000842
	adds r1, r3, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0802118E:
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080211A0: .4byte 0x084D513C
_080211A4: .4byte 0x06014800
_080211A8: .4byte 0x0850E678
_080211AC: .4byte 0x050002E0
_080211B0: .4byte 0x083B5F80
_080211B4: .4byte 0x03002C30
_080211B8: .4byte 0x00000849
_080211BC: .4byte 0x00000848
_080211C0: .4byte 0x03001800
_080211C4: .4byte 0x00000842
_080211C8:
	.byte 0x0A, 0x49, 0x0B, 0x48, 0x09, 0x18, 0x08, 0x78
	.byte 0x08, 0x30, 0x08, 0x70, 0x00, 0x06, 0x00, 0x0E, 0x40, 0x28, 0x1C, 0xD1, 0x07, 0x48, 0x01, 0x1C
	.byte 0x51, 0x31, 0x09, 0x78, 0x02, 0x1C, 0x03, 0x29, 0x0C, 0xD1, 0x05, 0x48, 0x86, 0x30, 0x01, 0x21
	.byte 0x0B, 0xE0, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03, 0x48, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.byte 0x40, 0x04, 0x00, 0x03, 0x04, 0x48, 0x86, 0x30, 0x3C, 0x21, 0x01, 0x80, 0x11, 0x1C, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x40, 0x04, 0x00, 0x03
	.syntax divided
