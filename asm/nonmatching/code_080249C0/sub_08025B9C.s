	.syntax unified

	thumb_func_start sub_08025B9C
sub_08025B9C: @ 0x08025B9C
	push {r4, r5, r6, lr}
	ldr r0, _08025C50 @ =0x084D6F88
	ldr r1, _08025C54 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08025C58 @ =0x0850E938
	ldr r1, _08025C5C @ =0x050002E0
	movs r2, #0x10
	bl CpuFastSet
	ldr r2, _08025C60 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	ldrh r3, [r1]
	movs r4, #0x88
	lsls r4, r4, #2
	adds r0, r4, #0
	movs r6, #0
	movs r4, #0
	orrs r0, r3
	strh r0, [r1]
	ldr r1, _08025C64 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08025C68 @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	ldr r1, _08025C6C @ =0x00000858
	adds r0, r2, r1
	strh r4, [r0]
	adds r3, #1
	adds r1, r2, r3
	movs r0, #7
	strb r0, [r1]
	ldr r5, _08025C70 @ =0x03001800
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
	ldr r3, _08025C74 @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r4, #0xc
	adds r1, r2, r4
	movs r0, #6
	strb r0, [r1]
	ldr r0, _08025C78 @ =0x00000863
	adds r2, r2, r0
	strb r6, [r2]
	ldr r4, _08025C7C @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x84
	movs r1, #0x48
	strb r1, [r0]
	ldr r0, _08025C80 @ =0x083B5F80
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
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08025C50: .4byte 0x084D6F88
_08025C54: .4byte 0x06014800
_08025C58: .4byte 0x0850E938
_08025C5C: .4byte 0x050002E0
_08025C60: .4byte 0x03002C30
_08025C64: .4byte 0x00000848
_08025C68: .4byte 0x00000849
_08025C6C: .4byte 0x00000858
_08025C70: .4byte 0x03001800
_08025C74: .4byte 0x00000872
_08025C78: .4byte 0x00000863
_08025C7C: .4byte 0x03000440
_08025C80: .4byte 0x083B5F80
	.syntax divided
