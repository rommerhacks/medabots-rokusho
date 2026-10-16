	.syntax unified

	thumb_func_start sub_08070760
sub_08070760: @ 0x08070760
	push {r4, lr}
	ldr r4, _08070790 @ =0x03001800
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0807076E
	bl sub_0807068C
_0807076E:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _08070778
	bl sub_080706AC
_08070778:
	ldr r1, _08070794 @ =0x084860C8
	ldr r0, _08070798 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08070790: .4byte 0x03001800
_08070794: .4byte 0x084860C8
_08070798: .4byte 0x0300137C
	.syntax divided
