	.syntax unified

	thumb_func_start sub_08029868
sub_08029868: @ 0x08029868
	push {r4, r5, lr}
	ldr r0, _08029918 @ =0x084DD894
	ldr r1, _0802991C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08029920 @ =0x0850ECD8
	ldr r1, _08029924 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08029928 @ =0x084E30B8
	ldr r1, _0802992C @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _08029930 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r3, #0
	movs r2, #0
	ldr r0, _08029934 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _08029938 @ =0x0000085C
	adds r0, r4, r1
	strb r3, [r0]
	ldr r5, _0802993C @ =0x00000844
	adds r1, r4, r5
	movs r0, #0xe0
	strh r0, [r1]
	ldr r0, _08029940 @ =0x0000084A
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	adds r5, #7
	adds r1, r4, r5
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _08029944 @ =0x00000848
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _08029948 @ =0x00000858
	adds r0, r4, r1
	strh r2, [r0]
	adds r5, #0x1f
	adds r0, r4, r5
	strb r3, [r0]
	adds r1, #0x16
	adds r0, r4, r1
	movs r2, #0x5c
	strb r2, [r0]
	adds r5, #1
	adds r1, r4, r5
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0802994C @ =0x0000086B
	adds r1, r4, r0
	movs r0, #0x20
	strb r0, [r1]
	adds r5, #3
	adds r1, r4, r5
	movs r0, #0xc0
	strb r0, [r1]
	ldr r1, _08029950 @ =0x0000086D
	adds r0, r4, r1
	strb r3, [r0]
	ldr r0, _08029954 @ =0x083B5F80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08029958 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802995C
	subs r5, #0x2a
	adds r1, r4, r5
	movs r0, #0xb8
	b _08029962
	.align 2, 0
_08029918: .4byte 0x084DD894
_0802991C: .4byte 0x06014800
_08029920: .4byte 0x0850ECD8
_08029924: .4byte 0x050002E0
_08029928: .4byte 0x084E30B8
_0802992C: .4byte 0x050002C0
_08029930: .4byte 0x03002C30
_08029934: .4byte 0x0000C604
_08029938: .4byte 0x0000085C
_0802993C: .4byte 0x00000844
_08029940: .4byte 0x0000084A
_08029944: .4byte 0x00000848
_08029948: .4byte 0x00000858
_0802994C: .4byte 0x0000086B
_08029950: .4byte 0x0000086D
_08029954: .4byte 0x083B5F80
_08029958: .4byte 0x03001800
_0802995C:
	ldr r0, _0802997C @ =0x00000842
	adds r1, r4, r0
	movs r0, #0x38
_08029962:
	strh r0, [r1]
	ldr r1, _08029980 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x51
	movs r0, #1
	strb r0, [r2]
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802997C: .4byte 0x00000842
_08029980: .4byte 0x03001800
	.syntax divided
