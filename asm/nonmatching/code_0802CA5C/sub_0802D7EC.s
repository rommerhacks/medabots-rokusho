	.syntax unified

	thumb_func_start sub_0802D7EC
sub_0802D7EC: @ 0x0802D7EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r0, _0802D8B0 @ =0x084D651C
	ldr r1, _0802D8B4 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802D8B8 @ =0x0850E858
	ldr r1, _0802D8BC @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r3, #0
	ldr r0, _0802D8C0 @ =0x03001800
	mov sl, r0
	ldr r4, _0802D8C4 @ =0x03002C30
	movs r7, #0
	mov sb, r7
	movs r0, #0
	mov r8, r0
	movs r6, #0x40
	ldr r5, _0802D8C0 @ =0x03001800
	adds r5, #0x60
	ldr r7, _0802D8C8 @ =0x00000864
	adds r1, r4, r7
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r7, _0802D8CC @ =0x0000C624
	mov ip, r7
_0802D834:
	mov r0, sl
	adds r0, #0xd2
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D88C
	mov r0, ip
	strh r0, [r2]
	mov r7, sb
	strb r7, [r2, #0x1c]
	movs r0, #0x78
	strh r0, [r2, #2]
	movs r0, #0x40
	strh r0, [r2, #4]
	movs r0, #7
	strb r0, [r2, #0xa]
	movs r0, #0xf0
	strb r0, [r2, #0xb]
	strb r6, [r2, #8]
	strb r6, [r2, #9]
	mov r0, r8
	strh r0, [r2, #0x18]
	ldrb r0, [r5]
	adds r0, r0, r3
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	strh r0, [r2, #0x30]
	ldrb r0, [r5]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r2, #0x32]
	movs r0, #6
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #7
	strh r0, [r2, #6]
_0802D88C:
	adds r1, #0x40
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802D834
	ldr r1, _0802D8C0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D8B0: .4byte 0x084D651C
_0802D8B4: .4byte 0x06014800
_0802D8B8: .4byte 0x0850E858
_0802D8BC: .4byte 0x050002E0
_0802D8C0: .4byte 0x03001800
_0802D8C4: .4byte 0x03002C30
_0802D8C8: .4byte 0x00000864
_0802D8CC: .4byte 0x0000C624
	.syntax divided
