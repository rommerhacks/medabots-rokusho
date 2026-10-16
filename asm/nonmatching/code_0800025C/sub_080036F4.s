	.syntax unified

	thumb_func_start sub_080036F4
sub_080036F4: @ 0x080036F4
	push {r4, lr}
	ldr r1, _08003728 @ =0x040000D4
	ldr r0, _0800372C @ =0x06002800
	str r0, [r1]
	ldr r0, _08003730 @ =0x02020800
	str r0, [r1, #4]
	ldr r0, _08003734 @ =0x84000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08003738 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x8f
	ldrb r4, [r1]
	cmp r4, #0
	beq _08003740
	cmp r4, #1
	beq _08003760
	adds r0, #0x3c
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	ldr r1, _0800373C @ =0x03002B8C
	movs r0, #5
	b _0800376E
	.align 2, 0
_08003728: .4byte 0x040000D4
_0800372C: .4byte 0x06002800
_08003730: .4byte 0x02020800
_08003734: .4byte 0x84000200
_08003738: .4byte 0x03000440
_0800373C: .4byte 0x03002B8C
_08003740:
	adds r0, #0x50
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	ldr r1, _08003758 @ =0x03002B8C
	movs r0, #3
	str r0, [r1]
	ldr r0, _0800375C @ =0x0300137C
	str r4, [r0]
	b _08003776
	.align 2, 0
_08003758: .4byte 0x03002B8C
_0800375C: .4byte 0x0300137C
_08003760:
	adds r0, #0x3c
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	ldr r1, _0800377C @ =0x03002B8C
	movs r0, #4
_0800376E:
	str r0, [r1]
	ldr r1, _08003780 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_08003776:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800377C: .4byte 0x03002B8C
_08003780: .4byte 0x0300137C
	.syntax divided
