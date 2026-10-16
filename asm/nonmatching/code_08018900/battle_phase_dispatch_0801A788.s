	.syntax unified

	thumb_func_start battle_phase_dispatch_0801A788
	.global battle_phase_dispatch_0801A788
battle_phase_dispatch_0801A788: @ 0x0801A788
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	ldr r0, _0801A7AC @ =0x03000440
	movs r3, #0x9d
	lsls r3, r3, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r3, r0, #0
	cmp r1, #8
	bls _0801A7A0
	b _0801ABEC
_0801A7A0:
	lsls r0, r1, #2
	ldr r1, _0801A7B0 @ =_0801A7B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A7AC: .4byte 0x03000440
_0801A7B0: .4byte _0801A7B4
_0801A7B4: @ jump table
	.4byte _0801A7D8 @ case 0
	.4byte _0801A818 @ case 1
	.4byte _0801A85C @ case 2
	.4byte _0801A8BC @ case 3
	.4byte _0801A910 @ case 4
	.4byte _0801A950 @ case 5
	.4byte _0801A958 @ case 6
	.4byte _0801A998 @ case 7
	.4byte _0801A9C8 @ case 8
_0801A7D8:
	ldr r0, _0801A7FC @ =0x084C4F00
	ldr r1, _0801A800 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _0801A804 @ =0x084C4F8C
	ldr r1, _0801A808 @ =0x06004140
	bl lz_decompress_dispatch
	ldr r0, _0801A80C @ =0x084879F0
	ldr r1, _0801A810 @ =0x06004200
	bl lz_decompress_dispatch
	ldr r0, _0801A814 @ =0x03000440
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r0, r2
	b _0801A9B6
	.align 2, 0
_0801A7FC: .4byte 0x084C4F00
_0801A800: .4byte 0x06004000
_0801A804: .4byte 0x084C4F8C
_0801A808: .4byte 0x06004140
_0801A80C: .4byte 0x084879F0
_0801A810: .4byte 0x06004200
_0801A814: .4byte 0x03000440
_0801A818:
	ldr r0, _0801A83C @ =0x084C5080
	ldr r1, _0801A840 @ =0x06004300
	bl lz_decompress_dispatch
	ldr r0, _0801A844 @ =0x084C3648
	ldr r1, _0801A848 @ =0x06004400
	bl lz_decompress_dispatch
	ldr r0, _0801A84C @ =0x08487A24
	ldr r1, _0801A850 @ =0x0600C000
	bl lz_decompress_dispatch
	ldr r0, _0801A854 @ =0x084C5008
	ldr r1, _0801A858 @ =0x0600C600
	bl lz_decompress_dispatch
	b _0801A9AE
	.align 2, 0
_0801A83C: .4byte 0x084C5080
_0801A840: .4byte 0x06004300
_0801A844: .4byte 0x084C3648
_0801A848: .4byte 0x06004400
_0801A84C: .4byte 0x08487A24
_0801A850: .4byte 0x0600C000
_0801A854: .4byte 0x084C5008
_0801A858: .4byte 0x0600C600
_0801A85C:
	ldr r0, _0801A890 @ =0x08487E68
	ldr r1, _0801A894 @ =0x06004E00
	bl lz_decompress_dispatch
	ldr r0, _0801A898 @ =0x08487F64
	ldr r1, _0801A89C @ =0x06005100
	bl lz_decompress_dispatch
	ldr r0, _0801A8A0 @ =0x0848803C
	ldr r1, _0801A8A4 @ =0x06005400
	bl lz_decompress_dispatch
	ldr r0, _0801A8A8 @ =0x08488114
	ldr r1, _0801A8AC @ =0x06005700
	bl lz_decompress_dispatch
	ldr r0, _0801A8B0 @ =0x084881EC
	ldr r1, _0801A8B4 @ =0x06005A00
	bl lz_decompress_dispatch
	ldr r0, _0801A8B8 @ =0x03000440
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r0, r2
	b _0801A9B6
	.align 2, 0
_0801A890: .4byte 0x08487E68
_0801A894: .4byte 0x06004E00
_0801A898: .4byte 0x08487F64
_0801A89C: .4byte 0x06005100
_0801A8A0: .4byte 0x0848803C
_0801A8A4: .4byte 0x06005400
_0801A8A8: .4byte 0x08488114
_0801A8AC: .4byte 0x06005700
_0801A8B0: .4byte 0x084881EC
_0801A8B4: .4byte 0x06005A00
_0801A8B8: .4byte 0x03000440
_0801A8BC:
	ldr r0, _0801A8E8 @ =0x084C4BAC
	ldr r1, _0801A8EC @ =0x0600C280
	bl lz_decompress_dispatch
	ldr r0, _0801A8F0 @ =0x084C7634
	ldr r1, _0801A8F4 @ =0x06012000
	bl lz_decompress_dispatch
	ldr r0, _0801A8F8 @ =0x084C8AC4
	ldr r1, _0801A8FC @ =0x06014E00
	bl lz_decompress_dispatch
	ldr r0, _0801A900 @ =0x084C984C
	ldr r1, _0801A904 @ =0x06017F80
	bl lz_decompress_dispatch
	ldr r0, _0801A908 @ =0x084C6A98
	ldr r1, _0801A90C @ =0x06017400
	bl lz_decompress_dispatch
	b _0801A9AE
	.align 2, 0
_0801A8E8: .4byte 0x084C4BAC
_0801A8EC: .4byte 0x0600C280
_0801A8F0: .4byte 0x084C7634
_0801A8F4: .4byte 0x06012000
_0801A8F8: .4byte 0x084C8AC4
_0801A8FC: .4byte 0x06014E00
_0801A900: .4byte 0x084C984C
_0801A904: .4byte 0x06017F80
_0801A908: .4byte 0x084C6A98
_0801A90C: .4byte 0x06017400
_0801A910:
	ldr r0, _0801A934 @ =0x08487B80
	ldr r1, _0801A938 @ =0x06004600
	bl lz_decompress_dispatch
	ldr r0, _0801A93C @ =0x08487C94
	ldr r1, _0801A940 @ =0x06004800
	bl lz_decompress_dispatch
	ldr r0, _0801A944 @ =0x08487D6C
	ldr r1, _0801A948 @ =0x06004B00
	bl lz_decompress_dispatch
	ldr r0, _0801A94C @ =0x03000440
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r0, r2
	b _0801A9B6
	.align 2, 0
_0801A934: .4byte 0x08487B80
_0801A938: .4byte 0x06004600
_0801A93C: .4byte 0x08487C94
_0801A940: .4byte 0x06004800
_0801A944: .4byte 0x08487D6C
_0801A948: .4byte 0x06004B00
_0801A94C: .4byte 0x03000440
_0801A950:
	movs r0, #0x9d
	lsls r0, r0, #1
	adds r1, r3, r0
	b _0801A9B6
_0801A958:
	ldr r0, _0801A97C @ =0x084C7FC0
	ldr r1, _0801A980 @ =0x06013000
	bl lz_decompress_dispatch
	ldr r0, _0801A984 @ =0x084E2950
	ldr r1, _0801A988 @ =0x06013C00
	bl lz_decompress_dispatch
	ldr r0, _0801A98C @ =0x084E2C18
	ldr r1, _0801A990 @ =0x06014200
	bl lz_decompress_dispatch
	ldr r0, _0801A994 @ =0x03000440
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r0, r2
	b _0801A9B6
	.align 2, 0
_0801A97C: .4byte 0x084C7FC0
_0801A980: .4byte 0x06013000
_0801A984: .4byte 0x084E2950
_0801A988: .4byte 0x06013C00
_0801A98C: .4byte 0x084E2C18
_0801A990: .4byte 0x06014200
_0801A994: .4byte 0x03000440
_0801A998:
	ldr r0, _0801A9C0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
_0801A9AE:
	ldr r0, _0801A9C4 @ =0x03000440
	movs r3, #0x9d
	lsls r3, r3, #1
	adds r1, r0, r3
_0801A9B6:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801ABEC
	.align 2, 0
_0801A9C0: .4byte 0x0400000A
_0801A9C4: .4byte 0x03000440
_0801A9C8:
	cmp r2, #0
	beq _0801A9CE
	b _0801AAE0
_0801A9CE:
	ldr r0, _0801AA78 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _0801AA7C @ =0x03001800
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #1
	bl decompress_sprite_to_vram_08043C08
	ldr r0, _0801AA80 @ =0x084C6A18
	ldr r1, _0801AA84 @ =0x0202FB00
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AA88 @ =0x08488AC4
	ldr r1, _0801AA8C @ =0x0202FB40
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AA90 @ =0x08488B04
	ldr r1, _0801AA94 @ =0x0202FB60
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AA98 @ =0x08488AE4
	ldr r1, _0801AA9C @ =0x0202FB80
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AAA0 @ =0x084C6A38
	ldr r1, _0801AAA4 @ =0x0202FBA0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AAA8 @ =0x084E2EF8
	ldr r1, _0801AAAC @ =0x0202F900
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AAB0 @ =0x084E2F18
	ldr r1, _0801AAB4 @ =0x0202F920
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AAB8 @ =0x084E2F38
	ldr r1, _0801AABC @ =0x0202F940
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AAC0 @ =0x0850DFF8
	ldr r1, _0801AAC4 @ =0x0202F960
	movs r2, #0x10
	bl CpuFastSet
	ldr r4, _0801AAC8 @ =0x0850DDB8
	ldr r1, _0801AACC @ =0x0202F9A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x20
	ldr r1, _0801AAD0 @ =0x0202F9C0
	movs r2, #8
	bl CpuFastSet
	adds r4, #0x40
	ldr r1, _0801AAD4 @ =0x0202F9E0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AAD8 @ =0x0850E0D8
	ldr r1, _0801AADC @ =0x0202F8A0
	movs r2, #8
	bl CpuFastSet
	b _0801AB74
	.align 2, 0
_0801AA78: .4byte 0x04000008
_0801AA7C: .4byte 0x03001800
_0801AA80: .4byte 0x084C6A18
_0801AA84: .4byte 0x0202FB00
_0801AA88: .4byte 0x08488AC4
_0801AA8C: .4byte 0x0202FB40
_0801AA90: .4byte 0x08488B04
_0801AA94: .4byte 0x0202FB60
_0801AA98: .4byte 0x08488AE4
_0801AA9C: .4byte 0x0202FB80
_0801AAA0: .4byte 0x084C6A38
_0801AAA4: .4byte 0x0202FBA0
_0801AAA8: .4byte 0x084E2EF8
_0801AAAC: .4byte 0x0202F900
_0801AAB0: .4byte 0x084E2F18
_0801AAB4: .4byte 0x0202F920
_0801AAB8: .4byte 0x084E2F38
_0801AABC: .4byte 0x0202F940
_0801AAC0: .4byte 0x0850DFF8
_0801AAC4: .4byte 0x0202F960
_0801AAC8: .4byte 0x0850DDB8
_0801AACC: .4byte 0x0202F9A0
_0801AAD0: .4byte 0x0202F9C0
_0801AAD4: .4byte 0x0202F9E0
_0801AAD8: .4byte 0x0850E0D8
_0801AADC: .4byte 0x0202F8A0
_0801AAE0:
	ldr r0, _0801AB84 @ =0x03001800
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #0
	bl decompress_sprite_to_vram_08043C08
	ldr r0, _0801AB88 @ =0x084C6A18
	ldr r1, _0801AB8C @ =0x05000100
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AB90 @ =0x08488AC4
	ldr r1, _0801AB94 @ =0x05000140
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801AB98 @ =0x08488B04
	ldr r1, _0801AB9C @ =0x05000160
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801ABA0 @ =0x08488AE4
	ldr r1, _0801ABA4 @ =0x05000180
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801ABA8 @ =0x084C6A38
	ldr r1, _0801ABAC @ =0x050001A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801ABB0 @ =0x084E2EF8
	ldr r1, _0801ABB4 @ =0x05000300
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801ABB8 @ =0x084E2F18
	ldr r1, _0801ABBC @ =0x05000320
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801ABC0 @ =0x084E2F38
	ldr r1, _0801ABC4 @ =0x05000340
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801ABC8 @ =0x0850DFF8
	ldr r1, _0801ABCC @ =0x05000360
	movs r2, #0x10
	bl CpuFastSet
	ldr r4, _0801ABD0 @ =0x0850DDB8
	ldr r1, _0801ABD4 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x20
	ldr r1, _0801ABD8 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	adds r4, #0x40
	ldr r1, _0801ABDC @ =0x050003E0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801ABE0 @ =0x0850E0D8
	ldr r1, _0801ABE4 @ =0x050002A0
	movs r2, #8
	bl CpuFastSet
_0801AB74:
	ldr r0, _0801ABE8 @ =0x03000440
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0801ABEE
	.align 2, 0
_0801AB84: .4byte 0x03001800
_0801AB88: .4byte 0x084C6A18
_0801AB8C: .4byte 0x05000100
_0801AB90: .4byte 0x08488AC4
_0801AB94: .4byte 0x05000140
_0801AB98: .4byte 0x08488B04
_0801AB9C: .4byte 0x05000160
_0801ABA0: .4byte 0x08488AE4
_0801ABA4: .4byte 0x05000180
_0801ABA8: .4byte 0x084C6A38
_0801ABAC: .4byte 0x050001A0
_0801ABB0: .4byte 0x084E2EF8
_0801ABB4: .4byte 0x05000300
_0801ABB8: .4byte 0x084E2F18
_0801ABBC: .4byte 0x05000320
_0801ABC0: .4byte 0x084E2F38
_0801ABC4: .4byte 0x05000340
_0801ABC8: .4byte 0x0850DFF8
_0801ABCC: .4byte 0x05000360
_0801ABD0: .4byte 0x0850DDB8
_0801ABD4: .4byte 0x050003A0
_0801ABD8: .4byte 0x050003C0
_0801ABDC: .4byte 0x050003E0
_0801ABE0: .4byte 0x0850E0D8
_0801ABE4: .4byte 0x050002A0
_0801ABE8: .4byte 0x03000440
_0801ABEC:
	movs r0, #0
_0801ABEE:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
