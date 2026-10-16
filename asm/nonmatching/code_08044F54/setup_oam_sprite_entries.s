	.syntax unified

	thumb_func_start setup_oam_sprite_entries
setup_oam_sprite_entries: @ 0x08045120
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	str r1, [sp, #0x1c]
	mov sl, r2
	mov sb, r3
	ldr r0, [sp, #0x58]
	ldr r1, [sp, #0x5c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x20]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	ldr r1, [r3]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1e
	lsls r0, r0, #0xe
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1e
	lsls r1, r1, #0x1e
	bl sub_08044E64
	adds r7, r0, #0
	add r1, sp, #0x18
	lsrs r0, r7, #0x10
	strh r0, [r1]
	adds r0, r1, #0
	strh r7, [r0, #2]
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	adds r7, r1, #0
	muls r7, r0, r7
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08045178
	lsrs r7, r7, #1
_08045178:
	mov r1, sb
	ldr r4, [r1]
	lsls r3, r4, #0x14
	lsrs r0, r3, #0x1c
	adds r1, r7, #0
	muls r1, r0, r1
	lsls r5, r4, #0x10
	lsrs r0, r5, #0x1c
	adds r7, r1, #0
	muls r7, r0, r7
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x1e
	lsls r1, r1, #0xe
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x1e
	lsls r2, r2, #0x1e
	lsrs r3, r3, #0x1c
	adds r5, r0, #0
	str r5, [sp]
	lsls r4, r4, #0x1c
	lsrs r4, r4, #0x1c
	str r4, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _08045310 @ =0x02030000
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x1c]
	bl decompress_and_load_sprite_tiles
	mov r1, sl
	cmp r1, #0
	beq _080451CE
	ldr r2, [sp, #0x20]
	lsls r1, r2, #5
	ldr r0, _08045314 @ =0x05000200
	adds r1, r1, r0
	mov r0, sl
	movs r2, #0x10
	bl CpuSet
_080451CE:
	add r0, sp, #0x18
	ldrh r1, [r0]
	lsrs r1, r1, #3
	ldrh r0, [r0, #2]
	lsrs r0, r0, #3
	adds r7, r1, #0
	muls r7, r0, r7
	movs r2, #0
	mov r0, sb
	ldr r1, [r0]
	lsls r0, r1, #0x14
	lsrs r0, r0, #0x1c
	str r1, [sp, #0x30]
	cmp r2, r0
	blo _080451EE
	b _080452FE
_080451EE:
	mov r0, sp
	adds r0, #0x18
	str r0, [sp, #0x24]
_080451F4:
	movs r4, #0
	adds r3, r1, #0
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x1c
	adds r1, r2, #1
	str r1, [sp, #0x2c]
	cmp r4, r0
	bhs _080452EC
	ldr r1, [sp, #0x24]
	ldrh r0, [r1]
	muls r0, r2, r0
	ldr r2, [sp, #0x54]
	ldrb r2, [r2, #4]
	adds r0, r0, r2
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x54]
	ldrb r5, [r0, #7]
	lsls r1, r5, #0x1c
	mov sl, r1
	movs r2, #0xd
	rsbs r2, r2, #0
	mov ip, r2
	ldr r0, [sp, #0x24]
	ldrh r0, [r0, #2]
	mov sb, r0
_08045226:
	add r1, sp, #0x28
	ldrb r1, [r1]
	strb r1, [r6]
	lsls r0, r5, #0x1e
	lsrs r0, r0, #0x1e
	movs r2, #3
	ands r0, r2
	ldrb r2, [r6, #1]
	movs r1, #4
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	mov r2, sl
	lsrs r0, r2, #0x1e
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #2
	mov r2, ip
	ands r1, r2
	orrs r1, r0
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r1, r0
	lsls r0, r3, #0x1c
	lsrs r0, r0, #0x1c
	movs r2, #1
	ands r0, r2
	lsls r0, r0, #5
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	lsls r0, r3, #0x1a
	lsrs r0, r0, #0x1e
	lsls r0, r0, #6
	movs r2, #0x3f
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, #1]
	ldr r0, [sp, #0x54]
	movs r2, #2
	ldrsh r1, [r0, r2]
	mov r0, sb
	muls r0, r4, r0
	adds r1, r1, r0
	ldr r2, _08045318 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r6, #2]
	ldr r0, _0804531C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, #2]
	ldrb r1, [r6, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r0, r2
	movs r1, #0xc0
	ands r1, r3
	movs r2, #0x3f
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #3]
	ldr r1, _08045320 @ =0x000003FF
	mov r0, r8
	ands r1, r0
	ldrh r2, [r6, #4]
	ldr r0, _08045324 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, #4]
	ldrb r1, [r6, #5]
	mov r0, ip
	ands r0, r1
	ldr r1, [sp, #0x20]
	lsls r2, r1, #4
	movs r1, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r6, #5]
	mov r2, r8
	adds r0, r2, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r6, #8
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x1c
	cmp r4, r0
	blo _08045226
_080452EC:
	ldr r1, [sp, #0x2c]
	lsls r0, r1, #0x18
	lsrs r2, r0, #0x18
	ldr r1, [sp, #0x30]
	lsls r0, r1, #0x14
	lsrs r0, r0, #0x1c
	cmp r2, r0
	bhs _080452FE
	b _080451F4
_080452FE:
	mov r0, r8
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08045310: .4byte 0x02030000
_08045314: .4byte 0x05000200
_08045318: .4byte 0x000001FF
_0804531C: .4byte 0xFFFFFE00
_08045320: .4byte 0x000003FF
_08045324: .4byte 0xFFFFFC00
	.syntax divided
