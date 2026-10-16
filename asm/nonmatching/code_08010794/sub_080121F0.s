	.syntax unified

	thumb_func_start sub_080121F0
sub_080121F0: @ 0x080121F0
	push {r4, r5, r6, lr}
	movs r4, #0
	movs r3, #0
	ldr r5, _08012230 @ =0x03000590
	adds r6, r5, #0
	adds r6, #0x59
_080121FC:
	adds r0, r3, #3
	lsls r1, r0, #8
	adds r0, r1, r5
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0
	beq _08012228
	movs r2, #1
	adds r3, #1
	adds r0, r1, r6
	adds r1, r0, #0
	adds r1, #0x18
_08012214:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801221C
	adds r4, #0xa
_0801221C:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #3
	bls _08012214
	cmp r3, #2
	bls _080121FC
_08012228:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08012230: .4byte 0x03000590
	.syntax divided
