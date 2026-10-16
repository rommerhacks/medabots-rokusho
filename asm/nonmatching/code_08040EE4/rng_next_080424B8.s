	.syntax unified

	thumb_func_start rng_next_080424B8
	.global rng_next_080424B8
rng_next_080424B8: @ 0x080424B8
	push {r4, r5, lr}
	ldr r2, _080424E4 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	beq _080424EC
	adds r3, r2, #0
	adds r3, #0x8d
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, _080424E8 @ =0x083B286C
	ldrb r0, [r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	strb r1, [r0]
	ldrb r0, [r0]
	b _08042530
	.align 2, 0
_080424E4: .4byte 0x03000440
_080424E8: .4byte 0x083B286C
_080424EC:
	movs r0, #0x8a
	adds r0, r0, r2
	mov ip, r0
	adds r5, r2, #0
	adds r5, #0x8c
	ldrb r0, [r5]
	mov r1, ip
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r2, #0x87
	ldr r0, _08042538 @ =0x03001780
	ldr r1, [r0]
	lsls r0, r1, #4
	lsrs r1, r1, #4
	adds r0, r0, r1
	adds r0, #1
	lsrs r0, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0xff
	ands r1, r2
	lsls r4, r1, #8
	lsrs r3, r2, #8
	adds r0, r3, #0
	eors r0, r1
	orrs r4, r0
	mov r0, ip
	strh r4, [r0]
	eors r3, r2
	strb r3, [r5]
	ldrb r0, [r5]
_08042530:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08042538: .4byte 0x03001780
	.syntax divided
