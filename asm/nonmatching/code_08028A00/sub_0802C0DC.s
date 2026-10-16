	.syntax unified

	thumb_func_start sub_0802C0DC
sub_0802C0DC: @ 0x0802C0DC
	push {r4, r5, r6, r7, lr}
	ldr r4, _0802C18C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0xd2
	ldr r5, _0802C190 @ =0x030004C4
	ldr r0, _0802C194 @ =0x03002C30
	ldr r1, _0802C198 @ =0x00000844
	adds r2, r0, r1
	movs r4, #1
_0802C100:
	adds r0, r3, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C118
	ldrb r1, [r5]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0802C118
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0802C118:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802C100
	ldr r4, _0802C18C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	adds r7, r4, #0
	ldr r6, _0802C190 @ =0x030004C4
	ldr r0, _0802C194 @ =0x03002C30
	ldr r1, _0802C19C @ =0x00000904
	adds r2, r0, r1
	movs r0, #0xd6
	adds r0, r0, r7
	mov ip, r0
	movs r5, #1
_0802C146:
	mov r1, ip
	ldrh r0, [r1]
	ldr r4, _0802C1A0 @ =0x03000440
	cmp r0, #0
	beq _0802C160
	ldrb r1, [r6]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0802C160
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_0802C160:
	adds r2, #0x40
	movs r0, #2
	add ip, r0
	adds r3, #1
	cmp r3, #2
	bls _0802C146
	adds r1, r4, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #0x20
	bne _0802C182
	adds r1, #2
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xaa
	ldrb r0, [r1]
_0802C182:
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C18C: .4byte 0x03001800
_0802C190: .4byte 0x030004C4
_0802C194: .4byte 0x03002C30
_0802C198: .4byte 0x00000844
_0802C19C: .4byte 0x00000904
_0802C1A0: .4byte 0x03000440
	.syntax divided
