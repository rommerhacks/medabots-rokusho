	.syntax unified

	thumb_func_start sub_080085E8
sub_080085E8: @ 0x080085E8
	push {r4, lr}
	bl sub_080093F8
	ldr r4, _08008620 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800862C
	bl sub_0800AD00
	ldr r2, _08008624 @ =0x083B825C
	ldr r1, _08008628 @ =0x03000BE0
	adds r3, r4, #0
	adds r3, #0x46
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldrb r3, [r3]
	adds r0, r0, r3
	adds r1, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	b _08008630
	.align 2, 0
_08008620: .4byte 0x03000440
_08008624: .4byte 0x083B825C
_08008628: .4byte 0x03000BE0
_0800862C:
	ldr r0, _08008648 @ =0x083B53F8
	ldr r0, [r0, #0x3c]
_08008630:
	bl run_message
	cmp r0, #0
	beq _08008640
	ldr r1, _0800864C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08008640:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008648: .4byte 0x083B53F8
_0800864C: .4byte 0x0300137C
	.syntax divided
