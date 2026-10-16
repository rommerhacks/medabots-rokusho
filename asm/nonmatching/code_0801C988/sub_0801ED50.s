	.syntax unified

	thumb_func_start sub_0801ED50
sub_0801ED50: @ 0x0801ED50
	push {r4, lr}
	ldr r3, _0801ED9C @ =0x03000590
	ldr r2, _0801EDA0 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, #0x87
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x30
	bne _0801EDBC
	ldr r0, _0801EDA4 @ =0x084CC7C8
	ldr r1, _0801EDA8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801EDAC @ =0x0850E318
	ldr r1, _0801EDB0 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801EDB4 @ =0x03002C30
	ldr r1, _0801EDB8 @ =0x00000286
	adds r0, r0, r1
	movs r1, #0x84
	lsls r1, r1, #6
	strh r1, [r0]
	movs r0, #0x54
	bl play_sound_effect
	b _0801EDE0
	.align 2, 0
_0801ED9C: .4byte 0x03000590
_0801EDA0: .4byte 0x03001800
_0801EDA4: .4byte 0x084CC7C8
_0801EDA8: .4byte 0x06010000
_0801EDAC: .4byte 0x0850E318
_0801EDB0: .4byte 0x050003C0
_0801EDB4: .4byte 0x03002C30
_0801EDB8: .4byte 0x00000286
_0801EDBC:
	ldr r0, _0801EE38 @ =0x084CA61C
	ldr r1, _0801EE3C @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801EE40 @ =0x0850E198
	ldr r1, _0801EE44 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801EE48 @ =0x03002C30
	ldr r4, _0801EE4C @ =0x00000286
	adds r0, r0, r4
	movs r1, #0xa8
	lsls r1, r1, #5
	strh r1, [r0]
	movs r0, #0x2a
	bl play_sound_effect
_0801EDE0:
	ldr r2, _0801EE48 @ =0x03002C30
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _0801EE50 @ =0x0000C404
	strh r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _0801EE54 @ =0x0000028A
	adds r1, r2, r4
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, _0801EE58 @ =0x0000028B
	adds r1, r2, r0
	movs r0, #0x80
	strb r0, [r1]
	ldr r1, _0801EE5C @ =0x000002A3
	adds r0, r2, r1
	strb r3, [r0]
	ldr r3, _0801EE60 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801EE80
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #2
	bne _0801EE68
	movs r4, #0xac
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrh r0, [r0]
	subs r0, #0x10
	ldr r4, _0801EE64 @ =0x00000282
	adds r1, r2, r4
	strh r0, [r1]
	b _0801EE76
	.align 2, 0
_0801EE38: .4byte 0x084CA61C
_0801EE3C: .4byte 0x06010000
_0801EE40: .4byte 0x0850E198
_0801EE44: .4byte 0x050003C0
_0801EE48: .4byte 0x03002C30
_0801EE4C: .4byte 0x00000286
_0801EE50: .4byte 0x0000C404
_0801EE54: .4byte 0x0000028A
_0801EE58: .4byte 0x0000028B
_0801EE5C: .4byte 0x000002A3
_0801EE60: .4byte 0x03001800
_0801EE64: .4byte 0x00000282
_0801EE68:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r4, _0801EE7C @ =0x00000282
	adds r0, r2, r4
	strh r1, [r0]
_0801EE76:
	movs r1, #0xad
	lsls r1, r1, #1
	b _0801EEB2
	.align 2, 0
_0801EE7C: .4byte 0x00000282
_0801EE80:
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801EEA0
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r0, #0x10
	ldr r4, _0801EE9C @ =0x00000282
	adds r1, r2, r4
	strh r0, [r1]
	b _0801EEAE
	.align 2, 0
_0801EE9C: .4byte 0x00000282
_0801EEA0:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r4, _0801EED0 @ =0x00000282
	adds r0, r2, r4
	strh r1, [r0]
_0801EEAE:
	movs r1, #0xab
	lsls r1, r1, #1
_0801EEB2:
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r4, #0xa1
	lsls r4, r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801EED0: .4byte 0x00000282
_0801EED4:
	.byte 0x02, 0x48, 0xAA, 0x30, 0x0A, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
