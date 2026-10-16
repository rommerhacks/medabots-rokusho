	.syntax unified

	thumb_func_start sub_0801E5DC
sub_0801E5DC: @ 0x0801E5DC
	push {r4, lr}
	ldr r2, _0801E638 @ =0x03000590
	ldr r3, _0801E63C @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r3, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x30
	bne _0801E658
	adds r0, r3, #0
	adds r0, #0x88
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x8b
	ldrb r1, [r1]
	bl sub_08036B84
	ldr r0, _0801E640 @ =0x084CC7C8
	ldr r1, _0801E644 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801E648 @ =0x0850E318
	ldr r1, _0801E64C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801E650 @ =0x03002C30
	ldr r1, _0801E654 @ =0x00000286
	adds r0, r0, r1
	movs r1, #0x84
	lsls r1, r1, #6
	strh r1, [r0]
	movs r0, #0x54
	bl play_sound_effect
	b _0801E740
	.align 2, 0
_0801E638: .4byte 0x03000590
_0801E63C: .4byte 0x03001800
_0801E640: .4byte 0x084CC7C8
_0801E644: .4byte 0x06010000
_0801E648: .4byte 0x0850E318
_0801E64C: .4byte 0x050003C0
_0801E650: .4byte 0x03002C30
_0801E654: .4byte 0x00000286
_0801E658:
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801E6AC
	cmp r0, #1
	bgt _0801E66C
	cmp r0, #0
	beq _0801E676
	b _0801E73A
_0801E66C:
	cmp r0, #2
	beq _0801E6E4
	cmp r0, #3
	beq _0801E71C
	b _0801E73A
_0801E676:
	ldr r0, _0801E694 @ =0x084CB950
	ldr r1, _0801E698 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801E69C @ =0x0850E258
	ldr r1, _0801E6A0 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801E6A4 @ =0x03002C30
	ldr r4, _0801E6A8 @ =0x00000286
	adds r0, r0, r4
	movs r1, #0xd8
	lsls r1, r1, #5
	b _0801E738
	.align 2, 0
_0801E694: .4byte 0x084CB950
_0801E698: .4byte 0x06010000
_0801E69C: .4byte 0x0850E258
_0801E6A0: .4byte 0x050003C0
_0801E6A4: .4byte 0x03002C30
_0801E6A8: .4byte 0x00000286
_0801E6AC:
	ldr r0, _0801E6CC @ =0x084CBC10
	ldr r1, _0801E6D0 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801E6D4 @ =0x0850E278
	ldr r1, _0801E6D8 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801E6DC @ =0x03002C30
	ldr r1, _0801E6E0 @ =0x00000286
	adds r0, r0, r1
	movs r1, #0xe0
	lsls r1, r1, #5
	b _0801E738
	.align 2, 0
_0801E6CC: .4byte 0x084CBC10
_0801E6D0: .4byte 0x06010000
_0801E6D4: .4byte 0x0850E278
_0801E6D8: .4byte 0x050003C0
_0801E6DC: .4byte 0x03002C30
_0801E6E0: .4byte 0x00000286
_0801E6E4:
	ldr r0, _0801E704 @ =0x084CBF04
	ldr r1, _0801E708 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801E70C @ =0x0850E298
	ldr r1, _0801E710 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801E714 @ =0x03002C30
	ldr r4, _0801E718 @ =0x00000286
	adds r0, r0, r4
	movs r1, #0xe8
	lsls r1, r1, #5
	b _0801E738
	.align 2, 0
_0801E704: .4byte 0x084CBF04
_0801E708: .4byte 0x06010000
_0801E70C: .4byte 0x0850E298
_0801E710: .4byte 0x050003C0
_0801E714: .4byte 0x03002C30
_0801E718: .4byte 0x00000286
_0801E71C:
	ldr r0, _0801E798 @ =0x084CC19C
	ldr r1, _0801E79C @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801E7A0 @ =0x0850E2B8
	ldr r1, _0801E7A4 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801E7A8 @ =0x03002C30
	ldr r1, _0801E7AC @ =0x00000286
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #5
_0801E738:
	strh r1, [r0]
_0801E73A:
	movs r0, #6
	bl play_sound_effect
_0801E740:
	ldr r2, _0801E7A8 @ =0x03002C30
	movs r4, #0xa0
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r3, #0
	ldr r0, _0801E7B0 @ =0x0000C404
	strh r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r3, [r0]
	adds r4, #0xa
	adds r1, r2, r4
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, _0801E7B4 @ =0x0000028B
	adds r1, r2, r0
	movs r0, #0x80
	strb r0, [r1]
	ldr r1, _0801E7B8 @ =0x000002A3
	adds r0, r2, r1
	strb r3, [r0]
	ldr r3, _0801E7BC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801E7DC
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #2
	bne _0801E7C4
	movs r4, #0xac
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrh r0, [r0]
	subs r0, #0x10
	ldr r4, _0801E7C0 @ =0x00000282
	adds r1, r2, r4
	strh r0, [r1]
	b _0801E7D2
	.align 2, 0
_0801E798: .4byte 0x084CC19C
_0801E79C: .4byte 0x06010000
_0801E7A0: .4byte 0x0850E2B8
_0801E7A4: .4byte 0x050003C0
_0801E7A8: .4byte 0x03002C30
_0801E7AC: .4byte 0x00000286
_0801E7B0: .4byte 0x0000C404
_0801E7B4: .4byte 0x0000028B
_0801E7B8: .4byte 0x000002A3
_0801E7BC: .4byte 0x03001800
_0801E7C0: .4byte 0x00000282
_0801E7C4:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r4, _0801E7D8 @ =0x00000282
	adds r0, r2, r4
	strh r1, [r0]
_0801E7D2:
	movs r1, #0xad
	lsls r1, r1, #1
	b _0801E80E
	.align 2, 0
_0801E7D8: .4byte 0x00000282
_0801E7DC:
	adds r0, r3, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801E7FC
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r0, #0x10
	ldr r4, _0801E7F8 @ =0x00000282
	adds r1, r2, r4
	strh r0, [r1]
	b _0801E80A
	.align 2, 0
_0801E7F8: .4byte 0x00000282
_0801E7FC:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r4, _0801E82C @ =0x00000282
	adds r0, r2, r4
	strh r1, [r0]
_0801E80A:
	movs r1, #0xab
	lsls r1, r1, #1
_0801E80E:
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
_0801E82C: .4byte 0x00000282
	.syntax divided
