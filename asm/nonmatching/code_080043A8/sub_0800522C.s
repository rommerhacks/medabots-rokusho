	.syntax unified

	thumb_func_start sub_0800522C
	.global sub_0800522C
sub_0800522C: @ 0x0800522C
	push {lr}
	sub sp, #8
	ldr r1, _08005254 @ =0x030017A0
	ldr r0, _08005258 @ =0x03000440
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #1
	bls _08005264
	ldrb r0, [r1, #2]
	lsls r0, r0, #7
	ldr r1, _0800525C @ =0x084C21BC
	adds r0, r0, r1
	ldr r1, _08005260 @ =0x06006600
	movs r2, #0x20
	bl CpuFastSet
	b _0800526E
	.align 2, 0
_08005254: .4byte 0x030017A0
_08005258: .4byte 0x03000440
_0800525C: .4byte 0x084C21BC
_08005260: .4byte 0x06006600
_08005264:
	ldr r0, _0800528C @ =0x084C30BC
	ldr r1, _08005290 @ =0x06006600
	movs r2, #0x20
	bl CpuFastSet
_0800526E:
	ldr r0, _08005294 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08005298 @ =0x00006330
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #1
	movs r3, #0x10
	bl fill_tilemap_rect_08042698
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800528C: .4byte 0x084C30BC
_08005290: .4byte 0x06006600
_08005294: .4byte 0x0400000A
_08005298: .4byte 0x00006330
	.syntax divided
