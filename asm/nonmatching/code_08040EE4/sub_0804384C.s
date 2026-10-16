	.syntax unified

	thumb_func_start sub_0804384C
	.global sub_0804384C
sub_0804384C: @ 0x0804384C
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x1d
	bls _0804385A
	b _08043872
_08043856:
	adds r0, r2, #0
	b _08043874
_0804385A:
	movs r2, #0
	ldr r1, _08043878 @ =0x030017A0
_0804385E:
	ldrb r0, [r1]
	cmp r0, #1
	bls _0804386A
	ldrb r0, [r1, #2]
	cmp r0, r3
	beq _08043856
_0804386A:
	adds r1, #8
	adds r2, #1
	cmp r2, #8
	bls _0804385E
_08043872:
	movs r0, #0xff
_08043874:
	bx lr
	.align 2, 0
_08043878: .4byte 0x030017A0
	.syntax divided
