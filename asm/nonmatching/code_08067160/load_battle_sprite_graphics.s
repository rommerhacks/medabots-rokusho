	.syntax unified

	thumb_func_start load_battle_sprite_graphics
load_battle_sprite_graphics: @ 0x08069874
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08069954 @ =0x083F80F4
	adds r0, #0x94
	ldr r0, [r0]
	ldr r1, _08069958 @ =0x06012400
	bl LZ77UnCompVram
	ldr r4, _0806995C @ =0x040000D4
	ldr r0, _08069960 @ =0x083F8634
	mov r8, r0
	adds r0, #0x94
	ldr r0, [r0]
	str r0, [r4]
	ldr r0, _08069964 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _08069968 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806996C @ =0x087AD4E4
	ldr r1, _08069970 @ =0x06012E00
	bl LZ77UnCompVram
	ldr r1, _08069954 @ =0x083F80F4
	ldr r0, [r1]
	ldr r1, _08069974 @ =0x06015100
	bl LZ77UnCompVram
	mov r1, r8
	ldr r0, [r1]
	str r0, [r4]
	ldr r0, _08069978 @ =0x05000300
	str r0, [r4, #4]
	ldr r5, _0806997C @ =0x84000008
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r6, _08069980 @ =0x083C1A00
	ldr r0, _08069984 @ =0x08486160
	mov sl, r0
	ldr r1, _08069988 @ =0x03006FDC
	mov sb, r1
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sl
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r7, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #2
	ldr r1, _08069954 @ =0x083F80F4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0806998C @ =0x06015A00
	bl LZ77UnCompVram
	ldrb r0, [r7]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r0, [r4]
	ldr r0, _08069990 @ =0x05000320
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, sb
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sl
	movs r1, #6
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r7, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #2
	ldr r1, _08069954 @ =0x083F80F4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08069994 @ =0x06016300
	bl LZ77UnCompVram
	ldrb r0, [r7]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r0, [r4]
	ldr r0, _08069998 @ =0x05000340
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806999C @ =0x0807C300
	str r0, [r4]
	ldr r0, _080699A0 @ =0x050003A0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069954: .4byte 0x083F80F4
_08069958: .4byte 0x06012400
_0806995C: .4byte 0x040000D4
_08069960: .4byte 0x083F8634
_08069964: .4byte 0x05000200
_08069968: .4byte 0x80000010
_0806996C: .4byte 0x087AD4E4
_08069970: .4byte 0x06012E00
_08069974: .4byte 0x06015100
_08069978: .4byte 0x05000300
_0806997C: .4byte 0x84000008
_08069980: .4byte 0x083C1A00
_08069984: .4byte 0x08486160
_08069988: .4byte 0x03006FDC
_0806998C: .4byte 0x06015A00
_08069990: .4byte 0x05000320
_08069994: .4byte 0x06016300
_08069998: .4byte 0x05000340
_0806999C: .4byte 0x0807C300
_080699A0: .4byte 0x050003A0
	.syntax divided
