	.syntax unified

	thumb_func_start sub_08015648
sub_08015648: @ 0x08015648
	cmp r0, #2
	bls _08015658
	ldr r0, _0801565C @ =0x030057E0
	ldr r1, _08015660 @ =0x000007FF
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _08015664
_08015658:
	movs r0, #0
	b _08015666
	.align 2, 0
_0801565C: .4byte 0x030057E0
_08015660: .4byte 0x000007FF
_08015664:
	movs r0, #1
_08015666:
	bx lr
	.syntax divided
