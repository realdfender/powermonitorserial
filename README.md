Made to read the serial data of the Lechacal.com power / current sensors

Based on the code from @ssieb - serial_csv.

Added filter for minimum power sice my lechacal sensors is old and 50A - Noise is a bit.


First value is an ID number.


Esp home yaml config example:


external_components:
  - source:
      type: git
      url: https://github.com/realdfender/powermonitorserial
    components: [powermonitorserial]
    refresh: 0s

sensor:
- platform: powermonitorserial
  uart_id: uart_bus   # optional
  sensors:
    - index: 0
      name: idpow
    - index: 1
      name: "Sensor1"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"
    - index: 2
      name: "Sensor2"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"
    - index: 3
      name: "Sensor3"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"
    - index: 4
      name: "Sensor4"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"
    - index: 5
      name: "Sensor5"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"
    - index: 6
      name: "Sensor6"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"
    - index: 7
      name: "Sensor7"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"
    - index: 8
      name: "Sensor8"
      unit_of_measurement: "W"
      accuracy_decimals: 1
      icon: "mdi:lightning-bolt"

