	.syntax unified

	thumb_func_start sub_080385F8
	.global sub_080385F8
sub_080385F8: @ 0x080385F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #1
	movs r4, #0
	ldr r0, _08038644 @ =0x0300056F
	mov r8, r0
	movs r5, #0x84
	lsls r5, r5, #4
	ldr r7, _08038648 @ =0x083AF6E0
_0803860C:
	adds r0, r4, #0
	adds r0, #0x21
	mov r1, r8
	strb r0, [r1]
	ldr r0, _0803864C @ =0x03002C30
	adds r0, r5, r0
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _08038624
	movs r6, #0
_08038624:
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	bl _call_via_r0
	adds r5, #0x40
	adds r4, #1
	cmp r4, #0x1a
	bls _0803860C
	adds r0, r6, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08038644: .4byte 0x0300056F
_08038648: .4byte 0x083AF6E0
_0803864C: .4byte 0x03002C30
	.syntax divided
