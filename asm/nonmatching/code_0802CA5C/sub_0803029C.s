	.syntax unified

	thumb_func_start sub_0803029C
sub_0803029C: @ 0x0803029C
	push {r4, r5, r6, r7, lr}
	ldr r2, _08030334 @ =0x03002C30
	movs r0, #0x94
	lsls r0, r0, #4
	adds r5, r2, r0
	movs r6, #0
	ldr r0, _08030338 @ =0x0000C404
	strh r0, [r5]
	ldr r1, _0803033C @ =0x0000095C
	adds r0, r2, r1
	strb r6, [r0]
	ldr r4, _08030340 @ =0x03001800
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r7, _08030344 @ =0x00000942
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08030348 @ =0x00000944
	adds r1, r2, r3
	strh r0, [r1]
	adds r7, #8
	adds r1, r2, r7
	movs r0, #7
	strb r0, [r1]
	ldr r0, _0803034C @ =0x0000094B
	adds r2, r2, r0
	movs r0, #0xf2
	strb r0, [r2]
	ldr r0, _08030350 @ =0x083B5F80
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x25
	bl init_battle_sprite_entry_08040B90
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803031C
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
_0803031C:
	movs r0, #0x30
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030334: .4byte 0x03002C30
_08030338: .4byte 0x0000C404
_0803033C: .4byte 0x0000095C
_08030340: .4byte 0x03001800
_08030344: .4byte 0x00000942
_08030348: .4byte 0x00000944
_0803034C: .4byte 0x0000094B
_08030350: .4byte 0x083B5F80
	.syntax divided
