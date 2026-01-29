#include "../Inc/STM32F446RE_Base.h"
#include "gpio.h"


//#define SET_SPI_BAUDRATE 1000000

typedef enum {
    SPI_2LINES_UNIDIR = 0,
    SPI_1LINE_BIDIR  = 1
}spi_CR1_BidirectionalMode;

typedef enum {
    SPI_RX_ONLY_FULL_DUPLEX = 0,
    SPI_RX_ONLY_RX_ONLY  = 1
}spi_CR1_RX_ONLY;

typedef enum {
    SPI_RX_ONLY = 0,
    SPI_TX_ONLY = 1
}spi_CR1_BidirectionalMode_OutputEnable;

typedef enum {
    SPI_CRC_DISABLE = 0,
    SPI_CRC_ENABLE  = 1
}spi_CR1_HwCRC_En;

/**/
typedef enum {
    SPI_DATA_PHASE = 0,
    SPI_NEXT_TRANSFER = 1
}spi_CR1_CRC_Transfer_Next;

typedef enum {
    SPI_8BIT_DATA = 0,
    SPI_16BIT_DATA = 1
}spi_CR1_DataFrameFormat;

typedef enum {
    SPI_SSM_DISABLE = 0,
    SPI_SSM_ENABLE  = 1
}spi_CR1_SoftSlaveMgmt;

typedef enum {
   NODATA = 0
}spi_CR1_InternalSlaveSelect;

typedef enum {
    SPI_MSB_TRANSFER = 0,
    SPI_LSB_TRANSFER = 1
}spi_CR1_FrameFormat;

typedef enum {
    SPI_ENABLE = 0,
    SPI_DISABLE = 1
}spi_CR1_SPI_Enable;

typedef enum {
    SPI_DIV_2 = 0,    /*Fpclk/2*/
    SPI_DIV_4 = 1,    /*Fpclk/4*/
    SPI_DIV_8 = 2,    /*Fpclk/8*/
    SPI_DIV_16 = 3,   /*Fpclk/16*/
    SPI_DIV_32 = 4,   /*Fpclk/32*/
    SPI_DIV_64 = 5,   /*Fpclk/64*/
    SPI_DIV_128 = 6,  /*Fpclk/128*/
    SPI_DIV_256 = 7   /*Fpclk/256*/
}spi_CR1_BaudRate;

typedef enum {
    SPI_SLAVE_CFG = 0,
    SPI_MASTER_CFG = 1
}spi_CR1_MasterSelect;

typedef enum {
    SPI_CLK_POL_HIGH = 0,
    SPI_CLK_POL_LOW = 1
}spi_CR1_ClockPolarity;

typedef enum {
    SPI_CLK_PHA_1ST_EDGE = 0, /*leading edge*/
    SPI_CLK_PHA_2ND_EDGE = 1  /*trailing edge*/
}spi_CR1_ClockPhase;


typedef struct spi_CR1
{
    spi_CR1_BidirectionalMode bidir_mod;
    spi_CR1_BidirectionalMode_OutputEnable bidirmod_outen;
    spi_CR1_RX_ONLY rx_only;
    spi_CR1_HwCRC_En hw_crc_en;
    spi_CR1_CRC_Transfer_Next crc_next;
    spi_CR1_DataFrameFormat data_frame_format;
    spi_CR1_SoftSlaveMgmt soft_slave_mgmt;
    spi_CR1_InternalSlaveSelect internal_slave_select;
    spi_CR1_FrameFormat frame_format;
    spi_CR1_SPI_Enable spi_en;
    spi_CR1_BaudRate baudrate;
    spi_CR1_MasterSelect master_select;
    spi_CR1_ClockPolarity clk_pol;
    spi_CR1_ClockPhase clk_pha;
}spi_CR1_type;

/*
#define SPI1_CONFIGURATION {
.bidir_mod = SPI_1LINE_BIDIR, \
.bidirmod_outen = ,\
.
}
*/
