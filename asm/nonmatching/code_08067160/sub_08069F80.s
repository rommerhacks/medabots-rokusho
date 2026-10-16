	.syntax unified

	thumb_func_start sub_08069F80
sub_08069F80: @ 0x08069F80
	push {r4, r5, lr}
	ldr r0, _08069F98 @ =0x03006F88
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0x16
	bls _08069F8E
	b _0806A220
_08069F8E:
	lsls r0, r1, #2
	ldr r1, _08069F9C @ =_08069FA0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08069F98: .4byte 0x03006F88
_08069F9C: .4byte _08069FA0
_08069FA0: @ jump table
	.4byte _08069FFC @ case 0
	.4byte _0806A040 @ case 1
	.4byte _0806A040 @ case 2
	.4byte _0806A040 @ case 3
	.4byte _0806A040 @ case 4
	.4byte _0806A040 @ case 5
	.4byte _0806A034 @ case 6
	.4byte _0806A034 @ case 7
	.4byte _0806A034 @ case 8
	.4byte _0806A034 @ case 9
	.4byte _0806A034 @ case 10
	.4byte _0806A034 @ case 11
	.4byte _0806A034 @ case 12
	.4byte _0806A034 @ case 13
	.4byte _0806A050 @ case 14
	.4byte _0806A078 @ case 15
	.4byte _0806A084 @ case 16
	.4byte _0806A09C @ case 17
	.4byte _0806A10C @ case 18
	.4byte _0806A130 @ case 19
	.4byte _0806A1AC @ case 20
	.4byte _0806A1CC @ case 21
	.4byte _0806A20C @ case 22
_08069FFC:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	bl init_battle_sprite_small
	movs r0, #0
	movs r1, #1
	movs r2, #0x18
	movs r3, #0x58
	bl sprite_animation_dispatch
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806A030 @ =0x03006F88
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0806A228
	.align 2, 0
_0806A030: .4byte 0x03006F88
_0806A034:
	ldr r0, [r2]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl dma_copy_tilemap_strip
_0806A040:
	ldr r0, _0806A04C @ =0x084864E8
	ldr r0, [r0, #4]
	bl run_message
	b _0806A1F2
	.align 2, 0
_0806A04C: .4byte 0x084864E8
_0806A050:
	ldr r0, _0806A074 @ =0x084864E8
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	bne _0806A05E
	b _0806A220
_0806A05E:
	bl sub_0803FB0C
	bl init_battle_sprite_medium
	movs r0, #1
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sprite_animation_dispatch
	b _0806A1F2
	.align 2, 0
_0806A074: .4byte 0x084864E8
_0806A078:
	ldr r0, _0806A080 @ =0x084864E8
	ldr r0, [r0, #8]
	b _0806A1E6
	.align 2, 0
_0806A080: .4byte 0x084864E8
_0806A084:
	ldr r0, _0806A098 @ =0x03002C30
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A090
	b _0806A220
_0806A090:
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	b _0806A220
	.align 2, 0
_0806A098: .4byte 0x03002C30
_0806A09C:
	ldr r0, _0806A0F0 @ =0x084864E8
	ldr r0, [r0, #0x14]
	bl run_message
	cmp r0, #0
	bne _0806A0AA
	b _0806A220
_0806A0AA:
	bl sub_0803FB0C
	ldr r3, _0806A0F4 @ =0x083C1A00
	ldr r2, _0806A0F8 @ =0x08486160
	ldr r0, _0806A0FC @ =0x03006FDC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, [r0]
	ldr r0, _0806A100 @ =0x030004DE
	ldr r2, _0806A104 @ =0x083C3F38
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl sub_08069EE4
	movs r0, #0
	movs r1, #2
	movs r2, #0x40
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r0, _0806A108 @ =0x03002C30
	adds r0, #0x42
	movs r1, #0x68
	strh r1, [r0]
	b _0806A1F2
	.align 2, 0
_0806A0F0: .4byte 0x084864E8
_0806A0F4: .4byte 0x083C1A00
_0806A0F8: .4byte 0x08486160
_0806A0FC: .4byte 0x03006FDC
_0806A100: .4byte 0x030004DE
_0806A104: .4byte 0x083C3F38
_0806A108: .4byte 0x03002C30
_0806A10C:
	ldr r0, _0806A128 @ =0x084864E8
	ldr r0, [r0, #0xc]
	bl run_message
	cmp r0, #0
	bne _0806A11A
	b _0806A220
_0806A11A:
	ldr r0, _0806A12C @ =0x03002C30
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806A126
	b _0806A220
_0806A126:
	b _0806A1EE
	.align 2, 0
_0806A128: .4byte 0x084864E8
_0806A12C: .4byte 0x03002C30
_0806A130:
	ldr r2, _0806A190 @ =0x084864E8
	ldr r5, _0806A194 @ =0x08486160
	ldr r4, _0806A198 @ =0x03006FDC
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r0, [r0, #9]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _0806A220
	bl sub_0803FB0C
	ldr r2, _0806A19C @ =0x083C1A00
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r3, #6
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r0, _0806A1A0 @ =0x030004DE
	ldr r2, _0806A1A4 @ =0x083C3F38
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl sub_08069EE4
	movs r0, #0
	movs r1, #2
	movs r2, #0x40
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r0, _0806A1A8 @ =0x03002C30
	adds r0, #0x42
	movs r1, #0xa8
	strh r1, [r0]
	b _0806A1F2
	.align 2, 0
_0806A190: .4byte 0x084864E8
_0806A194: .4byte 0x08486160
_0806A198: .4byte 0x03006FDC
_0806A19C: .4byte 0x083C1A00
_0806A1A0: .4byte 0x030004DE
_0806A1A4: .4byte 0x083C3F38
_0806A1A8: .4byte 0x03002C30
_0806A1AC:
	ldr r0, _0806A1C4 @ =0x084864E8
	ldr r0, [r0, #0x10]
	bl run_message
	cmp r0, #0
	beq _0806A220
	ldr r0, _0806A1C8 @ =0x03002C30
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806A220
	b _0806A1EE
	.align 2, 0
_0806A1C4: .4byte 0x084864E8
_0806A1C8: .4byte 0x03002C30
_0806A1CC:
	ldr r3, _0806A1FC @ =0x084864E8
	ldr r2, _0806A200 @ =0x08486160
	ldr r0, _0806A204 @ =0x03006FDC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #9]
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
_0806A1E6:
	bl run_message
	cmp r0, #0
	beq _0806A220
_0806A1EE:
	bl sub_0803FB0C
_0806A1F2:
	ldr r1, _0806A208 @ =0x03006F88
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0806A220
	.align 2, 0
_0806A1FC: .4byte 0x084864E8
_0806A200: .4byte 0x08486160
_0806A204: .4byte 0x03006FDC
_0806A208: .4byte 0x03006F88
_0806A20C:
	ldr r0, _0806A21C @ =0x084864E8
	ldr r0, [r0, #0x18]
	bl run_message
	cmp r0, #0
	beq _0806A220
	movs r0, #1
	b _0806A22A
	.align 2, 0
_0806A21C: .4byte 0x084864E8
_0806A220:
	bl update_sprite_animations_tick_0806AF40
	bl update_sprite_animations_0806B334
_0806A228:
	movs r0, #0
_0806A22A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
