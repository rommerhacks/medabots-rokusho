	.syntax unified

	thumb_func_start sub_0802A534
sub_0802A534: @ 0x0802A534
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0
	ldr r4, _0802A5B8 @ =0x03001800
	adds r7, r4, #0
	adds r7, #0x60
	movs r0, #0xc8
	adds r0, r0, r4
	mov sl, r0
	ldr r2, _0802A5BC @ =0x030005D8
	mov r8, r2
	movs r3, #0x48
	rsbs r3, r3, #0
	add r3, r8
	mov sb, r3
_0802A558:
	adds r6, r4, #0
	adds r6, #0xd2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A59A
	ldrb r0, [r7]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0xec
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl sub_08037498
	lsls r1, r5, #1
	adds r0, r4, #0
	adds r0, #0xd6
	adds r1, r1, r0
	mov r3, sl
	ldrh r0, [r3]
	strh r0, [r1]
	ldrb r2, [r7]
	adds r2, r2, r5
	lsls r2, r2, #8
	mov r3, r8
	adds r0, r2, r3
	adds r0, #0x10
	ldrh r1, [r1]
	add r2, sb
	adds r2, #0x50
	ldrb r2, [r2]
	bl sub_08035740
_0802A59A:
	adds r5, #1
	cmp r5, #2
	bls _0802A558
	adds r1, r6, #0
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
_0802A5B8: .4byte 0x03001800
_0802A5BC: .4byte 0x030005D8
	.syntax divided
