	.syntax unified

	thumb_func_start sub_0802A440
sub_0802A440: @ 0x0802A440
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sl, r0
	movs r6, #0
	movs r4, #0
	ldr r1, _0802A4B4 @ =0x030018D2
	mov sb, r1
	movs r5, #0x8c
	lsls r5, r5, #4
	ldr r7, _0802A4B8 @ =0x03002C30
	mov r8, r7
_0802A45E:
	mov r1, sb
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A48A
	adds r6, #1
	adds r0, r4, #0
	adds r0, #0x23
	mov r7, r8
	adds r3, r5, r7
	ldrh r1, [r3, #0x18]
	adds r1, #0x20
	ldr r7, _0802A4BC @ =0x000003FF
	adds r2, r7, #0
	ands r1, r2
	strh r1, [r3, #0x18]
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0802A48A
	movs r0, #1
	add sl, r0
_0802A48A:
	adds r5, #0x40
	adds r4, #1
	cmp r4, #2
	bls _0802A45E
	cmp r6, sl
	bne _0802A4A6
	movs r0, #0x2b
	bl play_sound_effect
	ldr r1, _0802A4C0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802A4A6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A4B4: .4byte 0x030018D2
_0802A4B8: .4byte 0x03002C30
_0802A4BC: .4byte 0x000003FF
_0802A4C0: .4byte 0x03001800
	.syntax divided
