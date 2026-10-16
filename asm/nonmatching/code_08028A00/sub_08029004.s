	.syntax unified

	thumb_func_start sub_08029004
sub_08029004: @ 0x08029004
	push {r4, r5, r6, lr}
	ldr r0, _08029124 @ =0x084CCE48
	ldr r1, _08029128 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802912C @ =0x0850E358
	ldr r1, _08029130 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _08029134 @ =0x03002C30
	ldr r1, _08029138 @ =0x00000848
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _0802913C @ =0x00000849
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08029140 @ =0x00000858
	adds r0, r4, r1
	movs r6, #0
	strh r2, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _08029144 @ =0x083B5F80
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x84
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r3, #0x88
	lsls r3, r3, #4
	adds r1, r4, r3
	adds r0, r5, #0
	movs r2, #0x20
	bl CpuSet
	movs r0, #0x8c
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, r5, #0
	movs r2, #0x20
	bl CpuSet
	movs r3, #0x90
	lsls r3, r3, #4
	adds r1, r4, r3
	adds r0, r5, #0
	movs r2, #0x20
	bl CpuSet
	movs r0, #0x94
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, r5, #0
	movs r2, #0x20
	bl CpuSet
	ldr r1, _08029148 @ =0x00000864
	adds r0, r4, r1
	strb r6, [r0]
	ldr r3, _0802914C @ =0x000008A4
	adds r0, r4, r3
	movs r2, #2
	strb r2, [r0]
	ldr r0, _08029150 @ =0x000008A5
	adds r1, r4, r0
	movs r0, #0x1c
	strb r0, [r1]
	subs r3, #0x22
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	ldr r0, _08029154 @ =0x00000884
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	ldr r1, _08029158 @ =0x000008E4
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0x63
	adds r1, r4, r3
	movs r0, #4
	strb r0, [r1]
	ldr r0, _0802915C @ =0x000008C2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
	subs r3, #0x21
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	ldr r1, _08029160 @ =0x00000924
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0x61
	adds r1, r4, r3
	movs r0, #0x14
	strb r0, [r1]
	ldr r0, _08029164 @ =0x00000902
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	subs r3, #0x21
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
	ldr r1, _08029168 @ =0x00000964
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0x61
	adds r1, r4, r3
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, _0802916C @ =0x00000942
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
	ldr r1, _08029170 @ =0x00000944
	adds r4, r4, r1
	ldrh r0, [r4]
	adds r0, #0x10
	strh r0, [r4]
	ldr r1, _08029174 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08029124: .4byte 0x084CCE48
_08029128: .4byte 0x06014800
_0802912C: .4byte 0x0850E358
_08029130: .4byte 0x050002E0
_08029134: .4byte 0x03002C30
_08029138: .4byte 0x00000848
_0802913C: .4byte 0x00000849
_08029140: .4byte 0x00000858
_08029144: .4byte 0x083B5F80
_08029148: .4byte 0x00000864
_0802914C: .4byte 0x000008A4
_08029150: .4byte 0x000008A5
_08029154: .4byte 0x00000884
_08029158: .4byte 0x000008E4
_0802915C: .4byte 0x000008C2
_08029160: .4byte 0x00000924
_08029164: .4byte 0x00000902
_08029168: .4byte 0x00000964
_0802916C: .4byte 0x00000942
_08029170: .4byte 0x00000944
_08029174: .4byte 0x03001800
	.syntax divided
