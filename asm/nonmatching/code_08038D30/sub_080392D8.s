	.syntax unified

	thumb_func_start sub_080392D8
	.global sub_080392D8
sub_080392D8: @ 0x080392D8
	push {r4, r5, r6, r7, lr}
	ldr r4, _08039308 @ =0x03001800
	adds r7, r4, #0
	adds r7, #0x87
	ldrb r0, [r7]
	adds r6, r4, #0
	adds r6, #0xa7
	ldrb r1, [r6]
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r2, [r5]
	bl check_can_target_bot
	cmp r0, #0
	beq _0803930C
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #4
	strb r0, [r1]
	adds r1, #7
	movs r0, #2
	strb r0, [r1]
	b _08039344
	.align 2, 0
_08039308: .4byte 0x03001800
_0803930C:
	ldrb r0, [r7]
	ldrb r1, [r6]
	ldrb r2, [r5]
	bl check_battle_can_support_target
	cmp r0, #0
	beq _0803932A
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #4
	strb r0, [r1]
	adds r1, #7
	movs r0, #3
	strb r0, [r1]
	b _08039344
_0803932A:
	ldrb r0, [r7]
	ldrb r1, [r6]
	ldrb r2, [r5]
	bl check_battle_can_special_target
	cmp r0, #0
	beq _08039344
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #4
	strb r1, [r0]
	adds r0, #7
	strb r1, [r0]
_08039344:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
