	.syntax unified

	thumb_func_start sub_08025FC8
sub_08025FC8: @ 0x08025FC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08026028 @ =0x084D513C
	ldr r1, _0802602C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08026030 @ =0x0850E678
	ldr r1, _08026034 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r5, #0
	movs r0, #0
	mov r8, r0
	movs r6, #0
	ldr r7, _08026038 @ =0x0000C404
_08025FEA:
	ldr r2, _0802603C @ =0x03002C30
	adds r1, r5, #0
	adds r1, #0x21
	lsls r0, r1, #6
	adds r4, r0, r2
	strh r7, [r4]
	mov r2, r8
	strb r2, [r4, #0x1c]
	movs r0, #0x58
	subs r0, r0, r6
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	ldr r0, _08026040 @ =0x083B5F80
	adds r0, #0xe0
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08026044 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08026048
	movs r0, #0x88
	b _08026056
	.align 2, 0
_08026028: .4byte 0x084D513C
_0802602C: .4byte 0x06014800
_08026030: .4byte 0x0850E678
_08026034: .4byte 0x050002E0
_08026038: .4byte 0x0000C404
_0802603C: .4byte 0x03002C30
_08026040: .4byte 0x083B5F80
_08026044: .4byte 0x03001800
_08026048:
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x68
_08026056:
	strh r0, [r4, #2]
	adds r6, #0x18
	adds r5, #1
	cmp r5, #2
	bls _08025FEA
	movs r0, #0x52
	bl play_sound_effect
	ldr r1, _0802607C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802607C: .4byte 0x03001800
	.syntax divided
