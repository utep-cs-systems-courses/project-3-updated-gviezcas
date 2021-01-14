all: main.elf shapeLib.a p2swLib.a



CPU             = msp430g2553







CFLAGS          = -mmcu=${CPU} -Os -I../h







LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/





#switch the compiler (for the internal make rules)







CC              = msp430-elf-gcc







AS              = msp430-elf-as -mmcu=${CPU} -c







AR              = msp430-elf-ar





main.elf: main.o stateMachines.o buzzer.o led.o switches.o wdInterruptHandler.o wdt_handler.o p1_interrupt_handler.o wd_redInterruptHandler.o jumpTable.o



	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer





clean:



	rm -f *.a *.o *.elf *~



load: main.elf



	msp430loader.sh $^







main.o: stateMachines.h







stateMachines.o: stateMachines.h
