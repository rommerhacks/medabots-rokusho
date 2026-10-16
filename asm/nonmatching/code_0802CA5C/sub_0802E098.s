	.syntax unified

	thumb_func_start sub_0802E098
sub_0802E098: @ 0x0802E098
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r2, #0
	ldr r5, _0802E12C @ =0x030018D2
	ldr r3, _0802E130 @ =0x03002C30
	movs r0, #0
	mov r8, r0
	ldr r7, _0802E134 @ =0x0000C624
	mov sb, r7
	movs r0, #0x72
	rsbs r0, r0, #0
	adds r0, r0, r5
	mov ip, r0
	movs r7, #0x84
	lsls r7, r7, #4
	adds r1, r3, r7
	movs r4, #0x80
	ldr r6, _0802E138 @ =0x00007F03
_0802E0C0:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E108
	mov r0, sb
	strh r0, [r1]
	mov r7, r8
	strb r7, [r1, #0x1c]
	mov r7, ip
	ldrb r0, [r7]
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	mov r7, ip
	ldrb r0, [r7]
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r1, #4]
	strb r4, [r1, #8]
	strb r4, [r1, #9]
	movs r0, #7
	strb r0, [r1, #0xa]
	movs r0, #0xf0
	strb r0, [r1, #0xb]
	strh r6, [r1, #6]
_0802E108:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #2
	bls _0802E0C0
	movs r0, #0x54
	bl play_sound_effect
	ldr r1, _0802E13C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E12C: .4byte 0x030018D2
_0802E130: .4byte 0x03002C30
_0802E134: .4byte 0x0000C624
_0802E138: .4byte 0x00007F03
_0802E13C: .4byte 0x03001800
	.syntax divided
