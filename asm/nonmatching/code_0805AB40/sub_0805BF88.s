	.syntax unified

	thumb_func_start sub_0805BF88
sub_0805BF88: @ 0x0805BF88
	push {lr}
	ldr r1, _0805BFC8 @ =0x08483B78
	ldr r0, _0805BFCC @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, _0805BFD0 @ =0x0300057C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	ldr r0, _0805BFD4 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805BFC2
	ldr r0, _0805BFD8 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0805BFC2:
	pop {r0}
	bx r0
	.align 2, 0
_0805BFC8: .4byte 0x08483B78
_0805BFCC: .4byte 0x0300137C
_0805BFD0: .4byte 0x0300057C
_0805BFD4: .4byte 0x03001780
_0805BFD8: .4byte 0x03001C04
	.syntax divided
