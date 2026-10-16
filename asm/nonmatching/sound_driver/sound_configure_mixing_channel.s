	.syntax unified

	thumb_func_start sound_configure_mixing_channel
sound_configure_mixing_channel: @ 0x08073B64
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r0, _08073B80 @ =0x03007014
	ldr r0, [r0]
	ldr r1, _08073B84 @ =0x0000072C
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08073B88
	movs r6, #3
	b _08073B9C
	.align 2, 0
_08073B80: .4byte 0x03007014
_08073B84: .4byte 0x0000072C
_08073B88:
	mov r1, ip
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	beq _08073B96
	adds r6, r0, #0
	b _08073B9C
_08073B96:
	mov r0, ip
	adds r0, #0x3f
	ldrb r6, [r0]
_08073B9C:
	ldr r5, _08073BE4 @ =0x04000082
	ldr r0, _08073BE8 @ =0x083ABAC2
	mov r1, ip
	adds r1, #0x3a
	ldrb r2, [r1]
	subs r2, #1
	lsls r1, r2, #1
	adds r0, r1, r0
	ldrh r4, [r5]
	ldrh r3, [r0]
	ands r3, r4
	ldr r0, _08073BEC @ =0x083ABA88
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r3, r0
	ldr r4, _08073BF0 @ =0x083ABAB2
	lsls r0, r6, #1
	lsls r1, r2, #3
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	orrs r3, r0
	ldr r1, _08073BF4 @ =0x083ABA8C
	mov r0, ip
	adds r0, #0x3c
	lsls r2, r2, #4
	ldrb r0, [r0]
	adds r2, r2, r0
	adds r2, r2, r1
	ldrb r0, [r2]
	orrs r0, r3
	strh r0, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08073BE4: .4byte 0x04000082
_08073BE8: .4byte 0x083ABAC2
_08073BEC: .4byte 0x083ABA88
_08073BF0: .4byte 0x083ABAB2
_08073BF4: .4byte 0x083ABA8C
	.syntax divided
