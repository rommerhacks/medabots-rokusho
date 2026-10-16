	.syntax unified

	thumb_func_start sub_0805FE90
sub_0805FE90: @ 0x0805FE90
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r4, _0805FEE4 @ =0x03006F74
	ldr r2, [r4]
	ldrh r1, [r2, #0x3a]
	lsls r3, r1, #0x10
	asrs r0, r3, #0x10
	cmp r0, #7
	bgt _0805FF04
	adds r0, r1, #1
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0805FECC
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0805FEE8 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x17
	bl play_sound_effect
_0805FECC:
	ldr r0, [r4]
	movs r4, #0x3a
	ldrsh r0, [r0, r4]
	cmp r0, #3
	bgt _0805FEF0
	ldr r2, _0805FEEC @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x44
	ldrh r0, [r1]
	subs r0, #1
	b _0805FEFA
	.align 2, 0
_0805FEE4: .4byte 0x03006F74
_0805FEE8: .4byte 0x0000FEFF
_0805FEEC: .4byte 0x03002C30
_0805FEF0:
	ldr r2, _0805FF00 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x44
	ldrh r0, [r1]
	adds r0, #1
_0805FEFA:
	strh r0, [r1]
	adds r6, r2, #0
	b _0805FFA6
	.align 2, 0
_0805FF00: .4byte 0x03002C30
_0805FF04:
	lsrs r0, r3, #0x10
	cmp r0, #0x31
	bhi _0805FF0E
	adds r0, r1, #1
	strh r0, [r2, #0x3a]
_0805FF0E:
	ldr r0, [r4]
	ldrh r0, [r0, #0x3a]
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0805FF2A
	ldr r2, _0805FF50 @ =0x03002C30
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
_0805FF2A:
	cmp r3, #0x13
	bhi _0805FF54
	lsls r0, r3, #6
	movs r1, #0x14
	bl sub_0807CBBC
	adds r1, r0, #0
	subs r1, #0x20
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r2, _0805FF50 @ =0x03002C30
	movs r3, #0x80
	rsbs r3, r3, #0
	adds r1, r3, #0
	subs r1, r1, r0
	strb r1, [r2, #8]
	strb r1, [r2, #9]
	b _0805FFA0
	.align 2, 0
_0805FF50: .4byte 0x03002C30
_0805FF54:
	adds r0, r3, #0
	subs r0, #0x14
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0805FF68
	ldr r1, _0805FF80 @ =0x03002C30
	movs r0, #0x40
	strb r0, [r1, #8]
	strb r0, [r1, #9]
_0805FF68:
	cmp r3, #0xc
	bhi _0805FF88
	ldr r0, _0805FF84 @ =0x080AF95A
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0805FFA0
	.align 2, 0
_0805FF80: .4byte 0x03002C30
_0805FF84: .4byte 0x080AF95A
_0805FF88:
	movs r4, #0x20
	adds r0, r3, #0
	subs r0, #0xd
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #7
	bhi _0805FF9E
	adds r0, r3, #0
	bl clear_or_fill_bg2_tilemap
	b _0805FFA0
_0805FF9E:
	movs r7, #1
_0805FFA0:
	ldr r0, _08060000 @ =0x03002C30
	strh r4, [r0, #4]
	adds r6, r0, #0
_0805FFA6:
	adds r1, r6, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x47
	bls _0805FFBC
	strh r5, [r1]
_0805FFBC:
	ldr r4, _08060004 @ =0x080AF942
	ldrh r0, [r1]
	movs r1, #6
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x46
	strh r0, [r1]
	ldr r0, _08060008 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0805FFFA
	cmp r7, #0
	beq _0805FFFA
	adds r1, r6, #0
	adds r1, #0x40
	ldr r0, _0806000C @ =0x0000CA20
	strh r0, [r1]
	ldr r0, _08060010 @ =0x03006F74
	ldr r0, [r0]
	strh r5, [r0, #0x3a]
	ldr r1, _08060014 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_0805FFFA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060000: .4byte 0x03002C30
_08060004: .4byte 0x080AF942
_08060008: .4byte 0x0300058C
_0806000C: .4byte 0x0000CA20
_08060010: .4byte 0x03006F74
_08060014: .4byte 0x0300137C
_08060018:
	.byte 0x06, 0x4A, 0x11, 0x68, 0x08, 0x78, 0x20, 0x28
	.byte 0x0C, 0xD0, 0x01, 0x30, 0x08, 0x70, 0x04, 0x49, 0x10, 0x68, 0x00, 0x78, 0x40, 0x08, 0x08, 0x80
	.byte 0x12, 0xE0, 0x00, 0x00, 0x74, 0x6F, 0x00, 0x03, 0x54, 0x00, 0x00, 0x04, 0x80, 0x22, 0xD2, 0x04
	.byte 0x11, 0x88, 0x06, 0x48, 0x08, 0x40, 0x10, 0x80, 0x05, 0x49, 0x03, 0x20, 0x08, 0x60, 0x05, 0x48
	.byte 0x00, 0x21, 0x01, 0x60, 0x04, 0x48, 0x01, 0x60, 0x70, 0x47, 0x00, 0x00, 0xFF, 0xFD, 0x00, 0x00
	.byte 0x8C, 0x17, 0x00, 0x03, 0x8C, 0x2B, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
