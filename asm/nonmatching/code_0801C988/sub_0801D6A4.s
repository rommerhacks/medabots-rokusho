	.syntax unified

	thumb_func_start sub_0801D6A4
sub_0801D6A4: @ 0x0801D6A4
	push {lr}
	ldr r0, _0801D6BC @ =0x03001800
	adds r0, #0xdf
	ldrb r0, [r0]
	cmp r0, #0x1c
	beq _0801D6E0
	cmp r0, #0x1c
	bgt _0801D6C0
	cmp r0, #0x1b
	beq _0801D6C6
	b _0801D716
	.align 2, 0
_0801D6BC: .4byte 0x03001800
_0801D6C0:
	cmp r0, #0x1d
	beq _0801D704
	b _0801D716
_0801D6C6:
	ldr r0, _0801D6D4 @ =0x084C9880
	ldr r1, _0801D6D8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801D6DC @ =0x0850E0F8
	b _0801D6EA
	.align 2, 0
_0801D6D4: .4byte 0x084C9880
_0801D6D8: .4byte 0x06014800
_0801D6DC: .4byte 0x0850E0F8
_0801D6E0:
	ldr r0, _0801D6F4 @ =0x084C9B88
	ldr r1, _0801D6F8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801D6FC @ =0x0850E118
_0801D6EA:
	ldr r1, _0801D700 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	b _0801D716
	.align 2, 0
_0801D6F4: .4byte 0x084C9B88
_0801D6F8: .4byte 0x06014800
_0801D6FC: .4byte 0x0850E118
_0801D700: .4byte 0x050002C0
_0801D704:
	ldr r0, _0801D724 @ =0x084C9E9C
	ldr r1, _0801D728 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801D72C @ =0x0850E138
	ldr r1, _0801D730 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
_0801D716:
	ldr r1, _0801D734 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801D724: .4byte 0x084C9E9C
_0801D728: .4byte 0x06014800
_0801D72C: .4byte 0x0850E138
_0801D730: .4byte 0x050002C0
_0801D734: .4byte 0x03001800
	.syntax divided
