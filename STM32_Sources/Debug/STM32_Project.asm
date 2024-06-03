
STM32_Project.elf:     file format elf32-littlearm


Disassembly of section .text:

080001c4 <__do_global_dtors_aux>:
 80001c4:	b510      	push	{r4, lr}
 80001c6:	4c05      	ldr	r4, [pc, #20]	@ (80001dc <__do_global_dtors_aux+0x18>)
 80001c8:	7823      	ldrb	r3, [r4, #0]
 80001ca:	b933      	cbnz	r3, 80001da <__do_global_dtors_aux+0x16>
 80001cc:	4b04      	ldr	r3, [pc, #16]	@ (80001e0 <__do_global_dtors_aux+0x1c>)
 80001ce:	b113      	cbz	r3, 80001d6 <__do_global_dtors_aux+0x12>
 80001d0:	4804      	ldr	r0, [pc, #16]	@ (80001e4 <__do_global_dtors_aux+0x20>)
 80001d2:	f3af 8000 	nop.w
 80001d6:	2301      	movs	r3, #1
 80001d8:	7023      	strb	r3, [r4, #0]
 80001da:	bd10      	pop	{r4, pc}
 80001dc:	20000000 	.word	0x20000000
 80001e0:	00000000 	.word	0x00000000
 80001e4:	080002a8 	.word	0x080002a8

080001e8 <frame_dummy>:
 80001e8:	b508      	push	{r3, lr}
 80001ea:	4b03      	ldr	r3, [pc, #12]	@ (80001f8 <frame_dummy+0x10>)
 80001ec:	b11b      	cbz	r3, 80001f6 <frame_dummy+0xe>
 80001ee:	4903      	ldr	r1, [pc, #12]	@ (80001fc <frame_dummy+0x14>)
 80001f0:	4803      	ldr	r0, [pc, #12]	@ (8000200 <frame_dummy+0x18>)
 80001f2:	f3af 8000 	nop.w
 80001f6:	bd08      	pop	{r3, pc}
 80001f8:	00000000 	.word	0x00000000
 80001fc:	20000004 	.word	0x20000004
 8000200:	080002a8 	.word	0x080002a8

08000204 <main>:
 8000204:	b480      	push	{r7}
 8000206:	af00      	add	r7, sp, #0
 8000208:	bf00      	nop
 800020a:	e7fd      	b.n	8000208 <main+0x4>

0800020c <Reset_Handler>:
 800020c:	480d      	ldr	r0, [pc, #52]	@ (8000244 <LoopForever+0x2>)
 800020e:	4685      	mov	sp, r0
 8000210:	f3af 8000 	nop.w
 8000214:	480c      	ldr	r0, [pc, #48]	@ (8000248 <LoopForever+0x6>)
 8000216:	490d      	ldr	r1, [pc, #52]	@ (800024c <LoopForever+0xa>)
 8000218:	4a0d      	ldr	r2, [pc, #52]	@ (8000250 <LoopForever+0xe>)
 800021a:	2300      	movs	r3, #0
 800021c:	e002      	b.n	8000224 <LoopCopyDataInit>

0800021e <CopyDataInit>:
 800021e:	58d4      	ldr	r4, [r2, r3]
 8000220:	50c4      	str	r4, [r0, r3]
 8000222:	3304      	adds	r3, #4

08000224 <LoopCopyDataInit>:
 8000224:	18c4      	adds	r4, r0, r3
 8000226:	428c      	cmp	r4, r1
 8000228:	d3f9      	bcc.n	800021e <CopyDataInit>
 800022a:	4a0a      	ldr	r2, [pc, #40]	@ (8000254 <LoopForever+0x12>)
 800022c:	4c0a      	ldr	r4, [pc, #40]	@ (8000258 <LoopForever+0x16>)
 800022e:	2300      	movs	r3, #0
 8000230:	e001      	b.n	8000236 <LoopFillZerobss>

08000232 <FillZerobss>:
 8000232:	6013      	str	r3, [r2, #0]
 8000234:	3204      	adds	r2, #4

08000236 <LoopFillZerobss>:
 8000236:	42a2      	cmp	r2, r4
 8000238:	d3fb      	bcc.n	8000232 <FillZerobss>
 800023a:	f000 f811 	bl	8000260 <__libc_init_array>
 800023e:	f7ff ffe1 	bl	8000204 <main>

08000242 <LoopForever>:
 8000242:	e7fe      	b.n	8000242 <LoopForever>
 8000244:	20020000 	.word	0x20020000
 8000248:	20000000 	.word	0x20000000
 800024c:	20000000 	.word	0x20000000
 8000250:	080002c8 	.word	0x080002c8
 8000254:	20000000 	.word	0x20000000
 8000258:	2000001c 	.word	0x2000001c

0800025c <ADC_IRQHandler>:
 800025c:	e7fe      	b.n	800025c <ADC_IRQHandler>
	...

08000260 <__libc_init_array>:
 8000260:	b570      	push	{r4, r5, r6, lr}
 8000262:	4d0d      	ldr	r5, [pc, #52]	@ (8000298 <__libc_init_array+0x38>)
 8000264:	4c0d      	ldr	r4, [pc, #52]	@ (800029c <__libc_init_array+0x3c>)
 8000266:	1b64      	subs	r4, r4, r5
 8000268:	10a4      	asrs	r4, r4, #2
 800026a:	2600      	movs	r6, #0
 800026c:	42a6      	cmp	r6, r4
 800026e:	d109      	bne.n	8000284 <__libc_init_array+0x24>
 8000270:	4d0b      	ldr	r5, [pc, #44]	@ (80002a0 <__libc_init_array+0x40>)
 8000272:	4c0c      	ldr	r4, [pc, #48]	@ (80002a4 <__libc_init_array+0x44>)
 8000274:	f000 f818 	bl	80002a8 <_init>
 8000278:	1b64      	subs	r4, r4, r5
 800027a:	10a4      	asrs	r4, r4, #2
 800027c:	2600      	movs	r6, #0
 800027e:	42a6      	cmp	r6, r4
 8000280:	d105      	bne.n	800028e <__libc_init_array+0x2e>
 8000282:	bd70      	pop	{r4, r5, r6, pc}
 8000284:	f855 3b04 	ldr.w	r3, [r5], #4
 8000288:	4798      	blx	r3
 800028a:	3601      	adds	r6, #1
 800028c:	e7ee      	b.n	800026c <__libc_init_array+0xc>
 800028e:	f855 3b04 	ldr.w	r3, [r5], #4
 8000292:	4798      	blx	r3
 8000294:	3601      	adds	r6, #1
 8000296:	e7f2      	b.n	800027e <__libc_init_array+0x1e>
 8000298:	080002c0 	.word	0x080002c0
 800029c:	080002c0 	.word	0x080002c0
 80002a0:	080002c0 	.word	0x080002c0
 80002a4:	080002c4 	.word	0x080002c4

080002a8 <_init>:
 80002a8:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 80002aa:	bf00      	nop
 80002ac:	bcf8      	pop	{r3, r4, r5, r6, r7}
 80002ae:	bc08      	pop	{r3}
 80002b0:	469e      	mov	lr, r3
 80002b2:	4770      	bx	lr

080002b4 <_fini>:
 80002b4:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 80002b6:	bf00      	nop
 80002b8:	bcf8      	pop	{r3, r4, r5, r6, r7}
 80002ba:	bc08      	pop	{r3}
 80002bc:	469e      	mov	lr, r3
 80002be:	4770      	bx	lr
