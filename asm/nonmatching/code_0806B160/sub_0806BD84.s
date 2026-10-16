	.syntax unified

	thumb_func_start sub_0806BD84
sub_0806BD84: @ 0x0806BD84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0806BDD4 @ =0x03002C30
	movs r1, #0x9c
	lsls r1, r1, #3
	adds r3, r0, r1
	ldrb r1, [r3]
	adds r2, r0, #0
	cmp r1, #0
	bne _0806BDE4
	movs r4, #0
	mov ip, r3
	mov r8, r4
	ldr r5, _0806BDD8 @ =0x000004E1
	adds r6, r2, r5
	ldr r7, _0806BDDC @ =0x000004DA
	adds r5, r2, r7
	ldr r0, _0806BDE0 @ =0x00000A04
	adds r1, r2, r0
	movs r3, #7
_0806BDAE:
	ldrb r2, [r1, #0x1c]
	cmp r2, #1
	bne _0806BDCA
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r4, r0
	bge _0806BDCA
	adds r4, r0, #0
	mov r0, ip
	strb r2, [r0]
	ldrb r0, [r1, #0x1d]
	strb r0, [r6]
	mov r7, r8
	strh r7, [r5]
_0806BDCA:
	adds r1, #0x40
	subs r3, #1
	cmp r3, #0
	bge _0806BDAE
	b _0806BE40
	.align 2, 0
_0806BDD4: .4byte 0x03002C30
_0806BDD8: .4byte 0x000004E1
_0806BDDC: .4byte 0x000004DA
_0806BDE0: .4byte 0x00000A04
_0806BDE4:
	ldr r1, _0806BDF8 @ =0x000004E1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806BE10
	cmp r0, #1
	bgt _0806BDFC
	cmp r0, #0
	beq _0806BE02
	b _0806BE24
	.align 2, 0
_0806BDF8: .4byte 0x000004E1
_0806BDFC:
	cmp r0, #2
	beq _0806BE1C
	b _0806BE24
_0806BE02:
	ldr r5, _0806BE0C @ =0x000004C2
	adds r1, r2, r5
	movs r0, #0xb8
	b _0806BE22
	.align 2, 0
_0806BE0C: .4byte 0x000004C2
_0806BE10:
	ldr r7, _0806BE18 @ =0x000004C2
	adds r1, r2, r7
	movs r0, #0xc8
	b _0806BE22
	.align 2, 0
_0806BE18: .4byte 0x000004C2
_0806BE1C:
	ldr r0, _0806BE4C @ =0x000004C2
	adds r1, r2, r0
	movs r0, #0xd8
_0806BE22:
	strh r0, [r1]
_0806BE24:
	ldr r1, _0806BE50 @ =0x000004DA
	adds r4, r2, r1
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	movs r3, #0x49
	cmp r0, #0
	beq _0806BE36
	movs r3, #0x47
_0806BE36:
	ldr r5, _0806BE54 @ =0x000004C4
	adds r0, r2, r5
	strh r3, [r0]
	adds r0, r1, #1
	strh r0, [r4]
_0806BE40:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806BE4C: .4byte 0x000004C2
_0806BE50: .4byte 0x000004DA
_0806BE54: .4byte 0x000004C4
	.syntax divided
