	.syntax unified

	thumb_func_start sub_0807052C
sub_0807052C: @ 0x0807052C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _08070570
	ldr r4, _08070568 @ =0x03002C30
	lsls r5, r5, #6
	adds r0, r5, r4
	mov ip, r0
	adds r0, #0x23
	ldrb r2, [r0]
	ldr r3, _0807056C @ =0x080AFF50
	mov r0, ip
	adds r0, #0x21
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r2, r2, r0
	mov r1, ip
	strh r2, [r1, #4]
	adds r3, r4, #0
	adds r4, r5, #0
	b _08070598
	.align 2, 0
_08070568: .4byte 0x03002C30
_0807056C: .4byte 0x080AFF50
_08070570:
	ldr r3, _080705B4 @ =0x03002C30
	lsls r4, r5, #6
	adds r5, r4, r3
	movs r2, #0x23
	adds r2, r2, r5
	mov ip, r2
	ldr r2, _080705B8 @ =0x080AFF50
	adds r0, r5, #0
	adds r0, #0x21
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #4]
_08070598:
	adds r1, r4, r3
	adds r2, r1, #0
	adds r2, #0x21
	ldrb r0, [r2]
	adds r1, #0x22
	adds r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	strb r0, [r2]
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080705B4: .4byte 0x03002C30
_080705B8: .4byte 0x080AFF50
	.syntax divided
