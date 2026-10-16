	.syntax unified

	thumb_func_start sub_0801E918
sub_0801E918: @ 0x0801E918
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _0801E944 @ =0x084D1824
	ldr r1, _0801E948 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801E94C @ =0x0850E018
	ldr r1, _0801E950 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _0801E954 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801E958
	movs r1, #0xac
	lsls r1, r1, #1
	b _0801E95C
	.align 2, 0
_0801E944: .4byte 0x084D1824
_0801E948: .4byte 0x06010000
_0801E94C: .4byte 0x0850E018
_0801E950: .4byte 0x050003C0
_0801E954: .4byte 0x03001800
_0801E958:
	movs r1, #0xaa
	lsls r1, r1, #1
_0801E95C:
	adds r0, r2, r1
	ldrh r7, [r0]
	adds r1, #2
	adds r0, r2, r1
	ldrh r6, [r0]
	ldr r4, _0801E9A8 @ =0x0300052E
	ldr r5, _0801E9AC @ =0x03001800
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #1
	bl set_display_digit_type
	adds r0, r5, #0
	adds r0, #0x8b
	ldrb r2, [r0]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_080368C4
	movs r0, #0x5b
	bl play_sound_effect
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801E9A8: .4byte 0x0300052E
_0801E9AC: .4byte 0x03001800
	.syntax divided
