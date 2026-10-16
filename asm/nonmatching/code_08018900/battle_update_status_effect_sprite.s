	.syntax unified

	thumb_func_start battle_update_status_effect_sprite
battle_update_status_effect_sprite: @ 0x08019720
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08019770 @ =0x03000590
	lsls r7, r4, #8
	adds r0, r7, r0
	adds r0, #0xc9
	ldrb r1, [r0]
	adds r5, r1, #0
	cmp r5, #0
	bne _08019736
	b _08019B28
_08019736:
	adds r0, r1, #0
	subs r0, #0xd
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08019798
	ldr r2, _08019774 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r6, r0, #0
	adds r6, #0x47
	lsls r0, r6, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _0801977C
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, r5
	bne _0801977C
	ldr r0, _08019778 @ =0x083B5F80
	ldr r0, [r0, #0x18]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _0801978C
	.align 2, 0
_08019770: .4byte 0x03000590
_08019774: .4byte 0x03002C30
_08019778: .4byte 0x083B5F80
_0801977C:
	ldr r0, _08019790 @ =0x083B5F80
	ldr r0, [r0, #0x18]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_0801978C:
	ldr r0, _08019794 @ =0x083C4C60
	b _08019A82
	.align 2, 0
_08019790: .4byte 0x083B5F80
_08019794: .4byte 0x083C4C60
_08019798:
	adds r0, r1, #0
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080197A8
	cmp r5, #0x29
	bne _080197FC
_080197A8:
	ldr r2, _080197D8 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r6, r0, #0
	adds r6, #0x47
	lsls r0, r6, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _080197E0
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, r5
	bne _080197E0
	ldr r0, _080197DC @ =0x083B5F80
	ldr r0, [r0, #0x20]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _080197F0
	.align 2, 0
_080197D8: .4byte 0x03002C30
_080197DC: .4byte 0x083B5F80
_080197E0:
	ldr r0, _080197F4 @ =0x083B5F80
	ldr r0, [r0, #0x20]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_080197F0:
	ldr r0, _080197F8 @ =0x083C4C6C
	b _08019A82
	.align 2, 0
_080197F4: .4byte 0x083B5F80
_080197F8: .4byte 0x083C4C6C
_080197FC:
	adds r0, r1, #0
	subs r0, #0x13
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080198DC
	ldr r2, _08019834 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r6, r0, #0
	adds r6, #0x47
	lsls r0, r6, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _08019850
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, r5
	bne _08019850
	cmp r5, #0x13
	bne _0801983C
	ldr r0, _08019838 @ =0x083B5F80
	ldr r0, [r0, #0x24]
	b _08019840
	.align 2, 0
_08019834: .4byte 0x03002C30
_08019838: .4byte 0x083B5F80
_0801983C:
	ldr r0, _0801984C @ =0x083B5F80
	ldr r0, [r0, #0x28]
_08019840:
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	adds r5, r7, #0
	b _0801988C
	.align 2, 0
_0801984C: .4byte 0x083B5F80
_08019850:
	ldr r0, _08019874 @ =0x03000590
	lsls r1, r4, #8
	adds r0, r1, r0
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #0x13
	bne _0801987C
	ldr r0, _08019878 @ =0x083B5F80
	ldr r0, [r0, #0x24]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	b _0801988C
	.align 2, 0
_08019874: .4byte 0x03000590
_08019878: .4byte 0x083B5F80
_0801987C:
	ldr r0, _080198A4 @ =0x083B5F80
	ldr r0, [r0, #0x28]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_0801988C:
	ldr r0, _080198A8 @ =0x03000590
	adds r0, r5, r0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _080198B4
	ldr r0, _080198AC @ =0x083C4C70
	ldr r1, _080198B0 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	b _080198BE
	.align 2, 0
_080198A4: .4byte 0x083B5F80
_080198A8: .4byte 0x03000590
_080198AC: .4byte 0x083C4C70
_080198B0: .4byte 0x0300052E
_080198B4:
	ldr r0, _080198D0 @ =0x083C4C74
	ldr r1, _080198D4 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
_080198BE:
	ldr r0, _080198D8 @ =0x03002C30
	lsls r1, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r3, [r1, #0xb]
	subs r3, #2
	b _08019A9A
	.align 2, 0
_080198D0: .4byte 0x083C4C74
_080198D4: .4byte 0x0300052E
_080198D8: .4byte 0x03002C30
_080198DC:
	adds r0, r1, #0
	subs r0, #0xf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08019984
	ldr r2, _08019918 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r6, r0, #0
	adds r6, #0x47
	lsls r0, r6, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _08019920
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, r5
	bne _08019920
	ldr r0, _0801991C @ =0x083B5F80
	ldr r0, [r0, #0x1c]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _08019930
	.align 2, 0
_08019918: .4byte 0x03002C30
_0801991C: .4byte 0x083B5F80
_08019920:
	ldr r0, _0801994C @ =0x083B5F80
	ldr r0, [r0, #0x1c]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08019930:
	ldr r0, _08019950 @ =0x03000590
	lsls r1, r4, #8
	adds r1, r1, r0
	adds r1, #0xc9
	ldrb r0, [r1]
	cmp r0, #0xf
	bne _0801995C
	ldr r0, _08019954 @ =0x083C4C64
	ldr r1, _08019958 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	b _08019966
	.align 2, 0
_0801994C: .4byte 0x083B5F80
_08019950: .4byte 0x03000590
_08019954: .4byte 0x083C4C64
_08019958: .4byte 0x0300052E
_0801995C:
	ldr r0, _08019978 @ =0x083C4C68
	ldr r1, _0801997C @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
_08019966:
	ldr r0, _08019980 @ =0x03002C30
	lsls r1, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r3, [r1, #0xb]
	b _08019A98
	.align 2, 0
_08019978: .4byte 0x083C4C68
_0801997C: .4byte 0x0300052E
_08019980: .4byte 0x03002C30
_08019984:
	cmp r5, #0x2b
	bne _080199DC
	ldr r2, _080199B8 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r5, r0, #0
	adds r5, #0x47
	lsls r0, r5, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _080199C0
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _080199C0
	ldr r0, _080199BC @ =0x083B5F80
	ldr r0, [r0, #0x40]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _080199D0
	.align 2, 0
_080199B8: .4byte 0x03002C30
_080199BC: .4byte 0x083B5F80
_080199C0:
	ldr r0, _080199D4 @ =0x083B5F80
	ldr r0, [r0, #0x40]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_080199D0:
	ldr r0, _080199D8 @ =0x083C4C90
	b _08019A82
	.align 2, 0
_080199D4: .4byte 0x083B5F80
_080199D8: .4byte 0x083C4C90
_080199DC:
	cmp r5, #0x2c
	bne _08019A34
	ldr r2, _08019A10 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r5, r0, #0
	adds r5, #0x47
	lsls r0, r5, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _08019A18
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0x2c
	bne _08019A18
	ldr r0, _08019A14 @ =0x083B5F80
	ldr r0, [r0, #0x44]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _08019A28
	.align 2, 0
_08019A10: .4byte 0x03002C30
_08019A14: .4byte 0x083B5F80
_08019A18:
	ldr r0, _08019A2C @ =0x083B5F80
	ldr r0, [r0, #0x44]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08019A28:
	ldr r0, _08019A30 @ =0x083C4C94
	b _08019A82
	.align 2, 0
_08019A2C: .4byte 0x083B5F80
_08019A30: .4byte 0x083C4C94
_08019A34:
	cmp r5, #0x2e
	bne _08019AB8
	ldr r2, _08019A68 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r5, r0, #0
	adds r5, #0x47
	lsls r0, r5, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _08019A70
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0x2e
	bne _08019A70
	ldr r0, _08019A6C @ =0x083B5F80
	ldr r0, [r0, #0x48]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _08019A80
	.align 2, 0
_08019A68: .4byte 0x03002C30
_08019A6C: .4byte 0x083B5F80
_08019A70:
	ldr r0, _08019AA8 @ =0x083B5F80
	ldr r0, [r0, #0x48]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08019A80:
	ldr r0, _08019AAC @ =0x083C4C98
_08019A82:
	ldr r1, _08019AB0 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	ldr r1, _08019AB4 @ =0x03002C30
	lsls r0, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r3, [r0, #0xb]
_08019A98:
	adds r3, #4
_08019A9A:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl battle_setup_part_sprite
	b _08019B28
	.align 2, 0
_08019AA8: .4byte 0x083B5F80
_08019AAC: .4byte 0x083C4C98
_08019AB0: .4byte 0x0300052E
_08019AB4: .4byte 0x03002C30
_08019AB8:
	cmp r5, #0x2f
	bne _08019B28
	ldr r2, _08019AEC @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r5, r0, #0
	adds r5, #0x47
	lsls r0, r5, #6
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r2, r1, #0
	cmp r0, #0
	beq _08019AF4
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0x2f
	bne _08019AF4
	ldr r0, _08019AF0 @ =0x083B5F80
	ldr r0, [r0, #0x4c]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _08019B04
	.align 2, 0
_08019AEC: .4byte 0x03002C30
_08019AF0: .4byte 0x083B5F80
_08019AF4:
	ldr r0, _08019B30 @ =0x083B5F80
	ldr r0, [r0, #0x4c]
	adds r1, r2, r4
	adds r1, #0x47
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08019B04:
	ldr r0, _08019B34 @ =0x083C4C9C
	ldr r1, _08019B38 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	ldr r1, _08019B3C @ =0x03002C30
	lsls r0, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r3, [r0, #0xb]
	adds r3, #4
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl battle_setup_part_sprite
_08019B28:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08019B30: .4byte 0x083B5F80
_08019B34: .4byte 0x083C4C9C
_08019B38: .4byte 0x0300052E
_08019B3C: .4byte 0x03002C30
	.syntax divided
