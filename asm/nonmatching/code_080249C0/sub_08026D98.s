	.syntax unified

	thumb_func_start sub_08026D98
sub_08026D98: @ 0x08026D98
	push {r4, r5, lr}
	ldr r0, _08026E14 @ =0x084CA61C
	ldr r1, _08026E18 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _08026E1C @ =0x0850E198
	ldr r1, _08026E20 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r5, _08026E24 @ =0x03002C30
	ldr r0, _08026E28 @ =0x00000286
	adds r1, r5, r0
	movs r4, #0
	movs r0, #0xa8
	lsls r0, r0, #5
	strh r0, [r1]
	movs r0, #0x2a
	bl play_sound_effect
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, _08026E2C @ =0x0000C404
	strh r0, [r1]
	movs r3, #0xa7
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	ldr r0, _08026E30 @ =0x0000028A
	adds r1, r5, r0
	movs r0, #0xe
	strb r0, [r1]
	adds r2, #0xb
	adds r1, r5, r2
	movs r0, #0x80
	strb r0, [r1]
	adds r3, #7
	adds r0, r5, r3
	strb r4, [r0]
	ldr r2, _08026E34 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08026E60
	adds r0, r2, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #2
	bne _08026E3C
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r0, #0x10
	ldr r2, _08026E38 @ =0x00000282
	adds r1, r5, r2
	strh r0, [r1]
	b _08026E4A
	.align 2, 0
_08026E14: .4byte 0x084CA61C
_08026E18: .4byte 0x06010000
_08026E1C: .4byte 0x0850E198
_08026E20: .4byte 0x050003C0
_08026E24: .4byte 0x03002C30
_08026E28: .4byte 0x00000286
_08026E2C: .4byte 0x0000C404
_08026E30: .4byte 0x0000028A
_08026E34: .4byte 0x03001800
_08026E38: .4byte 0x00000282
_08026E3C:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	ldr r2, _08026E54 @ =0x00000282
	adds r0, r5, r2
	strh r1, [r0]
_08026E4A:
	ldr r0, _08026E58 @ =0x03002C30
	ldr r2, _08026E5C @ =0x03001800
	movs r3, #0xad
	lsls r3, r3, #1
	b _08026E96
	.align 2, 0
_08026E54: .4byte 0x00000282
_08026E58: .4byte 0x03002C30
_08026E5C: .4byte 0x03001800
_08026E60:
	adds r0, r2, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #1
	bne _08026E80
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r0, #0x10
	ldr r2, _08026E7C @ =0x00000282
	adds r1, r5, r2
	strh r0, [r1]
	b _08026E8E
	.align 2, 0
_08026E7C: .4byte 0x00000282
_08026E80:
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	ldr r2, _08026EB4 @ =0x00000282
	adds r0, r5, r2
	strh r1, [r0]
_08026E8E:
	ldr r0, _08026EB8 @ =0x03002C30
	ldr r2, _08026EBC @ =0x03001800
	movs r3, #0xab
	lsls r3, r3, #1
_08026E96:
	adds r1, r2, r3
	ldrh r1, [r1]
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r1, [r0]
	adds r1, r2, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08026EB4: .4byte 0x00000282
_08026EB8: .4byte 0x03002C30
_08026EBC: .4byte 0x03001800
_08026EC0:
	.byte 0x02, 0x48, 0xAA, 0x30, 0x02, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.syntax divided
