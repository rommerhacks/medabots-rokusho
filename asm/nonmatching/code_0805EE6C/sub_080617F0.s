	.syntax unified

	thumb_func_start sub_080617F0
sub_080617F0: @ 0x080617F0
	push {lr}
	ldr r1, _08061820 @ =0x08483E8C
	ldr r0, _08061824 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _08061828 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806181C
	ldr r0, _0806182C @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0806181C:
	pop {r0}
	bx r0
	.align 2, 0
_08061820: .4byte 0x08483E8C
_08061824: .4byte 0x0300137C
_08061828: .4byte 0x03001780
_0806182C: .4byte 0x03001C04
	.syntax divided
