	.syntax unified

	thumb_func_start sub_0802BA2C
sub_0802BA2C: @ 0x0802BA2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r4, #0
	ldr r0, _0802BA98 @ =0x083B6120
	mov sl, r0
	movs r6, #0x84
	lsls r6, r6, #0x16
	movs r5, #0x84
	lsls r5, r5, #4
	ldr r1, _0802BA9C @ =0x03002C30
	mov sb, r1
	movs r0, #0
	mov r8, r0
	ldr r7, _0802BAA0 @ =0x0000CC04
_0802BA4E:
	ldr r1, _0802BAA4 @ =0x030018D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BA6C
	mov r1, sb
	adds r0, r5, r1
	strh r7, [r0]
	mov r1, r8
	strb r1, [r0, #0xb]
	mov r1, sl
	ldr r0, [r1]
	lsrs r1, r6, #0x18
	bl init_battle_sprite_entry_08040B90
_0802BA6C:
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r6, r6, r0
	adds r5, #0x40
	adds r4, #1
	cmp r4, #2
	bls _0802BA4E
	movs r0, #0x30
	bl play_sound_effect
	ldr r1, _0802BAA8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BA98: .4byte 0x083B6120
_0802BA9C: .4byte 0x03002C30
_0802BAA0: .4byte 0x0000CC04
_0802BAA4: .4byte 0x030018D2
_0802BAA8: .4byte 0x03001800
	.syntax divided
