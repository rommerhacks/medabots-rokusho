	.syntax unified

	thumb_func_start sub_0801F018
sub_0801F018: @ 0x0801F018
	push {r4, lr}
	ldr r0, _0801F088 @ =0x084CC5F8
	ldr r1, _0801F08C @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801F090 @ =0x0850E2F8
	ldr r1, _0801F094 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0801F098 @ =0x03002C30
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #0
	ldr r0, _0801F09C @ =0x0000C404
	strh r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
	ldr r4, _0801F0A0 @ =0x0000028A
	adds r1, r3, r4
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, _0801F0A4 @ =0x0000028B
	adds r1, r3, r0
	movs r0, #0x80
	strb r0, [r1]
	subs r4, #4
	adds r1, r3, r4
	movs r0, #0x80
	lsls r0, r0, #6
	strh r0, [r1]
	ldr r1, _0801F0A8 @ =0x000002A3
	adds r0, r3, r1
	strb r2, [r0]
	ldr r2, _0801F0AC @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801F0B4
	movs r4, #0xac
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	ldr r4, _0801F0B0 @ =0x00000282
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	b _0801F0C6
	.align 2, 0
_0801F088: .4byte 0x084CC5F8
_0801F08C: .4byte 0x06010000
_0801F090: .4byte 0x0850E2F8
_0801F094: .4byte 0x050003C0
_0801F098: .4byte 0x03002C30
_0801F09C: .4byte 0x0000C404
_0801F0A0: .4byte 0x0000028A
_0801F0A4: .4byte 0x0000028B
_0801F0A8: .4byte 0x000002A3
_0801F0AC: .4byte 0x03001800
_0801F0B0: .4byte 0x00000282
_0801F0B4:
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r1, [r0]
	ldr r4, _0801F0E8 @ =0x00000282
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xab
	lsls r1, r1, #1
_0801F0C6:
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	movs r0, #0x2a
	bl play_sound_effect
	ldr r1, _0801F0EC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801F0E8: .4byte 0x00000282
_0801F0EC: .4byte 0x03001800
	.syntax divided
