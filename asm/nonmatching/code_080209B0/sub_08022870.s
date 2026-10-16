	.syntax unified

	thumb_func_start sub_08022870
sub_08022870: @ 0x08022870
	push {r4, r5, r6, lr}
	ldr r0, _08022908 @ =0x084D5860
	ldr r1, _0802290C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08022910 @ =0x0850E6F8
	ldr r1, _08022914 @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r2, _08022918 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r2, r0
	ldrh r1, [r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r6, _0802291C @ =0x00000848
	adds r0, r2, r6
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08022920 @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	ldr r4, _08022924 @ =0x0000084A
	adds r0, r2, r4
	movs r5, #6
	strb r5, [r0]
	ldr r4, _08022928 @ =0x03001800
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
	ldr r3, _0802292C @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r6, #0xc
	adds r2, r2, r6
	strb r5, [r2]
	ldr r0, _08022930 @ =0x083B5F80
	adds r0, #0xf8
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08022934 @ =0x03000440
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
_08022908: .4byte 0x084D5860
_0802290C: .4byte 0x06014800
_08022910: .4byte 0x0850E6F8
_08022914: .4byte 0x050002C0
_08022918: .4byte 0x03002C30
_0802291C: .4byte 0x00000848
_08022920: .4byte 0x00000849
_08022924: .4byte 0x0000084A
_08022928: .4byte 0x03001800
_0802292C: .4byte 0x00000872
_08022930: .4byte 0x083B5F80
_08022934: .4byte 0x03000440
	.syntax divided
