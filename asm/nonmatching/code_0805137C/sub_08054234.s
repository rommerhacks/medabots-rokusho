	.syntax unified

	thumb_func_start sub_08054234
sub_08054234: @ 0x08054234
	adds r1, r5, #0
	adds r1, #0xf4
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r0, [r0]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	cmp r0, #0x8a
	bls _0805424E
	bl _080566A8
_0805424E:
	lsls r0, r0, #2
	ldr r1, _08054260 @ =_08054264
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08054258: .4byte 0x03005350
_0805425C: .4byte 0x083D5D84
_08054260: .4byte _08054264
_08054264: @ jump table
	.4byte _080566B6 @ case 0
	.4byte _08054490 @ case 1
	.4byte _08054558 @ case 2
	.4byte _0805501C @ case 3
	.4byte _080566B6 @ case 4
	.4byte _08055074 @ case 5
	.4byte _08055088 @ case 6
	.4byte _0805510C @ case 7
	.4byte _08055190 @ case 8
	.4byte _08055228 @ case 9
	.4byte _08055254 @ case 10
	.4byte _08055284 @ case 11
	.4byte _08055310 @ case 12
	.4byte _0805539C @ case 13
	.4byte _080553CC @ case 14
	.4byte _080553FC @ case 15
	.4byte _08055440 @ case 16
	.4byte _08055440 @ case 17
	.4byte _08055440 @ case 18
	.4byte _08055654 @ case 19
	.4byte _080556CC @ case 20
	.4byte _08055754 @ case 21
	.4byte _08055804 @ case 22
	.4byte _080554C8 @ case 23
	.4byte _0805554C @ case 24
	.4byte _080555D0 @ case 25
	.4byte _080558C4 @ case 26
	.4byte _08055958 @ case 27
	.4byte _08055B88 @ case 28
	.4byte _08055BF0 @ case 29
	.4byte _08055C60 @ case 30
	.4byte _08055CC8 @ case 31
	.4byte _08055D1C @ case 32
	.4byte _08055D74 @ case 33
	.4byte _08055DCC @ case 34
	.4byte _08055E38 @ case 35
	.4byte _08055E84 @ case 36
	.4byte _080566B6 @ case 37
	.4byte _080566A8 @ case 38
	.4byte _080566A8 @ case 39
	.4byte _080566A8 @ case 40
	.4byte _080566A8 @ case 41
	.4byte _080566A8 @ case 42
	.4byte _080566A8 @ case 43
	.4byte _080566A8 @ case 44
	.4byte _080566A8 @ case 45
	.4byte _080566A8 @ case 46
	.4byte _080566A8 @ case 47
	.4byte _080566A8 @ case 48
	.4byte _080566A8 @ case 49
	.4byte _080566A8 @ case 50
	.4byte _080566A8 @ case 51
	.4byte _080566A8 @ case 52
	.4byte _080566A8 @ case 53
	.4byte _080566A8 @ case 54
	.4byte _080566A8 @ case 55
	.4byte _080566A8 @ case 56
	.4byte _080566A8 @ case 57
	.4byte _080566A8 @ case 58
	.4byte _080566A8 @ case 59
	.4byte _080566A8 @ case 60
	.4byte _080566A8 @ case 61
	.4byte _080566A8 @ case 62
	.4byte _080566A8 @ case 63
	.4byte _080566A8 @ case 64
	.4byte _080566A8 @ case 65
	.4byte _080566A8 @ case 66
	.4byte _080566A8 @ case 67
	.4byte _080566A8 @ case 68
	.4byte _080566A8 @ case 69
	.4byte _080566A8 @ case 70
	.4byte _080566A8 @ case 71
	.4byte _080566A8 @ case 72
	.4byte _080566A8 @ case 73
	.4byte _080566A8 @ case 74
	.4byte _080566A8 @ case 75
	.4byte _080566A8 @ case 76
	.4byte _080566A8 @ case 77
	.4byte _080566A8 @ case 78
	.4byte _080566A8 @ case 79
	.4byte _080566A8 @ case 80
	.4byte _080566A8 @ case 81
	.4byte _080566A8 @ case 82
	.4byte _080566A8 @ case 83
	.4byte _080566A8 @ case 84
	.4byte _080566A8 @ case 85
	.4byte _080566A8 @ case 86
	.4byte _080566A8 @ case 87
	.4byte _080566A8 @ case 88
	.4byte _080566A8 @ case 89
	.4byte _080566A8 @ case 90
	.4byte _080566A8 @ case 91
	.4byte _080566A8 @ case 92
	.4byte _080566A8 @ case 93
	.4byte _080566A8 @ case 94
	.4byte _080566A8 @ case 95
	.4byte _080566A8 @ case 96
	.4byte _080566A8 @ case 97
	.4byte _080566A8 @ case 98
	.4byte _080566A8 @ case 99
	.4byte _080566A8 @ case 100
	.4byte _080566A8 @ case 101
	.4byte _080566A8 @ case 102
	.4byte _080566A8 @ case 103
	.4byte _080566A8 @ case 104
	.4byte _080566A8 @ case 105
	.4byte _080566A8 @ case 106
	.4byte _080566A8 @ case 107
	.4byte _080566A8 @ case 108
	.4byte _080566A8 @ case 109
	.4byte _080566A8 @ case 110
	.4byte _080566A8 @ case 111
	.4byte _080566A8 @ case 112
	.4byte _080566A8 @ case 113
	.4byte _080566A8 @ case 114
	.4byte _080566A8 @ case 115
	.4byte _080566A8 @ case 116
	.4byte _080566A8 @ case 117
	.4byte _080566A8 @ case 118
	.4byte _080566A8 @ case 119
	.4byte _080566A8 @ case 120
	.4byte _080566A8 @ case 121
	.4byte _080566A8 @ case 122
	.4byte _080566A8 @ case 123
	.4byte _080566A8 @ case 124
	.4byte _080566A8 @ case 125
	.4byte _080566A8 @ case 126
	.4byte _080566A8 @ case 127
	.4byte _08055FB4 @ case 128
	.4byte _08056024 @ case 129
	.4byte _08056094 @ case 130
	.4byte _08056178 @ case 131
	.4byte _080562C4 @ case 132
	.4byte _0805648C @ case 133
	.4byte _08055ADC @ case 134
	.4byte _080564D8 @ case 135
	.4byte _08056678 @ case 136
	.4byte _08056534 @ case 137
	.4byte _080565F8 @ case 138
_08054490:
	ldr r7, _0805454C @ =0x03005350
	adds r6, r7, #0
	adds r6, #0xfc
	ldr r4, [r6]
	adds r4, #1
	str r4, [r6]
	adds r1, r7, #0
	adds r1, #0x9c
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	adds r1, #4
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	adds r5, r7, #0
	adds r5, #0x90
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	adds r5, #4
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	movs r2, #0x85
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x80
	str r0, [r1]
	movs r3, #0x86
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0
	str r0, [r1]
	movs r4, #0x87
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
	movs r6, #0x88
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r0, #0x80
	lsls r0, r0, #4
	str r0, [r1]
	bl sub_08053418
	ldr r7, _08054550 @ =0x03006D30
	mov r8, r7
	movs r7, #0xb2
	lsls r7, r7, #1
	ldr r2, _08054554 @ =0x3F800000
	movs r3, #0
	subs r6, #0xa4
	movs r5, #0xca
	lsls r5, r5, #1
	adds r4, #0xe4
	movs r0, #0xf
	str r0, [sp, #0x64]
_08054528:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r3, r0
	adds r1, r0, r7
	str r2, [r1]
	adds r1, r0, r6
	str r2, [r1]
	adds r0, r0, r5
	str r2, [r0]
	adds r3, r3, r4
	ldr r0, [sp, #0x64]
	subs r0, #1
	str r0, [sp, #0x64]
	cmp r0, #0
	bge _08054528
	bl _080566B6
	.align 2, 0
_0805454C: .4byte 0x03005350
_08054550: .4byte 0x03006D30
_08054554: .4byte 0x3F800000
_08054558:
	movs r1, #0
	str r1, [sp, #0x68]
	mov sl, r1
	movs r2, #0
	str r2, [sp, #0x6c]
	movs r3, #0
	str r3, [sp, #0x64]
	ldr r4, _080546A0 @ =0x03005490
	mov ip, r4
_0805456A:
	ldr r6, _080546A4 @ =0x03006D30
	ldr r2, [r6]
	ldr r7, [sp, #0x64]
	lsls r1, r7, #1
	adds r0, r1, r7
	lsls r3, r0, #8
	adds r2, r3, r2
	ldr r0, [r2]
	str r1, [sp, #0x88]
	adds r1, r7, #0
	adds r1, #1
	str r1, [sp, #0x84]
	cmp r0, #0
	beq _0805465E
	movs r4, #0x86
	lsls r4, r4, #2
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _0805465E
	movs r7, #0
	adds r6, r3, #0
	ldr r0, _080546A8 @ =0x030054D4
	mov r8, r0
_0805459A:
	ldr r1, _080546A4 @ =0x03006D30
	ldr r4, [r1]
	adds r2, r6, r4
	lsls r3, r7, #2
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r2, r1
	adds r5, r0, r3
	ldr r0, [r5]
	cmp r0, #0
	beq _08054636
	ldr r0, [sp, #0x6c]
	adds r0, #1
	str r0, [sp, #0x6c]
	subs r1, #0x80
	adds r0, r2, r1
	adds r0, r0, r3
	ldr r1, [r2, #4]
	ldr r0, [r0]
	cmp r1, r0
	blt _08054630
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r2, r1
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, r8
	str r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r1, r1, r4
	ldr r0, [r2, #0x10]
	str r0, [r1, #0x10]
	ldr r0, [r2, #0x58]
	str r0, [r1, #0x58]
	adds r1, #0xa0
	adds r0, r2, #0
	adds r0, #0xa0
	ldr r0, [r0]
	str r0, [r1]
	mov r2, ip
	ldr r1, [r2]
	lsls r1, r1, #2
	ldr r4, _080546AC @ =0x03005494
	adds r0, r1, r4
	mov r2, sb
	str r2, [r0]
	ldr r5, [r5]
	mov sb, r5
	ldr r4, _080546B0 @ =0x03005450
	adds r1, r1, r4
	ldr r2, _080546B4 @ =0x0300544C
	ldr r0, [r2]
	str r0, [r1]
	mov r4, ip
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	movs r0, #0
	str r0, [r2]
	ldr r0, [r5]
	ldr r1, _080546B8 @ =0x03005444
	str r0, [r1]
	ldr r2, _080546A4 @ =0x03006D30
	ldr r0, [r2]
	adds r0, r6, r0
	movs r4, #0xa7
	lsls r4, r4, #2
	adds r0, r0, r4
	adds r0, r0, r3
	movs r1, #0
	str r1, [r0]
	movs r2, #1
	mov sl, r2
_08054630:
	mov r3, sl
	cmp r3, #0
	bne _08054642
_08054636:
	mov r4, sl
	cmp r4, #0
	bne _08054642
	adds r7, #1
	cmp r7, #0xf
	ble _0805459A
_08054642:
	ldr r6, [sp, #0x6c]
	cmp r6, #0
	bne _0805465E
	ldr r7, _080546A4 @ =0x03006D30
	ldr r1, [r7]
	ldr r2, [sp, #0x88]
	ldr r3, [sp, #0x64]
	adds r0, r2, r3
	lsls r0, r0, #8
	adds r0, r0, r1
	movs r4, #0x86
	lsls r4, r4, #2
	adds r0, r0, r4
	str r6, [r0]
_0805465E:
	ldr r6, [sp, #0x84]
	str r6, [sp, #0x64]
	cmp r6, #0xf
	ble _0805456A
	mov r7, sl
	cmp r7, #0
	beq _08054670
	bl _080566B6
_08054670:
	movs r0, #0
	str r0, [sp, #0x64]
	movs r6, #0
_08054676:
	ldr r1, _080546A4 @ =0x03006D30
	ldr r0, [r1]
	adds r2, r6, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _08054684
	b _08054CCC
_08054684:
	ldr r0, [r2, #8]
	ldr r1, [r2, #4]
	cmp r0, r1
	ble _0805468E
	b _08054CC8
_0805468E:
	movs r7, #0
	ldr r5, _080546A4 @ =0x03006D30
	adds r4, r6, #0
_08054694:
	cmp r7, #0
	bne _080546BC
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #0x10
	b _080546D2
	.align 2, 0
_080546A0: .4byte 0x03005490
_080546A4: .4byte 0x03006D30
_080546A8: .4byte 0x030054D4
_080546AC: .4byte 0x03005494
_080546B0: .4byte 0x03005450
_080546B4: .4byte 0x0300544C
_080546B8: .4byte 0x03005444
_080546BC:
	cmp r7, #1
	bne _080546C8
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #0x58
	b _080546D2
_080546C8:
	cmp r7, #2
	bne _080546D4
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #0xa0
_080546D2:
	str r0, [sp, #0x74]
_080546D4:
	ldr r0, [sp, #0x74]
	bl animation_interpolation_step
	adds r7, #1
	cmp r7, #2
	ble _08054694
	movs r7, #0
	adds r5, r6, #0
_080546E4:
	cmp r7, #0
	bne _080546F8
	ldr r2, _080546F4 @ =0x03006D30
	ldr r0, [r2]
	adds r0, r0, r5
	adds r0, #0xe8
	str r0, [sp, #0x78]
	b _0805470A
	.align 2, 0
_080546F4: .4byte 0x03006D30
_080546F8:
	cmp r7, #1
	bne _0805470A
	ldr r3, _0805473C @ =0x03006D30
	ldr r0, [r3]
	adds r0, r0, r5
	movs r4, #0x80
	lsls r4, r4, #1
	adds r4, r0, r4
	str r4, [sp, #0x78]
_0805470A:
	ldr r1, [sp, #0x78]
	ldr r0, [r1]
	cmp r0, #0
	beq _0805474A
	ldr r0, [r1, #8]
	ldr r4, [r1, #4]
	cmp r0, r4
	bgt _08054744
	ldr r0, [r1, #0x10]
	ldr r1, [r1, #0x14]
	bl softfloat_add_f32
	ldr r2, [sp, #0x78]
	str r0, [r2, #0x10]
	adds r0, r4, #1
	str r0, [r2, #4]
	ldr r1, [r2, #0xc]
	ldr r3, _08054740 @ =0x0000FFFF
	cmp r1, r3
	beq _0805474A
	cmp r0, r1
	blt _0805474A
	movs r4, #0
	str r4, [r2]
	b _0805474A
	.align 2, 0
_0805473C: .4byte 0x03006D30
_08054740: .4byte 0x0000FFFF
_08054744:
	adds r0, r4, #1
	ldr r1, [sp, #0x78]
	str r0, [r1, #4]
_0805474A:
	adds r7, #1
	cmp r7, #1
	ble _080546E4
	movs r5, #0
	mov r8, r6
_08054754:
	cmp r5, #0
	bne _0805476C
	ldr r2, _08054768 @ =0x03006D30
	ldr r0, [r2]
	add r0, r8
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r3, r0, r3
	str r3, [sp, #0x7c]
	b _0805477E
	.align 2, 0
_08054768: .4byte 0x03006D30
_0805476C:
	cmp r5, #1
	bne _0805477E
	ldr r4, _080547C4 @ =0x03006D30
	ldr r0, [r4]
	add r0, r8
	movs r7, #0x9e
	lsls r7, r7, #1
	adds r7, r0, r7
	str r7, [sp, #0x7c]
_0805477E:
	ldr r0, [sp, #0x7c]
	ldr r2, [r0]
	adds r1, r5, #1
	mov sl, r1
	cmp r2, #0
	bne _0805478C
	b _080548DE
_0805478C:
	ldr r0, [r0, #0x14]
	ldr r3, [sp, #0x7c]
	ldr r1, [r3, #0x10]
	adds r3, r1, #0
	cmp r0, r1
	ble _0805479A
	b _080548D8
_0805479A:
	cmp r2, #1
	bne _080547E6
	ldr r4, [sp, #0x7c]
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	bl softfloat_add_f32
	str r0, [r4, #4]
	ldr r7, [sp, #0x64]
	lsls r0, r7, #6
	ldr r1, _080547C8 @ =0x03006D40
	adds r4, r0, r1
	movs r7, #3
_080547B4:
	cmp r5, #0
	bne _080547CC
	ldr r2, [sp, #0x7c]
	ldr r0, [r2, #4]
	bl float_to_int
	strh r0, [r4]
	b _080547DA
	.align 2, 0
_080547C4: .4byte 0x03006D30
_080547C8: .4byte 0x03006D40
_080547CC:
	cmp r5, #1
	bne _080547DA
	ldr r3, [sp, #0x7c]
	ldr r0, [r3, #4]
	bl float_to_int
	strh r0, [r4, #2]
_080547DA:
	adds r4, #0x10
	subs r7, #1
	cmp r7, #0
	bge _080547B4
	ldr r4, [sp, #0x7c]
	b _080548B8
_080547E6:
	cmp r2, #2
	bne _08054848
	ldr r7, [sp, #0x7c]
	ldr r0, [r7, #0xc]
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	ldr r0, _08054828 @ =0x080AE77C
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r0, [r7, #8]
	bl softfloat_multiply
	str r0, [r7, #4]
	ldr r3, [sp, #0x64]
	lsls r0, r3, #6
	ldr r7, _0805482C @ =0x03006D40
	adds r4, r0, r7
	movs r7, #3
_08054818:
	cmp r5, #0
	bne _08054830
	ldr r1, [sp, #0x7c]
	ldr r0, [r1, #4]
	bl float_to_int
	strh r0, [r4]
	b _0805483E
	.align 2, 0
_08054828: .4byte 0x080AE77C
_0805482C: .4byte 0x03006D40
_08054830:
	cmp r5, #1
	bne _0805483E
	ldr r2, [sp, #0x7c]
	ldr r0, [r2, #4]
	bl float_to_int
	strh r0, [r4, #2]
_0805483E:
	adds r4, #0x10
	subs r7, #1
	cmp r7, #0
	bge _08054818
	b _080548AA
_08054848:
	cmp r2, #3
	bne _080548BA
	ldr r7, [sp, #0x7c]
	ldr r0, [r7, #0xc]
	bl float_to_int
	movs r1, #0xff
	ands r1, r0
	adds r1, #0x40
	lsls r1, r1, #1
	ldr r0, _0805488C @ =0x080AE77C
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r0, [r7, #8]
	bl softfloat_multiply
	str r0, [r7, #4]
	ldr r3, [sp, #0x64]
	lsls r0, r3, #6
	ldr r7, _08054890 @ =0x03006D40
	adds r4, r0, r7
	movs r7, #3
_0805487C:
	cmp r5, #0
	bne _08054894
	ldr r1, [sp, #0x7c]
	ldr r0, [r1, #4]
	bl float_to_int
	strh r0, [r4]
	b _080548A2
	.align 2, 0
_0805488C: .4byte 0x080AE77C
_08054890: .4byte 0x03006D40
_08054894:
	cmp r5, #1
	bne _080548A2
	ldr r2, [sp, #0x7c]
	ldr r0, [r2, #4]
	bl float_to_int
	strh r0, [r4, #2]
_080548A2:
	adds r4, #0x10
	subs r7, #1
	cmp r7, #0
	bge _0805487C
_080548AA:
	ldr r3, [sp, #0x7c]
	ldr r0, [r3, #0xc]
	ldr r1, [r3, #0x1c]
	bl softfloat_add_f32
	ldr r4, [sp, #0x7c]
	str r0, [r4, #0xc]
_080548B8:
	ldr r3, [r4, #0x10]
_080548BA:
	adds r1, r3, #1
	ldr r7, [sp, #0x7c]
	str r1, [r7, #0x10]
	ldr r0, [r7, #0x18]
	ldr r2, _080548D4 @ =0x0000FFFF
	cmp r0, r2
	beq _080548DE
	cmp r1, r0
	blt _080548DE
	movs r0, #4
	str r0, [r7]
	b _080548DE
	.align 2, 0
_080548D4: .4byte 0x0000FFFF
_080548D8:
	adds r0, r1, #1
	ldr r3, [sp, #0x7c]
	str r0, [r3, #0x10]
_080548DE:
	mov r5, sl
	cmp r5, #1
	bgt _080548E6
	b _08054754
_080548E6:
	movs r7, #0
	adds r5, r6, #0
_080548EA:
	cmp r7, #0
	bne _08054900
	ldr r4, _080548FC @ =0x03006D30
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0xb0
	lsls r1, r1, #1
	b _08054926
	.align 2, 0
_080548FC: .4byte 0x03006D30
_08054900:
	cmp r7, #1
	bne _08054918
	ldr r2, _08054914 @ =0x03006D30
	ldr r0, [r2]
	adds r0, r0, r5
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r0, r3
	str r3, [sp, #0x80]
	b _0805492A
	.align 2, 0
_08054914: .4byte 0x03006D30
_08054918:
	cmp r7, #2
	bne _0805492A
	ldr r4, _0805495C @ =0x03006D30
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0xc8
	lsls r1, r1, #1
_08054926:
	adds r1, r0, r1
	str r1, [sp, #0x80]
_0805492A:
	ldr r2, [sp, #0x80]
	ldr r0, [r2]
	cmp r0, #0
	beq _0805496A
	ldr r0, [r2, #0x10]
	ldr r4, [r2, #0xc]
	cmp r0, r4
	bgt _08054964
	ldr r0, [r2, #4]
	ldr r1, [r2, #8]
	bl softfloat_add_f32
	ldr r3, [sp, #0x80]
	str r0, [r3, #4]
	adds r0, r4, #1
	str r0, [r3, #0xc]
	ldr r1, [r3, #0x14]
	ldr r4, _08054960 @ =0x0000FFFF
	cmp r1, r4
	beq _0805496A
	cmp r0, r1
	blt _0805496A
	movs r0, #0
	str r0, [r3]
	b _0805496A
	.align 2, 0
_0805495C: .4byte 0x03006D30
_08054960: .4byte 0x0000FFFF
_08054964:
	adds r0, r4, #1
	ldr r1, [sp, #0x80]
	str r0, [r1, #0xc]
_0805496A:
	adds r7, #1
	cmp r7, #2
	ble _080548EA
	ldr r2, _08054A08 @ =0x03006D30
	ldr r0, [r2]
	adds r2, r6, r0
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08054A18
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r7, #0xda
	lsls r7, r7, #1
	adds r3, r2, r7
	ldr r0, [r0]
	ldr r1, [r3]
	cmp r0, r1
	bgt _08054A14
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, [r4]
	ldr r1, [r1]
	bl softfloat_add_f32
	str r0, [r4]
	ldr r1, _08054A0C @ =0x03006D40
	adds r5, r6, #0
	ldr r4, [sp, #0x64]
	lsls r0, r4, #6
	adds r4, r0, r1
	movs r7, #3
_080549B8:
	ldr r1, _08054A08 @ =0x03006D30
	ldr r0, [r1]
	adds r0, r5, r0
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	bl float_to_int
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #4]
	adds r4, #0x10
	subs r7, #1
	cmp r7, #0
	bge _080549B8
	ldr r3, _08054A08 @ =0x03006D30
	ldr r0, [r3]
	adds r3, r6, r0
	movs r4, #0xda
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	adds r2, r0, #1
	str r2, [r1]
	movs r7, #0xde
	lsls r7, r7, #1
	adds r0, r3, r7
	ldr r0, [r0]
	ldr r1, _08054A10 @ =0x0000FFFF
	cmp r0, r1
	beq _08054A18
	cmp r2, r0
	blt _08054A18
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r3, #0
	str r3, [r0]
	b _08054A18
	.align 2, 0
_08054A08: .4byte 0x03006D30
_08054A0C: .4byte 0x03006D40
_08054A10: .4byte 0x0000FFFF
_08054A14:
	adds r0, r1, #1
	str r0, [r3]
_08054A18:
	ldr r4, _08054A34 @ =0x03006D30
	ldr r0, [r4]
	adds r1, r6, r0
	movs r7, #0x82
	lsls r7, r7, #2
	adds r0, r1, r7
	ldr r0, [r0]
	cmp r0, #0
	beq _08054A5C
	movs r7, #0
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r1, r2
	b _08054A56
	.align 2, 0
_08054A34: .4byte 0x03006D30
_08054A38:
	ldr r0, [r4]
	adds r0, r6, r0
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r0, r0, r3
	adds r0, r0, r7
	ldrb r0, [r0]
	bl advance_sprite_animation_frame
	adds r7, #1
	ldr r0, [r4]
	adds r0, r6, r0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r0, r1
_08054A56:
	ldr r0, [r0]
	cmp r7, r0
	blt _08054A38
_08054A5C:
	ldr r1, _08054B30 @ =0x03006D30
	ldr r0, [r1]
	adds r4, r6, r0
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08054B40
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r7, #0xe2
	lsls r7, r7, #1
	adds r2, r4, r7
	ldr r0, [r0]
	ldr r1, [r2]
	cmp r0, r1
	bgt _08054B3C
	movs r7, #0
	adds r3, #0x48
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r7, r0
	bge _08054ABC
	ldr r0, _08054B34 @ =0x03002C30
	mov r8, r0
	ldr r5, _08054B30 @ =0x03006D30
	movs r1, #0x80
	lsls r1, r1, #7
	adds r4, r1, #0
_08054A9A:
	ldr r2, [r5]
	adds r2, r6, r2
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r2, r1
	adds r0, r0, r7
	ldrb r1, [r0]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r7, #1
	adds r2, r2, r3
	ldr r0, [r2]
	cmp r7, r0
	blt _08054A9A
_08054ABC:
	ldr r2, _08054B30 @ =0x03006D30
	ldr r0, [r2]
	adds r3, r6, r0
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	adds r2, r0, #1
	str r2, [r1]
	movs r7, #0xe6
	lsls r7, r7, #1
	adds r0, r3, r7
	ldr r0, [r0]
	ldr r1, _08054B38 @ =0x0000FFFF
	cmp r0, r1
	beq _08054B40
	cmp r2, r0
	blt _08054B40
	movs r7, #0
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r7, r0
	bge _08054B14
	ldr r4, _08054B30 @ =0x03006D30
_08054AF0:
	ldr r0, [r4]
	adds r0, r6, r0
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r0, r0, r3
	adds r0, r0, r7
	ldrb r0, [r0]
	bl clear_battle_sprite_entry
	adds r7, #1
	ldr r0, [r4]
	adds r0, r6, r0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r7, r0
	blt _08054AF0
_08054B14:
	ldr r1, _08054B30 @ =0x03006D30
	ldr r0, [r1]
	adds r4, r6, r0
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	str r3, [r0]
	movs r7, #0x82
	lsls r7, r7, #2
	adds r0, r4, r7
	str r3, [r0]
	b _08054B40
	.align 2, 0
_08054B30: .4byte 0x03006D30
_08054B34: .4byte 0x03002C30
_08054B38: .4byte 0x0000FFFF
_08054B3C:
	adds r0, r1, #1
	str r0, [r2]
_08054B40:
	ldr r1, _08054BAC @ =0x03006D30
	ldr r0, [r1]
	adds r3, r6, r0
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08054C38
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	movs r7, #0xea
	lsls r7, r7, #1
	adds r2, r3, r7
	ldr r0, [r0]
	ldr r1, [r2]
	cmp r0, r1
	bgt _08054C34
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08054BB8
	movs r7, #0
	adds r4, #0x38
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r7, r0
	bge _08054BF6
	ldr r0, _08054BB0 @ =0x03002C30
	mov sl, r0
	ldr r5, _08054BAC @ =0x03006D30
	ldr r1, _08054BB4 @ =0x0000BFFF
	mov r8, r1
_08054B84:
	ldr r3, [r5]
	adds r3, r6, r3
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r3, r2
	adds r0, r0, r7
	ldrb r1, [r0]
	lsls r1, r1, #6
	add r1, sl
	ldrh r2, [r1]
	mov r0, r8
	ands r0, r2
	strh r0, [r1]
	adds r7, #1
	adds r3, r3, r4
	ldr r0, [r3]
	cmp r7, r0
	blt _08054B84
	b _08054BF6
	.align 2, 0
_08054BAC: .4byte 0x03006D30
_08054BB0: .4byte 0x03002C30
_08054BB4: .4byte 0x0000BFFF
_08054BB8:
	movs r7, #0
	movs r4, #0x84
	lsls r4, r4, #2
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r7, r0
	bge _08054BF6
	ldr r3, _08054C28 @ =0x03002C30
	mov r8, r3
	adds r3, r6, #0
	movs r0, #0x80
	lsls r0, r0, #7
	adds r5, r0, #0
_08054BD2:
	ldr r1, _08054C2C @ =0x03006D30
	ldr r2, [r1]
	adds r2, r3, r2
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r2, r1
	adds r0, r0, r7
	ldrb r1, [r0]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r7, #1
	adds r2, r2, r4
	ldr r0, [r2]
	cmp r7, r0
	blt _08054BD2
_08054BF6:
	ldr r2, _08054C2C @ =0x03006D30
	ldr r0, [r2]
	adds r3, r6, r0
	movs r4, #0xea
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	adds r2, r0, #1
	str r2, [r1]
	movs r7, #0xee
	lsls r7, r7, #1
	adds r0, r3, r7
	ldr r0, [r0]
	ldr r1, _08054C30 @ =0x0000FFFF
	cmp r0, r1
	beq _08054C38
	cmp r2, r0
	blt _08054C38
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r3, #0
	str r3, [r0]
	b _08054C38
	.align 2, 0
_08054C28: .4byte 0x03002C30
_08054C2C: .4byte 0x03006D30
_08054C30: .4byte 0x0000FFFF
_08054C34:
	adds r0, r1, #1
	str r0, [r2]
_08054C38:
	ldr r4, _08054C94 @ =0x03006D30
	ldr r0, [r4]
	adds r3, r6, r0
	movs r5, #0xbb
	lsls r5, r5, #2
	adds r0, r3, r5
	ldr r0, [r0]
	cmp r0, #0
	beq _08054CA0
	movs r7, #0xbd
	lsls r7, r7, #2
	adds r0, r3, r7
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r3, r1
	ldr r0, [r0]
	ldr r1, [r2]
	cmp r0, r1
	bgt _08054C9C
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r0, [r0]
	bl sub_08047BA8
	ldr r0, [r4]
	adds r3, r6, r0
	movs r4, #0xbc
	lsls r4, r4, #2
	adds r1, r3, r4
	ldr r0, [r1]
	adds r2, r0, #1
	str r2, [r1]
	adds r7, #4
	adds r0, r3, r7
	ldr r0, [r0]
	ldr r1, _08054C98 @ =0x0000FFFF
	cmp r0, r1
	beq _08054CA0
	cmp r2, r0
	blt _08054CA0
	adds r0, r3, r5
	movs r2, #0
	str r2, [r0]
	b _08054CA0
	.align 2, 0
_08054C94: .4byte 0x03006D30
_08054C98: .4byte 0x0000FFFF
_08054C9C:
	adds r0, r1, #1
	str r0, [r2]
_08054CA0:
	ldr r0, _08054CC0 @ =0x03006D30
	ldr r1, [r0]
	adds r1, r6, r1
	ldr r2, [r1, #4]
	adds r2, #1
	str r2, [r1, #4]
	ldr r1, [r1, #0xc]
	ldr r3, _08054CC4 @ =0x0000FFFF
	cmp r1, r3
	beq _08054CCC
	cmp r2, r1
	blt _08054CCC
	ldr r4, [sp, #0x68]
	adds r4, #1
	str r4, [sp, #0x68]
	b _08054CCC
	.align 2, 0
_08054CC0: .4byte 0x03006D30
_08054CC4: .4byte 0x0000FFFF
_08054CC8:
	adds r0, r1, #1
	str r0, [r2, #4]
_08054CCC:
	movs r7, #0xc0
	lsls r7, r7, #2
	adds r6, r6, r7
	ldr r0, [sp, #0x64]
	adds r0, #1
	str r0, [sp, #0x64]
	cmp r0, #0xf
	bgt _08054CDE
	b _08054676
_08054CDE:
	bl update_3d_entity_projections
	ldr r2, _08054D98 @ =0x03006D30
	ldr r1, [r2]
	adds r2, r7, #0
	movs r3, #0xf
	str r3, [sp, #0x64]
_08054CEC:
	ldr r0, [r1]
	cmp r0, #2
	bne _08054CF8
	ldr r4, [sp, #0x68]
	adds r4, #1
	str r4, [sp, #0x68]
_08054CF8:
	adds r1, r1, r2
	ldr r6, [sp, #0x64]
	subs r6, #1
	str r6, [sp, #0x64]
	cmp r6, #0
	bge _08054CEC
	movs r7, #0
	str r7, [sp, #0x64]
_08054D08:
	ldr r0, _08054D98 @ =0x03006D30
	ldr r2, [r0]
	ldr r3, [sp, #0x64]
	lsls r1, r3, #1
	adds r0, r1, r3
	lsls r0, r0, #8
	adds r2, r0, r2
	ldr r0, [r2]
	str r1, [sp, #0x88]
	adds r3, #1
	str r3, [sp, #0x84]
	cmp r0, #0
	beq _08054DD4
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r6, #0x9e
	lsls r6, r6, #1
	adds r1, r2, r6
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	cmp r0, #0
	bne _08054DD4
	movs r7, #0
	ldr r5, _08054D9C @ =0x03005350
	ldr r1, _08054DA0 @ =0x03006D40
	ldr r0, _08054DA4 @ =0x03002C30
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0x9c
	ldr r2, _08054DA8 @ =0x00000101
	mov sl, r2
	ldr r3, [sp, #0x64]
	lsls r0, r3, #6
	adds r4, r0, r1
_08054D50:
	ldr r0, _08054D98 @ =0x03006D30
	ldr r1, [r0]
	ldr r2, [sp, #0x88]
	ldr r3, [sp, #0x64]
	adds r0, r2, r3
	lsls r0, r0, #8
	adds r0, r0, r1
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r5, r0, r7
	ldrb r0, [r5]
	lsls r0, r0, #6
	add r0, r8
	ldr r0, [r0, #0x14]
	asrs r2, r0, #8
	ldr r1, [r6]
	cmp r2, r1
	ble _08054DAC
	adds r0, r2, #0
	bl sub_0807CBBC
	mov r2, sl
	subs r0, r2, r0
	strh r0, [r4]
	ldrb r0, [r5]
	lsls r0, r0, #6
	add r0, r8
	ldr r0, [r0, #0x14]
	asrs r0, r0, #8
	ldr r1, [r6]
	bl sub_0807CBBC
	mov r3, sl
	subs r0, r3, r0
	b _08054DCA
	.align 2, 0
_08054D98: .4byte 0x03006D30
_08054D9C: .4byte 0x03005350
_08054DA0: .4byte 0x03006D40
_08054DA4: .4byte 0x03002C30
_08054DA8: .4byte 0x00000101
_08054DAC:
	adds r0, r1, #0
	adds r1, r2, #0
	bl sub_0807CBBC
	adds r0, #0xff
	strh r0, [r4]
	ldrb r0, [r5]
	lsls r0, r0, #6
	add r0, r8
	ldr r1, [r0, #0x14]
	asrs r1, r1, #8
	ldr r0, [r6]
	bl sub_0807CBBC
	adds r0, #0xff
_08054DCA:
	strh r0, [r4, #2]
	adds r4, #0x10
	adds r7, #1
	cmp r7, #3
	ble _08054D50
_08054DD4:
	ldr r4, [sp, #0x84]
	str r4, [sp, #0x64]
	cmp r4, #0xf
	ble _08054D08
	bl update_battle_sprite_status_effects
	ldr r7, _08054E1C @ =0x03005350
	movs r6, #0xfa
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sl, r6
	ldr r2, [r6]
	cmp r2, #0
	bne _08054DF2
	b _08054FE4
_08054DF2:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r3, r7, r4
	ldr r0, [r0]
	ldr r1, [r3]
	cmp r0, r1
	ble _08054E08
	b _08054FE0
_08054E08:
	adds r0, r1, #1
	str r0, [r3]
	adds r0, r2, #0
	cmp r0, #2
	beq _08054E48
	cmp r0, #2
	bgt _08054E20
	cmp r0, #1
	beq _08054E2A
	b _08054F9C
	.align 2, 0
_08054E1C: .4byte 0x03005350
_08054E20:
	cmp r2, #3
	beq _08054E5C
	cmp r2, #4
	beq _08054F00
	b _08054F9C
_08054E2A:
	ldr r0, _08054E44 @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	bne _08054E36
	b _08054F9C
_08054E36:
	movs r0, #0
	mov r6, sl
	str r0, [r6]
	ldr r7, [sp, #0x68]
	adds r7, #1
	str r7, [sp, #0x68]
	b _08054F9C
	.align 2, 0
_08054E44: .4byte 0x00007FFF
_08054E48:
	ldr r0, _08054E58 @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	bne _08054E54
	b _08054F9C
_08054E54:
	b _08054EEA
	.align 2, 0
_08054E58: .4byte 0x00007FFF
_08054E5C:
	bl blend_effect_update
	movs r4, #0x84
	lsls r4, r4, #2
	adds r3, r7, r4
	ldrb r1, [r3]
	lsls r1, r1, #0xa
	ldr r6, _08054EDC @ =0x0300555F
	ldrb r0, [r6]
	lsls r0, r0, #5
	orrs r1, r0
	ldr r0, _08054EE0 @ =0x0000020E
	adds r5, r7, r0
	ldrb r0, [r5]
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x82
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	ldrb r2, [r1]
	movs r6, #0xfc
	lsls r6, r6, #1
	adds r4, r7, r6
	ldr r1, [r4]
	muls r1, r2, r1
	adds r6, #0x12
	adds r2, r7, r6
	ldrh r2, [r2]
	str r3, [sp, #0x94]
	bl sub_08049E74
	ldr r3, [sp, #0x94]
	ldrb r1, [r3]
	lsls r1, r1, #0xa
	ldr r2, _08054EDC @ =0x0300555F
	ldrb r0, [r2]
	lsls r0, r0, #5
	orrs r1, r0
	ldrb r0, [r5]
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, r8
	ldrb r2, [r3]
	ldr r1, [r4]
	muls r1, r2, r1
	adds r6, #2
	adds r2, r7, r6
	ldrh r2, [r2]
	bl sub_08049E88
	mov r7, r8
	ldrb r5, [r7]
	ldr r1, [r4]
	movs r0, #0x20
	bl sub_0807CBBC
	cmp r5, r0
	bge _08054EE4
	adds r0, r5, #1
	strb r0, [r7]
	b _08054F9C
	.align 2, 0
_08054EDC: .4byte 0x0300555F
_08054EE0: .4byte 0x0000020E
_08054EE4:
	ldr r0, _08054EF8 @ =0x030017F0
	ldr r1, _08054EFC @ =0x08000841
	str r1, [r0]
_08054EEA:
	movs r0, #0
	mov r1, sl
	str r0, [r1]
	ldr r2, [sp, #0x68]
	adds r2, #1
	str r2, [sp, #0x68]
	b _08054F9C
	.align 2, 0
_08054EF8: .4byte 0x030017F0
_08054EFC: .4byte 0x08000841
_08054F00:
	bl blend_effect_update
	movs r3, #0x82
	lsls r3, r3, #2
	adds r5, r7, r3
	ldrb r0, [r5]
	movs r4, #0xfc
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	ldr r1, [r4]
	muls r1, r0, r1
	subs r2, r1, #1
	adds r3, r2, #0
	adds r4, r2, #0
	ldr r6, _08054F80 @ =0x0000020E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r2, r0
	bge _08054F2A
	adds r2, r0, #0
_08054F2A:
	ldr r6, _08054F84 @ =0x0000020F
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r3, r0
	bge _08054F36
	adds r3, r0, #0
_08054F36:
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r4, r0
	bge _08054F44
	adds r4, r0, #0
_08054F44:
	lsls r4, r4, #0xa
	lsls r0, r3, #5
	orrs r4, r0
	orrs r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r2, _08054F88 @ =0x0000020A
	adds r0, r7, r2
	ldrh r2, [r0]
	adds r0, r4, #0
	bl sub_08049E74
	ldrb r1, [r5]
	mov r3, r8
	ldr r0, [r3]
	muls r1, r0, r1
	movs r6, #0x83
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r2, [r0]
	adds r0, r4, #0
	bl sub_08049E88
	ldrb r0, [r5]
	adds r2, r0, #0
	cmp r2, #0
	beq _08054F8C
	subs r0, #1
	strb r0, [r5]
	b _08054F9C
	.align 2, 0
_08054F80: .4byte 0x0000020E
_08054F84: .4byte 0x0000020F
_08054F88: .4byte 0x0000020A
_08054F8C:
	ldr r1, _08054FD0 @ =0x030017F0
	ldr r0, _08054FD4 @ =0x08000841
	str r0, [r1]
	mov r7, sl
	str r2, [r7]
	ldr r0, [sp, #0x68]
	adds r0, #1
	str r0, [sp, #0x68]
_08054F9C:
	ldr r2, _08054FD8 @ =0x03005350
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r0, _08054FDC @ =0x0000FFFF
	cmp r1, r0
	beq _08054FE4
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, r1
	blt _08054FE4
	ldr r1, _08054FD0 @ =0x030017F0
	ldr r0, _08054FD4 @ =0x08000841
	str r0, [r1]
	movs r4, #0xfa
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0
	str r0, [r1]
	ldr r6, [sp, #0x68]
	adds r6, #1
	str r6, [sp, #0x68]
	b _08054FE4
	.align 2, 0
_08054FD0: .4byte 0x030017F0
_08054FD4: .4byte 0x08000841
_08054FD8: .4byte 0x03005350
_08054FDC: .4byte 0x0000FFFF
_08054FE0:
	adds r0, r1, #1
	str r0, [r3]
_08054FE4:
	ldr r7, [sp, #0x68]
	cmp r7, #0
	bne _08054FEE
	bl _080566B6
_08054FEE:
	ldr r2, _08055018 @ =0x03005350
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08055000
	bl _080566B6
_08055000:
	adds r1, r2, #0
	adds r1, #0xfc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	subs r1, #8
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	bl _080566B6
	.align 2, 0
_08055018: .4byte 0x03005350
_0805501C:
	ldr r0, _0805506C @ =0x03005350
	adds r3, r0, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r0, _08055070 @ =0x03006D30
	ldr r0, [r0]
	lsls r2, r7, #1
	adds r2, r2, r7
	lsls r2, r2, #8
	adds r2, r2, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2, #4]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2, #8]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2, #0xc]
	bl _0805666A
	.align 2, 0
_0805506C: .4byte 0x03005350
_08055070: .4byte 0x03006D30
_08055074:
	ldr r1, _08055084 @ =0x03005350
	adds r1, #0xfc
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
	bl _080566B6
	.align 2, 0
_08055084: .4byte 0x03005350
_08055088:
	ldr r0, _080550D0 @ =0x03005350
	movs r3, #0xfc
	adds r3, r3, r0
	mov r8, r3
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r7, [r0]
	adds r6, r1, #0
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	adds r6, #1
	str r6, [r3]
	cmp r0, #0
	bne _080550D8
	ldr r0, _080550D4 @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r4, #0x10]
	adds r0, r6, #1
	mov r6, r8
	str r0, [r6]
	bl _080566B6
	.align 2, 0
_080550D0: .4byte 0x03005350
_080550D4: .4byte 0x03006D30
_080550D8:
	ldr r0, _08055108 @ =0x03006D30
	ldr r5, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r5
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	movs r7, #0x85
	lsls r7, r7, #2
	adds r1, r4, r7
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #8
	adds r1, r1, r5
	ldr r1, [r1, #0x10]
	bl softfloat_add_f32
	str r0, [r4, #0x10]
	b _08055182
	.align 2, 0
_08055108: .4byte 0x03006D30
_0805510C:
	ldr r0, _0805514C @ =0x03005350
	movs r2, #0xfc
	adds r2, r2, r0
	mov r8, r2
	ldr r1, [r2]
	adds r1, #2
	str r1, [r2]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r7, [r0]
	adds r6, r1, #0
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	adds r6, #1
	str r6, [r2]
	cmp r0, #0
	bne _08055154
	ldr r0, _08055150 @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r4, #0x58]
	b _080551D0
	.align 2, 0
_0805514C: .4byte 0x03005350
_08055150: .4byte 0x03006D30
_08055154:
	ldr r0, _0805518C @ =0x03006D30
	ldr r5, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r5
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	movs r7, #0x85
	lsls r7, r7, #2
	adds r1, r4, r7
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #8
	adds r1, r1, r5
	ldr r1, [r1, #0x58]
	bl softfloat_add_f32
	str r0, [r4, #0x58]
_08055182:
	adds r0, r6, #1
	mov r1, r8
	str r0, [r1]
	bl _080566B6
	.align 2, 0
_0805518C: .4byte 0x03006D30
_08055190:
	ldr r0, _080551DC @ =0x03005350
	movs r2, #0xfc
	adds r2, r2, r0
	mov r8, r2
	ldr r1, [r2]
	adds r1, #2
	str r1, [r2]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r7, [r0]
	adds r6, r1, #0
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	adds r6, #1
	str r6, [r2]
	cmp r0, #0
	bne _080551E4
	ldr r0, _080551E0 @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	adds r4, #0xa0
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r4]
_080551D0:
	adds r0, r6, #1
	mov r4, r8
	str r0, [r4]
	bl _080566B6
	.align 2, 0
_080551DC: .4byte 0x03005350
_080551E0: .4byte 0x03006D30
_080551E4:
	ldr r0, _08055224 @ =0x03006D30
	ldr r4, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r4
	adds r5, r7, #0
	adds r5, #0xa0
	lsls r0, r6, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	movs r2, #0x85
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #8
	adds r1, r1, r4
	adds r1, #0xa0
	ldr r1, [r1]
	bl softfloat_add_f32
	str r0, [r5]
	adds r0, r6, #1
	mov r3, r8
	str r0, [r3]
	bl _080566B6
	.align 2, 0
_08055224: .4byte 0x03006D30
_08055228:
	ldr r0, _0805524C @ =0x03005350
	adds r6, r0, #0
	adds r6, #0xfc
	ldr r5, [r6]
	adds r5, #2
	str r5, [r6]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r7, [r0]
	ldr r0, _08055250 @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	adds r4, #0xf8
	b _08055422
	.align 2, 0
_0805524C: .4byte 0x03005350
_08055250: .4byte 0x03006D30
_08055254:
	ldr r0, _0805527C @ =0x03005350
	adds r6, r0, #0
	adds r6, #0xfc
	ldr r5, [r6]
	adds r5, #2
	str r5, [r6]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r0, r7
	ldr r7, [r0]
	ldr r0, _08055280 @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	movs r0, #0x88
	lsls r0, r0, #1
	adds r4, r4, r0
	b _08055422
	.align 2, 0
_0805527C: .4byte 0x03005350
_08055280: .4byte 0x03006D30
_08055284:
	adds r6, r5, #0
	adds r6, #0xfc
	ldr r4, [r6]
	adds r4, #2
	str r4, [r6]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08055308 @ =0x03006D30
	ldr r1, [r2]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	mov r8, r0
	adds r3, r0, r1
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r3, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r5, r3, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r1, [sp, #0x8c]
	str r2, [sp, #0x90]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	ldr r1, [sp, #0x8c]
	ldr r0, [r1]
	cmp r0, #0
	bne _080552DC
	bl _080566B6
_080552DC:
	ldr r1, _0805530C @ =0x03006D40
	mov r5, r8
	lsls r0, r7, #6
	adds r4, r0, r1
	movs r7, #3
_080552E6:
	ldr r1, _08055308 @ =0x03006D30
	ldr r0, [r1]
	adds r0, r5, r0
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	bl float_to_int
	strh r0, [r4]
	adds r4, #0x10
	subs r7, #1
	cmp r7, #0
	bge _080552E6
	bl _080566B6
	.align 2, 0
_08055308: .4byte 0x03006D30
_0805530C: .4byte 0x03006D40
_08055310:
	adds r6, r5, #0
	adds r6, #0xfc
	ldr r4, [r6]
	adds r4, #2
	str r4, [r6]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r7, [r0]
	ldr r2, _08055394 @ =0x03006D30
	ldr r1, [r2]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	mov r8, r0
	adds r3, r0, r1
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r1, r3, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r5, r3, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r1, [sp, #0x8c]
	str r2, [sp, #0x90]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	ldr r1, [sp, #0x8c]
	ldr r0, [r1]
	cmp r0, #0
	bne _08055368
	bl _080566B6
_08055368:
	ldr r1, _08055398 @ =0x03006D40
	mov r5, r8
	lsls r0, r7, #6
	adds r4, r0, r1
	movs r7, #3
_08055372:
	ldr r1, _08055394 @ =0x03006D30
	ldr r0, [r1]
	adds r0, r5, r0
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	bl float_to_int
	strh r0, [r4, #2]
	adds r4, #0x10
	subs r7, #1
	cmp r7, #0
	bge _08055372
	bl _080566B6
	.align 2, 0
_08055394: .4byte 0x03006D30
_08055398: .4byte 0x03006D40
_0805539C:
	ldr r0, _080553C4 @ =0x03005350
	adds r6, r0, #0
	adds r6, #0xfc
	ldr r5, [r6]
	adds r5, #2
	str r5, [r6]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r7, [r0]
	ldr r0, _080553C8 @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	movs r7, #0xb2
	lsls r7, r7, #1
	b _08055420
	.align 2, 0
_080553C4: .4byte 0x03005350
_080553C8: .4byte 0x03006D30
_080553CC:
	ldr r0, _080553F4 @ =0x03005350
	adds r6, r0, #0
	adds r6, #0xfc
	ldr r5, [r6]
	adds r5, #2
	str r5, [r6]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r0, _080553F8 @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r4, r4, r2
	b _08055422
	.align 2, 0
_080553F4: .4byte 0x03005350
_080553F8: .4byte 0x03006D30
_080553FC:
	ldr r0, _08055438 @ =0x03005350
	adds r6, r0, #0
	adds r6, #0xfc
	ldr r5, [r6]
	adds r5, #2
	str r5, [r6]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r7, [r0]
	ldr r0, _0805543C @ =0x03006D30
	ldr r0, [r0]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r4, r4, r0
	movs r7, #0xca
	lsls r7, r7, #1
_08055420:
	adds r4, r4, r7
_08055422:
	lsls r0, r5, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r4]
	adds r5, #1
	str r5, [r6]
	bl _080566B6
	.align 2, 0
_08055438: .4byte 0x03005350
_0805543C: .4byte 0x03006D30
_08055440:
	adds r1, r5, #0
	adds r1, #0xfc
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	adds r0, r5, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0x10
	bne _08055470
	ldr r0, _0805546C @ =0x03006D30
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #8
	ldr r0, [r0]
	adds r0, r0, r1
	adds r0, #0x10
	b _0805549A
	.align 2, 0
_0805546C: .4byte 0x03006D30
_08055470:
	cmp r0, #0x11
	bne _08055488
	ldr r0, _08055484 @ =0x03006D30
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #8
	ldr r0, [r0]
	adds r0, r0, r1
	adds r0, #0x58
	b _0805549A
	.align 2, 0
_08055484: .4byte 0x03006D30
_08055488:
	cmp r0, #0x12
	bne _0805549C
	ldr r0, _080554C0 @ =0x03006D30
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #8
	ldr r0, [r0]
	adds r0, r0, r1
	adds r0, #0xa0
_0805549A:
	str r0, [sp, #0x74]
_0805549C:
	ldr r4, _080554C4 @ =0x03005350
	adds r4, #0xfc
	ldr r0, [r4]
	lsls r0, r0, #2
	add r0, sb
	add r1, sp, #0x14
	movs r2, #0x40
	bl memcpy_u8
	ldr r0, [r4]
	adds r0, #0x10
	str r0, [r4]
	ldr r0, [sp, #0x74]
	add r1, sp, #0x14
	bl sub_0805689C
	bl _080566B6
	.align 2, 0
_080554C0: .4byte 0x03006D30
_080554C4: .4byte 0x03005350
_080554C8:
	ldr r0, _08055540 @ =0x03005350
	adds r5, r0, #0
	adds r5, #0xfc
	ldr r4, [r5]
	adds r4, #2
	str r4, [r5]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r0, _08055544 @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r6, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _08055548 @ =0x41200000
	bl softfloat_divide
	str r0, [r6]
	adds r4, #1
	str r4, [r5]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r1, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r6, #0xba
	lsls r6, r6, #1
	b _0805593A
	.align 2, 0
_08055540: .4byte 0x03005350
_08055544: .4byte 0x03006D30
_08055548: .4byte 0x41200000
_0805554C:
	ldr r0, _080555C4 @ =0x03005350
	adds r5, r0, #0
	adds r5, #0xfc
	ldr r4, [r5]
	adds r4, #2
	str r4, [r5]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r0, r0, r6
	ldr r7, [r0]
	ldr r0, _080555C8 @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _080555CC @ =0x41200000
	bl softfloat_divide
	mov r2, r8
	str r0, [r2]
	adds r4, #1
	str r4, [r5]
	adds r6, r7, r6
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r6]
	adds r4, #1
	str r4, [r5]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r6, #0xc6
	lsls r6, r6, #1
	b _0805593A
	.align 2, 0
_080555C4: .4byte 0x03005350
_080555C8: .4byte 0x03006D30
_080555CC: .4byte 0x41200000
_080555D0:
	ldr r0, _08055648 @ =0x03005350
	adds r5, r0, #0
	adds r5, #0xfc
	ldr r4, [r5]
	adds r4, #2
	str r4, [r5]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r0, r7
	ldr r7, [r0]
	ldr r0, _0805564C @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r6, r7, r1
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _08055650 @ =0x41200000
	bl softfloat_divide
	str r0, [r6]
	adds r4, #1
	str r4, [r5]
	movs r2, #0xce
	lsls r2, r2, #1
	adds r1, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r1, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r6, #0xd2
	lsls r6, r6, #1
	b _0805593A
	.align 2, 0
_08055648: .4byte 0x03005350
_0805564C: .4byte 0x03006D30
_08055650: .4byte 0x41200000
_08055654:
	ldr r0, _080556C0 @ =0x03005350
	adds r5, r0, #0
	adds r5, #0xfc
	ldr r4, [r5]
	adds r4, #2
	str r4, [r5]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r0, r7
	ldr r7, [r0]
	ldr r0, _080556C4 @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	adds r1, r7, #0
	adds r1, #0xe8
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	adds r6, r7, #0
	adds r6, #0xfc
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _080556C8 @ =0x3E000000
	bl softfloat_multiply
	str r0, [r6]
	adds r4, #1
	str r4, [r5]
	adds r1, r7, #0
	adds r1, #0xec
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	adds r1, #4
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	adds r1, #4
	b _0805593C
	.align 2, 0
_080556C0: .4byte 0x03005350
_080556C4: .4byte 0x03006D30
_080556C8: .4byte 0x3E000000
_080556CC:
	ldr r0, _08055748 @ =0x03005350
	adds r5, r0, #0
	adds r5, #0xfc
	ldr r4, [r5]
	adds r4, #2
	str r4, [r5]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r0, _0805574C @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r6, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _08055750 @ =0x3E000000
	bl softfloat_multiply
	str r0, [r6]
	adds r4, #1
	str r4, [r5]
	movs r6, #0x82
	lsls r6, r6, #1
	adds r1, r7, r6
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r7, r2
	b _0805593C
	.align 2, 0
_08055748: .4byte 0x03005350
_0805574C: .4byte 0x03006D30
_08055750: .4byte 0x3E000000
_08055754:
	ldr r0, _080557F8 @ =0x03005350
	adds r6, r0, #0
	adds r6, #0xfc
	ldr r4, [r6]
	adds r4, #2
	str r4, [r6]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r7, [r0]
	ldr r0, _080557FC @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r1, #0x90
	lsls r1, r1, #1
	adds r5, r7, r1
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _08055800 @ =0x3E000000
	bl softfloat_multiply
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	movs r2, #0x92
	lsls r2, r2, #1
	adds r5, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r5, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r3, #0x98
	lsls r3, r3, #1
	b _080558A6
	.align 2, 0
_080557F8: .4byte 0x03005350
_080557FC: .4byte 0x03006D30
_08055800: .4byte 0x3E000000
_08055804:
	ldr r0, _080558B8 @ =0x03005350
	adds r6, r0, #0
	adds r6, #0xfc
	ldr r4, [r6]
	adds r4, #2
	str r4, [r6]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r0, r7
	ldr r7, [r0]
	ldr r0, _080558BC @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r5, r7, r1
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _080558C0 @ =0x3E000000
	bl softfloat_multiply
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r5, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	movs r3, #0xac
	lsls r3, r3, #1
	adds r5, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	str r0, [r5]
	adds r4, #1
	str r4, [r6]
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	movs r3, #0xaa
	lsls r3, r3, #1
_080558A6:
	adds r1, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r6]
	bl _080566B6
	.align 2, 0
_080558B8: .4byte 0x03005350
_080558BC: .4byte 0x03006D30
_080558C0: .4byte 0x3E000000
_080558C4:
	ldr r0, _0805594C @ =0x03005350
	adds r5, r0, #0
	adds r5, #0xfc
	ldr r4, [r5]
	adds r4, #2
	str r4, [r5]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r0, r0, r6
	ldr r7, [r0]
	ldr r0, _08055950 @ =0x03006D30
	ldr r1, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r7, r0, r1
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r6, r7, r1
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	bl int_to_softfloat
	ldr r1, _08055954 @ =0x3E000000
	bl softfloat_multiply
	str r0, [r6]
	adds r4, #1
	str r4, [r5]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r1, r7, r2
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r1, r7, r3
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	movs r6, #0xde
	lsls r6, r6, #1
_0805593A:
	adds r1, r7, r6
_0805593C:
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r4, #1
	str r4, [r5]
	bl _080566B6
	.align 2, 0
_0805594C: .4byte 0x03005350
_08055950: .4byte 0x03006D30
_08055954: .4byte 0x3E000000
_08055958:
	ldr r7, _08055A34 @ =0x03005350
	mov r8, r7
	mov r2, r8
	adds r2, #0xfc
	ldr r1, [r2]
	adds r1, #2
	str r1, [r2]
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	adds r1, #1
	str r1, [r2]
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [sp, #0x58]
	adds r1, #1
	str r1, [r2]
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [sp, #0x5c]
	adds r1, #1
	str r1, [r2]
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [sp, #0x60]
	adds r1, #1
	str r1, [r2]
	ldr r1, _08055A38 @ =0x083D2DB0
	ldr r2, _08055A3C @ =0x03005448
	ldr r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r6, r7, #2
	adds r0, r6, r0
	ldr r2, [r0]
	ldr r3, _08055A40 @ =0x03006D30
	ldr r1, [r3]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r5, r0, #8
	adds r4, r5, r1
	movs r0, #0x84
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, [r2]
	cmp sl, r0
	blt _080559D0
	bl _080566B6
_080559D0:
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r4, r1
	add r0, sl
	mov r2, sl
	adds r1, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r0, [r3]
	adds r3, r5, r0
	mov r4, sl
	lsls r1, r4, #1
	movs r6, #0xb8
	lsls r6, r6, #2
	adds r0, r3, r6
	adds r0, r0, r1
	movs r1, #0
	strh r2, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r3, r2
	add r0, sl
	strb r1, [r0]
	ldr r1, _08055A44 @ =0x0847ECC0
	ldr r3, _08055A3C @ =0x03005448
	ldr r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08055A48 @ =0x06016C00
	bl LZ77UnCompVram
	movs r0, #0xea
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08055A58
	ldr r1, _08055A4C @ =0x040000D4
	ldr r2, _08055A50 @ =0x0847EC40
	ldr r4, _08055A3C @ =0x03005448
	ldr r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08055A54 @ =0x050003A0
	b _08055A6A
	.align 2, 0
_08055A34: .4byte 0x03005350
_08055A38: .4byte 0x083D2DB0
_08055A3C: .4byte 0x03005448
_08055A40: .4byte 0x03006D30
_08055A44: .4byte 0x0847ECC0
_08055A48: .4byte 0x06016C00
_08055A4C: .4byte 0x040000D4
_08055A50: .4byte 0x0847EC40
_08055A54: .4byte 0x050003A0
_08055A58:
	ldr r1, _08055AC0 @ =0x040000D4
	ldr r2, _08055AC4 @ =0x0847EC40
	ldr r6, _08055AC8 @ =0x03005448
	ldr r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08055ACC @ =0x0202F9A0
_08055A6A:
	str r0, [r1, #4]
	ldr r0, _08055AD0 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r6, _08055AD4 @ =0x03006D30
	ldr r0, [r6]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #8
	adds r0, r4, r0
	movs r5, #0xb7
	lsls r5, r5, #2
	adds r0, r0, r5
	add r0, sl
	ldrb r0, [r0]
	ldr r2, [sp, #0x58]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x5c]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	str r3, [sp]
	movs r3, #0xd
	bl init_battle_sprite_entry_08048818
	ldr r2, _08055AD8 @ =0x03002C30
	ldr r0, [r6]
	adds r4, r4, r0
	adds r4, r4, r5
	add r4, sl
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r6, [sp, #0x60]
	orrs r6, r1
	strh r6, [r0]
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r2
	b _08055B72
	.align 2, 0
_08055AC0: .4byte 0x040000D4
_08055AC4: .4byte 0x0847EC40
_08055AC8: .4byte 0x03005448
_08055ACC: .4byte 0x0202F9A0
_08055AD0: .4byte 0x84000008
_08055AD4: .4byte 0x03006D30
_08055AD8: .4byte 0x03002C30
_08055ADC:
	ldr r0, _08055B7C @ =0x03005350
	adds r4, r0, #0
	adds r4, #0xfc
	ldr r2, [r4]
	adds r2, #2
	str r2, [r4]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r7, [r0]
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	adds r2, #1
	str r2, [r4]
	ldr r6, _08055B80 @ =0x03006D30
	ldr r1, [r6]
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #8
	adds r1, r3, r1
	movs r0, #0xb7
	lsls r0, r0, #2
	mov r8, r0
	add r1, r8
	add r1, sl
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	strb r0, [r1]
	adds r2, #1
	str r2, [r4]
	ldr r0, [r6]
	adds r0, r0, r3
	mov ip, r0
	mov r1, sl
	lsls r0, r1, #1
	movs r1, #0xb8
	lsls r1, r1, #2
	add r1, ip
	adds r1, r1, r0
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	strh r0, [r1]
	adds r2, #1
	str r2, [r4]
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, ip
	add r1, sl
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	strb r0, [r1]
	adds r2, #1
	str r2, [r4]
	ldr r5, _08055B84 @ =0x03002C30
	ldr r0, [r6]
	adds r3, r3, r0
	add r3, r8
	add r3, sl
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r5
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	strh r0, [r1]
	adds r2, #1
	str r2, [r4]
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r5
_08055B72:
	lsls r0, r7, #2
	add r0, sl
	strb r0, [r1, #0x1d]
	bl _080566B6
	.align 2, 0
_08055B7C: .4byte 0x03005350
_08055B80: .4byte 0x03006D30
_08055B84: .4byte 0x03002C30
_08055B88:
	ldr r0, _08055BE8 @ =0x03005350
	adds r3, r0, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r0, _08055BEC @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r4, r0, r2
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0xe2
	lsls r7, r7, #1
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r6, #0xc
	adds r2, r4, r6
	bl _08056662
	.align 2, 0
_08055BE8: .4byte 0x03005350
_08055BEC: .4byte 0x03006D30
_08055BF0:
	adds r4, r5, #0
	adds r4, #0xfc
	ldr r1, [r4]
	adds r1, #2
	str r1, [r4]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r7, [r0]
	ldr r0, _08055C5C @ =0x03006D30
	ldr r0, [r0]
	lsls r2, r7, #1
	adds r2, r2, r7
	lsls r2, r2, #8
	adds r7, r2, r0
	movs r0, #0x82
	lsls r0, r0, #2
	adds r3, r7, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r3]
	adds r1, #1
	str r1, [r4]
	movs r6, #0x81
	lsls r6, r6, #2
	adds r3, r7, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r3]
	adds r1, #1
	str r1, [r4]
	movs r7, #0
	adds r4, r2, #0
_08055C36:
	ldr r0, _08055C5C @ =0x03006D30
	ldr r0, [r0]
	adds r1, r4, r0
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r1, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	movs r3, #0x81
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrb r1, [r1]
	bl sub_080493D4
	adds r7, #1
	cmp r7, #3
	ble _08055C36
	bl _080566B6
	.align 2, 0
_08055C5C: .4byte 0x03006D30
_08055C60:
	ldr r0, _08055CC0 @ =0x03005350
	adds r3, r0, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r7, [r0]
	ldr r0, _08055CC4 @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r4, r0, r2
	movs r6, #0xe8
	lsls r6, r6, #1
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0xea
	lsls r7, r7, #1
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r6, #0xc
	adds r2, r4, r6
	bl _08056662
	.align 2, 0
_08055CC0: .4byte 0x03005350
_08055CC4: .4byte 0x03006D30
_08055CC8:
	ldr r0, _08055D14 @ =0x03005350
	adds r3, r0, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r7, #0xc2
	lsls r7, r7, #1
	adds r0, r0, r7
	ldr r7, [r0]
	ldr r0, _08055D18 @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r4, r0, r2
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r6, #0xf2
	lsls r6, r6, #1
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0xf4
	lsls r7, r7, #1
	bl _08056660
	.align 2, 0
_08055D14: .4byte 0x03005350
_08055D18: .4byte 0x03006D30
_08055D1C:
	ldr r0, _08055D6C @ =0x03005350
	adds r3, r0, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r0, _08055D70 @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r4, r0, r2
	movs r6, #0xf6
	lsls r6, r6, #1
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0xf8
	lsls r7, r7, #1
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r2, r4, r0
	bl _08056662
	.align 2, 0
_08055D6C: .4byte 0x03005350
_08055D70: .4byte 0x03006D30
_08055D74:
	ldr r0, _08055DC4 @ =0x03005350
	adds r3, r0, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r0, _08055DC8 @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r4, r0, r2
	movs r6, #0xfc
	lsls r6, r6, #1
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0xfe
	lsls r7, r7, #1
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r4, r0
	bl _08056662
	.align 2, 0
_08055DC4: .4byte 0x03005350
_08055DC8: .4byte 0x03006D30
_08055DCC:
	ldr r7, _08055E34 @ =0x03005350
	adds r5, r7, #0
	adds r5, #0xfc
	ldr r2, [r5]
	adds r2, #1
	str r2, [r5]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r6, r7, r1
	ldr r1, [r6]
	lsls r1, r1, #2
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r3, r7, r4
	adds r1, r1, r3
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r2, #1
	str r2, [r5]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, [r6]
	lsls r1, r1, #2
	adds r3, r1, r3
	ldr r0, [r3]
	str r0, [r4]
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r0, r7, r3
	adds r0, r1, r0
	mov r4, sb
	str r4, [r0]
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	mov sb, r0
	adds r2, #1
	str r2, [r5]
	subs r3, #0x44
	adds r0, r7, r3
	adds r1, r1, r0
	str r2, [r1]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	movs r0, #0
	str r0, [r5]
	bl _080566B6
	.align 2, 0
_08055E34: .4byte 0x03005350
_08055E38:
	ldr r3, _08055E80 @ =0x03005350
	adds r2, r3, #0
	adds r2, #0xfc
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	lsls r1, r1, #2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r3, r6
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [r2]
	movs r7, #0xa2
	lsls r7, r7, #1
	adds r0, r3, r7
	adds r0, r1, r0
	ldr r0, [r0]
	mov sb, r0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r2, r3, r0
	adds r4, #0x48
	adds r0, r3, r4
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	bl _080566B6
	.align 2, 0
_08055E80: .4byte 0x03005350
_08055E84:
	ldr r5, _08055FAC @ =0x03005350
	adds r6, r5, #0
	adds r6, #0xfc
	ldr r2, [r6]
	adds r2, #1
	str r2, [r6]
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r4, r5, r7
	ldr r1, [r4]
	lsls r1, r1, #2
	movs r0, #0xc4
	lsls r0, r0, #1
	adds r3, r5, r0
	adds r1, r1, r3
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r2, #1
	str r2, [r6]
	ldr r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r7, [r0]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sl, r1
	ldr r1, [r1]
	ldr r0, _08055FB0 @ =0x03006D30
	ldr r4, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r4
	lsls r2, r7, #2
	mov r8, r2
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r0, r3
	add r0, r8
	str r7, [r0]
	ldr r1, [r6]
	lsls r0, r1, #2
	add r0, sb
	ldr r3, [r0]
	adds r1, #1
	str r1, [r6]
	mov r1, sl
	ldr r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r1, r1, r4
	movs r2, #0x86
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r0, #0xff
	ands r0, r3
	str r0, [r1]
	mov r1, sl
	ldr r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r1, r1, r4
	adds r2, #4
	mov ip, r2
	add r1, ip
	add r1, r8
	ldr r2, [r6]
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r2, #1
	str r2, [r6]
	mov r1, sl
	ldr r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r1, r1, r4
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r1, r1, r0
	add r1, r8
	lsls r0, r2, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	adds r2, #1
	str r2, [r6]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r0, r0, r4
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, sl
	ldr r1, [r2]
	str r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r3, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r3, r0
	beq _08055F64
	b _080566B6
_08055F64:
	ldr r1, [r6]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r1, #1
	str r1, [r6]
	lsls r0, r1, #2
	add r0, sb
	ldr r5, [r0]
	adds r1, #1
	str r1, [r6]
	cmp r2, #1
	beq _08055F80
	b _080566B6
_08055F80:
	mov r3, sl
	ldr r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r1, r1, r4
	mov r4, ip
	adds r0, r1, r4
	mov r6, r8
	adds r2, r0, r6
	ldr r3, [r2]
	cmp r5, #0
	bne _08055FA2
	adds r0, r1, #0
	adds r0, #0xc4
	ldr r0, [r0]
	str r0, [sp, #0x70]
_08055FA2:
	ldr r7, [sp, #0x70]
	subs r0, r7, r3
	str r0, [r2]
	b _080566B6
	.align 2, 0
_08055FAC: .4byte 0x03005350
_08055FB0: .4byte 0x03006D30
_08055FB4:
	ldr r4, _08056010 @ =0x03005350
	adds r3, r4, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0x81
	lsls r7, r7, #2
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	ldr r0, _08056014 @ =0x00007FFF
	ldr r1, _08056018 @ =0x00000000
	ldr r2, _0805601C @ =0x42000000
	ldr r3, _08056020 @ =0x41000000
	bl setup_palette_fade_to_color_with_obj
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #1
	str r0, [r1]
	b _080566B6
	.align 2, 0
_08056010: .4byte 0x03005350
_08056014: .4byte 0x00007FFF
_08056018: .4byte 0x00000000
_0805601C: .4byte 0x42000000
_08056020: .4byte 0x41000000
_08056024:
	ldr r4, _08056080 @ =0x03005350
	adds r3, r4, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #1
	str r1, [r3]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0x81
	lsls r0, r0, #2
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	ldr r0, _08056084 @ =0x00007FFF
	ldr r1, _08056088 @ =0x42000000
	ldr r2, _0805608C @ =0x00000000
	ldr r3, _08056090 @ =0x41000000
	bl setup_palette_fade_to_color
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #2
	str r0, [r1]
	b _080566B6
	.align 2, 0
_08056080: .4byte 0x03005350
_08056084: .4byte 0x00007FFF
_08056088: .4byte 0x42000000
_0805608C: .4byte 0x00000000
_08056090: .4byte 0x41000000
_08056094:
	ldr r5, _08056170 @ =0x03005350
	adds r3, r5, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	movs r4, #0x82
	lsls r4, r4, #2
	adds r0, r5, r4
	movs r4, #0
	strb r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	ldr r6, _08056174 @ =0x0000020A
	adds r0, r5, r6
	strh r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	movs r7, #0x83
	lsls r7, r7, #2
	adds r0, r5, r7
	strh r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #1
	str r1, [r3]
	subs r7, #0x17
	adds r2, r5, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r2, r5, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	subs r6, #0x10
	adds r2, r5, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r7, #0xc
	adds r2, r5, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #3
	str r0, [r1]
	bl sub_08049CC0
	movs r1, #0xbc
	lsls r1, r1, #6
	movs r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xd
	str r0, [sp, #8]
	movs r0, #0xb
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #0x40
	movs r2, #6
	b _080562BC
	.align 2, 0
_08056170: .4byte 0x03005350
_08056174: .4byte 0x0000020A
_08056178:
	ldr r5, _08056270 @ =0x03005350
	adds r3, r5, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r4, [r0]
	movs r2, #0x82
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r6, #0
	strb r4, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	ldr r7, _08056274 @ =0x0000020A
	adds r0, r5, r7
	strh r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r7, #2
	adds r0, r5, r7
	strh r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	adds r1, #1
	str r1, [r3]
	lsls r0, r1, #2
	add r0, sb
	ldr r2, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r5, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	subs r7, #0x14
	adds r2, r5, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r5, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r7, #8
	adds r2, r5, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #4
	str r0, [r1]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	cmp r4, #0
	beq _080562A6
	cmp r4, #0x10
	bne _08056288
	ldr r0, _08056278 @ =0x00007FFF
	movs r1, #0x20
	bl sub_08049CB0
	ldr r1, _0805627C @ =0x03006F40
	ldr r0, _08056280 @ =0x42000000
	str r0, [r1, #0x24]
	ldr r0, _08056284 @ =0x00000000
	str r0, [r1, #0x2c]
	movs r1, #0xbc
	lsls r1, r1, #6
	movs r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xe
	str r0, [sp, #8]
	movs r0, #0xc
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	movs r0, #0x40
	movs r2, #5
	b _080562BC
	.align 2, 0
_08056270: .4byte 0x03005350
_08056274: .4byte 0x0000020A
_08056278: .4byte 0x00007FFF
_0805627C: .4byte 0x03006F40
_08056280: .4byte 0x42000000
_08056284: .4byte 0x00000000
_08056288:
	cmp r4, #8
	beq _0805628E
	b _080566B6
_0805628E:
	movs r1, #0xbc
	lsls r1, r1, #6
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	movs r0, #0xa
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	movs r0, #0x40
	movs r2, #6
	b _080562BC
_080562A6:
	movs r1, #0xbc
	lsls r1, r1, #6
	movs r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #0x40
	movs r2, #4
_080562BC:
	movs r3, #8
	bl setup_blend_effect
	b _080566B6
_080562C4:
	ldr r4, _08056328 @ =0x03005350
	adds r1, r4, #0
	adds r1, #0xfc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bl populate_battle_entity_tile_positions
	ldr r0, _0805632C @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _08056330 @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r6, #0
	str r6, [sp, #0x54]
	ldr r1, _08056334 @ =0x040000D4
	add r0, sp, #0x54
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08056338 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl init_battle_medapart_sprites_all
	adds r0, r4, #0
	adds r0, #0xf8
	ldr r0, [r0]
	cmp r0, #0x12
	bne _080563D8
	ldr r0, _0805633C @ =0x03006D38
	ldrb r1, [r0, #5]
	adds r5, r0, #0
	cmp r1, #8
	bhi _08056344
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08056340 @ =0x083D2AAB
	ldrb r0, [r5, #5]
	adds r0, r0, r1
	ldrb r0, [r0]
	str r0, [r2]
	b _0805634C
	.align 2, 0
_08056328: .4byte 0x03005350
_0805632C: .4byte 0x03002C30
_08056330: .4byte 0x030055A0
_08056334: .4byte 0x040000D4
_08056338: .4byte 0x85000100
_0805633C: .4byte 0x03006D38
_08056340: .4byte 0x083D2AAB
_08056344:
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r0, r4, r2
	str r6, [r0]
_0805634C:
	ldr r6, _080563BC @ =0x03005350
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r3, _080563C0 @ =0x083D2AB4
	ldrb r0, [r5, #5]
	lsls r0, r0, #2
	adds r0, #2
	adds r0, r0, r3
	ldrb r2, [r0]
	lsls r2, r2, #4
	str r2, [r1]
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrb r0, [r5, #5]
	lsls r0, r0, #2
	adds r0, #3
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #4
	str r0, [r1]
	ldr r4, _080563C4 @ =0x030057E0
	ldr r7, _080563C8 @ =0x00000C52
	adds r1, r4, r7
	strh r2, [r1]
	ldr r2, _080563CC @ =0x00000C54
	adds r5, r4, r2
	strh r0, [r5]
	ldrh r0, [r1]
	bl sub_080526F0
	ldr r3, _080563D0 @ =0x00000C56
	adds r1, r4, r3
	strb r0, [r1]
	ldrh r0, [r5]
	bl sub_08052714
	adds r7, #5
	adds r1, r4, r7
	strb r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _080563D4 @ =0x000007FE
	adds r4, r4, r2
	strb r0, [r4]
	bl field_center_camera_on_player
	movs r0, #0xc
	movs r1, #0
	bl dispatch_jump_table_29
	b _0805643A
	.align 2, 0
_080563BC: .4byte 0x03005350
_080563C0: .4byte 0x083D2AB4
_080563C4: .4byte 0x030057E0
_080563C8: .4byte 0x00000C52
_080563CC: .4byte 0x00000C54
_080563D0: .4byte 0x00000C56
_080563D4: .4byte 0x000007FE
_080563D8:
	cmp r0, #0xe
	bne _0805643A
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r6, r4, r3
	ldr r0, _08056460 @ =0x083D2AD8
	ldrb r0, [r0]
	str r0, [r6]
	movs r7, #0xec
	lsls r7, r7, #1
	adds r2, r4, r7
	ldr r0, _08056464 @ =0x083D2AD9
	ldrb r1, [r0, #2]
	lsls r1, r1, #4
	str r1, [r2]
	subs r3, #4
	adds r2, r4, r3
	ldrb r0, [r0, #3]
	lsls r0, r0, #4
	str r0, [r2]
	ldr r4, _08056468 @ =0x030057E0
	ldr r7, _0805646C @ =0x00000C52
	adds r2, r4, r7
	strh r1, [r2]
	ldr r1, _08056470 @ =0x00000C54
	adds r5, r4, r1
	strh r0, [r5]
	ldrh r0, [r2]
	bl sub_080526F0
	ldr r2, _08056474 @ =0x00000C56
	adds r1, r4, r2
	strb r0, [r1]
	ldrh r0, [r5]
	bl sub_08052714
	ldr r3, _08056478 @ =0x00000C57
	adds r1, r4, r3
	strb r0, [r1]
	ldr r0, [r6]
	ldr r6, _0805647C @ =0x000007FE
	adds r4, r4, r6
	strb r0, [r4]
	bl field_center_camera_on_player
	movs r0, #0xa
	movs r1, #0
	bl dispatch_jump_table_29
_0805643A:
	ldr r0, _08056468 @ =0x030057E0
	ldr r7, _08056480 @ =0x00000CBA
	adds r0, r0, r7
	movs r1, #1
	strb r1, [r0]
	bl update_battle_field_frame
	bl load_battlefield_data_to_buffer
	ldr r1, _08056484 @ =0x03002C30
	movs r0, #0xb2
	lsls r0, r0, #5
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08056488 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	b _080566B6
	.align 2, 0
_08056460: .4byte 0x083D2AD8
_08056464: .4byte 0x083D2AD9
_08056468: .4byte 0x030057E0
_0805646C: .4byte 0x00000C52
_08056470: .4byte 0x00000C54
_08056474: .4byte 0x00000C56
_08056478: .4byte 0x00000C57
_0805647C: .4byte 0x000007FE
_08056480: .4byte 0x00000CBA
_08056484: .4byte 0x03002C30
_08056488: .4byte 0x0000BFFF
_0805648C:
	ldr r4, _080564D4 @ =0x03005350
	adds r3, r4, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #1
	str r1, [r3]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0x86
	lsls r7, r7, #2
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r6, #0xc
	adds r2, r4, r6
	b _08056662
	.align 2, 0
_080564D4: .4byte 0x03005350
_080564D8:
	ldr r4, _08056530 @ =0x03005350
	adds r3, r4, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #1
	str r1, [r3]
	movs r7, #0x89
	lsls r7, r7, #2
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r7, #0xc
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0x8d
	lsls r0, r0, #2
	b _08056640
	.align 2, 0
_08056530: .4byte 0x03005350
_08056534:
	ldr r2, _08056568 @ =0x03005350
	adds r2, #0xfc
	ldr r1, [r2]
	adds r1, #1
	str r1, [r2]
	lsls r0, r1, #2
	add r0, sb
	ldr r4, [r0]
	adds r1, #1
	str r1, [r2]
	lsls r0, r1, #2
	add r0, sb
	ldr r3, [r0]
	adds r1, #1
	lsls r0, r1, #2
	add r0, sb
	adds r1, #1
	str r1, [r2]
	ldr r0, [r0]
	cmp r0, #1
	beq _08056598
	cmp r0, #1
	bgt _0805656C
	cmp r0, #0
	beq _08056576
	b _080566B6
	.align 2, 0
_08056568: .4byte 0x03005350
_0805656C:
	cmp r0, #2
	beq _080565B8
	cmp r0, #3
	beq _080565D8
	b _080566B6
_08056576:
	ldr r0, _08056594 @ =0x03006D30
	ldr r2, [r0]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #8
	adds r1, r1, r2
	adds r1, #0xa0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xa0
	ldr r0, [r0]
	str r0, [r1]
	b _080566B6
	.align 2, 0
_08056594: .4byte 0x03006D30
_08056598:
	ldr r0, _080565B4 @ =0x03006D30
	ldr r2, [r0]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #8
	adds r1, r1, r2
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xc4
	ldr r0, [r0]
	str r0, [r1, #0xc]
	b _080566B6
	.align 2, 0
_080565B4: .4byte 0x03006D30
_080565B8:
	ldr r0, _080565D4 @ =0x03006D30
	ldr r2, [r0]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #8
	adds r1, r1, r2
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r2
	ldr r0, [r0, #0x7c]
	str r0, [r1, #0xc]
	b _080566B6
	.align 2, 0
_080565D4: .4byte 0x03006D30
_080565D8:
	ldr r0, _080565F4 @ =0x03006D30
	ldr r2, [r0]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #8
	adds r1, r1, r2
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r2
	ldr r0, [r0, #0x34]
	str r0, [r1, #0xc]
	b _080566B6
	.align 2, 0
_080565F4: .4byte 0x03006D30
_080565F8:
	ldr r0, _08056670 @ =0x03005350
	adds r3, r0, #0
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #2
	str r1, [r3]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r0, _08056674 @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r4, r0, r2
	movs r6, #0xbb
	lsls r6, r6, #2
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r7, #0xbc
	lsls r7, r7, #2
	adds r2, r4, r7
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	movs r0, #0xbd
	lsls r0, r0, #2
_08056640:
	adds r2, r4, r0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r6, #0xc
	adds r2, r4, r6
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	str r1, [r3]
	adds r7, #0xc
_08056660:
	adds r2, r4, r7
_08056662:
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r2]
_0805666A:
	adds r1, #1
	str r1, [r3]
	b _080566B6
	.align 2, 0
_08056670: .4byte 0x03005350
_08056674: .4byte 0x03006D30
_08056678:
	ldr r3, _0805669C @ =0x03005350
	adds r3, #0xfc
	ldr r1, [r3]
	adds r1, #1
	str r1, [r3]
	ldr r2, _080566A0 @ =0x030057E0
	lsls r0, r1, #2
	add r0, sb
	ldr r0, [r0]
	ldr r4, _080566A4 @ =0x00000C4C
	adds r2, r2, r4
	strb r0, [r2]
	adds r1, #1
	str r1, [r3]
	bl update_battle_entity_status_chars
	b _080566B6
	.align 2, 0
_0805669C: .4byte 0x03005350
_080566A0: .4byte 0x030057E0
_080566A4: .4byte 0x00000C4C
_080566A8:
	ldr r0, _08056794 @ =0x03005350
	adds r1, r0, #0
	adds r1, #0xf4
	movs r2, #0
	str r2, [r1]
	adds r0, #0xfc
	str r2, [r0]
_080566B6:
	ldr r1, _08056794 @ =0x03005350
	adds r0, r1, #0
	adds r0, #0xf4
	ldr r0, [r0]
	adds r5, r1, #0
	cmp r0, #0
	beq _0805677C
	cmp r0, #1
	beq _0805677C
	cmp r0, #2
	beq _0805677C
	cmp r0, #4
	beq _080566D4
	bl sub_08054234
_080566D4:
	adds r0, r5, #0
	adds r0, #0xfc
	movs r1, #0
	str r1, [r0]
	subs r0, #0xc
	str r1, [r0]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	cmp r1, #0xd
	beq _08056708
	cmp r1, #0x16
	beq _08056708
	bl sub_080492CC
	movs r4, #0
_080566FA:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl calculate_oam_affine_matrix
	adds r4, #1
	cmp r4, #0x1f
	ble _080566FA
_08056708:
	ldr r0, _08056794 @ =0x03005350
	adds r0, #0xf8
	ldr r0, [r0]
	cmp r0, #0xe
	beq _08056716
	cmp r0, #0x12
	bne _0805676A
_08056716:
	ldr r4, _08056798 @ =0x030057E0
	ldr r7, _0805679C @ =0x00000C67
	adds r5, r4, r7
	movs r0, #1
	strb r0, [r5]
	bl set_battle_state_cancel_flag
	bl init_battle_field_setup
	bl update_bg_scroll_offsets_a
	ldrb r0, [r5]
	bl field_set_player_facing
	ldr r0, _080567A0 @ =0x00000C76
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08056766
	ldr r4, _080567A4 @ =0x03002C30
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	bl set_battle_state_byte_c83
	ldr r2, _080567A8 @ =0x00000C2B
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r3, #0xc2
	lsls r3, r3, #4
	adds r4, r4, r3
	lsls r1, r1, #2
	ldrb r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
_08056766:
	bl update_battle_entity_status_chars
_0805676A:
	ldr r1, _08056794 @ =0x03005350
	adds r0, r1, #0
	adds r0, #0xf4
	ldr r0, [r0]
	adds r5, r1, #0
	cmp r0, #4
	beq _0805677C
	bl sub_08054234
_0805677C:
	adds r0, r5, #0
	adds r0, #0xf4
	ldr r0, [r0]
	add sp, #0x98
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08056794: .4byte 0x03005350
_08056798: .4byte 0x030057E0
_0805679C: .4byte 0x00000C67
_080567A0: .4byte 0x00000C76
_080567A4: .4byte 0x03002C30
_080567A8: .4byte 0x00000C2B
	.syntax divided
