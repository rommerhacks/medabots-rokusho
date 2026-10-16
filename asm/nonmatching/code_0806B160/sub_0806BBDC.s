	.syntax unified

	thumb_func_start sub_0806BBDC
sub_0806BBDC: @ 0x0806BBDC
	push {r4, lr}
	sub sp, #4
	ldr r1, _0806BBFC @ =0x03002C30
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #7
	bls _0806BBF0
	b _0806BD78
_0806BBF0:
	lsls r0, r0, #2
	ldr r1, _0806BC00 @ =_0806BC04
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806BBFC: .4byte 0x03002C30
_0806BC00: .4byte _0806BC04
_0806BC04: @ jump table
	.4byte _0806BC24 @ case 0
	.4byte _0806BC50 @ case 1
	.4byte _0806BC78 @ case 2
	.4byte _0806BC8E @ case 3
	.4byte _0806BCF6 @ case 4
	.4byte _0806BCF6 @ case 5
	.4byte _0806BCF6 @ case 6
	.4byte _0806BD26 @ case 7
_0806BC24:
	movs r1, #0xca
	lsls r1, r1, #8
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r2, #0x2e
	movs r3, #0xa
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806BC4C @ =0x03002C30
	movs r2, #0
	movs r0, #0x78
	strh r0, [r1, #2]
	movs r0, #0x50
	strh r0, [r1, #4]
	strh r2, [r1, #0x1a]
	movs r0, #4
	strb r0, [r1, #8]
	strb r0, [r1, #9]
	b _0806BD1C
	.align 2, 0
_0806BC4C: .4byte 0x03002C30
_0806BC50:
	ldrh r0, [r4, #0x1a]
	cmp r0, #0x17
	bls _0806BC7E
	adds r0, #1
	strh r0, [r4, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb4
	bhi _0806BD16
	ldr r0, _0806BC74 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	bne _0806BC70
	b _0806BD78
_0806BC70:
	b _0806BD16
	.align 2, 0
_0806BC74: .4byte 0x0300058C
_0806BC78:
	ldrh r0, [r4, #0x1a]
	cmp r0, #0x17
	bhi _0806BC84
_0806BC7E:
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _0806BD78
_0806BC84:
	movs r0, #0
	strh r0, [r4, #0x1a]
	movs r0, #0xc8
	strh r0, [r4, #4]
	b _0806BD1A
_0806BC8E:
	ldr r2, _0806BCE0 @ =0x03001800
	movs r1, #0xc
	ldrsb r1, [r2, r1]
	ldrb r3, [r2, #0xe]
	movs r0, #0xe
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0806BCF0
	ldr r1, _0806BCE4 @ =0x0000CA08
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r2, #0x2f
	movs r3, #0xb
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806BCE8 @ =0x03002C30
	movs r2, #0
	movs r3, #0
	movs r0, #0x78
	strh r0, [r1, #2]
	movs r0, #0x50
	strh r0, [r1, #4]
	strb r2, [r1, #8]
	movs r0, #0x60
	strb r0, [r1, #9]
	strh r3, [r1, #0x1a]
	adds r1, #0x20
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _0806BCEC @ =0x04000050
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	strh r0, [r1]
	b _0806BD78
	.align 2, 0
_0806BCE0: .4byte 0x03001800
_0806BCE4: .4byte 0x0000CA08
_0806BCE8: .4byte 0x03002C30
_0806BCEC: .4byte 0x04000050
_0806BCF0:
	adds r0, r3, #1
	strb r0, [r2, #0xe]
	b _0806BD78
_0806BCF6:
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _0806BD02
	movs r0, #0x18
	bl play_sound_effect
_0806BD02:
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _0806BD78
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_0806BD16:
	movs r0, #0
	strh r0, [r4, #0x1a]
_0806BD1A:
	adds r1, r4, #0
_0806BD1C:
	adds r1, #0x20
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0806BD78
_0806BD26:
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _0806BD32
	movs r0, #7
	bl play_sound_effect
_0806BD32:
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _0806BD78
	movs r0, #0
	bl sub_0806B584
	ldr r2, _0806BD70 @ =0x03001800
	movs r0, #0
	str r0, [r2, #8]
	movs r0, #0xc
	ldrsb r0, [r2, r0]
	movs r1, #0xd
	ldrsb r1, [r2, r1]
	adds r0, r0, r1
	str r0, [r2, #0x44]
	ldr r1, _0806BD74 @ =0x04000050
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0x38
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #1
	b _0806BD7A
	.align 2, 0
_0806BD70: .4byte 0x03001800
_0806BD74: .4byte 0x04000050
_0806BD78:
	movs r0, #0
_0806BD7A:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
