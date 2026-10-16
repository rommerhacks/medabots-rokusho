	.syntax unified

	thumb_func_start decompress_medal_sprite_to_vram
decompress_medal_sprite_to_vram: @ 0x08067DD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r4, _08067EE0 @ =0x03000BE0
	ldr r5, _08067EE4 @ =0x030017EC
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r2, [r0, #1]
	ldrb r1, [r0, #8]
	subs r1, #1
	ldr r3, _08067EE8 @ =0x083AC494
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r1, _08067EEC @ =0x06010000
	bl lz_decompress_dispatch
	ldr r1, _08067EF0 @ =0x03002C30
	movs r2, #0
	ldr r0, _08067EF4 @ =0x0000CA04
	strh r0, [r1]
	movs r0, #0x78
	strh r0, [r1, #2]
	movs r0, #0x28
	strh r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1, #6]
	strb r2, [r1, #0xa]
	strb r2, [r1, #0x1c]
	movs r0, #0x40
	strb r0, [r1, #0xb]
	strb r0, [r1, #8]
	strb r0, [r1, #9]
	movs r2, #0
	ldr r3, _08067EF8 @ =0x030004DE
	ldr r6, _08067EFC @ =0x083B6410
	adds r7, r5, #0
_08067E2A:
	adds r1, r2, r3
	ldrb r0, [r7]
	lsls r0, r0, #6
	ldr r4, _08067EE0 @ =0x03000BE0
	adds r0, r0, r4
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xfe
	beq _08067E50
	adds r2, #1
	cmp r2, #0xf
	ble _08067E2A
_08067E50:
	movs r0, #0xa
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #0x14
	movs r2, #5
	movs r3, #0xa
	bl render_text_sprites_08040DB8
	ldrb r0, [r7]
	lsls r0, r0, #6
	ldr r6, _08067EE0 @ =0x03000BE0
	adds r1, r0, r6
	ldrb r0, [r1, #5]
	cmp r0, #0x64
	bne _08067F18
	ldr r5, _08067F00 @ =0x04000008
	ldrh r1, [r5]
	lsrs r1, r1, #8
	movs r4, #0x1f
	ands r1, r4
	lsls r1, r1, #0xb
	ldr r0, _08067F04 @ =0x0600029A
	adds r1, r1, r0
	ldr r3, _08067F08 @ =0x03006F74
	ldr r0, [r3]
	ldrh r0, [r0, #0x36]
	adds r0, #0x14
	movs r6, #0xe0
	lsls r6, r6, #7
	adds r2, r6, #0
	orrs r0, r2
	strh r0, [r1]
	ldrh r1, [r5]
	lsrs r1, r1, #8
	ands r1, r4
	lsls r1, r1, #0xb
	ldr r0, _08067F0C @ =0x060002DA
	adds r1, r1, r0
	ldr r0, [r3]
	ldrh r0, [r0, #0x36]
	adds r0, #0x15
	orrs r0, r2
	strh r0, [r1]
	ldrh r1, [r5]
	lsrs r1, r1, #8
	ands r1, r4
	lsls r1, r1, #0xb
	ldr r0, _08067F10 @ =0x0600029C
	adds r1, r1, r0
	ldr r0, [r3]
	ldrh r0, [r0, #0x36]
	adds r0, #0x16
	orrs r0, r2
	strh r0, [r1]
	ldrh r1, [r5]
	lsrs r1, r1, #8
	ands r1, r4
	lsls r1, r1, #0xb
	ldr r0, _08067F14 @ =0x060002DC
	adds r1, r1, r0
	ldr r0, [r3]
	ldrh r0, [r0, #0x36]
	adds r0, #0x17
	orrs r0, r2
	strh r0, [r1]
	b _08067FE2
	.align 2, 0
_08067EE0: .4byte 0x03000BE0
_08067EE4: .4byte 0x030017EC
_08067EE8: .4byte 0x083AC494
_08067EEC: .4byte 0x06010000
_08067EF0: .4byte 0x03002C30
_08067EF4: .4byte 0x0000CA04
_08067EF8: .4byte 0x030004DE
_08067EFC: .4byte 0x083B6410
_08067F00: .4byte 0x04000008
_08067F04: .4byte 0x0600029A
_08067F08: .4byte 0x03006F74
_08067F0C: .4byte 0x060002DA
_08067F10: .4byte 0x0600029C
_08067F14: .4byte 0x060002DC
_08067F18:
	ldr r0, _08068078 @ =0x04000008
	mov sb, r0
	ldrh r4, [r0]
	lsrs r4, r4, #8
	movs r2, #0x1f
	mov r8, r2
	mov r3, r8
	ands r4, r3
	lsls r4, r4, #0xb
	ldr r0, _0806807C @ =0x0600029A
	adds r4, r4, r0
	ldr r6, _08068080 @ =0x03006F74
	ldr r5, [r6]
	ldrb r0, [r1, #5]
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldrh r5, [r5, #0x36]
	adds r0, r0, r5
	movs r1, #0xe0
	lsls r1, r1, #7
	mov sl, r1
	mov r2, sl
	orrs r0, r2
	strh r0, [r4]
	mov r3, sb
	ldrh r4, [r3]
	lsrs r4, r4, #8
	mov r0, r8
	ands r4, r0
	lsls r4, r4, #0xb
	ldr r0, _08068084 @ =0x060002DA
	adds r4, r4, r0
	ldr r5, [r6]
	ldrb r0, [r7]
	lsls r0, r0, #6
	ldr r1, _08068088 @ =0x03000BE0
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldrh r5, [r5, #0x36]
	adds r0, r0, r5
	adds r0, #1
	mov r2, sl
	orrs r0, r2
	strh r0, [r4]
	mov r3, sb
	ldrh r4, [r3]
	lsrs r4, r4, #8
	mov r0, r8
	ands r4, r0
	lsls r4, r4, #0xb
	ldr r0, _0806808C @ =0x0600029C
	adds r4, r4, r0
	ldr r5, [r6]
	ldrb r0, [r7]
	lsls r0, r0, #6
	ldr r1, _08068088 @ =0x03000BE0
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	movs r1, #0xa
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldrh r5, [r5, #0x36]
	adds r0, r0, r5
	mov r2, sl
	orrs r0, r2
	strh r0, [r4]
	mov r3, sb
	ldrh r4, [r3]
	lsrs r4, r4, #8
	mov r0, r8
	ands r4, r0
	lsls r4, r4, #0xb
	ldr r0, _08068090 @ =0x060002DC
	adds r4, r4, r0
	ldr r5, [r6]
	ldrb r0, [r7]
	lsls r0, r0, #6
	ldr r1, _08068088 @ =0x03000BE0
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	movs r1, #0xa
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldrh r5, [r5, #0x36]
	adds r0, r0, r5
	adds r0, #1
	mov r2, sl
	orrs r0, r2
	strh r0, [r4]
_08067FE2:
	ldr r0, _08068094 @ =0x030017EC
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r1, _08068098 @ =0x03000BEA
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0x1e
	movs r2, #0x11
	movs r3, #0xa
	bl render_text_sprites_08040DB8
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #3
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #5
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08068080 @ =0x03006F74
	ldr r0, [r1]
	movs r2, #0
	strh r4, [r0, #0x3a]
	adds r0, #0x48
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0x49
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0x4a
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0x4b
	strb r2, [r0]
	ldr r0, [r1]
	strb r2, [r0, #5]
	ldr r1, _0806809C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _080680A0 @ =0x03000440
	adds r0, #0x84
	strb r2, [r0]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068078: .4byte 0x04000008
_0806807C: .4byte 0x0600029A
_08068080: .4byte 0x03006F74
_08068084: .4byte 0x060002DA
_08068088: .4byte 0x03000BE0
_0806808C: .4byte 0x0600029C
_08068090: .4byte 0x060002DC
_08068094: .4byte 0x030017EC
_08068098: .4byte 0x03000BEA
_0806809C: .4byte 0x0300137C
_080680A0: .4byte 0x03000440
	.syntax divided
