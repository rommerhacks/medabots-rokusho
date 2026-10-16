	.syntax unified

	thumb_func_start sub_08040820
sub_08040820: @ 0x08040820
	push {lr}
	ldr r2, _08040874 @ =0x03000440
	ldrb r1, [r2, #0x14]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _08040856
	ldrb r0, [r2, #0x14]
	adds r1, r0, #0
	adds r1, #8
	asrs r1, r1, #3
	subs r1, #1
	lsls r1, r1, #0x18
	ldr r0, _08040878 @ =0x02020000
	lsrs r1, r1, #0x12
	ldrb r3, [r2, #0x17]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r3
	lsls r2, r2, #7
	ldr r3, _0804087C @ =0x06000280
	adds r2, r2, r3
	adds r1, r1, r2
	movs r2, #0x10
	bl CpuFastSet
_08040856:
	ldr r2, _08040874 @ =0x03000440
	movs r0, #0
	strb r0, [r2, #0x14]
	ldrh r0, [r2, #0xc]
	ldr r1, [r2, #8]
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	adds r3, r2, #0
	cmp r0, #4
	bhi _080408C4
	lsls r0, r0, #2
	ldr r1, _08040880 @ =_08040884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040874: .4byte 0x03000440
_08040878: .4byte 0x02020000
_0804087C: .4byte 0x06000280
_08040880: .4byte _08040884
_08040884: @ jump table
	.4byte _08040898 @ case 0
	.4byte _080408BC @ case 1
	.4byte _08040898 @ case 2
	.4byte _08040898 @ case 3
	.4byte _080408BC @ case 4
_08040898:
	ldr r0, _080408B4 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080408CA
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, _080408B8 @ =0x03000440
	ldrb r0, [r1, #4]
	adds r0, #1
	strb r0, [r1, #4]
	b _080408CA
	.align 2, 0
_080408B4: .4byte 0x03001798
_080408B8: .4byte 0x03000440
_080408BC:
	ldrb r0, [r3, #4]
	adds r0, #1
	strb r0, [r3, #4]
	b _080408CA
_080408C4:
	ldrb r0, [r2, #4]
	adds r0, #1
	strb r0, [r2, #4]
_080408CA:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
