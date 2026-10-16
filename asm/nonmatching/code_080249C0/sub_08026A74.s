	.syntax unified

	thumb_func_start sub_08026A74
sub_08026A74: @ 0x08026A74
	push {r4, r5, r6, r7, lr}
	ldr r6, _08026AEC @ =0x030018D6
	adds r7, r6, #0
	subs r7, #0x4e
	ldrb r1, [r7]
	adds r0, r6, #0
	movs r2, #0
	bl sub_08036BB8
	adds r4, r0, #0
	adds r0, r6, #2
	ldrb r1, [r7]
	movs r2, #1
	bl sub_08036BB8
	adds r4, r4, r0
	adds r0, r6, #4
	ldrb r1, [r7]
	movs r2, #2
	bl sub_08036BB8
	adds r4, r4, r0
	adds r0, r6, #6
	ldrb r1, [r7]
	movs r2, #3
	bl sub_08036BB8
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0x22
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	movs r5, #0
	cmp r0, #0
	bne _08026ABE
	movs r5, #1
_08026ABE:
	ldrb r1, [r7]
	adds r0, r5, #0
	bl sub_08036370
	ldrb r1, [r7]
	adds r0, r5, #0
	bl sub_080364A8
	cmp r4, #4
	bne _08026AE4
	ldr r0, _08026AF0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r1, r6, #0
	subs r1, #0x2c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08026AE4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026AEC: .4byte 0x030018D6
_08026AF0: .4byte 0x03000440
	.syntax divided
