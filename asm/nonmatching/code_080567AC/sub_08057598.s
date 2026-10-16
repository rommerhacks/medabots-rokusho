	.syntax unified

	thumb_func_start sub_08057598
sub_08057598: @ 0x08057598
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x1c
	bl sub_0804B1FC
	ldr r0, _080576F8 @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	mov sl, r1
	bl sub_080496C8
	ldr r0, _080576FC @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r2, #0
	mov sb, r2
	str r2, [sp, #0x18]
	ldr r4, _08057700 @ =0x040000D4
	add r0, sp, #0x18
	str r0, [r4]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08057704 @ =0x85000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xfa
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08057708 @ =0x030057E0
	ldr r1, _0805770C @ =0x00000CBA
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bl update_battle_field_frame
	ldr r0, _08057710 @ =0x084C1C14
	ldr r1, _08057714 @ =0x060017E0
	bl lz_decompress_dispatch
	ldr r0, _08057718 @ =0x084C1608
	ldr r1, _0805771C @ =0x06001800
	bl lz_decompress_dispatch
	ldr r0, _08057720 @ =0x084C17F0
	ldr r1, _08057724 @ =0x06001B00
	bl lz_decompress_dispatch
	ldr r0, _08057728 @ =0x084C1934
	ldr r1, _0805772C @ =0x06001E00
	bl lz_decompress_dispatch
	ldr r0, _08057730 @ =0x084C1ACC
	ldr r6, _08057734 @ =0x06002100
	adds r1, r6, #0
	bl lz_decompress_dispatch
	ldr r0, _08057738 @ =0x08487708
	ldr r1, _0805773C @ =0x06002400
	bl lz_decompress_dispatch
	ldr r0, _08057740 @ =0x08488A84
	str r0, [r4]
	ldr r0, _08057744 @ =0x0202FBE0
	str r0, [r4, #4]
	ldr r5, _08057748 @ =0x84000008
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0805774C @ =0x084C6A98
	ldr r1, _08057750 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r0, _08057754 @ =0x084E2E38
	str r0, [r4]
	ldr r0, _08057758 @ =0x0202F9E0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0805775C @ =0x085FA144
	ldr r1, _08057760 @ =0x06000F80
	bl LZ77UnCompVram
	ldr r0, _08057764 @ =0x085FA5D8
	adds r1, r6, #0
	bl LZ77UnCompVram
	ldr r2, _08057768 @ =0x03006D14
	mov r8, r2
	ldr r0, [r2]
	mov r1, sl
	bl sub_080496C8
	ldr r0, _0805776C @ =0x085FA4D8
	str r0, [r4]
	mov r0, r8
	ldr r1, [r0]
	str r1, [r4, #4]
	ldr r0, _08057770 @ =0x80000070
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08057774 @ =0x085FA620
	str r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	str r0, [r4, #4]
	ldr r0, _08057778 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0805777C @ =0x083D5F30
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r1, r4
	movs r2, #0x10
	str r2, [sp]
	movs r6, #0xa
	str r6, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	movs r5, #0xf
	str r5, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl copy_tilemap_region
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r6, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r5, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #2
	movs r2, #0xe
	movs r3, #0x10
	bl fill_tilemap_rect_0804916C
	mov r2, r8
	ldr r0, [r2]
	adds r4, r0, r4
	movs r2, #0xe
	str r2, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #0x7c
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	mov r1, sb
	str r1, [sp, #0x10]
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl copy_tilemap_region
	movs r0, #0
	bl check_vehicle_usability
	cmp r0, #0
	beq _08057784
	cmp r0, #1
	beq _08057798
	ldr r0, _08057780 @ =0x085FA87C
	b _08057786
	.align 2, 0
_080576F8: .4byte 0x03002C30
_080576FC: .4byte 0x030055A0
_08057700: .4byte 0x040000D4
_08057704: .4byte 0x85000100
_08057708: .4byte 0x030057E0
_0805770C: .4byte 0x00000CBA
_08057710: .4byte 0x084C1C14
_08057714: .4byte 0x060017E0
_08057718: .4byte 0x084C1608
_0805771C: .4byte 0x06001800
_08057720: .4byte 0x084C17F0
_08057724: .4byte 0x06001B00
_08057728: .4byte 0x084C1934
_0805772C: .4byte 0x06001E00
_08057730: .4byte 0x084C1ACC
_08057734: .4byte 0x06002100
_08057738: .4byte 0x08487708
_0805773C: .4byte 0x06002400
_08057740: .4byte 0x08488A84
_08057744: .4byte 0x0202FBE0
_08057748: .4byte 0x84000008
_0805774C: .4byte 0x084C6A98
_08057750: .4byte 0x06017400
_08057754: .4byte 0x084E2E38
_08057758: .4byte 0x0202F9E0
_0805775C: .4byte 0x085FA144
_08057760: .4byte 0x06000F80
_08057764: .4byte 0x085FA5D8
_08057768: .4byte 0x03006D14
_0805776C: .4byte 0x085FA4D8
_08057770: .4byte 0x80000070
_08057774: .4byte 0x085FA620
_08057778: .4byte 0x80000010
_0805777C: .4byte 0x083D5F30
_08057780: .4byte 0x085FA87C
_08057784:
	ldr r0, _08057790 @ =0x085FA660
_08057786:
	ldr r1, _08057794 @ =0x06016F80
	bl LZ77UnCompVram
	b _080577A6
	.align 2, 0
_08057790: .4byte 0x085FA660
_08057794: .4byte 0x06016F80
_08057798:
	ldr r0, _080577B8 @ =0x085FAA98
	ldr r1, _080577BC @ =0x06016F80
	bl LZ77UnCompVram
	movs r0, #0
	bl render_npc_tilemap_row
_080577A6:
	movs r0, #1
	bl check_vehicle_usability
	cmp r0, #0
	beq _080577C4
	cmp r0, #1
	beq _080577D8
	ldr r0, _080577C0 @ =0x085FA904
	b _080577C6
	.align 2, 0
_080577B8: .4byte 0x085FAA98
_080577BC: .4byte 0x06016F80
_080577C0: .4byte 0x085FA904
_080577C4:
	ldr r0, _080577D0 @ =0x085FA6E8
_080577C6:
	ldr r1, _080577D4 @ =0x06017000
	bl LZ77UnCompVram
	b _080577E6
	.align 2, 0
_080577D0: .4byte 0x085FA6E8
_080577D4: .4byte 0x06017000
_080577D8:
	ldr r0, _080577F8 @ =0x085FAA98
	ldr r1, _080577FC @ =0x06017000
	bl LZ77UnCompVram
	movs r0, #1
	bl render_npc_tilemap_row
_080577E6:
	movs r0, #2
	bl check_vehicle_usability
	cmp r0, #0
	beq _08057804
	cmp r0, #1
	beq _08057818
	ldr r0, _08057800 @ =0x085FA990
	b _08057806
	.align 2, 0
_080577F8: .4byte 0x085FAA98
_080577FC: .4byte 0x06017000
_08057800: .4byte 0x085FA990
_08057804:
	ldr r0, _08057810 @ =0x085FA774
_08057806:
	ldr r1, _08057814 @ =0x06017080
	bl LZ77UnCompVram
	b _08057826
	.align 2, 0
_08057810: .4byte 0x085FA774
_08057814: .4byte 0x06017080
_08057818:
	ldr r0, _08057838 @ =0x085FAA98
	ldr r1, _0805783C @ =0x06017080
	bl LZ77UnCompVram
	movs r0, #2
	bl render_npc_tilemap_row
_08057826:
	movs r0, #3
	bl check_vehicle_usability
	cmp r0, #0
	beq _08057844
	cmp r0, #1
	beq _08057858
	ldr r0, _08057840 @ =0x085FAA18
	b _08057846
	.align 2, 0
_08057838: .4byte 0x085FAA98
_0805783C: .4byte 0x06017080
_08057840: .4byte 0x085FAA18
_08057844:
	ldr r0, _08057850 @ =0x085FA7FC
_08057846:
	ldr r1, _08057854 @ =0x06017100
	bl LZ77UnCompVram
	b _08057866
	.align 2, 0
_08057850: .4byte 0x085FA7FC
_08057854: .4byte 0x06017100
_08057858:
	ldr r0, _08057914 @ =0x085FAA98
	ldr r1, _08057918 @ =0x06017100
	bl LZ77UnCompVram
	movs r0, #3
	bl render_npc_tilemap_row
_08057866:
	ldr r0, _0805791C @ =0x084873D0
	ldr r1, _08057920 @ =0x06000020
	bl lz_decompress_dispatch
	ldr r0, _08057924 @ =0x084C31BC
	ldr r1, _08057928 @ =0x06001780
	bl lz_decompress_dispatch
	ldr r4, _0805792C @ =0x040000D4
	ldr r0, _08057930 @ =0x08488A84
	str r0, [r4]
	ldr r0, _08057934 @ =0x0202FBE0
	str r0, [r4, #4]
	ldr r5, _08057938 @ =0x84000008
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0805793C @ =0x084C6998
	str r0, [r4]
	ldr r0, _08057940 @ =0x0202FBC0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08057944 @ =0x084878EC
	ldr r1, _08057948 @ =0x06002600
	bl lz_decompress_dispatch
	ldr r0, _0805794C @ =0x0848796C
	ldr r1, _08057950 @ =0x060026E0
	bl lz_decompress_dispatch
	ldr r0, _08057954 @ =0x084C7318
	ldr r1, _08057958 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r0, _0805795C @ =0x084E2E58
	str r0, [r4]
	ldr r0, _08057960 @ =0x0202F9C0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08057964 @ =0x03006512
	ldr r1, _08057968 @ =0x06002800
	movs r2, #0x1e
	str r2, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r2, #0x20
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #0
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r3, #0
	bl copy_tilemap_rect_with_offset
	ldr r0, _0805796C @ =0x085FA640
	str r0, [r4]
	ldr r0, _08057970 @ =0x0202F980
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08057974 @ =0x085FA85C
	str r0, [r4]
	ldr r0, _08057978 @ =0x0202F9A0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #0
	bl init_vehicle_menu_sprite
	ldr r1, _0805797C @ =0x42000000
	ldr r2, _08057980 @ =0x00000000
	ldr r3, _08057984 @ =0x41000000
	movs r0, #0
	bl setup_palette_fade_to_color
	bl sub_0804A1C4
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08057914: .4byte 0x085FAA98
_08057918: .4byte 0x06017100
_0805791C: .4byte 0x084873D0
_08057920: .4byte 0x06000020
_08057924: .4byte 0x084C31BC
_08057928: .4byte 0x06001780
_0805792C: .4byte 0x040000D4
_08057930: .4byte 0x08488A84
_08057934: .4byte 0x0202FBE0
_08057938: .4byte 0x84000008
_0805793C: .4byte 0x084C6998
_08057940: .4byte 0x0202FBC0
_08057944: .4byte 0x084878EC
_08057948: .4byte 0x06002600
_0805794C: .4byte 0x0848796C
_08057950: .4byte 0x060026E0
_08057954: .4byte 0x084C7318
_08057958: .4byte 0x06017E00
_0805795C: .4byte 0x084E2E58
_08057960: .4byte 0x0202F9C0
_08057964: .4byte 0x03006512
_08057968: .4byte 0x06002800
_0805796C: .4byte 0x085FA640
_08057970: .4byte 0x0202F980
_08057974: .4byte 0x085FA85C
_08057978: .4byte 0x0202F9A0
_0805797C: .4byte 0x42000000
_08057980: .4byte 0x00000000
_08057984: .4byte 0x41000000
	.syntax divided
