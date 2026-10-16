	.syntax unified

	thumb_func_start sub_0800DDC0
sub_0800DDC0: @ 0x0800DDC0
	push {lr}
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800DDF4 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	ldr r0, _0800DDF8 @ =0x083B53F8
	ldr r0, [r0, #0x40]
	bl run_message
	cmp r0, #0
	beq _0800DDEE
	ldr r1, _0800DDFC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800DDEE:
	pop {r0}
	bx r0
	.align 2, 0
_0800DDF4: .4byte 0x03001780
_0800DDF8: .4byte 0x083B53F8
_0800DDFC: .4byte 0x0300137C
	.syntax divided
