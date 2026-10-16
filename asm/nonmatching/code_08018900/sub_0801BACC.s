	.syntax unified

	thumb_func_start sub_0801BACC
	.global sub_0801BACC
sub_0801BACC: @ 0x0801BACC
	push {r4, r5, lr}
	ldr r3, _0801BB44 @ =0x03002C30
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801BB70
	movs r2, #0x99
	lsls r2, r2, #2
	adds r4, r3, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801BB68
	ldr r5, _0801BB48 @ =0x00000265
	adds r1, r3, r5
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #2
	ldrb r2, [r4]
	adds r0, r0, r2
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r2, #0x40
	strb r2, [r0, #8]
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #2
	ldrb r5, [r4]
	adds r0, r0, r5
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r3
	strb r2, [r0, #9]
	ldr r0, _0801BB4C @ =0x03001800
	adds r0, #0x80
	ldrb r2, [r0]
	ldrb r0, [r1]
	subs r0, #1
	cmp r2, r0
	bne _0801BB68
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801BB54
	lsls r0, r2, #2
	ldrb r4, [r4]
	adds r0, r0, r4
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r2, [r0]
	ldr r1, _0801BB50 @ =0x0000FFDF
	b _0801BB64
	.align 2, 0
_0801BB44: .4byte 0x03002C30
_0801BB48: .4byte 0x00000265
_0801BB4C: .4byte 0x03001800
_0801BB50: .4byte 0x0000FFDF
_0801BB54:
	lsls r0, r2, #2
	ldrb r4, [r4]
	adds r0, r0, r4
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r2, [r0]
	ldr r1, _0801BB78 @ =0x0000FDDF
_0801BB64:
	ands r1, r2
	strh r1, [r0]
_0801BB68:
	movs r0, #9
	movs r1, #1
	bl clear_battle_sprite_slot
_0801BB70:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801BB78: .4byte 0x0000FDDF
	.syntax divided
