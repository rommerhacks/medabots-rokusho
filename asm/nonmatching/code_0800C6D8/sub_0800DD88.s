	.syntax unified

	thumb_func_start sub_0800DD88
sub_0800DD88: @ 0x0800DD88
	push {lr}
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800DDB8 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _0800DDBC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800DDB8: .4byte 0x03001780
_0800DDBC: .4byte 0x0300137C
	.syntax divided
