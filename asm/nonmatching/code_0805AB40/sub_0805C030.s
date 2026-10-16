	.syntax unified

	thumb_func_start sub_0805C030
sub_0805C030: @ 0x0805C030
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r1, _0805C124 @ =0x04000008
	movs r0, #1
	mov r8, r0
	ldr r0, _0805C128 @ =0x00001F04
	strh r0, [r1]
	ldr r4, _0805C12C @ =0x0400000A
	subs r0, #0xff
	strh r0, [r4]
	ldr r5, _0805C130 @ =0x0400000C
	ldr r0, _0805C134 @ =0x00003D06
	strh r0, [r5]
	ldr r6, _0805C138 @ =0x0400000E
	subs r0, #0xff
	strh r0, [r6]
	ldr r0, _0805C13C @ =0x0878FBB4
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _0805C140 @ =0x0878FD84
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _0805C144 @ =0x0878FFC8
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _0805C148 @ =0x08790128
	ldrh r1, [r6]
	bl decompress_and_write_tilemap
	ldr r0, _0805C14C @ =0x0878E5F4
	ldr r5, _0805C150 @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r1, _0805C154 @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	bl CpuSet
	ldr r6, _0805C158 @ =0x03006F74
	ldr r0, [r6]
	lsrs r4, r4, #5
	subs r4, #1
	movs r5, #0
	strh r4, [r0, #0x36]
	ldr r0, _0805C15C @ =0x08784DA4
	ldr r1, _0805C160 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r4, _0805C164 @ =0x0878E3F4
	ldr r1, _0805C168 @ =0x0202FA00
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	ldr r4, _0805C16C @ =0x084E2E58
	ldr r1, _0805C170 @ =0x0202F800
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	ldr r1, _0805C174 @ =0x05000200
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	ldr r1, _0805C178 @ =0x03002C30
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r2]
	ldr r2, _0805C17C @ =0x0000038B
	adds r0, r1, r2
	mov r2, r8
	strb r2, [r0]
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r0, #2
	strb r0, [r2]
	ldr r2, _0805C180 @ =0x0000038A
	adds r0, r1, r2
	strb r5, [r0]
	ldr r0, _0805C184 @ =0x00000386
	adds r2, r1, r0
	movs r0, #6
	strh r0, [r2]
	ldr r0, _0805C188 @ =0x00000382
	adds r2, r1, r0
	movs r0, #0x20
	strh r0, [r2]
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r0, #0x50
	strh r0, [r1]
	ldr r0, [r6]
	strb r5, [r0, #5]
	ldr r1, _0805C18C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805C124: .4byte 0x04000008
_0805C128: .4byte 0x00001F04
_0805C12C: .4byte 0x0400000A
_0805C130: .4byte 0x0400000C
_0805C134: .4byte 0x00003D06
_0805C138: .4byte 0x0400000E
_0805C13C: .4byte 0x0878FBB4
_0805C140: .4byte 0x0878FD84
_0805C144: .4byte 0x0878FFC8
_0805C148: .4byte 0x08790128
_0805C14C: .4byte 0x0878E5F4
_0805C150: .4byte 0x02030000
_0805C154: .4byte 0x06004000
_0805C158: .4byte 0x03006F74
_0805C15C: .4byte 0x08784DA4
_0805C160: .4byte 0x06010000
_0805C164: .4byte 0x0878E3F4
_0805C168: .4byte 0x0202FA00
_0805C16C: .4byte 0x084E2E58
_0805C170: .4byte 0x0202F800
_0805C174: .4byte 0x05000200
_0805C178: .4byte 0x03002C30
_0805C17C: .4byte 0x0000038B
_0805C180: .4byte 0x0000038A
_0805C184: .4byte 0x00000386
_0805C188: .4byte 0x00000382
_0805C18C: .4byte 0x0300137C
	.syntax divided
