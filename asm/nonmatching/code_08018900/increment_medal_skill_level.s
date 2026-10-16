	.syntax unified

	thumb_func_start increment_medal_skill_level
	.global increment_medal_skill_level
increment_medal_skill_level: @ 0x0801BE48
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	cmp r7, #2
	bhi _0801BF04
	ldr r0, _0801BE8C @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801BF04
	ldr r0, _0801BE90 @ =0x03000590
	lsls r1, r7, #8
	adds r3, r1, r0
	ldrb r2, [r3, #5]
	adds r5, r0, #0
	adds r6, r1, #0
	cmp r2, #0x64
	beq _0801BF04
	ldr r1, _0801BE94 @ =0x03001800
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	mov ip, r1
	cmp r0, #0
	beq _0801BF04
	adds r1, r3, #0
	adds r1, #0xdd
	ldrb r0, [r1]
	cmp r0, #3
	bls _0801BE98
	adds r0, r3, #0
	adds r0, #0xa9
	b _0801BEA8
	.align 2, 0
_0801BE8C: .4byte 0x03000440
_0801BE90: .4byte 0x03000590
_0801BE94: .4byte 0x03001800
_0801BE98:
	ldrb r1, [r1]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r0, r0, r5
	adds r0, #0x4a
_0801BEA8:
	ldrb r4, [r0]
	adds r1, r4, r6
	adds r0, r5, #0
	adds r0, #0x20
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0x64
	bne _0801BEC8
	adds r0, r5, #0
	adds r0, #0x28
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #6
	bhi _0801BEFE
	adds r0, #1
	b _0801BEFC
_0801BEC8:
	adds r0, r5, #0
	adds r0, #0x28
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0801BEFE
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r3, _0801BF0C @ =0x00000165
	add r3, ip
	movs r0, #1
	strb r0, [r3]
	movs r0, #0xb3
	lsls r0, r0, #1
	add r0, ip
	strb r4, [r0]
	ldrb r0, [r2]
	ldr r1, _0801BF10 @ =0x00000167
	add r1, ip
_0801BEFC:
	strb r0, [r1]
_0801BEFE:
	adds r0, r7, #0
	bl sync_medal_stats_from_battle_bot
_0801BF04:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BF0C: .4byte 0x00000165
_0801BF10: .4byte 0x00000167
	.syntax divided
