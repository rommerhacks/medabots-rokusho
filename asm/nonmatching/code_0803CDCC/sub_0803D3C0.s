	.syntax unified

	thumb_func_start sub_0803D3C0
sub_0803D3C0: @ 0x0803D3C0
	push {r4, r5, lr}
	ldr r2, _0803D410 @ =0x083B5F80
	ldr r5, _0803D414 @ =0x03002C30
	ldr r0, _0803D418 @ =0x03000440
	ldr r1, _0803D41C @ =0x0000012F
	adds r4, r0, r1
	ldrb r1, [r4]
	lsls r0, r1, #6
	adds r0, r0, r5
	adds r0, #0x26
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldrb r0, [r4]
	bl sub_080353CC
	cmp r0, #0
	beq _0803D40A
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r5
	adds r2, r1, #0
	adds r2, #0x28
	ldr r3, _0803D420 @ =0x00006307
	adds r0, r3, #0
	ldrb r2, [r2]
	adds r0, r0, r2
	movs r2, #0
	strh r0, [r1, #6]
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x29
	strb r2, [r0]
_0803D40A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803D410: .4byte 0x083B5F80
_0803D414: .4byte 0x03002C30
_0803D418: .4byte 0x03000440
_0803D41C: .4byte 0x0000012F
_0803D420: .4byte 0x00006307
	.syntax divided
