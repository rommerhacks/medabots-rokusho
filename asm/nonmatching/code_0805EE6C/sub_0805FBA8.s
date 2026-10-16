	.syntax unified

	thumb_func_start sub_0805FBA8
sub_0805FBA8: @ 0x0805FBA8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r2, _0805FCB4 @ =0x04000008
	movs r0, #1
	mov sb, r0
	ldr r0, _0805FCB8 @ =0x00001F04
	strh r0, [r2]
	ldr r1, _0805FCBC @ =0x0400000A
	subs r0, #0xff
	strh r0, [r1]
	ldr r4, _0805FCC0 @ =0x0400000C
	subs r0, #0xff
	strh r0, [r4]
	ldr r5, _0805FCC4 @ =0x0400000E
	ldr r0, _0805FCC8 @ =0x00003C07
	strh r0, [r5]
	ldr r0, _0805FCCC @ =0x087962E8
	ldrh r1, [r2]
	bl decompress_and_write_tilemap
	ldr r0, _0805FCD0 @ =0x08796474
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _0805FCD4 @ =0x08796598
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _0805FCD8 @ =0x0879579C
	ldr r5, _0805FCDC @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r1, _0805FCE0 @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	bl CpuSet
	ldr r0, _0805FCE4 @ =0x08784CB0
	ldr r2, _0805FCE0 @ =0x06004000
	adds r1, r4, r2
	bl lz_decompress_dispatch
	ldr r6, _0805FCE8 @ =0x03006F74
	ldr r0, [r6]
	lsrs r4, r4, #5
	subs r4, #1
	movs r1, #0
	mov r8, r1
	movs r5, #0
	strh r4, [r0, #0x36]
	ldr r0, _0805FCEC @ =0x0879559C
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _0805FCF0 @ =0x080AF900
	ldr r1, _0805FCF4 @ =0x05000200
	movs r2, #0x10
	bl CpuFastSet
	ldr r0, _0805FCF8 @ =0x08785F34
	ldr r1, _0805FCFC @ =0x06010000
	bl lz_decompress_dispatch
	ldr r2, _0805FD00 @ =0x03002C30
	mov ip, r2
	ldr r0, _0805FD04 @ =0x00008A20
	strh r0, [r2]
	movs r3, #2
	strb r3, [r2, #0x1c]
	movs r4, #0x78
	strh r4, [r2, #2]
	ldr r0, _0805FD08 @ =0x0000FFE0
	strh r0, [r2, #4]
	mov r0, r8
	strb r0, [r2, #0xa]
	movs r0, #0x84
	lsls r0, r0, #1
	strh r0, [r2, #6]
	movs r2, #0x80
	mov r1, ip
	strb r2, [r1, #8]
	strb r2, [r1, #9]
	strh r5, [r1, #0x18]
	adds r1, #0x40
	ldr r0, _0805FD0C @ =0x00008220
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x5c
	strb r3, [r0]
	subs r0, #0x1a
	strh r4, [r0]
	adds r1, #4
	ldr r0, _0805FD10 @ =0x0000FFC0
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	mov r1, sb
	strb r1, [r0]
	mov r1, ip
	adds r1, #0x46
	ldr r0, _0805FD14 @ =0x00000109
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x48
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0xf
	strh r5, [r0]
	ldr r1, [r6]
	strh r5, [r1, #2]
	movs r0, #0x3c
	strb r0, [r1, #0x15]
	ldr r0, [r6]
	mov r2, r8
	strb r2, [r0, #0x16]
	ldr r1, _0805FD18 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805FCB4: .4byte 0x04000008
_0805FCB8: .4byte 0x00001F04
_0805FCBC: .4byte 0x0400000A
_0805FCC0: .4byte 0x0400000C
_0805FCC4: .4byte 0x0400000E
_0805FCC8: .4byte 0x00003C07
_0805FCCC: .4byte 0x087962E8
_0805FCD0: .4byte 0x08796474
_0805FCD4: .4byte 0x08796598
_0805FCD8: .4byte 0x0879579C
_0805FCDC: .4byte 0x02030000
_0805FCE0: .4byte 0x06004000
_0805FCE4: .4byte 0x08784CB0
_0805FCE8: .4byte 0x03006F74
_0805FCEC: .4byte 0x0879559C
_0805FCF0: .4byte 0x080AF900
_0805FCF4: .4byte 0x05000200
_0805FCF8: .4byte 0x08785F34
_0805FCFC: .4byte 0x06010000
_0805FD00: .4byte 0x03002C30
_0805FD04: .4byte 0x00008A20
_0805FD08: .4byte 0x0000FFE0
_0805FD0C: .4byte 0x00008220
_0805FD10: .4byte 0x0000FFC0
_0805FD14: .4byte 0x00000109
_0805FD18: .4byte 0x0300137C
_0805FD1C:
	.byte 0x80, 0x22, 0xD2, 0x04
	.byte 0x10, 0x88, 0x80, 0x23, 0x1B, 0x01, 0x19, 0x1C, 0x08, 0x43, 0x10, 0x80, 0x10, 0x88, 0x80, 0x23
	.byte 0x5B, 0x01, 0x19, 0x1C, 0x08, 0x43, 0x10, 0x80, 0x06, 0x4A, 0x11, 0x68, 0x20, 0x20, 0x08, 0x70
	.byte 0x05, 0x49, 0x10, 0x68, 0x00, 0x78, 0x40, 0x08, 0x08, 0x80, 0x04, 0x49, 0x08, 0x68, 0x01, 0x30
	.byte 0x08, 0x60, 0x70, 0x47, 0x74, 0x6F, 0x00, 0x03, 0x54, 0x00, 0x00, 0x04, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
