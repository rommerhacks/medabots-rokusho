	.syntax unified

	thumb_func_start sub_0803B8C8
sub_0803B8C8: @ 0x0803B8C8
	push {r4, r5, r6, r7, lr}
	movs r4, #0
	ldr r7, _0803B8F4 @ =0x0300056F
	ldr r6, _0803B8F8 @ =0x083AF96C
	ldr r5, _0803B8FC @ =0x03002C30
_0803B8D2:
	adds r4, #1
	strb r4, [r7]
	lsls r0, r4, #6
	adds r0, r0, r5
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	bl _call_via_r0
	cmp r4, #0x26
	bls _0803B8D2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B8F4: .4byte 0x0300056F
_0803B8F8: .4byte 0x083AF96C
_0803B8FC: .4byte 0x03002C30
	.syntax divided
