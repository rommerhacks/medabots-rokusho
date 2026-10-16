	.syntax unified

	thumb_func_start reduce_medapart_stat
	.global reduce_medapart_stat
reduce_medapart_stat: @ 0x08042170
	push {r4, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _0804219C @ =0x03004C40
	lsls r3, r1, #4
	subs r3, r3, r1
	lsls r3, r3, #4
	lsrs r0, r0, #0x17
	adds r3, r3, r0
	adds r3, r3, r4
	ldrb r0, [r3]
	subs r0, r0, r2
	cmp r0, #0
	bge _08042194
	movs r0, #0
_08042194:
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804219C: .4byte 0x03004C40
	.syntax divided
