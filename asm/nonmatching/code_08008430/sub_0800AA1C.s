	.syntax unified

	thumb_func_start sub_0800AA1C
sub_0800AA1C: @ 0x0800AA1C
	push {r4, lr}
	ldr r1, _0800AAA8 @ =0x083B7EBC
	ldr r4, _0800AAAC @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x45
	strb r0, [r1]
	ldr r0, _0800AAB0 @ =0x03002C30
	mov ip, r0
	movs r1, #0xc0
	lsls r1, r1, #1
	add r1, ip
	movs r3, #0
	ldr r0, _0800AAB4 @ =0x0000C004
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x44
	ldrb r0, [r1]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #3
	movs r4, #0xc1
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	ldrb r0, [r1]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	lsls r0, r0, #3
	movs r1, #0xc2
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0xc2
	lsls r0, r0, #2
	strh r0, [r1]
	movs r1, #0xc5
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0xe
	strb r0, [r1]
	movs r0, #0xce
	lsls r0, r0, #1
	add r0, ip
	strb r3, [r0]
	ldr r1, _0800AAB8 @ =0x0000018B
	add r1, ip
	movs r0, #0xc1
	strb r0, [r1]
	ldr r0, _0800AABC @ =0x083B5F80
	ldr r0, [r0, #0xc]
	movs r1, #6
	bl init_battle_sprite_entry_08040B90
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AAA8: .4byte 0x083B7EBC
_0800AAAC: .4byte 0x03000440
_0800AAB0: .4byte 0x03002C30
_0800AAB4: .4byte 0x0000C004
_0800AAB8: .4byte 0x0000018B
_0800AABC: .4byte 0x083B5F80
	.syntax divided
