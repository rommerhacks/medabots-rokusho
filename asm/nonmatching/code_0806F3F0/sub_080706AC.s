	.syntax unified

	thumb_func_start sub_080706AC
sub_080706AC: @ 0x080706AC
	push {lr}
	ldr r1, _08070738 @ =0x03001780
	ldr r2, [r1]
	movs r0, #3
	ands r2, r0
	adds r3, r1, #0
	cmp r2, #0
	bne _080706E8
	ldr r1, _0807073C @ =0x03001800
	ldrb r0, [r1, #0xe]
	adds r0, #1
	strb r0, [r1, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080706CE
	strb r2, [r1, #0xe]
_080706CE:
	ldr r2, _08070740 @ =0x040000D4
	ldrb r1, [r1, #0xe]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08070744 @ =0x02031000
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08070748 @ =0x06004020
	str r0, [r2, #4]
	ldr r0, _0807074C @ =0x84000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_080706E8:
	ldr r1, [r3]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	bne _08070724
	ldr r3, _0807073C @ =0x03001800
	ldrb r0, [r3, #0xf]
	adds r0, #1
	strb r0, [r3, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _08070704
	strb r1, [r3, #0xf]
_08070704:
	ldrb r0, [r3, #0xf]
	cmp r0, #5
	bhi _08070724
	ldr r2, _08070740 @ =0x040000D4
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08070750 @ =0x02031100
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08070754 @ =0x06004120
	str r0, [r2, #4]
	ldr r0, _08070758 @ =0x84000060
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08070724:
	bl sub_08071614
	ldr r0, _0807075C @ =0x03007010
	ldrb r0, [r0]
	cmp r0, #0
	beq _08070734
	bl sub_0807168C
_08070734:
	pop {r0}
	bx r0
	.align 2, 0
_08070738: .4byte 0x03001780
_0807073C: .4byte 0x03001800
_08070740: .4byte 0x040000D4
_08070744: .4byte 0x02031000
_08070748: .4byte 0x06004020
_0807074C: .4byte 0x84000040
_08070750: .4byte 0x02031100
_08070754: .4byte 0x06004120
_08070758: .4byte 0x84000060
_0807075C: .4byte 0x03007010
	.syntax divided
