	.syntax unified

	thumb_func_start sub_08024E9C
sub_08024E9C: @ 0x08024E9C
	push {r4, r5, lr}
	ldr r0, _08024F60 @ =0x084D6780
	ldr r1, _08024F64 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08024F68 @ =0x0850E878
	ldr r1, _08024F6C @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r0, _08024F70 @ =0x03001800
	mov ip, r0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08024ED4
	ldr r0, _08024F74 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
_08024ED4:
	ldr r2, _08024F74 @ =0x03002C30
	movs r4, #0x84
	lsls r4, r4, #4
	adds r3, r2, r4
	ldrh r1, [r3]
	movs r5, #0x88
	lsls r5, r5, #2
	adds r0, r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _08024F78 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08024F7C @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	ldr r5, _08024F80 @ =0x00000858
	adds r0, r2, r5
	strh r4, [r0]
	ldr r1, _08024F84 @ =0x0000084A
	adds r0, r2, r1
	movs r4, #6
	strb r4, [r0]
	subs r3, #3
	adds r1, r2, r3
	movs r0, #0x9e
	lsls r0, r0, #7
	strh r0, [r1]
	mov r3, ip
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	movs r5, #0x87
	lsls r5, r5, #4
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08024F88 @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r5, #0xc
	adds r2, r2, r5
	strb r4, [r2]
	ldr r0, _08024F8C @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	mov r1, ip
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08024F60: .4byte 0x084D6780
_08024F64: .4byte 0x06014800
_08024F68: .4byte 0x0850E878
_08024F6C: .4byte 0x050002C0
_08024F70: .4byte 0x03001800
_08024F74: .4byte 0x03002C30
_08024F78: .4byte 0x00000848
_08024F7C: .4byte 0x00000849
_08024F80: .4byte 0x00000858
_08024F84: .4byte 0x0000084A
_08024F88: .4byte 0x00000872
_08024F8C: .4byte 0x03000440
	.syntax divided
