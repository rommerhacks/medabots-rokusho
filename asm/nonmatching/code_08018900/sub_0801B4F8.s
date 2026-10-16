	.syntax unified

	thumb_func_start sub_0801B4F8
sub_0801B4F8: @ 0x0801B4F8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r4, #0
	movs r2, #0
	ldr r5, _0801B538 @ =0x03000590
	adds r7, r5, #0
	adds r7, #0x59
_0801B506:
	adds r0, r6, r2
	lsls r1, r0, #8
	adds r0, r1, r5
	adds r0, #0xba
	ldrb r0, [r0]
	adds r3, r2, #1
	cmp r0, #0
	beq _0801B52A
	movs r2, #0
	adds r1, r1, r7
_0801B51A:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801B522
	adds r4, #1
_0801B522:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #3
	bls _0801B51A
_0801B52A:
	adds r2, r3, #0
	cmp r2, #2
	bls _0801B506
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B538: .4byte 0x03000590
	.syntax divided
