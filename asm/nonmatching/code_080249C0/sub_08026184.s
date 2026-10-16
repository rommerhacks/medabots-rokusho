	.syntax unified

	thumb_func_start sub_08026184
sub_08026184: @ 0x08026184
	push {r4, r5, r6, lr}
	ldr r0, _0802624C @ =0x084D71D8
	ldr r1, _08026250 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08026254 @ =0x0850E978
	ldr r1, _08026258 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _0802625C @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r5, r2, r0
	movs r6, #0
	ldr r3, _08026260 @ =0x0000C624
	strh r3, [r5]
	ldr r4, _08026264 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080261C2
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r5]
_080261C2:
	ldr r1, _08026268 @ =0x0000085C
	adds r0, r2, r1
	strb r6, [r0]
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _0802626C @ =0x00000842
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #6
	ldr r3, _08026270 @ =0x00000844
	adds r1, r2, r3
	strh r0, [r1]
	adds r5, #0x16
	adds r1, r2, r5
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08026274 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	adds r3, #5
	adds r0, r2, r3
	strb r1, [r0]
	subs r5, #0xe
	adds r1, r2, r5
	movs r0, #7
	strb r0, [r1]
	ldr r0, _08026278 @ =0x0000084B
	adds r1, r2, r0
	movs r0, #0xf0
	strb r0, [r1]
	subs r3, #3
	adds r1, r2, r3
	ldr r0, _0802627C @ =0x00000616
	strh r0, [r1]
	adds r5, #0x19
	adds r0, r2, r5
	strb r6, [r0]
	ldr r0, _08026280 @ =0x083B5F80
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802624C: .4byte 0x084D71D8
_08026250: .4byte 0x06014800
_08026254: .4byte 0x0850E978
_08026258: .4byte 0x050002E0
_0802625C: .4byte 0x03002C30
_08026260: .4byte 0x0000C624
_08026264: .4byte 0x03001800
_08026268: .4byte 0x0000085C
_0802626C: .4byte 0x00000842
_08026270: .4byte 0x00000844
_08026274: .4byte 0x00000848
_08026278: .4byte 0x0000084B
_0802627C: .4byte 0x00000616
_08026280: .4byte 0x083B5F80
	.syntax divided
