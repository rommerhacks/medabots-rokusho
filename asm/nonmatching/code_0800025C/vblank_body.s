	.syntax unified

	thumb_func_start vblank_body
vblank_body: @ 0x0800065C
	push {r4, r5, lr}
	ldr r0, _08000760 @ =0x03000434
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080006B8
	ldr r1, _08000764 @ =0x04000010
	ldr r5, _08000768 @ =0x03005000
	ldr r2, _0800076C @ =0x03002C2C
	ldrh r4, [r2]
	ldrh r3, [r5]
	adds r0, r4, r3
	strh r0, [r1]
	adds r1, #2
	ldrh r3, [r2, #2]
	ldrh r5, [r5, #2]
	adds r0, r3, r5
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08000770 @ =0x03004C30
	ldrh r5, [r2]
	adds r0, r4, r5
	strh r0, [r1]
	adds r1, #2
	ldrh r2, [r2, #2]
	adds r0, r3, r2
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08000774 @ =0x0300057C
	ldrh r5, [r2]
	adds r0, r4, r5
	strh r0, [r1]
	adds r1, #2
	ldrh r2, [r2, #2]
	adds r0, r3, r2
	strh r0, [r1]
	ldr r0, _08000778 @ =0x0400001C
	ldr r1, _0800077C @ =0x03001C04
	ldrh r2, [r1]
	adds r4, r4, r2
	strh r4, [r0]
	adds r0, #2
	ldrh r1, [r1, #2]
	adds r3, r3, r1
	strh r3, [r0]
_080006B8:
	ldr r1, _08000780 @ =0x03000430
	ldr r0, [r1]
	cmp r0, #0
	beq _080007B2
	cmp r0, #2
	bne _080007AC
	bl update_anim_object_flags
	ldr r4, _08000784 @ =0x03002414
	ldr r1, [r4]
	ldr r3, _08000788 @ =0x00000B84
	adds r0, r1, r3
	ldr r5, _0800078C @ =0x00000F8C
	adds r1, r1, r5
	bl sub_08045A14
	movs r2, #0
	ldr r5, _08000790 @ =0x00000B8A
	ldr r3, _08000794 @ =0x03001380
_080006DE:
	lsls r0, r2, #3
	ldr r1, [r4]
	adds r1, r1, r0
	adds r1, r1, r5
	ldrh r0, [r1]
	strh r0, [r3, #6]
	adds r3, #8
	adds r2, #1
	cmp r2, #0x57
	ble _080006DE
	movs r2, #0
	ldr r5, _08000784 @ =0x03002414
	ldr r0, _08000794 @ =0x03001380
	ldr r4, _08000790 @ =0x00000B8A
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r3, r0, r1
_08000700:
	ldr r0, [r5]
	lsls r1, r2, #3
	adds r0, r0, r1
	ldrh r1, [r3, #6]
	adds r0, r0, r4
	strh r1, [r0]
	adds r3, #8
	adds r2, #1
	cmp r2, #0x27
	ble _08000700
	ldr r4, _08000798 @ =0x03000440
	ldr r2, _0800079C @ =0x00000131
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08000730
	ldr r0, _08000784 @ =0x03002414
	ldr r0, [r0]
	ldr r3, _08000788 @ =0x00000B84
	adds r0, r0, r3
	ldr r1, _080007A0 @ =0x070002C0
	movs r2, #0x50
	bl CpuFastSet
_08000730:
	ldr r2, _08000784 @ =0x03002414
	ldr r0, [r2]
	ldr r5, _080007A4 @ =0x00001094
	adds r0, r0, r5
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _080007A8 @ =0x00001095
	adds r0, r0, r2
	strb r1, [r0]
	movs r3, #0x97
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080007CE
	ldr r0, _08000794 @ =0x03001380
	movs r1, #0xe0
	lsls r1, r1, #0x13
	movs r2, #0xb0
	bl CpuFastSet
	b _080007CE
	.align 2, 0
_08000760: .4byte 0x03000434
_08000764: .4byte 0x04000010
_08000768: .4byte 0x03005000
_0800076C: .4byte 0x03002C2C
_08000770: .4byte 0x03004C30
_08000774: .4byte 0x0300057C
_08000778: .4byte 0x0400001C
_0800077C: .4byte 0x03001C04
_08000780: .4byte 0x03000430
_08000784: .4byte 0x03002414
_08000788: .4byte 0x00000B84
_0800078C: .4byte 0x00000F8C
_08000790: .4byte 0x00000B8A
_08000794: .4byte 0x03001380
_08000798: .4byte 0x03000440
_0800079C: .4byte 0x00000131
_080007A0: .4byte 0x070002C0
_080007A4: .4byte 0x00001094
_080007A8: .4byte 0x00001095
_080007AC:
	movs r0, #0
	str r0, [r1]
	b _080007CE
_080007B2:
	ldr r0, _08000808 @ =0x03000440
	movs r5, #0x97
	lsls r5, r5, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080007CE
	ldr r0, _0800080C @ =0x03001380
	movs r1, #0xe0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
_080007CE:
	ldr r0, _08000808 @ =0x03000440
	movs r2, #0x97
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1]
	ldr r4, _08000810 @ =0x03000B98
	ldr r0, [r4]
	bl _call_via_r0
	ldr r0, _08000814 @ =0x030017F0
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _08000818 @ =0x08000841
	str r0, [r4]
	ldr r0, _0800081C @ =0x03007FF8
	movs r1, #1
	strh r1, [r0]
	ldr r0, _08000820 @ =0x04000202
	strh r1, [r0]
	bl sound_tick_both_channels
	bl sound_engine_tick
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08000808: .4byte 0x03000440
_0800080C: .4byte 0x03001380
_08000810: .4byte 0x03000B98
_08000814: .4byte 0x030017F0
_08000818: .4byte 0x08000841
_0800081C: .4byte 0x03007FF8
_08000820: .4byte 0x04000202
	.syntax divided
