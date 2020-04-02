import time
import serial
          
      
ser = serial.Serial(
              
    port='/dev/ttyACM0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)
          
      
while 1:
    ADC_val=ser.readline()
    ADC_val = str(ADC_val, 'utf-8')
    ADC_val = ADC_val[:(len(ADC_val)-2)]
    ADC_val = 5*(float(ADC_val)/1024)
    print (str(ADC_val) + "V")
    
