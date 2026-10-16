	.syntax unified

	thumb_func_start sub_0802DD98
sub_0802DD98: @ 0x0802DD98
	push {r4, lr}
	ldr r0, _0802DDEC @ =0x083B5F80
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r3, _0802DDF0 @ =0x03002C30
	ldr r4, _0802DDF4 @ =0x00000844
	adds r2, r3, r4
	ldrh r1, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0x40
	bne _0802DE0C
	ldr r0, _0802DDF8 @ =0x03000440
	adds r0, #0x86
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0802DDFC @ =0x00000865
	adds r1, r3, r0
	movs r0, #0x14
	strb r0, [r1]
	ldr r1, _0802DE00 @ =0x00000864
	adds r0, r3, r1
	strb r2, [r0]
	ldr r4, _0802DE04 @ =0x00000868
	adds r0, r3, r4
	strb r2, [r0]
	subs r1, #1
	adds r0, r3, r1
	strb r2, [r0]
	ldr r1, _0802DE08 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802DE14
	.align 2, 0
_0802DDEC: .4byte 0x083B5F80
_0802DDF0: .4byte 0x03002C30
_0802DDF4: .4byte 0x00000844
_0802DDF8: .4byte 0x03000440
_0802DDFC: .4byte 0x00000865
_0802DE00: .4byte 0x00000864
_0802DE04: .4byte 0x00000868
_0802DE08: .4byte 0x03001800
_0802DE0C:
	adds r0, r1, #1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r2]
_0802DE14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
