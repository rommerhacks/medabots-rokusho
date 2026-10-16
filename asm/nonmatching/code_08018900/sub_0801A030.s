	.syntax unified

	thumb_func_start sub_0801A030
	.global sub_0801A030
sub_0801A030: @ 0x0801A030
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r4, #0
	ldr r2, _0801A064 @ =0x03000590
	lsls r0, r3, #8
	adds r0, r0, r2
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801A098
	cmp r3, #2
	bhi _0801A06C
	ldr r0, _0801A068 @ =0x03002C30
	lsls r1, r3, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r1, r1, r6
	adds r1, r1, r0
	movs r6, #2
	ldrsh r0, [r1, r6]
	cmp r0, #0x28
	bne _0801A082
	b _0801A080
	.align 2, 0
_0801A064: .4byte 0x03000590
_0801A068: .4byte 0x03002C30
_0801A06C:
	ldr r0, _0801A0A0 @ =0x03002C30
	lsls r1, r3, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r1, r1, r6
	adds r1, r1, r0
	movs r6, #2
	ldrsh r0, [r1, r6]
	cmp r0, #0xc8
	bne _0801A082
_0801A080:
	movs r4, #1
_0801A082:
	cmp r5, #0
	bne _0801A098
	cmp r4, #0
	beq _0801A098
	lsls r0, r3, #8
	adds r0, r0, r2
	adds r0, #0xa2
	ldrb r1, [r0]
	adds r0, r3, #0
	bl battle_add_active_medal_slot
_0801A098:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A0A0: .4byte 0x03002C30
	.syntax divided
