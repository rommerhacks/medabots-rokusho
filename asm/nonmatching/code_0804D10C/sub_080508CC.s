	.syntax unified

	thumb_func_start sub_080508CC
sub_080508CC: @ 0x080508CC
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r5, _08050960 @ =0x03002C30
	ldr r4, _08050964 @ =0x03006D20
	ldrb r2, [r4, #0xa]
	lsls r0, r2, #6
	adds r3, r0, r5
	adds r1, r3, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _08050974
	ldrh r2, [r4, #8]
	ldr r0, _08050968 @ =0x083D69A0
	mov ip, r0
	ldrb r0, [r1]
	lsls r0, r0, #4
	add r0, ip
	movs r6, #0
	ldrsh r1, [r0, r6]
	cmp r1, #0
	bge _080508FA
	adds r1, #0xf
_080508FA:
	asrs r1, r1, #4
	subs r1, r2, r1
	lsls r1, r1, #8
	ldrb r0, [r3, #0x10]
	orrs r0, r1
	str r0, [r3, #0x10]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #6
	adds r2, r0, r5
	adds r0, r2, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #4
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	cmp r1, #0
	bge _08050920
	adds r1, #0xf
_08050920:
	asrs r1, r1, #4
	adds r0, r2, #0
	adds r0, #0x2c
	strb r1, [r0]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x28
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r3, [r4, #0xa]
	lsls r0, r3, #6
	adds r5, r0, r5
	ldr r0, [r5, #0x10]
	asrs r0, r0, #8
	cmp r0, #0
	bge _08050946
	adds r0, #3
_08050946:
	asrs r2, r0, #2
	ldrh r1, [r4, #8]
	adds r0, r1, #0
	subs r0, #0x10
	cmp r0, #0
	bge _08050954
	adds r0, #3
_08050954:
	asrs r0, r0, #2
	cmp r2, r0
	bgt _0805096C
	movs r0, #0xff
	strb r0, [r5, #0xb]
	b _08050996
	.align 2, 0
_08050960: .4byte 0x03002C30
_08050964: .4byte 0x03006D20
_08050968: .4byte 0x083D69A0
_0805096C:
	adds r0, r3, #0
	bl sub_0804877C
	b _08050996
_08050974:
	adds r0, r2, #0
	bl sub_0804877C
	ldrb r2, [r4, #0xa]
	lsls r2, r2, #6
	adds r2, r2, r5
	ldrh r1, [r4, #8]
	lsls r1, r1, #8
	ldrb r0, [r2, #0x10]
	orrs r0, r1
	str r0, [r2, #0x10]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2c
	strb r7, [r0]
	movs r7, #1
_08050996:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
