CC = arm-none-eabi-gcc
MARCH = cortex-m4
STD = gnu11
CFLAGS = -c -mcpu=$(MARCH) -mthumb -mfloat-abi=soft -Wall -std=$(STD) -O0
# LDFLAGS = -mcpu=$(MARCH) -mthumb -mfloat-abi=soft --specs=nano.specs -T stm32_ls.ld -Wl,-Map=final.map
LDFLAGS_SH = -mcpu=$(MARCH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32_ls.ld -Wl,-Map=final.map

all : main.o led.o syscalls.o stm32_startup.o final.elf

semi : main.o led.o stm32_startup.o final_sh.elf

main.o : main.c
	$(CC) $(CFLAGS) $^ -o $@

led.o : led.c
	$(CC) $(CFLAGS) $^ -o $@

stm32_startup.o : stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

syscalls.o : syscalls.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf : main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS) $^ syscalls.o -o $@

final_sh.elf : main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS_SH) $^ -o $@
	
load :
	openocd -f board/stm32f4discovery.cfg
clean :
	rm -rf *.o *.elf