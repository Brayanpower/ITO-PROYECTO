from machine import Pin, PWM
from utime import sleep_us, sleep
import _thread
from hcsr04 import HCSR04

# Configura el servo SG90
# Declaro servo
servo = PWM(Pin(13), freq=50)

sensor = HCSR04(trigger_pin=18, echo_pin=5, echo_timeout_us=30000)

# Configura los pines del motor paso a paso
IN1 = Pin(2, Pin.OUT)
IN2 = Pin(4, Pin.OUT)
IN3 = Pin(19, Pin.OUT)
IN4 = Pin(21, Pin.OUT)

pins = [IN1, IN2, IN3, IN4]

sequence = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]

def stop_stepper():
    for pin in pins:
        pin.value(0)

# Función para controlar el motor a pasos
def control_motor():
    while True:
        for step in sequence:
            for i in range(len(pins)):
                pins[i].value(step[i])
                sleep_us(1000)  # Utiliza sleep_us para obtener microsegundos de pausa

# Inicia el hilo para controlar el motor a pasos
_thread.start_new_thread(control_motor, ())
 
# Define el valor de duty cycle para la posición del servo
duty_cycle_movimiento = 26  # Por ejemplo, cuando se toca

while True:
    # Mide la distancia
    distancia = sensor.distance_cm()
    print("Distancia medida:", distancia, "cm")
    
    # Lógica para controlar el servo en función de la distancia
    if distancia <= 60 :
        # Resto de la lógica principal
        servo.duty(90)
        sleep(1)
        servo.duty(121)
        sleep(1)
    else:
        # Detener el servo y el motor cuando la distancia no es suficiente
        servo.duty(0)
        stop_stepper()