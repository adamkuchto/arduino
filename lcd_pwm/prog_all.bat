@set PROCESOR=m328
@set PROGRAMATOR=usbasp
@set FILE_HEX=lcd_pwm.ino.with_bootloader.eightanaloginputs.hex

@set H_FUSE=0xC9
@set L_FUSE=0x3F
@set LOCK_=0xFC


avrdude.exe -p %PROCESOR% -c %PROGRAMATOR% -e -U flash:w:%FILE_HEX%.hex  -U hfuse:w:%H_FUSE%:m -U lfuse:w:%L_FUSE%:m -U lock:w:%LOCK_%:m
pause
