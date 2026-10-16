	.syntax unified

	thumb_func_start sub_0802A2D4
sub_0802A2D4: @ 0x0802A2D4
	push {r4, lr}
	ldr r1, _0802A2F8 @ =0x03002C30
	ldr r0, _0802A2FC @ =0x00000844
	adds r2, r1, r0
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0x20
	bne _0802A304
	movs r0, #0x42
	bl play_sound_effect
	ldr r1, _0802A300 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A312
	.align 2, 0
_0802A2F8: .4byte 0x03002C30
_0802A2FC: .4byte 0x00000844
_0802A300: .4byte 0x03001800
_0802A304:
	subs r0, r3, #1
	strh r0, [r2]
	ldr r0, _0802A318 @ =0x00000884
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0802A312:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A318: .4byte 0x00000884
	.syntax divided
