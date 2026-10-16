	.syntax unified

	thumb_func_start sub_08023274
sub_08023274: @ 0x08023274
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0802330C @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	movs r6, #0
	ldr r2, _08023310 @ =0x03000590
	ldr r3, _08023314 @ =0x03002C30
	movs r1, #0
	mov sb, r1
	ldr r5, _08023318 @ =0x0000C624
	mov r8, r5
	ldr r1, _0802331C @ =0x00004801
	mov ip, r1
	lsls r1, r0, #8
	movs r5, #0x84
	lsls r5, r5, #4
	adds r4, r3, r5
	adds r0, r1, #0
	adds r2, #0x40
	adds r2, r0, r2
	movs r5, #0x40
	movs r7, #0x80
	lsls r7, r7, #1
	ldr r0, _08023320 @ =0x00001742
	adds r1, r1, r0
	adds r1, r1, r3
_080232B2:
	ldrb r0, [r2]
	cmp r0, #0
	beq _080232D8
	mov r0, r8
	strh r0, [r4]
	mov r0, sb
	strb r0, [r4, #0x1c]
	ldrh r0, [r1]
	strh r0, [r4, #2]
	ldrh r0, [r1, #2]
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	strb r5, [r4, #8]
	strb r5, [r4, #9]
	mov r0, ip
	strh r0, [r4, #6]
_080232D8:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r4, #0x40
	adds r2, r2, r7
	adds r6, #1
	cmp r6, #2
	bls _080232B2
	movs r1, #0
	ldr r0, _08023324 @ =0x03000440
	adds r0, #0x86
	strh r1, [r0]
	movs r0, #0x2e
	bl play_sound_effect
	ldr r1, _0802330C @ =0x03001800
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
_0802330C: .4byte 0x03001800
_08023310: .4byte 0x03000590
_08023314: .4byte 0x03002C30
_08023318: .4byte 0x0000C624
_0802331C: .4byte 0x00004801
_08023320: .4byte 0x00001742
_08023324: .4byte 0x03000440
	.syntax divided
