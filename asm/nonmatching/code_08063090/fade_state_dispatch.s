	.syntax unified

	thumb_func_start fade_state_dispatch
fade_state_dispatch: @ 0x08065D3C
	push {r4, r5, lr}
	ldr r0, _08065D64 @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	bne _08065D48
	b _08065EF4
_08065D48:
	ldr r1, _08065D68 @ =0x03006F74
	ldr r0, [r1]
	movs r2, #0x3a
	ldrsh r0, [r0, r2]
	adds r5, r1, #0
	cmp r0, #5
	bls _08065D58
	b _08066094
_08065D58:
	lsls r0, r0, #2
	ldr r1, _08065D6C @ =_08065D70
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08065D64: .4byte 0x03000B90
_08065D68: .4byte 0x03006F74
_08065D6C: .4byte _08065D70
_08065D70: @ jump table
	.4byte _08065D88 @ case 0
	.4byte _08065DE0 @ case 1
	.4byte _08065E24 @ case 2
	.4byte _08065E40 @ case 3
	.4byte _08065E98 @ case 4
	.4byte _08065EDC @ case 5
_08065D88:
	bl sub_080440B4
	cmp r0, #1
	bgt _08065DAC
	ldr r2, _08065DA0 @ =0x03006F74
	ldr r0, [r2]
	adds r0, #0x7b
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08065DA4 @ =0x03005010
	ldr r0, _08065DA8 @ =0x0000FF02
	b _08065DBA
	.align 2, 0
_08065DA0: .4byte 0x03006F74
_08065DA4: .4byte 0x03005010
_08065DA8: .4byte 0x0000FF02
_08065DAC:
	ldr r2, _08065DD0 @ =0x03006F74
	ldr r0, [r2]
	adds r0, #0x7b
	movs r1, #0xff
	strb r1, [r0]
	ldr r1, _08065DD4 @ =0x03005010
	ldr r0, _08065DD8 @ =0x0000FF03
_08065DBA:
	strh r0, [r1, #6]
	adds r5, r2, #0
	adds r3, r1, #0
	ldrh r1, [r3, #0xa]
	ldr r0, _08065DDC @ =0x0000FF04
	cmp r1, r0
	beq _08065DCA
	b _08066094
_08065DCA:
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08065DD0: .4byte 0x03006F74
_08065DD4: .4byte 0x03005010
_08065DD8: .4byte 0x0000FF03
_08065DDC: .4byte 0x0000FF04
_08065DE0:
	ldr r3, _08065E14 @ =0x03005010
	ldr r4, _08065E18 @ =0x0000FF05
	strh r4, [r3, #6]
	ldrh r2, [r3, #0xa]
	adds r0, r2, #0
	adds r0, #0xfe
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08065E06
	ldr r0, [r5]
	ldr r1, _08065E1C @ =0x0000FF02
	eors r1, r2
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	adds r0, #0x7b
	strb r1, [r0]
	ldr r0, _08065E20 @ =0x0000FF04
	strh r0, [r3, #6]
_08065E06:
	ldrh r0, [r3, #0xa]
	cmp r0, r4
	beq _08065E0E
	b _08066094
_08065E0E:
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08065E14: .4byte 0x03005010
_08065E18: .4byte 0x0000FF05
_08065E1C: .4byte 0x0000FF02
_08065E20: .4byte 0x0000FF04
_08065E24:
	ldr r0, _08065E38 @ =0x03005010
	ldr r1, _08065E3C @ =0x0000FF06
	strh r1, [r0, #6]
	ldrh r0, [r0, #0xa]
	cmp r0, r1
	beq _08065E32
	b _08066094
_08065E32:
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08065E38: .4byte 0x03005010
_08065E3C: .4byte 0x0000FF06
_08065E40:
	bl sub_080440D4
	cmp r0, #0
	beq _08065E64
	ldr r2, _08065E58 @ =0x03006F74
	ldr r0, [r2]
	adds r0, #0x7c
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08065E5C @ =0x03005010
	ldr r0, _08065E60 @ =0x0000FF02
	b _08065E72
	.align 2, 0
_08065E58: .4byte 0x03006F74
_08065E5C: .4byte 0x03005010
_08065E60: .4byte 0x0000FF02
_08065E64:
	ldr r2, _08065E88 @ =0x03006F74
	ldr r0, [r2]
	adds r0, #0x7c
	movs r1, #0xff
	strb r1, [r0]
	ldr r1, _08065E8C @ =0x03005010
	ldr r0, _08065E90 @ =0x0000FF03
_08065E72:
	strh r0, [r1, #6]
	adds r5, r2, #0
	adds r3, r1, #0
	ldrh r1, [r3, #0xa]
	ldr r0, _08065E94 @ =0x0000FF04
	cmp r1, r0
	beq _08065E82
	b _08066094
_08065E82:
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08065E88: .4byte 0x03006F74
_08065E8C: .4byte 0x03005010
_08065E90: .4byte 0x0000FF03
_08065E94: .4byte 0x0000FF04
_08065E98:
	ldr r3, _08065ECC @ =0x03005010
	ldr r4, _08065ED0 @ =0x0000FF05
	strh r4, [r3, #6]
	ldrh r2, [r3, #0xa]
	adds r0, r2, #0
	adds r0, #0xfe
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08065EBE
	ldr r0, [r5]
	ldr r1, _08065ED4 @ =0x0000FF02
	eors r1, r2
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	adds r0, #0x7c
	strb r1, [r0]
	ldr r0, _08065ED8 @ =0x0000FF04
	strh r0, [r3, #6]
_08065EBE:
	ldrh r0, [r3, #0xa]
	cmp r0, r4
	beq _08065EC6
	b _08066094
_08065EC6:
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08065ECC: .4byte 0x03005010
_08065ED0: .4byte 0x0000FF05
_08065ED4: .4byte 0x0000FF02
_08065ED8: .4byte 0x0000FF04
_08065EDC:
	ldr r0, _08065EEC @ =0x03005010
	ldr r1, _08065EF0 @ =0x0000FF06
	strh r1, [r0, #6]
	ldrh r0, [r0, #0xa]
	cmp r0, r1
	beq _08065EEA
	b _08066094
_08065EEA:
	b _0806608C
	.align 2, 0
_08065EEC: .4byte 0x03005010
_08065EF0: .4byte 0x0000FF06
_08065EF4:
	ldr r1, _08065F10 @ =0x03006F74
	ldr r0, [r1]
	movs r2, #0x3a
	ldrsh r0, [r0, r2]
	adds r5, r1, #0
	cmp r0, #5
	bls _08065F04
	b _08066094
_08065F04:
	lsls r0, r0, #2
	ldr r1, _08065F14 @ =_08065F18
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08065F10: .4byte 0x03006F74
_08065F14: .4byte _08065F18
_08065F18: @ jump table
	.4byte _08065F30 @ case 0
	.4byte _08065F70 @ case 1
	.4byte _08065FA0 @ case 2
	.4byte _08065FD0 @ case 3
	.4byte _08066010 @ case 4
	.4byte _0806606C @ case 5
_08065F30:
	ldr r3, _08065F60 @ =0x03005010
	ldrh r2, [r3, #0xe]
	adds r0, r2, #0
	adds r0, #0xfe
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08065F52
	ldr r0, [r5]
	ldr r1, _08065F64 @ =0x0000FF02
	eors r1, r2
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	adds r0, #0x7b
	strb r1, [r0]
	ldr r0, _08065F68 @ =0x0000FF04
	strh r0, [r3, #6]
_08065F52:
	ldrh r1, [r3, #0xe]
	ldr r0, _08065F6C @ =0x0000FF05
	cmp r1, r0
	beq _08065F5C
	b _08066094
_08065F5C:
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08065F60: .4byte 0x03005010
_08065F64: .4byte 0x0000FF02
_08065F68: .4byte 0x0000FF04
_08065F6C: .4byte 0x0000FF05
_08065F70:
	ldr r0, [r5]
	adds r0, #0x7b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08065F86
	bl sub_080440B4
	cmp r0, #1
	bgt _08066040
_08065F86:
	ldr r1, _08065F98 @ =0x03005010
	movs r2, #0
	ldr r0, _08065F9C @ =0x0000FF02
	strh r0, [r1, #6]
	ldr r0, [r5]
	adds r0, #0x7b
	strb r2, [r0]
	b _08066046
	.align 2, 0
_08065F98: .4byte 0x03005010
_08065F9C: .4byte 0x0000FF02
_08065FA0:
	ldr r0, _08065FC4 @ =0x03005010
	ldr r2, _08065FC8 @ =0x0000FF05
	strh r2, [r0, #6]
	ldrh r1, [r0, #0xa]
	adds r3, r0, #0
	cmp r1, r2
	bne _08065FB8
	ldrh r1, [r3, #0xe]
	ldr r0, _08065FCC @ =0x0000FF06
	cmp r1, r0
	bne _08065FB8
	strh r1, [r3, #6]
_08065FB8:
	ldrh r1, [r3, #0xa]
	ldr r0, _08065FCC @ =0x0000FF06
	cmp r1, r0
	bne _08066094
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08065FC4: .4byte 0x03005010
_08065FC8: .4byte 0x0000FF05
_08065FCC: .4byte 0x0000FF06
_08065FD0:
	ldr r3, _08066000 @ =0x03005010
	ldrh r2, [r3, #0xe]
	adds r0, r2, #0
	adds r0, #0xfe
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08065FF2
	ldr r0, [r5]
	ldr r1, _08066004 @ =0x0000FF02
	eors r1, r2
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	adds r0, #0x7c
	strb r1, [r0]
	ldr r0, _08066008 @ =0x0000FF04
	strh r0, [r3, #6]
_08065FF2:
	ldrh r1, [r3, #0xe]
	ldr r0, _0806600C @ =0x0000FF05
	cmp r1, r0
	bne _08066094
	ldr r1, [r5]
	b _08066054
	.align 2, 0
_08066000: .4byte 0x03005010
_08066004: .4byte 0x0000FF02
_08066008: .4byte 0x0000FF04
_0806600C: .4byte 0x0000FF05
_08066010:
	ldr r0, [r5]
	adds r0, #0x7c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08066026
	bl sub_080440D4
	cmp r0, #0
	beq _08066040
_08066026:
	ldr r1, _08066038 @ =0x03005010
	movs r2, #0
	ldr r0, _0806603C @ =0x0000FF02
	strh r0, [r1, #6]
	ldr r0, [r5]
	adds r0, #0x7c
	strb r2, [r0]
	b _08066046
	.align 2, 0
_08066038: .4byte 0x03005010
_0806603C: .4byte 0x0000FF02
_08066040:
	ldr r1, _0806605C @ =0x03005010
	ldr r0, _08066060 @ =0x0000FF03
	strh r0, [r1, #6]
_08066046:
	adds r3, r1, #0
	ldrh r1, [r3, #0xe]
	ldr r0, _08066064 @ =0x0000FF04
	cmp r1, r0
	bne _08066094
	ldr r0, _08066068 @ =0x03006F74
	ldr r1, [r0]
_08066054:
	ldrh r0, [r1, #0x3a]
	adds r0, #1
	strh r0, [r1, #0x3a]
	b _08066094
	.align 2, 0
_0806605C: .4byte 0x03005010
_08066060: .4byte 0x0000FF03
_08066064: .4byte 0x0000FF04
_08066068: .4byte 0x03006F74
_0806606C:
	ldr r0, _0806609C @ =0x03005010
	ldr r2, _080660A0 @ =0x0000FF05
	strh r2, [r0, #6]
	ldrh r1, [r0, #0xa]
	adds r3, r0, #0
	cmp r1, r2
	bne _08066084
	ldrh r1, [r3, #0xe]
	ldr r0, _080660A4 @ =0x0000FF06
	cmp r1, r0
	bne _08066084
	strh r1, [r3, #6]
_08066084:
	ldrh r1, [r3, #0xa]
	ldr r0, _080660A4 @ =0x0000FF06
	cmp r1, r0
	bne _08066094
_0806608C:
	ldr r1, _080660A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08066094:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806609C: .4byte 0x03005010
_080660A0: .4byte 0x0000FF05
_080660A4: .4byte 0x0000FF06
_080660A8: .4byte 0x0300137C
	.syntax divided
