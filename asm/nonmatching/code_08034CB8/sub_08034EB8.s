	.syntax unified

	thumb_func_start sub_08034EB8
	.global sub_08034EB8
sub_08034EB8: @ 0x08034EB8
	push {r4, r5, r6, lr}
	ldr r1, _08034EFC @ =0x083C6B28
	ldr r0, _08034F00 @ =0x03001800
	mov ip, r0
	adds r0, #0xa8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r1, _08034F04 @ =0x083C6D38
	mov r5, ip
	adds r5, #0xbc
	ldrh r0, [r5]
	adds r0, r4, r0
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r2, #0
	cmp r2, r3
	bhs _08034EF6
	mov r6, ip
	adds r6, #0xac
_08034EE4:
	adds r0, r2, r6
	ldrh r1, [r5]
	adds r1, r1, r2
	adds r1, r1, r4
	ldrb r1, [r1, #1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, r3
	blo _08034EE4
_08034EF6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034EFC: .4byte 0x083C6B28
_08034F00: .4byte 0x03001800
_08034F04: .4byte 0x083C6D38
	.syntax divided
