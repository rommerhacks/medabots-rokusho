	.syntax unified

	thumb_func_start sub_08020DF8
sub_08020DF8: @ 0x08020DF8
	push {r4, r5, r6, lr}
	ldr r0, _08020EA4 @ =0x084D50DC
	ldr r1, _08020EA8 @ =0x06015800
	bl lz_decompress_dispatch
	ldr r0, _08020EAC @ =0x0850E658
	ldr r1, _08020EB0 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08020EB4 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	movs r5, #0
	ldr r0, _08020EB8 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _08020EBC @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _08020EC0 @ =0x03001800
	movs r6, #0x87
	adds r6, r6, r4
	mov ip, r6
	ldrb r0, [r6]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r6, _08020EC4 @ =0x00000842
	adds r0, r2, r6
	strh r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r6, _08020EC8 @ =0x00000844
	adds r1, r2, r6
	strh r0, [r1]
	ldr r0, _08020ECC @ =0x0000084A
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	adds r6, #7
	adds r1, r2, r6
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _08020ED0 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r6, #2
	adds r0, r2, r6
	strb r1, [r0]
	ldr r1, _08020ED4 @ =0x00000858
	adds r0, r2, r1
	strh r5, [r0]
	subs r6, #3
	adds r1, r2, r6
	movs r0, #0x82
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r1, _08020ED8 @ =0x00000863
	adds r0, r2, r1
	strb r3, [r0]
	adds r6, #0x21
	adds r2, r2, r6
	strb r3, [r2]
	movs r0, #0x29
	bl play_sound_effect
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08020EA4: .4byte 0x084D50DC
_08020EA8: .4byte 0x06015800
_08020EAC: .4byte 0x0850E658
_08020EB0: .4byte 0x050002E0
_08020EB4: .4byte 0x03002C30
_08020EB8: .4byte 0x0000C604
_08020EBC: .4byte 0x0000085C
_08020EC0: .4byte 0x03001800
_08020EC4: .4byte 0x00000842
_08020EC8: .4byte 0x00000844
_08020ECC: .4byte 0x0000084A
_08020ED0: .4byte 0x00000848
_08020ED4: .4byte 0x00000858
_08020ED8: .4byte 0x00000863
	.syntax divided
