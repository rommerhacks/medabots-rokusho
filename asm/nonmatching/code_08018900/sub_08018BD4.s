	.syntax unified

	thumb_func_start sub_08018BD4
	.global sub_08018BD4
sub_08018BD4: @ 0x08018BD4
	ldr r0, _08018BE8 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _08018BF0
	ldr r0, _08018BEC @ =0x03001800
	adds r0, #0x57
	movs r1, #0x28
	b _08018C2E
	.align 2, 0
_08018BE8: .4byte 0x03000440
_08018BEC: .4byte 0x03001800
_08018BF0:
	ldr r0, _08018C04 @ =0x03001788
	ldrb r0, [r0]
	cmp r0, #1
	beq _08018C1C
	cmp r0, #1
	bgt _08018C08
	cmp r0, #0
	beq _08018C0E
	b _08018C30
	.align 2, 0
_08018C04: .4byte 0x03001788
_08018C08:
	cmp r0, #2
	beq _08018C28
	b _08018C30
_08018C0E:
	ldr r0, _08018C18 @ =0x03001800
	adds r0, #0x57
	movs r1, #0x28
	b _08018C2E
	.align 2, 0
_08018C18: .4byte 0x03001800
_08018C1C:
	ldr r0, _08018C24 @ =0x03001800
	adds r0, #0x57
	movs r1, #0x1e
	b _08018C2E
	.align 2, 0
_08018C24: .4byte 0x03001800
_08018C28:
	ldr r0, _08018C34 @ =0x03001800
	adds r0, #0x57
	movs r1, #0x14
_08018C2E:
	strb r1, [r0]
_08018C30:
	bx lr
	.align 2, 0
_08018C34: .4byte 0x03001800
	.syntax divided
