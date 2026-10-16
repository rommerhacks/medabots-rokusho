	.syntax unified

	thumb_func_start sub_0801CC58
sub_0801CC58: @ 0x0801CC58
	push {r4, r5, lr}
	ldr r5, _0801CCA4 @ =0x03000440
	adds r4, r5, #0
	adds r4, #0x84
	ldrb r0, [r4]
	bl sub_080353AC
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _0801CC9C
	movs r0, #0x3f
	bl play_sound_effect
	ldr r1, _0801CCA8 @ =0x03001C04
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #2]
	strb r2, [r4]
	ldr r0, _0801CCAC @ =0x03002C30
	ldr r1, _0801CCB0 @ =0x00000842
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x86
	strh r1, [r0]
	ldr r1, _0801CCB4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801CC9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CCA4: .4byte 0x03000440
_0801CCA8: .4byte 0x03001C04
_0801CCAC: .4byte 0x03002C30
_0801CCB0: .4byte 0x00000842
_0801CCB4: .4byte 0x03001800
	.syntax divided
