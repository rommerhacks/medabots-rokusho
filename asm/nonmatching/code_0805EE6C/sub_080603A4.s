	.syntax unified

	thumb_func_start sub_080603A4
sub_080603A4: @ 0x080603A4
	push {r4, r5, lr}
	sub sp, #0xc
	movs r0, #4
	bl is_sound_playing_with_lock
	adds r3, r0, #0
	cmp r3, #0
	bne _0806041A
	ldr r2, _080603D8 @ =0x04000208
	strh r3, [r2]
	ldr r1, _080603DC @ =0x04000200
	ldrh r0, [r1]
	adds r5, r0, #0
	ldr r4, _080603E0 @ =0x00002020
	adds r0, r4, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	str r3, [sp, #8]
	add r0, sp, #8
	ldr r2, _080603E4 @ =0x05000002
	mov r1, sp
	bl CpuSet
	movs r4, #0
	b _080603EA
	.align 2, 0
_080603D8: .4byte 0x04000208
_080603DC: .4byte 0x04000200
_080603E0: .4byte 0x00002020
_080603E4: .4byte 0x05000002
_080603E8:
	adds r4, #1
_080603EA:
	cmp r4, #3
	bgt _080603FA
	movs r0, #0
	mov r1, sp
	bl ProgramEepromDwordEx
	cmp r0, #0
	bne _080603E8
_080603FA:
	ldr r1, _08060424 @ =0x04000200
	ldrh r0, [r1]
	orrs r5, r0
	strh r5, [r1]
	ldr r1, _08060428 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r1, _0806042C @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08060430 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	ldr r1, _08060434 @ =0x03007008
	movs r0, #1
	strb r0, [r1]
_0806041A:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08060424: .4byte 0x04000200
_08060428: .4byte 0x0300178C
_0806042C: .4byte 0x03002B8C
_08060430: .4byte 0x0300137C
_08060434: .4byte 0x03007008
	.syntax divided
