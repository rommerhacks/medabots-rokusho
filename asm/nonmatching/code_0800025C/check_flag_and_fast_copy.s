	.syntax unified

	thumb_func_start check_flag_and_fast_copy
check_flag_and_fast_copy: @ 0x08001520
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08001540 @ =0xFFFFFDC8
	add sp, r4
	ldr r2, _08001544 @ =0x03000438
	ldrb r0, [r2]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _08001548
	movs r0, #0
	strb r0, [r2]
	b _08001C8C
	.align 2, 0
_08001540: .4byte 0xFFFFFDC8
_08001544: .4byte 0x03000438
_08001548:
	add r0, sp, #0x204
	str r1, [r0]
	ldr r2, _080015A8 @ =0x01000040
	add r1, sp, #4
	bl CpuFastSet
	ldr r6, _080015AC @ =0x03002C30
	movs r0, #0
	str r0, [sp, #0x214]
	movs r1, #0
	str r1, [sp, #0x210]
	movs r3, #0x80
	lsls r3, r3, #8
	add r2, sp, #4
_08001564:
	ldrh r1, [r6]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08001580
	add r4, sp, #0x210
	ldrb r4, [r4]
	strb r4, [r2]
	ldrb r0, [r6, #0xb]
	strb r0, [r2, #1]
	adds r2, #4
	ldr r0, [sp, #0x214]
	adds r0, #1
	str r0, [sp, #0x214]
_08001580:
	ldr r1, [sp, #0x210]
	adds r1, #1
	str r1, [sp, #0x210]
	adds r6, #0x40
	cmp r1, #0x7f
	ble _08001564
	ldr r2, _080015B0 @ =0x03000438
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080015B4
	ldr r2, [sp, #0x214]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	add r0, sp, #4
	bl shell_sort_by_second_byte
	b _080015B8
	.align 2, 0
_080015A8: .4byte 0x01000040
_080015AC: .4byte 0x03002C30
_080015B0: .4byte 0x03000438
_080015B4:
	movs r0, #0
	strb r0, [r2]
_080015B8:
	ldr r0, _08001604 @ =0x03000430
	ldr r0, [r0]
	movs r3, #0
	str r3, [sp, #0x220]
	cmp r0, #2
	bne _080015C8
	movs r4, #0x16
	str r4, [sp, #0x220]
_080015C8:
	movs r0, #0
	str r0, [sp, #0x21c]
	movs r1, #0
	str r1, [sp, #0x210]
	ldr r2, [sp, #0x214]
	cmp r1, r2
	blt _080015D8
	b _08001C5C
_080015D8:
	ldr r3, [sp, #0x210]
	lsls r0, r3, #2
	add r0, sp
	adds r0, #4
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r1, _08001608 @ =0x03002C30
	adds r6, r0, r1
	movs r0, #1
	rsbs r0, r0, #0
	ldr r4, _0800160C @ =0x03005048
	str r0, [r4]
	ldrh r0, [r6]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0x80
	beq _08001610
	cmp r1, #0x80
	bgt _080016AE
	cmp r1, #0x40
	beq _08001690
	b _080016AE
	.align 2, 0
_08001604: .4byte 0x03000430
_08001608: .4byte 0x03002C30
_0800160C: .4byte 0x03005048
_08001610:
	ldr r0, [r6, #0xc]
	asrs r0, r0, #8
	lsls r0, r0, #2
	mov sl, r0
	ldr r1, [r6, #0x10]
	asrs r1, r1, #8
	ldr r0, _0800167C @ =0x03005044
	ldr r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #2
	mov sb, r1
	ldr r0, [r6, #0x14]
	asrs r1, r0, #8
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r0, r1, r2
	cmp r0, #0
	bge _08001638
	ldr r3, _08001680 @ =0x0000303F
	adds r0, r1, r3
_08001638:
	asrs r7, r0, #6
	mov r0, sl
	adds r1, r7, #0
	bl sub_0807CBBC
	mov sl, r0
	mov r0, sb
	adds r1, r7, #0
	bl sub_0807CBBC
	mov sb, r0
	ldr r0, _08001684 @ =0x03005040
	ldr r0, [r0]
	add r0, sl
	strh r0, [r6, #2]
	ldr r0, _08001688 @ =0x0300504C
	ldr r0, [r0]
	add r0, sb
	strh r0, [r6, #4]
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r7, #0
	bl sub_0807CBBC
	strb r0, [r6, #9]
	strb r0, [r6, #8]
	movs r0, #0xe0
	lsls r0, r0, #0xf
	adds r1, r7, #0
	bl sub_0807CBBC
	ldr r4, _0800168C @ =0x03005048
	str r0, [r4]
	b _080016AE
	.align 2, 0
_0800167C: .4byte 0x03005044
_08001680: .4byte 0x0000303F
_08001684: .4byte 0x03005040
_08001688: .4byte 0x0300504C
_0800168C: .4byte 0x03005048
_08001690:
	movs r0, #0xe
	ldrsh r1, [r6, r0]
	ldr r2, _080016C8 @ =0x03002C24
	ldrh r0, [r2]
	subs r1, r1, r0
	strh r1, [r6, #2]
	ldr r1, [r6, #0x10]
	asrs r1, r1, #8
	ldr r0, [r6, #0x14]
	asrs r0, r0, #8
	adds r1, r1, r0
	asrs r1, r1, #8
	ldrh r0, [r2, #2]
	subs r1, r1, r0
	strh r1, [r6, #4]
_080016AE:
	ldrb r0, [r6, #0x1c]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #1
	beq _080016CC
	cmp r1, #1
	ble _080016E4
	cmp r1, #2
	beq _080016D4
	cmp r1, #3
	beq _080016DC
	b _080016E4
	.align 2, 0
_080016C8: .4byte 0x03002C24
_080016CC:
	ldr r2, _080016D0 @ =0x083AC088
	b _080016E6
	.align 2, 0
_080016D0: .4byte gUnk_083AC088
_080016D4:
	ldr r2, _080016D8 @ =0x083AC0C8
	b _080016E6
	.align 2, 0
_080016D8: .4byte gUnk_083AC0C8
_080016DC:
	ldr r2, _080016E0 @ =0x083AC108
	b _080016E6
	.align 2, 0
_080016E0: .4byte gUnk_083AC108
_080016E4:
	ldr r2, _08001760 @ =0x083ABE30
_080016E6:
	ldrh r1, [r6, #6]
	lsrs r0, r1, #8
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp, #0x22c]
	adds r4, r1, #0
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #2
	ldr r1, [sp, #0x22c]
	adds r0, r0, r1
	ldr r0, [r0]
	adds r5, r0, #4
	ldr r3, _08001764 @ =0x03002C2C
	movs r0, #0
	ldrsh r2, [r3, r0]
	mov r8, r2
	ldr r2, _08001768 @ =0x03001794
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, r8
	subs r1, r0, r1
	mov sb, r1
	movs r1, #2
	ldrsh r0, [r6, r1]
	mov r8, r0
	mov r0, sb
	add r0, r8
	mov sl, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r0, r0, r1
	mov sb, r0
	ldrh r2, [r6]
	movs r0, #0xc0
	ands r0, r2
	cmp r0, #0x40
	bne _08001774
	mov r1, sb
	adds r1, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bhi _08001756
	mov r1, sl
	adds r1, #0x20
	movs r0, #0xa8
	lsls r0, r0, #1
	cmp r1, r0
	bls _0800176C
_08001756:
	movs r0, #2
	orrs r0, r2
	strh r0, [r6]
	b _08001C4E
	.align 2, 0
_08001760: .4byte gUnk_083ABE30
_08001764: .4byte 0x03002C2C
_08001768: .4byte 0x03001794
_0800176C:
	ldr r3, _080017B8 @ =0x0000FFFD
	adds r0, r3, #0
	ands r0, r2
	strh r0, [r6]
_08001774:
	ldrh r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08001784
	b _08001C4E
_08001784:
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08001808
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0xc0
	beq _080017EE
	ldr r0, [sp, #0x220]
	cmp r0, #0x1f
	bgt _08001810
	ldrh r0, [r6, #0x18]
	cmp r0, #0
	beq _080017BC
	adds r1, r0, #0
	ldrb r2, [r6, #8]
	ldrb r3, [r6, #9]
	ldrh r0, [r6]
	str r0, [sp]
	ldr r0, [sp, #0x220]
	bl set_oam_affine_params
	b _080017C8
	.align 2, 0
_080017B8: .4byte 0x0000FFFD
_080017BC:
	ldrb r1, [r6, #8]
	ldrb r2, [r6, #9]
	ldrh r3, [r6]
	ldr r0, [sp, #0x220]
	bl compute_scaled_value
_080017C8:
	ldrh r1, [r6]
	movs r0, #0x20
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp, #0x224]
	cmp r0, #0
	beq _080017DE
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [sp, #0x224]
_080017DE:
	ldr r3, [sp, #0x220]
	lsls r3, r3, #9
	str r3, [sp, #0x228]
	ldr r4, [sp, #0x220]
	adds r4, #1
	str r4, [sp, #0x220]
	ldrh r4, [r6, #6]
	b _08001810
_080017EE:
	movs r0, #0x20
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp, #0x224]
	cmp r0, #0
	beq _08001802
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [sp, #0x224]
_08001802:
	ldrb r0, [r6, #0x1d]
	lsls r0, r0, #9
	b _0800180E
_08001808:
	movs r3, #0
	str r3, [sp, #0x224]
	movs r0, #0
_0800180E:
	str r0, [sp, #0x228]
_08001810:
	movs r1, #0
	str r1, [sp, #0x218]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #2
	ldr r2, [sp, #0x22c]
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r1, r0
	blt _08001828
	b _08001C48
_08001828:
	ldr r0, _08001864 @ =0x03001380
	ldr r3, [sp, #0x21c]
	lsls r3, r3, #3
	str r3, [sp, #0x234]
	adds r3, r3, r0
	mov r8, r3
	movs r4, #0x82
	lsls r4, r4, #2
	add r4, sp
	str r4, [sp, #0x230]
_0800183C:
	ldrh r1, [r5]
	ldr r2, _08001868 @ =0x0000C0C0
	adds r0, r2, #0
	adds r4, r0, #0
	ands r4, r1
	movs r0, #0x81
	lsls r0, r0, #7
	cmp r4, r0
	beq _080018B4
	cmp r4, r0
	bgt _08001878
	cmp r4, #0x80
	beq _080018B4
	cmp r4, #0x80
	bgt _0800186C
	cmp r4, #0
	beq _080018B4
	cmp r4, #0x40
	beq _080018B8
	b _080018C2
	.align 2, 0
_08001864: .4byte 0x03001380
_08001868: .4byte 0x0000C0C0
_0800186C:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r4, r0
	beq _080018B8
	adds r0, #0x40
	b _080018AA
_08001878:
	ldr r0, _0800188C @ =0x00008080
	cmp r4, r0
	beq _080018B8
	cmp r4, r0
	bgt _08001890
	subs r0, #0x80
	cmp r4, r0
	beq _080018BC
	adds r0, #0x40
	b _080018AA
	.align 2, 0
_0800188C: .4byte 0x00008080
_08001890:
	ldr r0, _080018A4 @ =0x0000C040
	cmp r4, r0
	beq _080018C0
	cmp r4, r0
	bgt _080018A8
	subs r0, #0x40
	cmp r4, r0
	beq _080018C0
	b _080018C2
	.align 2, 0
_080018A4: .4byte 0x0000C040
_080018A8:
	ldr r0, _080018B0 @ =0x0000C080
_080018AA:
	cmp r4, r0
	beq _080018BC
	b _080018C2
	.align 2, 0
_080018B0: .4byte 0x0000C080
_080018B4:
	movs r7, #4
	b _080018C2
_080018B8:
	movs r7, #8
	b _080018C2
_080018BC:
	movs r7, #0x10
	b _080018C2
_080018C0:
	movs r7, #0x20
_080018C2:
	movs r0, #0x81
	lsls r0, r0, #7
	cmp r4, r0
	beq _08001934
	cmp r4, r0
	bgt _080018F0
	cmp r4, #0x80
	beq _08001930
	cmp r4, #0x80
	bgt _080018E0
	cmp r4, #0
	beq _0800192C
	cmp r4, #0x40
	beq _0800192C
	b _0800193A
_080018E0:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r4, r0
	beq _08001930
	adds r0, #0x40
	cmp r4, r0
	beq _0800192C
	b _0800193A
_080018F0:
	ldr r0, _08001908 @ =0x00008080
	cmp r4, r0
	beq _08001934
	cmp r4, r0
	bgt _0800190C
	subs r0, #0x80
	cmp r4, r0
	beq _08001934
	adds r0, #0x40
	cmp r4, r0
	beq _08001930
	b _0800193A
	.align 2, 0
_08001908: .4byte 0x00008080
_0800190C:
	ldr r0, _0800191C @ =0x0000C040
	cmp r4, r0
	beq _08001934
	cmp r4, r0
	bgt _08001920
	subs r0, #0x40
	b _08001922
	.align 2, 0
_0800191C: .4byte 0x0000C040
_08001920:
	ldr r0, _08001928 @ =0x0000C080
_08001922:
	cmp r4, r0
	beq _08001938
	b _0800193A
	.align 2, 0
_08001928: .4byte 0x0000C080
_0800192C:
	movs r4, #4
	b _0800193A
_08001930:
	movs r4, #8
	b _0800193A
_08001934:
	movs r4, #0x10
	b _0800193A
_08001938:
	movs r4, #0x20
_0800193A:
	ldrh r0, [r6]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	ands r1, r0
	adds r2, r0, #0
	cmp r1, #0
	bne _0800194C
	b _08001B18
_0800194C:
	movs r0, #0xc0
	ands r0, r2
	cmp r0, #0xc0
	bne _08001956
	b _08001A70
_08001956:
	movs r1, #4
	ldrsh r0, [r5, r1]
	adds r0, r0, r7
	ldr r2, [sp, #0x230]
	str r0, [r2]
	movs r3, #6
	ldrsh r0, [r5, r3]
	adds r0, r0, r4
	add r1, sp, #0x20c
	str r0, [r1]
	ldrh r1, [r6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800197E
	rsbs r0, r7, #0
	lsls r7, r0, #1
	rsbs r0, r4, #0
	lsls r4, r0, #1
	b _08001982
_0800197E:
	rsbs r7, r7, #0
	rsbs r4, r4, #0
_08001982:
	ldrh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080019AC
	ldr r3, [sp, #0x230]
	ldr r1, [r3]
	rsbs r2, r1, #0
	ldrb r0, [r6, #8]
	subs r0, #0x40
	muls r0, r1, r0
	cmp r0, #0
	bge _080019A2
	adds r0, #0x3f
_080019A2:
	asrs r0, r0, #6
	subs r0, r2, r0
	ldr r1, [sp, #0x230]
	str r0, [r1]
	b _080019C4
_080019AC:
	ldrb r0, [r6, #8]
	subs r0, #0x40
	ldr r2, [sp, #0x230]
	ldr r1, [r2]
	muls r0, r1, r0
	cmp r0, #0
	bge _080019BC
	adds r0, #0x3f
_080019BC:
	asrs r0, r0, #6
	adds r0, r1, r0
	ldr r3, [sp, #0x230]
	str r0, [r3]
_080019C4:
	ldrh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080019EA
	add r2, sp, #0x20c
	ldr r1, [r2]
	rsbs r3, r1, #0
	ldrb r0, [r6, #9]
	subs r0, #0x40
	muls r0, r1, r0
	cmp r0, #0
	bge _080019E4
	adds r0, #0x3f
_080019E4:
	asrs r0, r0, #6
	subs r0, r3, r0
	b _080019FE
_080019EA:
	ldrb r0, [r6, #9]
	subs r0, #0x40
	add r2, sp, #0x20c
	ldr r1, [r2]
	muls r0, r1, r0
	cmp r0, #0
	bge _080019FA
	adds r0, #0x3f
_080019FA:
	asrs r0, r0, #6
	adds r0, r1, r0
_080019FE:
	str r0, [r2]
	ldrh r0, [r6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08001A18
	add r0, sp, #0x208
	add r1, sp, #0x20c
	adds r2, r6, #0
	bl rotate_vector_2d
_08001A18:
	mov r0, sl
	adds r1, r7, r0
	ldr r2, [sp, #0x230]
	ldr r0, [r2]
	adds r7, r1, r0
	mov r3, sb
	adds r1, r4, r3
	add r0, sp, #0x20c
	ldr r0, [r0]
	adds r4, r1, r0
	movs r0, #0xff
	ands r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #8
	orrs r4, r0
	ldr r0, [sp, #0x224]
	orrs r4, r0
	ldrh r1, [r6]
	movs r0, #0x18
	ands r0, r1
	lsls r0, r0, #7
	orrs r4, r0
	movs r0, #1
	ands r0, r1
	lsls r0, r0, #0xc
	orrs r4, r0
	mov r1, r8
	strh r4, [r1]
	ldr r2, _08001A6C @ =0x000001FF
	adds r0, r2, #0
	adds r1, r7, #0
	ands r1, r0
	ldrb r2, [r5, #1]
	movs r0, #0xc0
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldr r3, [sp, #0x228]
	orrs r1, r3
	mov r4, r8
	strh r1, [r4, #2]
	b _08001B9E
	.align 2, 0
_08001A6C: .4byte 0x000001FF
_08001A70:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08001A82
	movs r0, #4
	ldrsh r7, [r5, r0]
	movs r1, #6
	ldrsh r4, [r5, r1]
	b _08001A86
_08001A82:
	movs r7, #0
	movs r4, #0
_08001A86:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _08001AA0
	movs r1, #4
	ldrsh r0, [r5, r1]
	rsbs r0, r0, #0
	subs r0, r0, r7
	add r0, sl
	subs r7, r0, r7
	b _08001AA8
_08001AA0:
	movs r3, #4
	ldrsh r0, [r5, r3]
	add r0, sl
	adds r7, r7, r0
_08001AA8:
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08001AC2
	movs r2, #6
	ldrsh r0, [r5, r2]
	rsbs r0, r0, #0
	subs r0, r0, r4
	add r0, sb
	subs r4, r0, r4
	b _08001ACA
_08001AC2:
	movs r3, #6
	ldrsh r0, [r5, r3]
	add r0, sb
	adds r4, r4, r0
_08001ACA:
	movs r0, #0xff
	ands r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #8
	orrs r4, r0
	ldr r0, [sp, #0x224]
	orrs r4, r0
	ldrh r1, [r6]
	movs r0, #0x18
	ands r0, r1
	lsls r0, r0, #7
	orrs r4, r0
	movs r0, #1
	ands r0, r1
	lsls r0, r0, #0xc
	orrs r4, r0
	mov r1, r8
	strh r4, [r1]
	ldr r2, _08001B14 @ =0x000001FF
	adds r0, r2, #0
	adds r1, r7, #0
	ands r1, r0
	ldrb r0, [r5, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldr r3, [sp, #0x228]
	orrs r1, r3
	ldrh r0, [r6]
	movs r4, #0xc0
	lsls r4, r4, #6
	adds r2, r4, #0
	ands r0, r2
	eors r1, r0
	mov r0, r8
	strh r1, [r0, #2]
	b _08001B9E
	.align 2, 0
_08001B14: .4byte 0x000001FF
_08001B18:
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08001B32
	movs r3, #4
	ldrsh r0, [r5, r3]
	rsbs r0, r0, #0
	subs r0, r0, r7
	add r0, sl
	subs r7, r0, r7
	b _08001B3A
_08001B32:
	movs r1, #4
	ldrsh r0, [r5, r1]
	mov r3, sl
	adds r7, r3, r0
_08001B3A:
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08001B54
	movs r2, #6
	ldrsh r0, [r5, r2]
	rsbs r0, r0, #0
	subs r0, r0, r4
	add r0, sb
	subs r4, r0, r4
	b _08001B5C
_08001B54:
	movs r3, #6
	ldrsh r0, [r5, r3]
	mov r1, sb
	adds r4, r1, r0
_08001B5C:
	movs r0, #0xff
	ands r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #8
	orrs r4, r0
	ldr r2, [sp, #0x224]
	orrs r4, r2
	ldrh r1, [r6]
	movs r0, #0x18
	ands r0, r1
	lsls r0, r0, #7
	orrs r4, r0
	movs r0, #1
	ands r0, r1
	lsls r0, r0, #0xc
	orrs r4, r0
	mov r3, r8
	strh r4, [r3]
	ldr r4, _08001BCC @ =0x000001FF
	adds r0, r4, #0
	adds r2, r7, #0
	ands r2, r0
	ldrb r0, [r5, #1]
	lsls r0, r0, #8
	orrs r2, r0
	ldrh r0, [r6]
	movs r3, #0xc0
	lsls r3, r3, #6
	adds r1, r3, #0
	ands r0, r1
	eors r2, r0
	mov r4, r8
	strh r2, [r4, #2]
_08001B9E:
	ldrh r4, [r6]
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _08001C00
	ldrh r3, [r5, #2]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08001BD4
	ldr r1, _08001BD0 @ =0x03001384
	ldr r2, [sp, #0x234]
	adds r1, r2, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r2, #0
	ands r0, r4
	orrs r0, r3
	strh r0, [r1]
	b _08001C1A
	.align 2, 0
_08001BCC: .4byte 0x000001FF
_08001BD0: .4byte 0x03001384
_08001BD4:
	ldr r2, _08001BF8 @ =0x03001384
	ldr r0, [sp, #0x234]
	adds r2, r0, r2
	ldr r1, _08001BFC @ =0x00000FFF
	adds r0, r1, #0
	adds r1, r3, #0
	ands r1, r0
	ldrb r0, [r6, #0xa]
	lsls r0, r0, #0xc
	orrs r1, r0
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r3, #0
	ands r0, r4
	orrs r1, r0
	strh r1, [r2]
	b _08001C1A
	.align 2, 0
_08001BF8: .4byte 0x03001384
_08001BFC: .4byte 0x00000FFF
_08001C00:
	ldr r2, _08001CA0 @ =0x03001384
	ldr r0, [sp, #0x234]
	adds r2, r0, r2
	ldrb r0, [r6, #0xa]
	lsls r0, r0, #0xc
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r1, r3, #0
	ands r1, r4
	orrs r0, r1
	strh r0, [r2]
_08001C1A:
	ldr r4, [sp, #0x234]
	adds r4, #8
	str r4, [sp, #0x234]
	movs r0, #8
	add r8, r0
	ldr r1, [sp, #0x21c]
	adds r1, #1
	str r1, [sp, #0x21c]
	adds r5, #8
	cmp r1, #0x7f
	bgt _08001C5C
	ldr r2, [sp, #0x218]
	adds r2, #1
	str r2, [sp, #0x218]
	ldrb r0, [r6, #6]
	lsls r0, r0, #2
	ldr r3, [sp, #0x22c]
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r2, r0
	bge _08001C48
	b _0800183C
_08001C48:
	ldr r4, [sp, #0x21c]
	cmp r4, #0x7f
	bgt _08001C5C
_08001C4E:
	ldr r0, [sp, #0x210]
	adds r0, #1
	str r0, [sp, #0x210]
	ldr r1, [sp, #0x214]
	cmp r0, r1
	bge _08001C5C
	b _080015D8
_08001C5C:
	ldr r2, [sp, #0x21c]
	str r2, [sp, #0x210]
	ldr r3, _08001CA4 @ =0x03000440
	cmp r2, #0x7f
	bgt _08001C82
	ldr r1, _08001CA8 @ =0x03001380
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r4, #0
	ldr r4, [sp, #0x210]
	lsls r0, r4, #3
	adds r0, r0, r1
_08001C74:
	strh r2, [r0]
	adds r0, #8
	ldr r1, [sp, #0x210]
	adds r1, #1
	str r1, [sp, #0x210]
	cmp r1, #0x7f
	ble _08001C74
_08001C82:
	movs r2, #0x97
	lsls r2, r2, #1
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
_08001C8C:
	movs r3, #0x8e
	lsls r3, r3, #2
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001CA0: .4byte 0x03001384
_08001CA4: .4byte 0x03000440
_08001CA8: .4byte 0x03001380
	.syntax divided
