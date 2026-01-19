
#include "dma.h"



void dma1_Stream_init(uint32 src, uint32 dest, uint32 length)
{
    //enable clock DMA acess
    vDo_APB1ENR_EnableClockAccessToDMA(21);

    //disable DMA1 stream6
    DMA1_STREAM6->CR &= ~(1<<0); 
    //clear all interrupts flags of stream6
    DMA1->HISR = (1<<16);
    DMA1->HISR = (1<<18);
    DMA1->HISR = (1<<19);
    DMA1->HISR = (1<<20);
    DMA1->HISR = (1<<21);
    //set destination buffer
    DMA1_STREAM6->SxPAR = dest;
    //set source buffer
    DMA1_STREAM6->M0AR = src;
    //set length
    DMA1_STREAM6->SxNDTR = length;
    //set streamx channelX
    DMA1_STREAM6->CR = 4<<25;
    //eneable memory intrement
    DMA1_STREAM6->CR = 1<<10;
    //configure transfer destination
    DMA1_STREAM6->CR = 1<<6;//from memory to pheripherels

    //enable dma transfer complete interrupt
     DMA1_STREAM6->CR = 1<<4;

    //enable direct mode and fisable fifo

    //direct mode disable  = 0 and FIFO 
    DMA1_STREAM6->SxFCR = 0;
    //enable dma1 steam6
    DMA1_STREAM6->CR |= (1<<0); 
    //enable uart2 transmitter MDA
    //Bit 7 DMAT: DMA enable transmitter
    USART_2->CR3 = 1<<7;
    //dma interrupt enable in NVIC
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}
