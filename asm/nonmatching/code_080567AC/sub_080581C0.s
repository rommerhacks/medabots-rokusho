	.syntax unified

	thumb_func_start sub_080581C0
sub_080581C0: @ 0x080581C0
	push {r4, lr}
	cmp r0, #0
	beq _0805820A
	cmp r0, #1
	bne _0805820A
	cmp r1, #0
	bne _080581E8
	ldr r4, _080581E4 @ =0x030057A0
	ldrh r0, [r4, #0x28]
	bl sub_08053194
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x28]
	bl sub_08053288
	strh r0, [r4, #0x2c]
	b _0805820A
	.align 2, 0
_080581E4: .4byte 0x030057A0
_080581E8:
	cmp r1, #0
	blt _0805820A
	cmp r1, #2
	bgt _0805820A
	ldr r4, _08058210 @ =0x030057A0
	ldrh r0, [r4, #0x28]
	ldrh r1, [r4, #0x2a]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_080531D0
	ldrh r0, [r4, #0x28]
	ldrh r1, [r4, #0x2c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_080531EC
_0805820A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08058210: .4byte 0x030057A0
	.syntax divided
