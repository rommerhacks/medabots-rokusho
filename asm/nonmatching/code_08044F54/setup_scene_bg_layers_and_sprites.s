	.syntax unified

	thumb_func_start setup_scene_bg_layers_and_sprites
	.global setup_scene_bg_layers_and_sprites
setup_scene_bg_layers_and_sprites: @ 0x08046D1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xb8
	mov sl, r1
	str r2, [sp, #0x94]
	str r3, [sp, #0x98]
	ldr r2, [sp, #0xf0]
	ldr r7, [sp, #0xf4]
	str r7, [sp, #0x9c]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _08046D8C
	ldr r1, _08046D80 @ =0x03000440
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08046D52
	ldr r3, _08046D84 @ =0x00000131
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
_08046D52:
	ldr r0, _08046D88 @ =0x03005308
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #4
	adds r0, r0, r1
	ldr r1, [r0, #0x2c]
	movs r2, #1
	orrs r1, r2
	subs r2, #0xa
	ands r1, r2
	str r1, [r0, #0x2c]
	ldr r4, [sp, #0x94]
	str r4, [r0, #4]
	ldr r5, [sp, #0x98]
	str r5, [r0, #8]
	ldr r6, [sp, #0xd8]
	str r6, [r0, #0xc]
	ldr r1, [sp, #0xdc]
	str r1, [r0, #0x10]
	str r7, [r0, #0x28]
	b _080471CA
	.align 2, 0
_08046D80: .4byte 0x03000440
_08046D84: .4byte 0x00000131
_08046D88: .4byte 0x03005308
_08046D8C:
	ldr r3, _08046E28 @ =0x03005308
	mov sb, r3
	ldr r1, [r3]
	lsls r0, r7, #1
	adds r0, r0, r7
	mov r8, r0
	mov r4, r8
	lsls r4, r4, #4
	str r4, [sp, #0xac]
	adds r1, r4, r1
	ldr r1, [r1, #0x2c]
	movs r0, #2
	adds r5, r1, #0
	ands r5, r0
	cmp r5, #0
	bne _08046DAE
	b _08047074
_08046DAE:
	movs r5, #0
	str r5, [sp, #0xa0]
	ands r2, r0
	cmp r2, #0
	beq _08046DBE
	movs r6, #0xb0
	lsls r6, r6, #1
	str r6, [sp, #0xa0]
_08046DBE:
	ldr r3, _08046E2C @ =0x030052D0
	adds r1, r3, #0
	ldr r0, _08046E30 @ =0x0807ECA0
	ldm r0!, {r2, r4, r7}
	stm r1!, {r2, r4, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldr r4, _08046E34 @ =0x030052B0
	adds r1, r4, #0
	ldr r0, _08046E38 @ =0x0807ECB8
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
	ldr r2, _08046E3C @ =0x03005290
	adds r1, r2, #0
	ldr r0, _08046E40 @ =0x0807ECD0
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldr r6, _08046E44 @ =0x030052F0
	mov ip, r6
	mov r1, ip
	ldr r0, _08046E48 @ =0x0807ECE8
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	mov r7, sb
	ldr r0, [r7]
	ldr r1, [sp, #0xac]
	adds r0, r1, r0
	ldr r5, [r0, #4]
	str r5, [sp, #0x94]
	ldr r6, [r0, #8]
	str r6, [sp, #0x98]
	ldr r7, [r0, #0xc]
	str r7, [sp, #0xd8]
	ldr r1, [r0, #0x10]
	str r1, [sp, #0xdc]
	ldr r7, [r0, #0x28]
	cmp r5, #0
	bge _08046E4C
	movs r0, #0
	strb r0, [r3, #0x10]
	strb r0, [r2, #0x10]
	strb r0, [r4, #0x10]
	ldr r2, [sp, #0x9c]
	lsls r2, r2, #1
	str r2, [sp, #0xa8]
	b _08046FF0
	.align 2, 0
_08046E28: .4byte 0x03005308
_08046E2C: .4byte 0x030052D0
_08046E30: .4byte 0x0807ECA0
_08046E34: .4byte 0x030052B0
_08046E38: .4byte 0x0807ECB8
_08046E3C: .4byte 0x03005290
_08046E40: .4byte 0x0807ECD0
_08046E44: .4byte 0x030052F0
_08046E48: .4byte 0x0807ECE8
_08046E4C:
	ldr r5, [sp, #0x94]
	lsls r1, r5, #4
	ldr r0, _08047050 @ =0x0807ED00
	adds r1, r1, r0
	ldr r0, [r1]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	strb r0, [r3, #0x10]
	ldr r6, [sp, #0x98]
	lsls r6, r6, #4
	mov sb, r6
	ldr r0, _08047054 @ =0x0807F4A0
	add r0, sb
	str r0, [sp, #0xa4]
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	strb r0, [r2, #0x10]
	ldr r0, [sp, #0xd8]
	lsls r0, r0, #4
	mov r8, r0
	ldr r6, _08047058 @ =0x0807FC40
	add r6, r8
	ldr r0, [r6]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0x10]
	ldr r2, [sp, #0xdc]
	lsls r5, r2, #5
	ldr r0, _0804705C @ =0x080803E0
	adds r5, r5, r0
	ldr r0, [r5]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	mov r3, ip
	strb r0, [r3, #0x10]
	ldr r4, [sp, #0xa0]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r2, r4, r0
	add r0, sp, #0x10
	strh r2, [r0]
	mov r2, sl
	ldr r0, [r2, #4]
	ldr r2, [r1]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	str r2, [sp, #0xb4]
	ldr r4, [sp, #0xec]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r3, sl
	ldr r3, [r3, #8]
	str r3, [sp]
	add r2, sp, #0x10
	str r2, [sp, #4]
	str r7, [sp, #8]
	ldr r2, [sp, #0xb4]
	adds r3, r4, #0
	bl load_sprite_tree_recursive
	add r1, sp, #0x10
	ldr r3, [sp, #0xa0]
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r3, r2
	strh r0, [r1]
	mov r3, sl
	ldr r0, [r3, #4]
	ldr r1, [sp, #0xa4]
	ldr r2, [r1]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	ldr r1, [r3, #8]
	str r1, [sp]
	add r3, sp, #0x10
	str r3, [sp, #4]
	str r7, [sp, #8]
	ldr r1, [sp, #0xa4]
	adds r3, r4, #0
	bl load_sprite_tree_recursive
	add r1, sp, #0x10
	ldr r2, [sp, #0xa0]
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r0, [r1]
	mov r1, sl
	ldr r0, [r1, #4]
	ldr r2, [r6]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	ldr r1, [r1, #8]
	str r1, [sp]
	add r3, sp, #0x10
	str r3, [sp, #4]
	str r7, [sp, #8]
	adds r1, r6, #0
	adds r3, r4, #0
	bl load_sprite_tree_recursive
	add r1, sp, #0x10
	ldr r6, [sp, #0xa0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r0, [r1]
	mov r3, sl
	ldr r0, [r3, #4]
	ldr r2, [r5]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	ldr r1, [r3, #8]
	str r1, [sp]
	add r6, sp, #0x10
	str r6, [sp, #4]
	str r7, [sp, #8]
	adds r1, r5, #0
	adds r3, r4, #0
	bl load_sprite_tree_recursive
	mov r6, sb
	ldr r7, [sp, #0x9c]
	lsls r7, r7, #1
	str r7, [sp, #0xa8]
	ldr r0, [sp, #0x9c]
	cmp r0, #0
	beq _08046FF0
	ldr r1, [sp, #0xa4]
	ldrb r0, [r1]
	lsls r0, r0, #0x1a
	cmp r0, #0
	beq _08046F8E
	adds r4, r1, #0
	adds r5, r6, #0
	ldr r7, _08047058 @ =0x0807FC40
_08046F5E:
	ldrb r0, [r4, #1]
	lsrs r0, r0, #7
	cmp r0, #0
	bne _08046F82
	mov r2, sl
	ldr r0, [r2, #4]
	ldr r1, [r2, #8]
	adds r2, r5, r7
	ldrb r3, [r2]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1a
	ldrb r2, [r4]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	str r2, [sp]
	adds r2, r6, r7
	bl load_sprite_tiles_by_table
_08046F82:
	adds r4, #4
	adds r5, #4
	ldrb r0, [r4]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bne _08046F5E
_08046F8E:
	ldr r1, _08047058 @ =0x0807FC40
	mov r7, r8
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	beq _08046FE4
	mov sb, r1
	movs r3, #0
	mov r8, r3
_08046FA2:
	adds r6, r7, #0
	mov r4, r8
	adds r5, r4, r6
	mov r0, sb
	adds r4, r5, r0
	ldrb r0, [r4, #1]
	lsrs r0, r0, #7
	cmp r0, #0
	bne _08046FD2
	mov r1, sl
	ldr r0, [r1, #4]
	ldr r1, [r1, #8]
	ldr r3, _08047054 @ =0x0807F4A0
	adds r2, r6, r3
	adds r3, r5, r3
	ldrb r3, [r3]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1a
	ldrb r4, [r4]
	lsls r4, r4, #0x1a
	lsrs r4, r4, #0x1a
	str r4, [sp]
	bl load_sprite_tiles_by_table
_08046FD2:
	movs r2, #4
	add r8, r2
	mov r3, r8
	adds r0, r3, r6
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bne _08046FA2
_08046FE4:
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	ldr r2, [sp, #0xd8]
	ldr r3, [sp, #0xdc]
	bl toggle_bg_layer_visibility
_08046FF0:
	ldr r4, [sp, #0xa8]
	ldr r5, [sp, #0x9c]
	adds r2, r4, r5
	lsls r0, r2, #5
	mov r6, sl
	adds r3, r6, r0
	adds r1, r3, #0
	adds r1, #0xc
	ldr r0, _08047060 @ =0x030052D0
	ldm r0!, {r4, r5, r7}
	stm r1!, {r4, r5, r7}
	ldm r0!, {r4, r6, r7}
	stm r1!, {r4, r6, r7}
	adds r1, r3, #0
	adds r1, #0x24
	ldr r0, _08047064 @ =0x03005290
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	adds r1, r3, #0
	adds r1, #0x3c
	ldr r0, _08047068 @ =0x030052B0
	ldm r0!, {r4, r5, r7}
	stm r1!, {r4, r5, r7}
	ldm r0!, {r4, r6, r7}
	stm r1!, {r4, r6, r7}
	adds r1, r3, #0
	adds r1, #0x54
	ldr r0, _0804706C @ =0x030052F0
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, _08047070 @ =0x03005308
	ldr r0, [r0]
	lsls r2, r2, #4
	adds r2, r2, r0
	ldr r0, [r2, #0x2c]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [r2, #0x2c]
	b _080471CA
	.align 2, 0
_08047050: .4byte 0x0807ED00
_08047054: .4byte 0x0807F4A0
_08047058: .4byte 0x0807FC40
_0804705C: .4byte 0x080803E0
_08047060: .4byte 0x030052D0
_08047064: .4byte 0x03005290
_08047068: .4byte 0x030052B0
_0804706C: .4byte 0x030052F0
_08047070: .4byte 0x03005308
_08047074:
	movs r0, #8
	ands r1, r0
	cmp r1, #0
	bne _0804707E
	b _080471CA
_0804707E:
	mov r6, sp
	adds r6, #0x14
	str r6, [sp, #0xb0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x80
	bl custom_memset
	ldr r0, _080471DC @ =0x03000440
	ldr r1, _080471E0 @ =0x00000131
	adds r0, r0, r1
	strb r5, [r0]
	mov r2, sb
	ldr r0, [r2]
	ldr r3, [sp, #0xac]
	adds r0, r3, r0
	ldr r4, [r0, #4]
	str r4, [sp, #0x94]
	ldr r5, [r0, #8]
	str r5, [sp, #0x98]
	ldr r6, [r0, #0xc]
	str r6, [sp, #0xd8]
	ldr r0, [r0, #0x10]
	str r0, [sp, #0xdc]
	ldr r2, _080471E4 @ =0x030052D0
	mov r1, r8
	lsls r0, r1, #5
	mov r4, sl
	adds r3, r4, r0
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0xc
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldr r1, _080471E8 @ =0x03005290
	adds r0, r3, #0
	adds r0, #0x24
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldr r1, _080471EC @ =0x030052B0
	adds r0, r3, #0
	adds r0, #0x3c
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldr r1, _080471F0 @ =0x030052F0
	adds r0, r3, #0
	adds r0, #0x54
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldr r4, [sp, #0xb0]
	ldrb r1, [r2, #0x10]
	ldr r0, [sp, #0xe0]
	lsls r0, r0, #8
	mov ip, r0
	ldr r0, [sp, #0xe4]
	lsls r3, r0, #8
	ldr r0, [sp, #0xe8]
	lsls r0, r0, #0x10
	mov r8, r0
	lsls r7, r7, #0x18
	mov sb, r7
	cmp r1, #0
	beq _0804712E
	ldr r7, [sp, #0x94]
	lsls r1, r7, #4
	ldr r0, _080471F4 @ =0x0807ED00
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _0804712E
	movs r5, #0x3f
_08047120:
	ldm r2!, {r0}
	stm r4!, {r0}
	ldrb r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08047120
_0804712E:
	ldr r0, _080471E8 @ =0x03005290
	ldrb r0, [r0, #0x10]
	ldr r6, _080471EC @ =0x030052B0
	ldr r7, _080471F0 @ =0x030052F0
	cmp r0, #0
	beq _0804715C
	ldr r0, [sp, #0x98]
	lsls r1, r0, #4
	ldr r0, _080471F8 @ =0x0807F4A0
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _0804715C
	movs r5, #0x3f
_0804714E:
	ldm r2!, {r0}
	stm r4!, {r0}
	ldrb r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804714E
_0804715C:
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	beq _08047184
	ldr r2, [sp, #0xd8]
	lsls r1, r2, #4
	ldr r0, _080471FC @ =0x0807FC40
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _08047184
	movs r5, #0x3f
_08047176:
	ldm r2!, {r0}
	stm r4!, {r0}
	ldrb r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08047176
_08047184:
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	beq _080471AC
	ldr r5, [sp, #0xdc]
	lsls r1, r5, #5
	ldr r0, _08047200 @ =0x080803E0
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _080471AC
	movs r5, #0x3f
_0804719E:
	ldm r2!, {r0}
	stm r4!, {r0}
	ldrb r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804719E
_080471AC:
	str r3, [sp]
	mov r6, r8
	asrs r0, r6, #0x10
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	mov r7, sb
	lsrs r0, r7, #0x18
	str r0, [sp, #0xc]
	mov r0, sl
	add r1, sp, #0x14
	movs r2, #1
	mov r3, ip
	bl render_sprite_node_recursive
_080471CA:
	add sp, #0xb8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080471DC: .4byte 0x03000440
_080471E0: .4byte 0x00000131
_080471E4: .4byte 0x030052D0
_080471E8: .4byte 0x03005290
_080471EC: .4byte 0x030052B0
_080471F0: .4byte 0x030052F0
_080471F4: .4byte 0x0807ED00
_080471F8: .4byte 0x0807F4A0
_080471FC: .4byte 0x0807FC40
_08047200: .4byte 0x080803E0
	.syntax divided
