	.syntax unified

	thumb_func_start sub_0806BEF0
sub_0806BEF0: @ 0x0806BEF0
	push {r4, lr}
	ldr r0, _0806BF40 @ =0x03002C30
	movs r1, #0x82
	lsls r1, r1, #4
	adds r4, r0, r1
	ldrb r2, [r4]
	adds r3, r0, #0
	cmp r2, #1
	beq _0806BF50
	cmp r2, #1
	bgt _0806BF08
	b _0806C07C
_0806BF08:
	cmp r2, #2
	beq _0806BF84
	cmp r2, #3
	beq _0806BF12
	b _0806C07C
_0806BF12:
	ldr r2, _0806BF44 @ =0x0000081A
	adds r1, r3, r2
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	beq _0806BF28
	b _0806C07C
_0806BF28:
	strb r2, [r4]
	ldr r4, _0806BF48 @ =0x00000821
	adds r0, r3, r4
	strb r2, [r0]
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0806BF4C @ =0x000007C4
	adds r1, r3, r0
	movs r0, #0xc8
	strh r0, [r1]
	b _0806C07C
	.align 2, 0
_0806BF40: .4byte 0x03002C30
_0806BF44: .4byte 0x0000081A
_0806BF48: .4byte 0x00000821
_0806BF4C: .4byte 0x000007C4
_0806BF50:
	ldr r1, _0806BF74 @ =0x000007A1
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806BF5C
	b _0806C078
_0806BF5C:
	ldr r2, _0806BF78 @ =0x00000802
	adds r0, r3, r2
	ldrh r1, [r0]
	ldr r4, _0806BF7C @ =0x000007C2
	adds r0, r3, r4
	strh r1, [r0]
	ldr r0, _0806BF80 @ =0x000007C4
	adds r1, r3, r0
	movs r0, #0x18
	strh r0, [r1]
	b _0806C07C
	.align 2, 0
_0806BF74: .4byte 0x000007A1
_0806BF78: .4byte 0x00000802
_0806BF7C: .4byte 0x000007C2
_0806BF80: .4byte 0x000007C4
_0806BF84:
	ldr r1, _0806BFAC @ =0x0000081A
	adds r2, r3, r1
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0806C078
	ldr r4, _0806BFB0 @ =0x00000821
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806BFE0
	cmp r0, #1
	bgt _0806BFB4
	cmp r0, #0
	beq _0806BFBA
	b _0806C050
	.align 2, 0
_0806BFAC: .4byte 0x0000081A
_0806BFB0: .4byte 0x00000821
_0806BFB4:
	cmp r0, #2
	beq _0806C02C
	b _0806C050
_0806BFBA:
	ldr r0, _0806BFDC @ =0x00000802
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x6b
	bgt _0806BFD0
	movs r0, #0x6c
	strh r0, [r1]
_0806BFD0:
	ldrh r0, [r1]
	ldrh r1, [r2]
	subs r0, r0, r1
	subs r0, #2
	b _0806C04A
	.align 2, 0
_0806BFDC: .4byte 0x00000802
_0806BFE0:
	ldr r4, _0806BFFC @ =0x00000802
	adds r2, r3, r4
	ldrh r0, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	cmp r1, #0x77
	bgt _0806C000
	adds r0, #2
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x78
	ble _0806C014
	b _0806C010
	.align 2, 0
_0806BFFC: .4byte 0x00000802
_0806C000:
	cmp r1, #0x78
	ble _0806C014
	subs r0, #2
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x77
	bgt _0806C014
_0806C010:
	movs r0, #0x78
	strh r0, [r2]
_0806C014:
	ldr r1, _0806C024 @ =0x00000802
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r2, _0806C028 @ =0x000007C2
	adds r0, r3, r2
	strh r1, [r0]
	b _0806C050
	.align 2, 0
_0806C024: .4byte 0x00000802
_0806C028: .4byte 0x000007C2
_0806C02C:
	ldr r4, _0806C068 @ =0x00000802
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x84
	ble _0806C042
	movs r0, #0x84
	strh r0, [r1]
_0806C042:
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r0, #2
_0806C04A:
	ldr r2, _0806C06C @ =0x000007C2
	adds r1, r3, r2
	strh r0, [r1]
_0806C050:
	ldr r4, _0806C070 @ =0x0000081A
	adds r0, r3, r4
	ldrh r0, [r0]
	movs r1, #0xa
	cmp r0, #3
	bhi _0806C05E
	movs r1, #0x12
_0806C05E:
	ldr r2, _0806C074 @ =0x000007C4
	adds r0, r3, r2
	strh r1, [r0]
	b _0806C07C
	.align 2, 0
_0806C068: .4byte 0x00000802
_0806C06C: .4byte 0x000007C2
_0806C070: .4byte 0x0000081A
_0806C074: .4byte 0x000007C4
_0806C078:
	movs r0, #3
	strb r0, [r4]
_0806C07C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
