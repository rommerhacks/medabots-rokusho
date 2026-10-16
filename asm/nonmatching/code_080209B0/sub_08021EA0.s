	.syntax unified

	thumb_func_start sub_08021EA0
sub_08021EA0: @ 0x08021EA0
	push {r4, r5, lr}
	ldr r0, _08021F60 @ =0x084D55D0
	ldr r1, _08021F64 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08021F68 @ =0x0850E6B8
	ldr r1, _08021F6C @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r5, _08021F70 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021ED8
	ldr r0, _08021F74 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
_08021ED8:
	ldr r2, _08021F74 @ =0x03002C30
	movs r4, #0x84
	lsls r4, r4, #4
	adds r3, r2, r4
	ldrh r1, [r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _08021F78 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08021F7C @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	ldr r1, _08021F80 @ =0x00000858
	adds r0, r2, r1
	strh r4, [r0]
	adds r3, r5, #0
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r4, #0xba
	lsls r4, r4, #5
	adds r0, r0, r4
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
	ldr r3, _08021F84 @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r4, #0xc
	adds r2, r2, r4
	movs r0, #6
	strb r0, [r2]
	ldr r0, _08021F88 @ =0x083B5F80
	adds r0, #0xf0
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08021F8C @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021F60: .4byte 0x084D55D0
_08021F64: .4byte 0x06014800
_08021F68: .4byte 0x0850E6B8
_08021F6C: .4byte 0x050002E0
_08021F70: .4byte 0x03001800
_08021F74: .4byte 0x03002C30
_08021F78: .4byte 0x00000848
_08021F7C: .4byte 0x00000849
_08021F80: .4byte 0x00000858
_08021F84: .4byte 0x00000872
_08021F88: .4byte 0x083B5F80
_08021F8C: .4byte 0x03000440
	.syntax divided
