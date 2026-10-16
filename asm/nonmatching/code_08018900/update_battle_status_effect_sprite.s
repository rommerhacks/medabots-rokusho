	.syntax unified

	thumb_func_start update_battle_status_effect_sprite
update_battle_status_effect_sprite: @ 0x08019B40
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r2, _08019BAC @ =0x03000590
	lsls r6, r4, #8
	adds r0, r6, r2
	mov ip, r0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08019B5A
	b _08019CE0
_08019B5A:
	mov r0, ip
	adds r0, #0xde
	ldrb r0, [r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r1, r1, r2
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _08019B76
	b _08019D02
_08019B76:
	ldr r2, _08019BB0 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r5, r0, #0
	adds r5, #0x48
	lsls r0, r5, #6
	adds r2, r0, r2
	ldrh r0, [r2]
	adds r3, r1, #0
	cmp r0, #0
	beq _08019BFC
	adds r0, r2, #0
	adds r0, #0x23
	mov r1, ip
	adds r1, #0xdf
	ldrb r0, [r0]
	ldrb r2, [r1]
	cmp r0, r2
	bne _08019BFC
	ldrb r1, [r1]
	cmp r1, #0x1c
	beq _08019BC4
	cmp r1, #0x1c
	bgt _08019BB4
	cmp r1, #0x1b
	beq _08019BBA
	b _08019BE4
	.align 2, 0
_08019BAC: .4byte 0x03000590
_08019BB0: .4byte 0x03002C30
_08019BB4:
	cmp r1, #0x1d
	beq _08019BD0
	b _08019BE4
_08019BBA:
	ldr r0, _08019BC0 @ =0x083B5F80
	ldr r0, [r0, #0x30]
	b _08019BD4
	.align 2, 0
_08019BC0: .4byte 0x083B5F80
_08019BC4:
	ldr r0, _08019BCC @ =0x083B5F80
	ldr r0, [r0, #0x34]
	b _08019BD4
	.align 2, 0
_08019BCC: .4byte 0x083B5F80
_08019BD0:
	ldr r0, _08019BE0 @ =0x083B5F80
	ldr r0, [r0, #0x38]
_08019BD4:
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	adds r5, r6, #0
	b _08019C60
	.align 2, 0
_08019BE0: .4byte 0x083B5F80
_08019BE4:
	ldr r0, _08019BF8 @ =0x083B5F80
	ldr r0, [r0, #0x2c]
	adds r1, r3, r4
	adds r1, #0x48
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	lsls r5, r4, #8
	b _08019C60
	.align 2, 0
_08019BF8: .4byte 0x083B5F80
_08019BFC:
	ldr r0, _08019C18 @ =0x03000590
	lsls r1, r4, #8
	adds r0, r1, r0
	adds r0, #0xdf
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #0x1c
	beq _08019C2C
	cmp r0, #0x1c
	bgt _08019C1C
	cmp r0, #0x1b
	beq _08019C22
	b _08019C50
	.align 2, 0
_08019C18: .4byte 0x03000590
_08019C1C:
	cmp r0, #0x1d
	beq _08019C38
	b _08019C50
_08019C22:
	ldr r0, _08019C28 @ =0x083B5F80
	ldr r0, [r0, #0x30]
	b _08019C3C
	.align 2, 0
_08019C28: .4byte 0x083B5F80
_08019C2C:
	ldr r0, _08019C34 @ =0x083B5F80
	ldr r0, [r0, #0x34]
	b _08019C3C
	.align 2, 0
_08019C34: .4byte 0x083B5F80
_08019C38:
	ldr r0, _08019C4C @ =0x083B5F80
	ldr r0, [r0, #0x38]
_08019C3C:
	adds r1, r3, r4
	adds r1, #0x48
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	b _08019C60
	.align 2, 0
_08019C4C: .4byte 0x083B5F80
_08019C50:
	ldr r0, _08019C78 @ =0x083B5F80
	ldr r0, [r0, #0x2c]
	adds r1, r3, r4
	adds r1, #0x48
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08019C60:
	ldr r0, _08019C7C @ =0x03000590
	adds r0, r5, r0
	adds r0, #0xdf
	ldrb r0, [r0]
	cmp r0, #0x1c
	beq _08019C90
	cmp r0, #0x1c
	bgt _08019C80
	cmp r0, #0x1b
	beq _08019C86
	b _08019CAC
	.align 2, 0
_08019C78: .4byte 0x083B5F80
_08019C7C: .4byte 0x03000590
_08019C80:
	cmp r0, #0x1d
	beq _08019C98
	b _08019CAC
_08019C86:
	ldr r0, _08019C8C @ =0x083C4C7C
	b _08019C9A
	.align 2, 0
_08019C8C: .4byte 0x083C4C7C
_08019C90:
	ldr r0, _08019C94 @ =0x083C4C80
	b _08019C9A
	.align 2, 0
_08019C94: .4byte 0x083C4C80
_08019C98:
	ldr r0, _08019CA4 @ =0x083C4C84
_08019C9A:
	ldr r1, _08019CA8 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	b _08019CB6
	.align 2, 0
_08019CA4: .4byte 0x083C4C84
_08019CA8: .4byte 0x0300052E
_08019CAC:
	ldr r0, _08019CD4 @ =0x083C4C78
	ldr r1, _08019CD8 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
_08019CB6:
	ldr r0, _08019CDC @ =0x03002C30
	lsls r1, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r3, [r1, #0xb]
	adds r3, #4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl battle_setup_part_sprite
	b _08019D84
	.align 2, 0
_08019CD4: .4byte 0x083C4C78
_08019CD8: .4byte 0x0300052E
_08019CDC: .4byte 0x03002C30
_08019CE0:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08019D84
	mov r0, ip
	adds r0, #0xde
	ldrb r0, [r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r1, r1, r2
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _08019D14
_08019D02:
	lsls r0, r4, #1
	adds r0, r0, r4
	adds r0, #0x48
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_sprite_table_mask
	b _08019D84
_08019D14:
	ldr r2, _08019D48 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r5, r0, #0
	adds r5, #0x48
	lsls r0, r5, #6
	adds r2, r0, r2
	ldrh r0, [r2]
	adds r3, r1, #0
	cmp r0, #0
	beq _08019D50
	adds r0, r2, #0
	adds r0, #0x23
	mov r1, ip
	adds r1, #0xdf
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08019D50
	ldr r0, _08019D4C @ =0x083B5F80
	ldr r0, [r0, #0x50]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _08019D60
	.align 2, 0
_08019D48: .4byte 0x03002C30
_08019D4C: .4byte 0x083B5F80
_08019D50:
	ldr r0, _08019D8C @ =0x083B5F80
	ldr r0, [r0, #0x50]
	adds r1, r3, r4
	adds r1, #0x48
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08019D60:
	ldr r0, _08019D90 @ =0x083C4CA0
	ldr r1, _08019D94 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	ldr r1, _08019D98 @ =0x03002C30
	lsls r0, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r3, [r0, #0xb]
	adds r3, #4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl battle_setup_part_sprite
_08019D84:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08019D8C: .4byte 0x083B5F80
_08019D90: .4byte 0x083C4CA0
_08019D94: .4byte 0x0300052E
_08019D98: .4byte 0x03002C30
	.syntax divided
