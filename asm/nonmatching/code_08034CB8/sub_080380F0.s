	.syntax unified

	thumb_func_start sub_080380F0
sub_080380F0: @ 0x080380F0
	push {r4, lr}
	ldr r4, _08038118 @ =0x03002C30
	ldr r0, _0803811C @ =0x03000440
	ldr r1, _08038120 @ =0x0000012F
	adds r1, r1, r0
	mov ip, r1
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r2, r0, r4
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r3, [r0]
	cmp r3, #0x46
	bne _08038124
	adds r1, r2, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08038168
	.align 2, 0
_08038118: .4byte 0x03002C30
_0803811C: .4byte 0x03000440
_08038120: .4byte 0x0000012F
_08038124:
	ldr r1, _08038170 @ =0x083AF670
	movs r0, #0xf
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	ldr r3, _08038174 @ =0x000001FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2, #2]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r2, r0, r4
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08038158
	ldrh r0, [r2, #4]
	adds r0, #1
	strh r0, [r2, #4]
_08038158:
	mov r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_08038168:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038170: .4byte 0x083AF670
_08038174: .4byte 0x000001FF
	.syntax divided
