	.syntax unified

	thumb_func_start sub_08018FF0
sub_08018FF0: @ 0x08018FF0
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08019018 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r1, r2, #0
	adds r1, #0x59
	ldrb r3, [r1]
	subs r2, r3, #1
	subs r0, r2, r4
	cmp r0, #0
	blt _0801901C
	subs r0, r3, r4
	strb r0, [r1]
	adds r0, r4, #0
	b _08019026
	.align 2, 0
_08019018: .4byte 0x03000590
_0801901C:
	movs r0, #1
	strb r0, [r1]
	subs r0, r4, r2
	lsls r0, r0, #8
	adds r0, r0, r2
_08019026:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
