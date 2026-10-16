	.syntax unified

	thumb_func_start sub_08064D3C
sub_08064D3C: @ 0x08064D3C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r1, _08064EA4 @ =0x0400000A
	ldr r0, _08064EA8 @ =0x00001F05
	strh r0, [r1]
	ldr r4, _08064EAC @ =0x0400000C
	subs r0, #0xff
	strh r0, [r4]
	ldr r5, _08064EB0 @ =0x0400000E
	subs r0, #0xff
	strh r0, [r5]
	ldr r0, _08064EB4 @ =0x0879A634
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _08064EB8 @ =0x0879A78C
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _08064EBC @ =0x0879A8BC
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _08064EC0 @ =0x08799D98
	ldr r5, _08064EC4 @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	ldr r1, _08064EC8 @ =0x06004000
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	bl CpuSet
	ldr r5, _08064ECC @ =0x03006F74
	ldr r1, [r5]
	lsrs r0, r4, #5
	subs r0, #1
	movs r6, #0
	strh r0, [r1, #0x36]
	ldr r0, _08064ED0 @ =0x084C21BC
	ldr r1, _08064EC8 @ =0x06004000
	adds r4, r4, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r4, #0
	bl CpuFastSet
	ldr r0, _08064ED4 @ =0x08784DA4
	ldr r1, _08064ED8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _08064EDC @ =0x084C6A98
	ldr r1, _08064EE0 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r2, _08064EE4 @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r2, r3
	movs r3, #0x80
	lsls r3, r3, #8
	strh r3, [r0]
	movs r4, #0x87
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #2
	strb r0, [r1]
	ldr r1, _08064EE8 @ =0x0000020A
	adds r0, r2, r1
	strb r6, [r0]
	subs r4, #0x16
	adds r1, r2, r4
	movs r0, #6
	strh r0, [r1]
	ldr r0, _08064EEC @ =0x00000202
	adds r1, r2, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #0x1c
	subs r4, #2
	adds r1, r2, r4
	strh r0, [r1]
	movs r4, #0
	movs r7, #0
	adds r6, r2, #0
	movs r5, #2
_08064DF4:
	adds r1, r4, #0
	adds r1, #0xa
	lsls r1, r1, #6
	adds r1, r1, r2
	strh r3, [r1]
	strb r5, [r1, #0x1c]
	strb r7, [r1, #0xa]
	movs r0, #8
	strh r0, [r1, #6]
	movs r0, #0x20
	strh r0, [r1, #2]
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, #0x14
	strh r0, [r1, #4]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #1
	bls _08064DF4
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r1, r6, r4
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r1]
	movs r0, #0xee
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #2
	strb r0, [r1]
	movs r3, #0xe5
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0xa
	strb r0, [r1]
	adds r4, #6
	adds r1, r6, r4
	movs r0, #0x1a
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x98
	strh r0, [r1]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	ldr r4, _08064EF0 @ =0x030004DE
	ldr r0, _08064EF4 @ =0x03002B70
	ldr r1, [r0]
	adds r0, r4, #0
	bl divide_by_10000
	movs r0, #7
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x15
	movs r3, #1
	bl render_text_sprites_08040DB8
	ldr r1, _08064EF8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08064EA4: .4byte 0x0400000A
_08064EA8: .4byte 0x00001F05
_08064EAC: .4byte 0x0400000C
_08064EB0: .4byte 0x0400000E
_08064EB4: .4byte 0x0879A634
_08064EB8: .4byte 0x0879A78C
_08064EBC: .4byte 0x0879A8BC
_08064EC0: .4byte 0x08799D98
_08064EC4: .4byte 0x02030000
_08064EC8: .4byte 0x06004000
_08064ECC: .4byte 0x03006F74
_08064ED0: .4byte 0x084C21BC
_08064ED4: .4byte 0x08784DA4
_08064ED8: .4byte 0x06010000
_08064EDC: .4byte 0x084C6A98
_08064EE0: .4byte 0x06017400
_08064EE4: .4byte 0x03002C30
_08064EE8: .4byte 0x0000020A
_08064EEC: .4byte 0x00000202
_08064EF0: .4byte 0x030004DE
_08064EF4: .4byte 0x03002B70
_08064EF8: .4byte 0x0300137C
	.syntax divided
