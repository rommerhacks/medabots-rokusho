	.syntax unified

	thumb_func_start sub_080383E8
	.global sub_080383E8
sub_080383E8: @ 0x080383E8
	push {r4, r5, r6, r7, lr}
	movs r4, #0xa
	ldr r7, _0803841C @ =0x0300056F
	ldr r6, _08038420 @ =0x083AF690
	movs r5, #0xac
	lsls r5, r5, #4
_080383F4:
	adds r0, r4, #0
	adds r0, #0x21
	strb r0, [r7]
	ldr r0, _08038424 @ =0x03002C30
	adds r0, r5, r0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	bl _call_via_r0
	adds r5, #0x40
	adds r4, #1
	cmp r4, #0x1a
	bls _080383F4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803841C: .4byte 0x0300056F
_08038420: .4byte 0x083AF690
_08038424: .4byte 0x03002C30
	.syntax divided
