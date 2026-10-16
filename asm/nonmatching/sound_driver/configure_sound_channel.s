	.syntax unified

	thumb_func_start configure_sound_channel
configure_sound_channel: @ 0x0807396C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r3, _080739A8 @ =0x04000083
	ldr r1, _080739AC @ =0x083ABAAC
	subs r2, r5, #1
	adds r1, r2, r1
	ldrb r0, [r3]
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _080739B0 @ =0x084873B8
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r2, [r2]
	adds r3, r4, #0
	movs r1, #7
_0807398E:
	ldm r3!, {r0}
	str r0, [r2]
	subs r1, #1
	cmp r1, #0
	bge _0807398E
	adds r1, r4, #0
	adds r1, #0x20
	adds r0, r5, #0
	bl sub_08073940
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080739A8: .4byte 0x04000083
_080739AC: .4byte 0x083ABAAC
_080739B0: .4byte 0x084873B8
	.syntax divided
