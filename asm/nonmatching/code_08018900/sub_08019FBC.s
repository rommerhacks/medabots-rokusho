	.syntax unified

	thumb_func_start sub_08019FBC
	.global sub_08019FBC
sub_08019FBC: @ 0x08019FBC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r4, #0
	ldr r2, _08019FF0 @ =0x03000590
	lsls r0, r3, #8
	adds r0, r0, r2
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0801A024
	cmp r3, #2
	bhi _08019FF8
	ldr r0, _08019FF4 @ =0x03002C30
	lsls r1, r3, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r1, r1, r6
	adds r1, r1, r0
	movs r6, #2
	ldrsh r0, [r1, r6]
	cmp r0, #0x68
	bne _0801A00E
	b _0801A00C
	.align 2, 0
_08019FF0: .4byte 0x03000590
_08019FF4: .4byte 0x03002C30
_08019FF8:
	ldr r0, _0801A02C @ =0x03002C30
	lsls r1, r3, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r1, r1, r6
	adds r1, r1, r0
	movs r6, #2
	ldrsh r0, [r1, r6]
	cmp r0, #0x88
	bne _0801A00E
_0801A00C:
	movs r4, #1
_0801A00E:
	cmp r5, #0
	bne _0801A024
	cmp r4, #0
	beq _0801A024
	lsls r0, r3, #8
	adds r0, r0, r2
	adds r0, #0xa2
	ldrb r1, [r0]
	adds r0, r3, #0
	bl battle_add_active_medal_slot
_0801A024:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A02C: .4byte 0x03002C30
	.syntax divided
