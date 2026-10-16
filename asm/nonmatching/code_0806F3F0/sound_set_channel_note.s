	.syntax unified

	thumb_func_start sound_set_channel_note
sound_set_channel_note: @ 0x08072728
	push {r4, lr}
	mov ip, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _08072748 @ =0x03007014
	ldr r0, [r4]
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r2, [r0]
	ldrh r0, [r2, #2]
	subs r3, r1, r0
	cmp r3, #0
	bge _0807274C
	movs r3, #0
	b _08072756
	.align 2, 0
_08072748: .4byte 0x03007014
_0807274C:
	ldrh r0, [r2]
	subs r0, #1
	cmp r0, r3
	bge _08072756
	adds r3, r0, #0
_08072756:
	mov r0, ip
	adds r0, #0x48
	movs r2, #0
	strh r3, [r0]
	mov r1, ip
	adds r1, #0x6c
	movs r0, #0xff
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strh r2, [r0]
	ldr r0, [r4]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r3, #2
	adds r0, #8
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, ip
	str r0, [r1, #0x24]
	str r2, [r1, #0x30]
	mov r2, ip
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #0x52
	orrs r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
