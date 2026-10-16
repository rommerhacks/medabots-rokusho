	.syntax unified

	thumb_func_start sub_08060C6C
sub_08060C6C: @ 0x08060C6C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	mov r8, r0
	ldr r2, _08060DA0 @ =0x01006000
	mov r0, sp
	mov r1, r8
	bl CpuFastSet
	bl sub_080415BC
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	adds r1, #0x50
	ldr r2, _08060DA4 @ =0x00000C42
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	strh r0, [r1]
	ldr r5, _08060DA8 @ =0x0400000A
	ldr r0, _08060DAC @ =0x00001B05
	strh r0, [r5]
	ldr r0, _08060DB0 @ =0x08799838
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r4, _08060DB4 @ =0x0400000C
	ldr r0, _08060DB8 @ =0x00001A06
	strh r0, [r4]
	ldr r0, _08060DBC @ =0x087999EC
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _08060DC0 @ =0x00001E05
	strh r0, [r5]
	subs r0, #0xff
	strh r0, [r4]
	ldr r6, _08060DC4 @ =0x0400000E
	subs r0, #0xff
	strh r0, [r6]
	ldr r0, _08060DC8 @ =0x08798608
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _08060DCC @ =0x08798824
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _08060DD0 @ =0x08798A34
	ldrh r1, [r6]
	bl decompress_and_write_tilemap
	ldr r0, _08060DD4 @ =0x0879691C
	ldr r6, _08060DD8 @ =0x02030000
	adds r1, r6, #0
	bl dma3_copy_or_decompress
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	add r1, r8
	lsrs r2, r4, #1
	ldr r0, _08060DDC @ =0x001FFFFF
	mov sb, r0
	ands r2, r0
	adds r0, r6, #0
	bl CpuSet
	ldr r0, _08060DE0 @ =0x084C4DB0
	ldr r2, _08060DE4 @ =0x06004000
	adds r1, r4, r2
	bl lz_decompress_dispatch
	adds r7, r0, #0
	ldr r0, _08060DE8 @ =0x03006F74
	mov r8, r0
	ldr r1, [r0]
	lsrs r0, r4, #5
	subs r0, #1
	strh r0, [r1, #0x38]
	adds r4, r4, r7
	lsrs r5, r4, #5
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x1b
	bl tilemap_offset_tiles_and_palette
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x1a
	bl tilemap_offset_tiles_and_palette
	ldr r0, _08060DEC @ =0x08798F2C
	adds r1, r6, #0
	bl dma3_copy_or_decompress
	adds r7, r0, #0
	ldr r1, _08060DE4 @ =0x06004000
	adds r5, r4, r1
	lsrs r2, r7, #1
	mov r0, sb
	ands r2, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl CpuSet
	mov r1, r8
	ldr r0, [r1]
	adds r4, r4, r7
	lsrs r4, r4, #5
	subs r4, #1
	strh r4, [r0, #0x36]
	ldr r0, _08060DF0 @ =0x08784CB0
	adds r5, r5, r7
	adds r1, r5, #0
	bl lz_decompress_dispatch
	ldr r0, _08060DF4 @ =0x08784DA4
	ldr r1, _08060DF8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _08060DFC @ =0x084C6A98
	ldr r1, _08060E00 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r0, _08060E04 @ =0x084C7318
	ldr r1, _08060E08 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r1, _08060E0C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060DA0: .4byte 0x01006000
_08060DA4: .4byte 0x00000C42
_08060DA8: .4byte 0x0400000A
_08060DAC: .4byte 0x00001B05
_08060DB0: .4byte 0x08799838
_08060DB4: .4byte 0x0400000C
_08060DB8: .4byte 0x00001A06
_08060DBC: .4byte 0x087999EC
_08060DC0: .4byte 0x00001E05
_08060DC4: .4byte 0x0400000E
_08060DC8: .4byte 0x08798608
_08060DCC: .4byte 0x08798824
_08060DD0: .4byte 0x08798A34
_08060DD4: .4byte 0x0879691C
_08060DD8: .4byte 0x02030000
_08060DDC: .4byte 0x001FFFFF
_08060DE0: .4byte 0x084C4DB0
_08060DE4: .4byte 0x06004000
_08060DE8: .4byte 0x03006F74
_08060DEC: .4byte 0x08798F2C
_08060DF0: .4byte 0x08784CB0
_08060DF4: .4byte 0x08784DA4
_08060DF8: .4byte 0x06010000
_08060DFC: .4byte 0x084C6A98
_08060E00: .4byte 0x06017400
_08060E04: .4byte 0x084C7318
_08060E08: .4byte 0x06017E00
_08060E0C: .4byte 0x0300137C
	.syntax divided
