	.syntax unified

	thumb_func_start sub_0804DE28
sub_0804DE28: @ 0x0804DE28
	push {r4, r5, r6, lr}
	ldr r5, _0804DE3C @ =0x03002C30
	ldr r0, _0804DE40 @ =0x00000BE6
	adds r3, r5, r0
	ldrb r1, [r3]
	cmp r1, #0
	beq _0804DE44
	cmp r1, #1
	beq _0804DEC8
	b _0804DEE0
	.align 2, 0
_0804DE3C: .4byte 0x03002C30
_0804DE40: .4byte 0x00000BE6
_0804DE44:
	ldr r0, _0804DEA0 @ =0x00000BE8
	adds r2, r5, r0
	ldrb r4, [r2]
	cmp r4, #0xf
	bhi _0804DEC0
	ldr r0, _0804DEA4 @ =0x030057E0
	ldr r1, _0804DEA8 @ =0x00000C94
	adds r6, r0, r1
	ldrb r3, [r6]
	ldr r1, _0804DEAC @ =0x083D69A0
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0804DE68
	adds r0, #0xf
_0804DE68:
	asrs r0, r0, #4
	subs r0, r3, r0
	ldr r3, _0804DEB0 @ =0x00000BC4
	adds r1, r5, r3
	strh r0, [r1]
	adds r0, r4, #1
	strb r0, [r2]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0804DE80
	adds r0, #3
_0804DE80:
	asrs r2, r0, #2
	ldrb r1, [r6]
	adds r0, r1, #0
	subs r0, #0x10
	cmp r0, #0
	bge _0804DE8E
	adds r0, #3
_0804DE8E:
	asrs r0, r0, #2
	cmp r2, r0
	bgt _0804DEB8
	ldr r3, _0804DEB4 @ =0x00000BCB
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	b _0804DEE0
	.align 2, 0
_0804DEA0: .4byte 0x00000BE8
_0804DEA4: .4byte 0x030057E0
_0804DEA8: .4byte 0x00000C94
_0804DEAC: .4byte 0x083D69A0
_0804DEB0: .4byte 0x00000BC4
_0804DEB4: .4byte 0x00000BCB
_0804DEB8:
	movs r0, #0x2f
	bl sub_0804877C
	b _0804DEE0
_0804DEC0:
	movs r0, #1
	strb r0, [r3]
	strb r1, [r2]
	b _0804DEE0
_0804DEC8:
	movs r0, #0x2f
	bl sub_0804877C
	ldr r0, _0804DEE8 @ =0x030057E0
	ldr r1, _0804DEEC @ =0x00000C94
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r2, _0804DEF0 @ =0x00000BC4
	adds r0, r5, r2
	strh r1, [r0]
	bl sub_08050244
_0804DEE0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804DEE8: .4byte 0x030057E0
_0804DEEC: .4byte 0x00000C94
_0804DEF0: .4byte 0x00000BC4
	.syntax divided
