	.syntax unified

	thumb_func_start sub_0802FC3C
sub_0802FC3C: @ 0x0802FC3C
	push {r4, r5, lr}
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r0, _0802FCD4 @ =0x0850EF18
	ldr r1, _0802FCD8 @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r2, _0802FCDC @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	movs r4, #0
	ldr r0, _0802FCE0 @ =0x0000C624
	strh r0, [r1]
	ldr r1, _0802FCE4 @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r3, _0802FCE8 @ =0x03001800
	movs r5, #0x87
	adds r5, r5, r3
	mov ip, r5
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _0802FCEC @ =0x00000842
	adds r0, r2, r5
	strh r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r5, _0802FCF0 @ =0x00000844
	adds r1, r2, r5
	strh r0, [r1]
	ldr r0, _0802FCF4 @ =0x0000084A
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0802FCF8 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x80
	strb r1, [r0]
	adds r5, #5
	adds r0, r2, r5
	strb r1, [r0]
	ldr r1, _0802FCFC @ =0x00000858
	adds r0, r2, r1
	strh r4, [r0]
	adds r5, #2
	adds r1, r2, r5
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _0802FD00 @ =0x00000846
	adds r2, r2, r0
	ldr r0, _0802FD04 @ =0x00008302
	strh r0, [r2]
	adds r3, #0xaa
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802FCD4: .4byte 0x0850EF18
_0802FCD8: .4byte 0x050002C0
_0802FCDC: .4byte 0x03002C30
_0802FCE0: .4byte 0x0000C624
_0802FCE4: .4byte 0x0000085C
_0802FCE8: .4byte 0x03001800
_0802FCEC: .4byte 0x00000842
_0802FCF0: .4byte 0x00000844
_0802FCF4: .4byte 0x0000084A
_0802FCF8: .4byte 0x00000848
_0802FCFC: .4byte 0x00000858
_0802FD00: .4byte 0x00000846
_0802FD04: .4byte 0x00008302
	.syntax divided
