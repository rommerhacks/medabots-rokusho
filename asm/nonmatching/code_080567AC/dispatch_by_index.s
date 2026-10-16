	.syntax unified

	thumb_func_start dispatch_by_index
dispatch_by_index: @ 0x08058124
	push {r4, lr}
	cmp r0, #6
	bhi _080581B4
	lsls r0, r0, #2
	ldr r1, _08058134 @ =_08058138
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058134: .4byte _08058138
_08058138: @ jump table
	.4byte _08058154 @ case 0
	.4byte _08058170 @ case 1
	.4byte _080581B4 @ case 2
	.4byte _080581B4 @ case 3
	.4byte _080581B4 @ case 4
	.4byte _08058198 @ case 5
	.4byte _080581A8 @ case 6
_08058154:
	ldr r0, _08058164 @ =0x030057A0
	ldr r1, _08058168 @ =0x030057E0
	ldr r2, _0805816C @ =0x000007FE
	adds r1, r1, r2
	ldrb r1, [r1]
	strh r1, [r0, #0x26]
	b _080581B4
	.align 2, 0
_08058164: .4byte 0x030057A0
_08058168: .4byte 0x030057E0
_0805816C: .4byte 0x000007FE
_08058170:
	ldr r4, _08058190 @ =0x030057A0
	ldr r0, _08058194 @ =0x030057E0
	movs r1, #0xc9
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x28]
	bl sub_08053194
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x28]
	bl sub_08053288
	strh r0, [r4, #0x2c]
	b _080581B4
	.align 2, 0
_08058190: .4byte 0x030057A0
_08058194: .4byte 0x030057E0
_08058198:
	ldr r0, _080581A4 @ =0x030057A0
	adds r0, #0x32
	movs r1, #0
	strb r1, [r0]
	b _080581B4
	.align 2, 0
_080581A4: .4byte 0x030057A0
_080581A8:
	ldr r1, _080581BC @ =0x030057A0
	adds r2, r1, #0
	adds r2, #0x32
	movs r0, #0
	strb r0, [r2]
	strh r0, [r1, #0x24]
_080581B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080581BC: .4byte 0x030057A0
	.syntax divided
