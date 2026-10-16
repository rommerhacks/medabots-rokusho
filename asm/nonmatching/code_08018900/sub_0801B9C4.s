	.syntax unified

	thumb_func_start sub_0801B9C4
	.global sub_0801B9C4
sub_0801B9C4: @ 0x0801B9C4
	push {r4, r5, r6, r7, lr}
	ldr r4, _0801BA58 @ =0x03002C30
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801BABA
	ldr r0, _0801BA5C @ =0x083B5F80
	ldr r0, [r0, #0x60]
	movs r1, #9
	bl process_sprite_anim_commands
	movs r7, #0x99
	lsls r7, r7, #2
	adds r5, r4, r7
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801BABA
	ldr r0, _0801BA60 @ =0x00000267
	adds r6, r4, r0
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r1, _0801BA64 @ =0x00000265
	adds r3, r4, r1
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	ldrb r7, [r5]
	adds r0, r0, r7
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r7, #0x88
	lsls r7, r7, #2
	adds r1, r7, #0
	orrs r1, r2
	strh r1, [r0]
	ldr r1, _0801BA68 @ =0x00000266
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801BA6C
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	ldrb r7, [r5]
	adds r0, r0, r7
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r1, [r6]
	lsls r1, r1, #1
	adds r1, #0x40
	strb r1, [r0, #8]
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	ldrb r5, [r5]
	adds r0, r0, r5
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r1, [r6]
	lsls r1, r1, #1
	adds r1, #0x40
	strb r1, [r0, #9]
	b _0801BA9E
	.align 2, 0
_0801BA58: .4byte 0x03002C30
_0801BA5C: .4byte 0x083B5F80
_0801BA60: .4byte 0x00000267
_0801BA64: .4byte 0x00000265
_0801BA68: .4byte 0x00000266
_0801BA6C:
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	ldrb r1, [r5]
	adds r0, r0, r1
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r1, [r6]
	lsls r1, r1, #1
	movs r2, #0x60
	subs r1, r2, r1
	strb r1, [r0, #8]
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	ldrb r5, [r5]
	adds r0, r0, r5
	adds r0, #0x59
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r1, [r6]
	lsls r1, r1, #1
	subs r2, r2, r1
	strb r2, [r0, #9]
_0801BA9E:
	ldr r2, _0801BAC0 @ =0x03002C30
	ldr r7, _0801BAC4 @ =0x00000267
	adds r3, r2, r7
	ldrb r0, [r3]
	cmp r0, #0x10
	bls _0801BABA
	ldr r0, _0801BAC8 @ =0x00000266
	adds r2, r2, r0
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	movs r1, #0
	strb r0, [r2]
	strb r1, [r3]
_0801BABA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BAC0: .4byte 0x03002C30
_0801BAC4: .4byte 0x00000267
_0801BAC8: .4byte 0x00000266
	.syntax divided
