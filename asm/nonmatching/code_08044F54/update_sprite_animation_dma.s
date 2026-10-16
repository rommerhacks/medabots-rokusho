	.syntax unified

	thumb_func_start update_sprite_animation_dma
	.global update_sprite_animation_dma
update_sprite_animation_dma: @ 0x08048128
	push {r4, r5, lr}
	ldr r1, _0804815C @ =0x084096F4
	ldr r3, _08048160 @ =0x030057E0
	ldr r2, _08048164 @ =0x000007FE
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrb r5, [r2]
	ldr r1, _08048168 @ =0x00000C34
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080481AE
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _080481AE
	ldr r0, _0804816C @ =0x00000C36
	adds r4, r3, r0
	ldrb r0, [r4]
	adds r1, r0, #0
	cmp r1, #0
	beq _08048170
	subs r0, #1
	b _080481AC
	.align 2, 0
_0804815C: .4byte 0x084096F4
_08048160: .4byte 0x030057E0
_08048164: .4byte 0x000007FE
_08048168: .4byte 0x00000C34
_0804816C: .4byte 0x00000C36
_08048170:
	ldr r0, _080481B4 @ =0x00000C35
	adds r3, r3, r0
	ldrb r0, [r3]
	adds r0, r0, r2
	ldrb r0, [r0, #3]
	cmp r0, #0xff
	bne _08048180
	strb r1, [r3]
_08048180:
	ldr r1, _080481B8 @ =0x030057DC
	ldrb r0, [r3]
	adds r0, r0, r2
	ldrb r0, [r0, #3]
	muls r0, r5, r0
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r2, _080481BC @ =0x040000D4
	str r1, [r2]
	ldr r0, _080481C0 @ =0x06009020
	str r0, [r2, #4]
	lsls r0, r5, #4
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	movs r0, #2
_080481AC:
	strb r0, [r4]
_080481AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080481B4: .4byte 0x00000C35
_080481B8: .4byte 0x030057DC
_080481BC: .4byte 0x040000D4
_080481C0: .4byte 0x06009020
	.syntax divided
