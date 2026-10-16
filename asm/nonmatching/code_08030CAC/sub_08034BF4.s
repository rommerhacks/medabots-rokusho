	.syntax unified

	thumb_func_start sub_08034BF4
sub_08034BF4: @ 0x08034BF4
	push {lr}
	bl sub_08028248
	ldr r0, _08034C0C @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034C08
	bl sub_08034F08
_08034C08:
	pop {r0}
	bx r0
	.align 2, 0
_08034C0C: .4byte 0x03001800
	.syntax divided
