	.syntax unified

	thumb_func_start sub_080420C4
	.global sub_080420C4
sub_080420C4: @ 0x080420C4
	push {r4, lr}
	ldr r4, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	cmp r4, #0
	beq _080420E8
	cmp r0, r4
	blo _080420E8
	movs r0, #4
	b _0804210E
_080420E8:
	cmp r3, #0
	beq _080420F4
	cmp r0, r3
	blo _080420F4
	movs r0, #3
	b _0804210E
_080420F4:
	cmp r2, #0
	beq _08042100
	cmp r0, r2
	blo _08042100
	movs r0, #2
	b _0804210E
_08042100:
	cmp r1, #0
	beq _0804210C
	cmp r0, r1
	blo _0804210C
	movs r0, #1
	b _0804210E
_0804210C:
	movs r0, #0
_0804210E:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
