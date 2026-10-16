	.syntax unified

	thumb_func_start sub_0800277C
sub_0800277C: @ 0x0800277C
	push {lr}
	ldr r0, _08002794 @ =0x03000440
	adds r0, #0x28
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0800279C
	ldr r0, _08002798 @ =0x083B53F8
	ldr r0, [r0, #0xc]
	b _080027A0
	.align 2, 0
_08002794: .4byte 0x03000440
_08002798: .4byte 0x083B53F8
_0800279C:
	ldr r0, _080027B4 @ =0x083B53F8
	ldr r0, [r0, #8]
_080027A0:
	bl run_message
	cmp r0, #0
	beq _080027AE
	ldr r1, _080027B8 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
_080027AE:
	pop {r0}
	bx r0
	.align 2, 0
_080027B4: .4byte 0x083B53F8
_080027B8: .4byte 0x0300137C
	.syntax divided
