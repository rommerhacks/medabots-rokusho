	.syntax unified

	thumb_func_start sub_08023E94
sub_08023E94: @ 0x08023E94
	push {r4, r5, lr}
	ldr r0, _08023F24 @ =0x084D6098
	ldr r1, _08023F28 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08023F2C @ =0x0850E7D8
	ldr r1, _08023F30 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08023F34 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r2, r0
	ldrh r1, [r3]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r5, _08023F38 @ =0x03001800
	adds r3, r5, #0
	adds r3, #0x87
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	movs r4, #0x87
	lsls r4, r4, #4
	adds r0, r2, r4
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08023F3C @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r4, #0xc
	adds r2, r2, r4
	movs r0, #6
	strb r0, [r2]
	ldr r4, _08023F40 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x84
	movs r1, #0x42
	strb r1, [r0]
	ldr r0, _08023F44 @ =0x083B5F80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r4, #0x86
	movs r0, #0x3c
	strh r0, [r4]
	adds r5, #0xaa
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023F24: .4byte 0x084D6098
_08023F28: .4byte 0x06014800
_08023F2C: .4byte 0x0850E7D8
_08023F30: .4byte 0x050002E0
_08023F34: .4byte 0x03002C30
_08023F38: .4byte 0x03001800
_08023F3C: .4byte 0x00000872
_08023F40: .4byte 0x03000440
_08023F44: .4byte 0x083B5F80
_08023F48:
	.byte 0x05, 0x49, 0x06, 0x48, 0x0A, 0x18, 0x10, 0x78
	.byte 0x40, 0x28, 0x0B, 0xD1, 0x04, 0x49, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x0C, 0xE0, 0x00, 0x00
	.byte 0x30, 0x2C, 0x00, 0x03, 0x48, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03, 0x08, 0x30, 0x10, 0x70
	.byte 0x02, 0x48, 0x09, 0x18, 0x08, 0x78, 0x08, 0x30, 0x08, 0x70, 0x70, 0x47, 0x49, 0x08, 0x00, 0x00
	.syntax divided
