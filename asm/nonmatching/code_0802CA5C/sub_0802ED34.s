	.syntax unified

	thumb_func_start sub_0802ED34
sub_0802ED34: @ 0x0802ED34
	push {r4, r5, lr}
	movs r3, #0
	movs r2, #0
	ldr r4, _0802ED58 @ =0x030018D2
	ldr r0, _0802ED5C @ =0x03002C30
	movs r5, #0x84
	lsls r5, r5, #4
	adds r1, r0, r5
_0802ED44:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802ED6A
	ldrb r0, [r1, #8]
	cmp r0, #0x40
	bne _0802ED60
	movs r3, #1
	b _0802ED6A
	.align 2, 0
_0802ED58: .4byte 0x030018D2
_0802ED5C: .4byte 0x03002C30
_0802ED60:
	subs r0, #4
	strb r0, [r1, #8]
	ldrb r0, [r1, #9]
	subs r0, #4
	strb r0, [r1, #9]
_0802ED6A:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #2
	bls _0802ED44
	cmp r3, #0
	beq _0802ED86
	movs r0, #0x51
	bl play_sound_effect
	ldr r1, _0802ED8C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802ED86:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802ED8C: .4byte 0x03001800
	.syntax divided
