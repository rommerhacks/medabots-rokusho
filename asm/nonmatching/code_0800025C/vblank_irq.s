	.syntax unified

	thumb_func_start vblank_irq
vblank_irq: @ 0x080005D0
	push {r4, r5, lr}
	ldr r4, _08000640 @ =0x03002B90
	ldrh r0, [r4]
	movs r5, #1
	ands r5, r0
	cmp r5, #0
	bne _0800063A
	ldrh r0, [r4]
	movs r1, #1
	orrs r0, r1
	strh r0, [r4]
	bl vblank_body
	ldrh r1, [r4]
	ldr r0, _08000644 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r4]
	ldr r4, _08000648 @ =0x03005010
	ldr r0, [r4]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08000602
	bl sub_080023D8
_08000602:
	ldr r0, _0800064C @ =0x04000208
	strh r5, [r0]
	ldr r1, _08000650 @ =0x03002410
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	ble _0800062C
	ldr r0, _08000654 @ =0x03005170
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _0800062C
	movs r0, #0xff
	strb r0, [r4, #0x1e]
	ldr r2, _08000658 @ =0x03007FF8
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
_0800062C:
	ldr r1, _08000658 @ =0x03007FF8
	ldrh r0, [r1]
	movs r2, #1
	orrs r0, r2
	strh r0, [r1]
	ldr r0, _0800064C @ =0x04000208
	strh r2, [r0]
_0800063A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08000640: .4byte 0x03002B90
_08000644: .4byte 0x0000FFFE
_08000648: .4byte 0x03005010
_0800064C: .4byte 0x04000208
_08000650: .4byte 0x03002410
_08000654: .4byte 0x03005170
_08000658: .4byte 0x03007FF8
	.syntax divided
