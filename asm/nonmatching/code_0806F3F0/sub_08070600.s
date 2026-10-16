	.syntax unified

	thumb_func_start sub_08070600
sub_08070600: @ 0x08070600
	push {r4, lr}
	lsls r0, r0, #0x18
	ldr r1, _0807061C @ =0x03002C30
	lsrs r0, r0, #0x12
	adds r2, r0, r1
	adds r3, r2, #0
	adds r3, #0x21
	ldrb r0, [r3]
	cmp r0, #0x47
	bhi _08070620
	adds r0, #1
	strb r0, [r3]
	b _0807063C
	.align 2, 0
_0807061C: .4byte 0x03002C30
_08070620:
	ldrh r4, [r2, #2]
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r0, #0xb4
	lsls r0, r0, #1
	cmp r1, r0
	ble _08070638
	movs r1, #0
	movs r0, #0
	strh r0, [r2, #2]
	strb r1, [r3]
	b _0807063C
_08070638:
	adds r0, r4, #6
	strh r0, [r2, #2]
_0807063C:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
