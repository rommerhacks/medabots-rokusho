	.syntax unified

	thumb_func_start sub_08052960
	.global sub_08052960
sub_08052960: @ 0x08052960
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0
	cmp r1, #0
	beq _08052974
	cmp r1, #1
	beq _08052980
	b _0805298A
_08052974:
	ldr r1, _0805297C @ =0x083F8B74
	lsls r0, r2, #1
	b _08052986
	.align 2, 0
_0805297C: .4byte 0x083F8B74
_08052980:
	ldr r1, _0805298C @ =0x083F8B74
	lsls r0, r2, #1
	adds r0, #1
_08052986:
	adds r0, r0, r1
	ldrb r0, [r0]
_0805298A:
	bx lr
	.align 2, 0
_0805298C: .4byte 0x083F8B74
	.syntax divided
