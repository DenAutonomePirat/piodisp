#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "piolib.h"
#include "clock.pio.h"
#include "vfd.c"

int main(int argc, const char **argv)
{
    PIO pio;
    int sm;
    uint offset;

    char line[33];
    uint32_t databuf[8];
    uint gpio = 2;
    int pass;
    // uint i;
    uint pin = 16; //
    uint clk = 20; // load on sideset +1

    if (argc == 2)
        gpio = (uint)strtoul(argv[1], NULL, 0);
    pio = pio0;
    // sm = 0;
    // pio_sm_claim(pio, sm);
    sm = pio_claim_unused_sm(pio, true);
    pio_sm_config_xfer(pio, sm, PIO_DIR_TO_SM, 256, 1);

    offset = pio_add_program(pio, &shift_20_msb_program);
    printf("Loaded program at %d, using sm %d, gpio %d\n", offset, sm, gpio);

    pio_sm_clear_fifos(pio, sm);
    shift_20_msb_program_init(pio, sm, offset, pin, clk);
    pio_sm_set_enabled(pio, sm, true);

    // Open FIFO for reading
    FILE *fifo = fopen("/tmp/myfifo", "rb");
    if (!fifo)
    {
        perror("Failed to open FIFO");
        return 1;
    }

    pass = 0;
    while (1)
    {
        fgets(line, sizeof(line), fifo);

        vfd_put_8_utf8(line, databuf);

        if (feof(fifo))
        {
            fprintf(stderr, "End of FIFO reached\n");
            break; // Exit the loop if EOF is reached
        }

        /*
        // Use sequential access to send data 8 kHz @ 35 %CPU
        for (int i = 0; i < 8; i++)
         {
             if (databuf[i] == 0)
             {
                 fprintf(stderr, "Received zero data at index %d\n", i);
                 continue; // Skip sending zero data
             }
             pio_sm_put_blocking(pio, sm, databuf[i]);
         }
        */

        // use DMA to transfer data to PIO 20 kHz @ 12 %CPU
        pio_sm_xfer_data(pio, sm, PIO_DIR_TO_SM, sizeof(databuf), databuf);
        // sleep_ms(1); // Uncomment if you want to slow down the loop
        pass++;
    }

    fprintf(stdout, "Pass %d: Sent data to PIO\n", pass);
    pio_sm_set_enabled(pio, sm, false);
    fclose(fifo);
    pio_sm_unclaim(pio, sm);

    return 0;
}
