	.syntax unified

	thumb_func_start sub_080712E8
sub_080712E8: @ 0x080712E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r5, #0
	str r5, [sp, #4]
	ldr r1, _0807145C @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r4, _08071460 @ =0x03002C30
	str r4, [r1, #4]
	ldr r0, _08071464 @ =0x85000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0xcc
	lsls r1, r1, #8
	mov sb, r1
	ldr r0, _08071468 @ =0x0000050E
	mov sl, r0
	movs r6, #3
	str r6, [sp]
	movs r0, #0
	mov r2, sl
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	movs r0, #0xd4
	strh r0, [r4, #2]
	strh r5, [r4, #4]
	movs r1, #0x4a
	mov r8, r1
	mov r0, r8
	strb r0, [r4, #0xb]
	ldr r0, _0807146C @ =0x000002A2
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	str r6, [sp]
	movs r0, #0xb
	mov r1, sb
	mov r2, sl
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	ldr r0, _08071470 @ =0x000002C2
	adds r1, r4, r0
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #7
	adds r0, r4, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, _08071474 @ =0x00000562
	adds r4, r4, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4]
	movs r4, #0
	movs r7, #0xb0
	lsls r7, r7, #3
	movs r6, #0x9c
	lsls r6, r6, #0xe
	movs r5, #0xb0
	lsls r5, r5, #0x15
_08071374:
	lsrs r0, r5, #0x18
	lsrs r2, r6, #0x10
	lsls r3, r4, #0x18
	lsrs r3, r3, #0x18
	movs r1, #1
	str r1, [sp]
	movs r1, #0xcc
	lsls r1, r1, #8
	bl init_battle_sprite_entry_08048818
	ldr r3, _08071460 @ =0x03002C30
	adds r1, r7, r3
	movs r0, #0x48
	strh r0, [r1, #4]
	adds r7, #0x40
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r6, r6, r1
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #3
	ble _08071374
	ldr r0, _08071478 @ =0x00000582
	adds r1, r3, r0
	movs r0, #0x58
	strh r0, [r1]
	ldr r1, _0807147C @ =0x0000058B
	adds r0, r3, r1
	movs r2, #8
	strb r2, [r0]
	ldr r0, _08071480 @ =0x000005C2
	adds r1, r3, r0
	movs r0, #0x88
	strh r0, [r1]
	ldr r1, _08071484 @ =0x000005CB
	adds r0, r3, r1
	strb r2, [r0]
	adds r1, #0x37
	adds r0, r3, r1
	movs r2, #0x70
	strh r2, [r0]
	ldr r0, _08071488 @ =0x0000060B
	adds r1, r3, r0
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, _0807148C @ =0x00000604
	adds r1, r3, r0
	movs r0, #0x24
	strh r0, [r1]
	ldr r1, _08071490 @ =0x00000642
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _08071494 @ =0x0000064B
	adds r1, r3, r0
	movs r0, #4
	strb r0, [r1]
	movs r4, #0
	ldr r1, _08071498 @ =0x00000682
	adds r5, r3, r1
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r7, r3, r0
	movs r6, #0xd0
	lsls r6, r6, #0x15
_080713F8:
	lsrs r0, r6, #0x18
	movs r1, #3
	str r1, [sp]
	ldr r1, _0807149C @ =0x0000CC08
	ldr r2, _080714A0 @ =0x00000513
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	ldrh r0, [r7, #2]
	strh r0, [r5]
	movs r0, #0x48
	strh r0, [r5, #2]
	adds r5, #0x40
	adds r7, #0x40
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r6, r6, r1
	adds r4, #1
	cmp r4, #3
	ble _080713F8
	movs r4, #0
	ldr r0, _08071460 @ =0x03002C30
	ldr r1, _080714A4 @ =0x00000704
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x38
	strh r1, [r0]
	ldr r0, _080714A8 @ =0x03007010
	strb r2, [r0]
	movs r0, #0x18
	movs r1, #0x3f
	movs r2, #0xc
	bl sound_channel_set_note
	ldr r0, _080714AC @ =0x03000430
	str r4, [r0]
	ldr r1, _080714B0 @ =0x03001800
	movs r0, #0xf
	strh r0, [r1, #4]
	ldr r1, _080714B4 @ =0x0300137C
	movs r0, #4
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807145C: .4byte 0x040000D4
_08071460: .4byte 0x03002C30
_08071464: .4byte 0x85000800
_08071468: .4byte 0x0000050E
_0807146C: .4byte 0x000002A2
_08071470: .4byte 0x000002C2
_08071474: .4byte 0x00000562
_08071478: .4byte 0x00000582
_0807147C: .4byte 0x0000058B
_08071480: .4byte 0x000005C2
_08071484: .4byte 0x000005CB
_08071488: .4byte 0x0000060B
_0807148C: .4byte 0x00000604
_08071490: .4byte 0x00000642
_08071494: .4byte 0x0000064B
_08071498: .4byte 0x00000682
_0807149C: .4byte 0x0000CC08
_080714A0: .4byte 0x00000513
_080714A4: .4byte 0x00000704
_080714A8: .4byte 0x03007010
_080714AC: .4byte 0x03000430
_080714B0: .4byte 0x03001800
_080714B4: .4byte 0x0300137C
	.syntax divided
