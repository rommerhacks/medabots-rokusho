	.syntax unified

	thumb_func_start sub_08023B44
sub_08023B44: @ 0x08023B44
	push {r4, r5, lr}
	ldr r0, _08023BE8 @ =0x084D61DC
	ldr r1, _08023BEC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08023BF0 @ =0x0850E7F8
	ldr r1, _08023BF4 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08023BF8 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r2, r0
	ldrh r1, [r3]
	movs r4, #0x88
	lsls r4, r4, #2
	adds r0, r4, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _08023BFC @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08023C00 @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	ldr r1, _08023C04 @ =0x00000858
	adds r0, r2, r1
	strh r4, [r0]
	ldr r5, _08023C08 @ =0x03001800
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
	ldr r3, _08023C0C @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r4, #0xc
	adds r2, r2, r4
	movs r0, #6
	strb r0, [r2]
	ldr r4, _08023C10 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x84
	movs r1, #0x45
	strb r1, [r0]
	ldr r0, _08023C14 @ =0x083B5F80
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
_08023BE8: .4byte 0x084D61DC
_08023BEC: .4byte 0x06014800
_08023BF0: .4byte 0x0850E7F8
_08023BF4: .4byte 0x050002E0
_08023BF8: .4byte 0x03002C30
_08023BFC: .4byte 0x00000848
_08023C00: .4byte 0x00000849
_08023C04: .4byte 0x00000858
_08023C08: .4byte 0x03001800
_08023C0C: .4byte 0x00000872
_08023C10: .4byte 0x03000440
_08023C14: .4byte 0x083B5F80
	.syntax divided
