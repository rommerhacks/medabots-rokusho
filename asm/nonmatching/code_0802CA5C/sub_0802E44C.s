	.syntax unified

	thumb_func_start sub_0802E44C
sub_0802E44C: @ 0x0802E44C
	push {r4, r5, r6, lr}
	bl sub_0803836C
	ldr r4, _0802E4C0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r2, #0
	ldr r6, _0802E4C4 @ =0x03000590
	adds r3, r4, #0
	adds r5, r1, #0
	mov ip, r3
	mov r4, ip
	adds r4, #0xd6
_0802E472:
	ldrb r0, [r5]
	adds r0, r0, r2
	lsls r0, r0, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E4A6
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E4A6
	adds r0, r3, #0
	adds r0, #0xd2
	adds r0, r2, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, r0, r2
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xc1
	ldrb r0, [r0]
	strh r0, [r4]
_0802E4A6:
	adds r4, #2
	adds r2, #1
	cmp r2, #2
	bls _0802E472
	mov r1, ip
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E4C0: .4byte 0x03001800
_0802E4C4: .4byte 0x03000590
	.syntax divided
