	.syntax unified

	thumb_func_start sub_0802B8BC
sub_0802B8BC: @ 0x0802B8BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802B95C @ =0x084DFC18
	ldr r1, _0802B960 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802B964 @ =0x0850EE38
	ldr r1, _0802B968 @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	movs r5, #0
	ldr r6, _0802B96C @ =0x03001800
	ldr r0, _0802B970 @ =0x03002C30
	mov r8, r0
	movs r4, #0x84
	lsls r4, r4, #4
	add r4, r8
	movs r2, #0
	mov sl, r2
	ldr r0, _0802B974 @ =0x0000C404
	mov sb, r0
_0802B8EE:
	adds r7, r6, #0
	adds r7, #0xd2
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B934
	adds r1, r5, #0
	adds r1, #0x21
	mov r2, sb
	strh r2, [r4]
	mov r0, sl
	strb r0, [r4, #0x1c]
	ldr r2, _0802B978 @ =0x03001860
	ldrb r0, [r2]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	add r0, r8
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	movs r2, #0xf0
	strh r2, [r4, #4]
	movs r0, #6
	strb r0, [r4, #0xa]
	strb r2, [r4, #0xb]
	ldr r0, _0802B97C @ =0x083B5F80
	adds r2, #0xac
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_0802B934:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802B8EE
	movs r0, #0x2c
	bl play_sound_effect
	adds r1, r7, #0
	subs r1, #0x28
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
_0802B95C: .4byte 0x084DFC18
_0802B960: .4byte 0x06014800
_0802B964: .4byte 0x0850EE38
_0802B968: .4byte 0x050002C0
_0802B96C: .4byte 0x03001800
_0802B970: .4byte 0x03002C30
_0802B974: .4byte 0x0000C404
_0802B978: .4byte 0x03001860
_0802B97C: .4byte 0x083B5F80
	.syntax divided
