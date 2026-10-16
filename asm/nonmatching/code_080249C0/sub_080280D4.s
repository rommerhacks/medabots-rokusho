	.syntax unified

	thumb_func_start sub_080280D4
sub_080280D4: @ 0x080280D4
	push {lr}
	ldr r1, _080280F0 @ =0x03002C30
	ldr r2, _080280F4 @ =0x00000867
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x10
	bne _080280FC
	movs r0, #0x3e
	bl play_sound_effect
	ldr r1, _080280F8 @ =0x03001800
	adds r1, #0xaa
	b _0802811E
	.align 2, 0
_080280F0: .4byte 0x03002C30
_080280F4: .4byte 0x00000867
_080280F8: .4byte 0x03001800
_080280FC:
	cmp r0, #7
	bhi _08028110
	ldr r0, _0802810C @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #8
	b _08028118
	.align 2, 0
_0802810C: .4byte 0x00000848
_08028110:
	ldr r0, _08028128 @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #8
_08028118:
	strb r0, [r1]
	ldr r0, _0802812C @ =0x00000867
	adds r1, r2, r0
_0802811E:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08028128: .4byte 0x00000848
_0802812C: .4byte 0x00000867
	.syntax divided
